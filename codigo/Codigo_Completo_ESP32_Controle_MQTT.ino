#include <WiFi.h>
#include <PubSubClient.h>

// Wi-Fi
const char* ssid = "SEM MUNDIAL";
const char* password = "vaiCorinthians";

// MQTT
const char* mqtt_server = "broker.hivemq.com";
const int mqtt_port = 1883;
const char* mqtt_topic_umidade = "projetoESP32/umidade";
const char* mqtt_topic_comando = "projetoESP32/comando";

WiFiClient espClient;
PubSubClient client(espClient);

// Pinos
const int sensorPin = 34;
const int bombaPin = 26;

unsigned long tempoBombaManual = 0;
bool bombaLigadaManualmente = false;

void setup_wifi() {
  delay(1000);
  Serial.println("Conectando ao WiFi...");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\n✅ WiFi conectado!");
  Serial.print("IP: ");
  Serial.println(WiFi.localIP());
}

void callback(char* topic, byte* payload, unsigned int length) {
  String mensagem = "";
  for (unsigned int i = 0; i < length; i++) {
    mensagem += (char)payload[i];
  }

  Serial.print("📩 Comando recebido no tópico ");
  Serial.print(topic);
  Serial.print(": ");
  Serial.println(mensagem);

  if (mensagem == "ligar") {
    bombaLigadaManualmente = true;
    tempoBombaManual = millis();
    digitalWrite(bombaPin, LOW);  // Liga bomba
    Serial.println("⚡ Bomba ligada manualmente!");
  }
}

void reconnect() {
  while (!client.connected()) {
    Serial.print("Conectando ao broker MQTT...");
    if (client.connect("ESP32Cliente")) {
      Serial.println("✅ conectado!");
      client.subscribe(mqtt_topic_comando);
    } else {
      Serial.print("❌ falhou, rc=");
      Serial.print(client.state());
      Serial.println(" tentando novamente em 5s");
      delay(5000);
    }
  }
}

void setup() {
  Serial.begin(115200);
  pinMode(bombaPin, OUTPUT);
  digitalWrite(bombaPin, HIGH); // bomba desligada inicialmente

  setup_wifi();
  client.setServer(mqtt_server, mqtt_port);
  client.setCallback(callback);
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  int umidade = analogRead(sensorPin);
  Serial.print("Umidade: ");
  Serial.print(umidade);

  String estado = "";

  // Prioridade: comando manual
  if (bombaLigadaManualmente) {
    estado = "⚠ MANUAL";
    if (millis() - tempoBombaManual > 5000) { // 5 segundos ligados
      bombaLigadaManualmente = false;
      digitalWrite(bombaPin, HIGH);  // Desliga
      Serial.println(" → Bomba manual desligada após 5s");
    } else {
      digitalWrite(bombaPin, LOW); // Mantém ligada
      Serial.println(" → Bomba ligada (modo manual)");
    }
  } else {
    if (umidade > 3000) {
      estado = "SECO";
      digitalWrite(bombaPin, LOW);  // Liga bomba
      Serial.println(" → SOLO SECO → LIGANDO bomba");
    } else {
      estado = "UMIDO";
      digitalWrite(bombaPin, HIGH); // Desliga bomba
      Serial.println(" → SOLO ÚMIDO → DESLIGANDO bomba");
    }
  }

  // Publica a umidade no MQTT
  String payload = "Umidade: " + String(umidade) + " → " + estado;
  client.publish(mqtt_topic_umidade, payload.c_str());

  delay(3000);
}
