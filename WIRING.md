# Wiring checklist

1. IR sensor: VCC to 5V, GND to GND, DO to D2.
2. Buzzer: positive to D7, negative to GND.
3. LED 1: D8 through a 1 kΩ resistor to LED long leg; short leg to GND.
4. LED 2: D9 through a 1 kΩ resistor to LED long leg; short leg to GND.
5. LED 3: D10 through a 1 kΩ resistor to LED long leg; short leg to GND.
6. Make sure all GND connections share Arduino GND.
7. Upload the sketch and test sensor status in Serial Monitor at 9600 baud.
