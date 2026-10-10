/*
  Smart Energy Saving and Automatic Load Control System
  Initial proof-of-concept prototype using Arduino UNO.

  IR sensor DO -> D2
  Active buzzer + -> D7, - -> GND
  LED1 through 1k ohm resistor -> D8; LED cathode -> GND
  LED2 through 1k ohm resistor -> D9; LED cathode -> GND
  LED3 through 1k ohm resistor -> D10; LED cathode -> GND

  Many IR modules output LOW when an object is detected.
  If your sensor behaves oppositely, change DETECTED_LEVEL to HIGH.
  LEDs simulate loads; this prototype does not measure real power.
*/
const byte IR_SENSOR_PIN = 2;
const byte BUZZER_PIN = 7;
const byte LED1_PIN = 8;
const byte LED2_PIN = 9;
const byte LED3_PIN = 10;

// Change to HIGH if your sensor outputs HIGH when detecting.
const byte DETECTED_LEVEL = LOW;

void setup() {
  pinMode(IR_SENSOR_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(LED1_PIN, OUTPUT);
  pinMode(LED2_PIN, OUTPUT);
  pinMode(LED3_PIN, OUTPUT);

  digitalWrite(BUZZER_PIN, LOW);
  digitalWrite(LED1_PIN, LOW);
  digitalWrite(LED2_PIN, LOW);
  digitalWrite(LED3_PIN, LOW);

  Serial.begin(9600);
  Serial.println("Smart Energy Saving System started");
}

void loop() {
  int sensorValue = digitalRead(IR_SENSOR_PIN);
  bool detected = (sensorValue == DETECTED_LEVEL);

  if (detected) {
    digitalWrite(LED1_PIN, HIGH);
    digitalWrite(LED2_PIN, HIGH);
    digitalWrite(LED3_PIN, HIGH);
    digitalWrite(BUZZER_PIN, HIGH);
    Serial.println("PERSON/OBJECT DETECTED - SIMULATED LOADS ON");
  } else {
    digitalWrite(LED1_PIN, LOW);
    digitalWrite(LED2_PIN, LOW);
    digitalWrite(LED3_PIN, LOW);
    digitalWrite(BUZZER_PIN, LOW);
    Serial.println("NO PERSON/OBJECT DETECTED - SIMULATED LOADS OFF");
  }
  delay(200);
}
