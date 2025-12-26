
### to get NextJs project web app follow this link
https://github.com/Kostalaroche1/Smart-Home-Web-App-Next.js-MQTT.git
---

# **2️⃣ ESP32 Repo README.md**

```markdown
# Smart Home Hardware – ESP32-CAM + MQTT

## Overview
This repository contains the **ESP32-CAM project** for controlling smart lights via **MQTT**.  
The ESP32 subscribes to a cloud MQTT broker and executes commands sent from the **Next.js app**.

## Features
- Control 5 relays/lights
- Connects to cloud MQTT (HiveMQ)
- Optional camera snapshots/stream
- Works remotely with Next.js backend

## Hardware Setup
- ESP32-CAM board
- 5 relays connected to GPIO: 2, 4, 5, 18, 19
- Power supply: 5V
- Wi-Fi connection to internet

## MQTT Configuration
- Use **HiveMQ Cloud** or other MQTT broker
- Create **username & password**
- Use **TLS port 8883** for secure communication

### Example in ESP32 `.ino`
```cpp
client.setServer("your-cluster.s1.eu.hivemq.cloud", 8883);
client.connect("esp32cam", mqttUser, mqttPass);
client.subscribe("home/lights");

