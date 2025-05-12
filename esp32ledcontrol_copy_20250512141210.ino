#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "BluetoothSerial.h"

BluetoothSerial SerialBT;

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define LED_PIN 4
#define BUZZER_PIN 23

void setup() {
    pinMode(LED_PIN, OUTPUT);
    pinMode(BUZZER_PIN, OUTPUT);
    digitalWrite(LED_PIN, LOW);
    digitalWrite(BUZZER_PIN, LOW);

    Serial.begin(115200);
    SerialBT.begin("ESP32 Voice");  // Set Bluetooth name

    if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
        Serial.println(F("SSD1306 allocation failed"));
        while (1);
    }

    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(0, 10);
    display.println("ESP32 Voice Ready");
    display.setCursor(0, 25);
    display.println("Waiting command...");
    display.display();
}

void loop() {
    if (SerialBT.available()) {
        String command = SerialBT.readStringUntil('\n');
        command.trim();

        display.clearDisplay();
        display.setTextSize(1);
        display.setTextColor(WHITE);
        display.setCursor(0, 10);

        if (command.equalsIgnoreCase("LED on")) {
            digitalWrite(LED_PIN, HIGH);
            display.println("Command: LED ON");
            display.setCursor(0, 25);
            display.println("LED is ON");
        } else if (command.equalsIgnoreCase("LED off")) {
            digitalWrite(LED_PIN, LOW);
            display.println("Command: LED OFF");
            display.setCursor(0, 25);
            display.println("LED is OFF");
        } else {
            display.println("Invalid Command:");
            display.setCursor(0, 25);
            display.println(command);
            digitalWrite(BUZZER_PIN, HIGH);
            delay(1000);
            digitalWrite(BUZZER_PIN, LOW);
        }

        display.display();
    }
}
