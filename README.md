# Smart Home Web App – Next.js + MQTT

## Overview
This repository contains the **Next.js frontend and backend** for controlling smart lights remotely via **ESP32-CAM** and a **cloud MQTT broker**.  
It includes **authentication, dashboard, and secure MQTT communication**.

## Features
- Control 5 lights remotely
- Secure user login (JWT)
- MQTT integration for real-time commands
- Ready for deployment on **Vercel**
- Supports remote access via internet

## Architecture
Browser / Phone
|
Next.js App (Vercel)
├─ Frontend: UI dashboard
├─ API: authentication & light control
|
MQTT Broker (HiveMQ Cloud)
|
ESP32-CAM: executes commands


## Getting Started

### 1. Clone the repo
```bash
git clone https://github.com/Kostalaroche1/control-in-remote-by-internet
cd nextjs-smart-home
npm install

 2. Environment Variables (.env.local)
JWT_SECRET=your_jwt_secret
MQTT_URL=mqtts://your-cluster.s1.eu.hivemq.cloud:8883
MQTT_USER=your_username
MQTT_PASS=your_password

3. Run locally
npm run dev

4. Deploy

Push to GitHub → connect to Vercel

Set environment variables in Vercel dashboard

Vercel builds only the Next.js project

References

HiveMQ Cloud

Next.js Documentation
