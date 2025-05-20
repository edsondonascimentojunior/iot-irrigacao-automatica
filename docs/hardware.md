# Hardware Utilizado

Este sistema de irrigação automática foi desenvolvido com os seguintes componentes:

## 🔌 Componentes principais

- **ESP32 (ESP-WROOM-32)**  
  Placa microcontroladora com suporte Wi-Fi integrada, utilizada para ler sensores e acionar diretamente a bomba d’água.

- **Sensor de Umidade do Solo YL-69 com Módulo**  
  O sensor possui duas pontas metálicas que são inseridas no solo e conectadas à plaquinha amplificadora. Esta envia o valor analógico ao ESP32 pelo pino **AO**.

- **Bomba d’água submersível 6V (acionada diretamente)**  
  Alimentada por 4 pilhas AA (6V). O fio negativo da bomba está conectado diretamente ao pino D26 do ESP32 para controle digital, e o fio positivo está conectado ao polo positivo das pilhas.

- **Protoboard e cabos jumper**  
  Utilizados para fazer as conexões físicas entre sensor, ESP32 e a alimentação externa (pilhas). O GND e 3V3 do ESP32 alimentam o módulo sensor via a protoboard.

- **Suporte para 4 pilhas AA (6V)**  
  Alimenta a bomba d’água separadamente do ESP32. O GND das pilhas está interligado ao GND da protoboard para referência comum.

## 🔧 Esquema de montagem

A imagem do circuito completo atualizado está disponível em:  
📁 [`/imagens/esquema_fritzing.png`](../imagens/esquema_fritzing.png)

Você pode visualizar:

- Sensor de umidade conectado ao pino D34 do ESP32 (analógico)
- Bomba conectada ao pino D26 do ESP32
- Protoboard conectando GND e 3V3 entre sensor e ESP32
- Alimentação da bomba separada, com GND comum

> ⚠️ Atenção: Esse esquema funciona com bombas de baixa corrente. Para bombas mais potentes, recomenda-se o uso de relé ou transistor com diodo de proteção.
