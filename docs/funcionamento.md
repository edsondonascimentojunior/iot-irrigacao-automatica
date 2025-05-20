# Funcionamento do Sistema

Este sistema de irrigação automática é baseado na leitura do sensor de umidade do solo e no acionamento de uma bomba de água diretamente pelo ESP32.

## 🔁 Lógica de funcionamento

1. O sensor de umidade envia dados analógicos para o ESP32.
2. O microcontrolador interpreta esses valores:
   - Se o solo estiver seco (abaixo de 40%), a bomba é acionada por um pino digital.
   - Se estiver úmido (acima de 40%), a bomba permanece desligada.
3. O valor de umidade e o estado da bomba são publicados via MQTT.
4. Um painel no Node-RED exibe os dados e permite controle manual da bomba.

## 🧠 Modo Automático

- A bomba liga automaticamente quando a umidade estiver abaixo do valor limite configurado.

## 🖐 Modo Manual (via MQTT)

- O sistema também permite receber comandos do tipo:
  - `LIGAR`

Isso permite o controle remoto via app, painel ou script MQTT.

## 💡 Observações

- A bomba é alimentada por 4 pilhas AA (6V), com o polo negativo controlado diretamente pelo pino D26 do ESP32. O controle é feito sem relé, diretamente por GPIO, com precaução quanto ao limite de corrente.
- As conexões são organizadas em uma protoboard, com alimentação compartilhada para o sensor via pinos 3V3 e GND do ESP32.
