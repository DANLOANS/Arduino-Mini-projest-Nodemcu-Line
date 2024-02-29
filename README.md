# NodeMCU V.2 Project: Rainfall Alert via LINE

## Project Description
This project utilizes NodeMCU V.2 programmed with Arduino IDE to detect rainfall using Rain Sensor Modules and send notification messages via the LINE API when it's raining.

## Components Used
1. NodeMCU V.2
2. Rain Sensor Modules
3. Female-to-Female Jumper Wires (20CM)
4. Shield Nodemcu AB-Maker V1.3 For Nodemcu Esp8266 V2

## Installation
1. Install the DHT library and LINE Notify library in the Arduino IDE.
2. Connect the Rain Sensor Modules to the NodeMCU V.2 as per the instructions provided in the code.

## Usage
1. Install the LINE application and subscribe to LINE Notify.
2. Visit the LINE Notify webpage [https://notify-bot.line.me/th/](https://notify-bot.line.me/th/) to obtain the access token for sending notification messages via LINE.
3. Replace the placeholder in the code with the received access token.
4. Upload the code to the NodeMCU V.2.
5. Power up the sensor and connect to the internet.

## Notification
When the sensor detects rainfall, it sends data to the NodeMCU V.2, which in turn sends notification messages via LINE Notify.

