# 🌱 iot-irrigacao-automatica

Sistema de irrigação automática utilizando ESP32, sensor de umidade do solo e bomba d’água controlada via MQTT.

---

## 📋 Descrição

Este projeto visa automatizar a irrigação de plantas com base na umidade do solo, utilizando um sensor conectado ao ESP32. A bomba d’água é acionada automaticamente quando o solo estiver seco e pode ser monitorada/controlada remotamente via protocolo MQTT, usando um painel como o Node-RED.

---

## ⚙️ Componentes Utilizados

- ESP-WROOM-32 (ESP32)
- Sensor de umidade do solo YL-69 com módulo
- Bomba d’água submersível 6V
- Suporte para 4 pilhas AA (6V)
- Protoboard e jumpers
- Cabo USB para alimentação e programação do ESP32

> 🔧 O controle da bomba é feito diretamente pelo GPIO26 do ESP32 (sem relé), considerando uma bomba de **baixa corrente**.

---

## 🧠 Funcionamento

1. O sensor de umidade mede os níveis do solo.
2. O ESP32 interpreta os dados:
   - Se a umidade estiver baixa, aciona a bomba via GPIO26.
   - Se a umidade estiver alta, a bomba permanece desligada.
3. Os dados são publicados via MQTT nos seguintes tópicos:
   - `irrigacao/umidade` (valor da umidade)
   - `irrigacao/status` (estado da bomba)
4. Comandos podem ser enviados ao tópico `irrigacao/comando` para ligar/desligar manualmente.

---

## 🖥️ Integração com Node-RED

- Visualize os dados de umidade e status da bomba.
- Envie comandos manuais pelo painel.
- O sistema pode operar de forma híbrida: automático + controle remoto MQTT.

> ⚠️ Certifique-se de que o ESP32 esteja conectado à mesma rede do servidor MQTT.

---

## 🔌 Esquema de Montagem

📷 Imagem disponível em:  
[📁 imagens/esquema_fritzing.png](./imagens/esquema_fritzing.png)

---

## ▶️ Demonstração

📺 [Clique aqui para assistir à demonstração do projeto no YouTube](https://www.youtube.com/watch?v=lU8Nx28ws5k) 


---

## 📁 Organização do Projeto

iot-irrigacao-automatica/
├── codigo/ # Código principal em main.ino
├── docs/ # Documentação técnica
│ ├── hardware.md
│ ├── comunicacao.md
│ └── funcionamento.md
├── imagens/ # Esquemas e fotos
└── README.md

---

## 👨‍💻 Autores

- Edson do Nascimento Junior  

---

## 📝 Licença

Este projeto foi desenvolvido como parte da disciplina de Objetos Inteligentes Conectados.
