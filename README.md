# Smart Energy Saving and Automatic Load Control System

## Project overview
This project demonstrates occupancy-based automatic load control. An IR proximity/obstacle sensor is read by an Arduino UNO. When the sensor detects a person or object, three LEDs turn ON to represent electrical loads. When detection is absent, the LEDs turn OFF. A buzzer is activated during detection.

## Current prototype status
**Initial proof of concept:** Arduino UNO, IR sensor, three LEDs, buzzer, breadboard, resistors and jumper wires.

The LCD is not included in the verified code yet because its exact type and wiring need to be confirmed. Actual voltage, current and energy measurement are not implemented in this prototype.

## Components
- Arduino UNO
- IR proximity/obstacle sensor module
- 3 LEDs
- 3 × 1 kΩ resistors (one in series with each LED)
- Active buzzer suitable for the Arduino output
- Breadboard and jumper wires
- USB data cable for programming

## Wiring
| Component | Arduino UNO |
|---|---|
| IR sensor VCC | 5V |
| IR sensor GND | GND |
| IR sensor DO | D2 |
| Buzzer positive (+) | D7 |
| Buzzer negative (-) | GND |
| LED 1 anode (+), through 1 kΩ resistor | D8 |
| LED 1 cathode (-) | GND |
| LED 2 anode (+), through 1 kΩ resistor | D9 |
| LED 2 cathode (-) | GND |
| LED 3 anode (+), through 1 kΩ resistor | D10 |
| LED 3 cathode (-) | GND |

All component grounds must connect to Arduino GND. Do not connect LEDs without series resistors.

## Setup instructions
1. Install Arduino IDE.
2. Connect Arduino UNO using a USB data cable.
3. Select **Tools → Board → Arduino Uno**.
4. Select the correct port under **Tools → Port**.
5. Open `arduino/smart_energy_saving_system.ino`.
6. Click **Verify**, then **Upload**.
7. Open **Tools → Serial Monitor** and set baud rate to **9600**.
8. Adjust the IR sensor potentiometer until detection is reliable.

## Expected behavior
- Detection active: all three simulated-load LEDs turn ON, buzzer turns ON, and a status message appears in Serial Monitor.
- No detection: all three LEDs and buzzer turn OFF.

Many IR modules output LOW on detection. If behavior is reversed, change `DETECTED_LEVEL` from `LOW` to `HIGH` and upload again.

## Limitations and planned improvements
The current prototype uses LEDs as simulated loads. It does not measure real load voltage, current, power or energy and does not switch mains appliances. The planned full version may add an ESP32, suitable current and voltage sensors, relay module, regulated DC supply/buck converter, LCD/dashboard, and protected enclosure.

## Safety
Do not connect mains AC wiring to a breadboard or directly to Arduino. Any future mains-load implementation requires correctly rated isolation, relay, fuse, enclosure and competent supervision.
