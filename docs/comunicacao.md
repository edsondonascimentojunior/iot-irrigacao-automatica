# Comunicação e Protocolo

O sistema de irrigação utiliza o protocolo **MQTT** para realizar a comunicação entre o ESP32 e uma interface como o **Node-RED**.

## 📡 Comunicação

- **Tipo de rede:** Wi-Fi (IEEE 802.11 b/g/n)
- **Protocolo de mensagens:** MQTT (Message Queuing Telemetry Transport)
- **Servidor MQTT:** Externo usado: broker.hivemq.com

## 🔁 Tópicos utilizados

- **Publicação (ESP32 → Broker):**
  - `irrigacao/umidade`: publica o valor lido do sensor de umidade
  - `irrigacao/status`: publica o estado da bomba (ligada/desligada)

- **Assinatura (Broker → ESP32):**
  - `irrigacao/comando`: recebe comandos de ligar a bomba manualmente

## 🛠 Exemplo de integração com Node-RED

- O Node-RED pode assinar os tópicos para exibir os dados graficamente.
- Pode também publicar comandos para ligar a bomba mesmo que o solo esteja úmido.

> ⚠️ Certifique-se de que o servidor MQTT está acessível pela rede Wi-Fi em que o ESP32 está conectado.
