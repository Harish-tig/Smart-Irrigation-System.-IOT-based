# Plan of Action


## Overview
The system uses electronic devices that can be modified as desired. If you have the following devices and materials ready, the time required to build and install this system is approximately 6-10 hours.
<br>
Make Sure you have installed Device driver for esp8266. and use 2.4ghz connection to connect with micro controller.
### Devices and Materials Required
- ESP8266 and a hotspot
- 2 Relays
- 2 Water pumps (10V)
- PCB or Breadboard (optional and recommended)
- I2C LCD (optional)
- Soil and DHT11 sensor
- Jumper wires
- Switch, bottle, containers, battery, tape, non-return valve, etc.

### Estimated Time
**6-10 hours**

### Connection Instructions
Understand the connections mentioned below to modify the code as needed.

#### 1. Connect ESP Pins as Follows
- **Relay 1:**
  - Vcc --> Vin
  - Gnd --> Gnd
  - In --> D0

- **Relay 2:**
  - Vcc --> Vin
  - Gnd --> Gnd
  - In --> D3

- **LCD:**
  - Vcc --> Vin3
  - Gnd --> Gnd
  - Scl --> D1
  - Sda --> D2

- **Moisture Sensor:**
  - Vcc --> Vin
  - Gnd --> Gnd
  - AO --> AO

- **DHT Sensor:**
  - Vcc --> Vcc
  - Gnd --> Gnd
  - Data --> D4
  
### Your Connection Architecture should look like this
<img src="https://github.com/user-attachments/assets/6151b5d6-6d8b-453b-8196-d78880e18efc" width=40% height="220" /> 

### Final Steps
Once the connections are completed, connect the ESP8266 to your laptop and upload the code to the ESP8266 using the Arduino IDE.
Download the required libraries for DHT11, i2CLCD, ESp8266 etc etc. variety of source is available out there.

# Blynk Web Dashboard

## Dashboard Configuration

1. **Build the Blynk Web Dashboard:**
   - Refer to "Picture 1" for the layout and design.
   - Add charts to monitor and study your system more accurately.

2. **Uploading Code:**
   - Once the dashboard is built and the code is uploaded, enter the Template ID in the Blynk app.

## Remote Control

- After adding the Template ID, you will be able to control your device via a laptop from anywhere in the world.
- You can also download the Blynk app from the Play Store to control it via mobile.

#### Example of Blynk WEB Dashboard (refer below image)
<img src="https://github.com/user-attachments/assets/ccf8490a-551d-4fd8-8f69-8bd3c19523b7" widht="400" height="300">

#### Example of Blynk mobile Dashboard (refer below image)
<img src = "https://github.com/user-attachments/assets/9e14299a-a49d-4a37-a886-de6954d58ba2" widht="400" height="300">



## Steps to Follow:

1. **Build the Web Dashboard:**
   - Follow the layout in "Picture 1".
   - Ensure to add charts for better monitoring.

2. **Upload Code:**
   - Upload your code to the ESP8266 using the Arduino IDE.
   - for Code refer CODE.C file inside Project repository.

3. **Enter Template ID:**
   - Open the Blynk app.
   - Enter the Template ID provided after uploading the code.

4. **Control Your Device:**
   - Use your laptop or mobile device to control and monitor the system remotely via the Blynk app.
