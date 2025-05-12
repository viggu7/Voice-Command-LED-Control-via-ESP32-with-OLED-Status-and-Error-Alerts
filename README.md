# Voice-Command-LED-Control-via-ESP32-with-OLED-Status-and-Error-Alerts

This project demonstrates how to control an LED using **Bluetooth voice commands** on an **ESP32** board. Status messages and error alerts are displayed on an **OLED screen**, and a buzzer signals invalid inputs.

## 🔧 Features
- ✅ LED control using Bluetooth (ON/OFF)
- 📺 OLED status display for command and result
- 🚨 Buzzer alert for invalid voice commands
- 🎙️ Bluetooth name: **ESP32 Voice**
- 🧠 Simple logic, beginner-friendly

## 🛠️ Components Used
- ESP32 Dev Board
- 0.96" OLED Display (SSD1306, I2C)
- LED
- Buzzer
- Android phone with Bluetooth terminal or voice app

## 🔌 Circuit Connections
| Component     | ESP32 Pin |
|---------------|-----------|
| LED           | GPIO 4    |
| Buzzer        | GPIO 23   |
| OLED SDA      | GPIO 21   |
| OLED SCL      | GPIO 22   |

## 📱 Voice Commands
- `"LED on"` → Turns on the LED
- `"LED off"` → Turns off the LED
- Any other input → Shows error and activates buzzer

## 🚀 Getting Started
1. Upload the code via Arduino IDE
2. Connect with your phone to **ESP32 Voice**
3. Send voice commands via Bluetooth terminal

## 📷 Demo (Optional)
_Add images or video link here_

## 🧠 Author
- Vignesh ([@viggu7](https://github.com/viggu7))

## 📝 License
MIT License
