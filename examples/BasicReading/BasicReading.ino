/*
 * SubniSimpleNTC — BasicReading
 *
 * Reads an NTC thermistor on A0 and prints the temperature once per second.
 * Requires the SubniAnalogTools library.
 */

#include <SubniAnalogTools.h>
#include <SubniSimpleNTC.h>

// NTC on A0. Defaults: 10k parallel resistor, beta 4000, k = 9.5 mW/°C.
// Override like: SubniSimpleNTC ntc(A0, 10000.0, 3950.0, 9.5);
SubniSimpleNTC ntc(A0);

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.print("Kelvin:     "); Serial.println(ntc.getKelvin());
  Serial.print("Celsius:    "); Serial.println(ntc.getCelsius());
  Serial.print("Fahrenheit: "); Serial.println(ntc.getFahrenheit());
  Serial.println();
  delay(1000);
}
