Project Overview

This project implements a collision detection and emergency alert system for vehicles using the CAN (Controller Area Network) protocol and GSM-based SMS notification.
The system continuously monitors vehicle parameters from the CAN bus and detects abnormal conditions such as sudden impact, rapid deceleration, or crash indicators.
When a collision is detected, the system automatically sends an SMS alert to predefined emergency contacts.

This enhances vehicle safety, provides real-time accident alerts, and helps reduce emergency response time.

🎯 Features

✔️ Reads real-time vehicle data using CAN Bus (MCP2515 Module)

✔️ Detects collision using CAN crash codes / abnormal sensor values

✔️ Alerts emergency contacts via GSM module (SIM800/SIM900)

✔️ Sends SMS with details such as:

Accident detected

Timestamp

(Optional) GPS location

✔️ Compact and cost-effective design

✔️ Fully compatible with Arduino Uno/Nano

🛠️ Components Used
Component	Quantity	Description
Arduino Uno / Nano	1	Main controller
MCP2515 CAN-Bus Module	1	To read data from vehicle CAN network
GSM Module SIM800L / SIM900A	1	Sends SMS alerts
12V to 5V Converter	1	To power Arduino from vehicle battery
Jumper Wires	–	Connections
(Optional) GPS Module NEO-6M	1	Sends location in SMS
🔧 System Architecture / Block Diagram
        Vehicle Sensors → CAN Bus → MCP2515 → Arduino → GSM Module → SMS Alert

📡 How Collision is Detected

The system analyzes CAN messages such as:

Airbag deployment signals

Sudden deceleration (high negative acceleration)

Impact sensor values

CAN error frames indicating crash

If any parameter crosses threshold limits, the system identifies it as a collision event.
