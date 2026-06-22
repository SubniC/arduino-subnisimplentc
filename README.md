# SubniSimpleNTC

Arduino library to read **temperature from NTC thermistors**.

It converts an analog reading into temperature (Kelvin / Celsius / Fahrenheit) using a
Beta-model of the thermistor and applies a **self-heating correction** based on the
thermistor's dissipation factor.

> **Legacy library (2013).** Kept for reference and archival; docs and packaging
> refreshed in 2026, library behavior unchanged.

## Features

- Temperature in `getKelvin()`, `getCelsius()` and `getFahrenheit()`.
- Configurable parallel resistor, Beta coefficient and dissipation factor `k`.
- Dissipation-factor (self-heating) compensation.
- Tiny footprint, no dynamic allocation.

## Dependencies

This library reads the ADC through [**SubniAnalogTools**](https://github.com/SubniC/arduino-subnianalogtools)
(`AnalogTools.read(pin)`), so install that library too.

## Installation

- **Manual**: copy this folder into your Arduino `libraries/` directory (alongside
  `SubniAnalogTools`) and restart the IDE.
- **PlatformIO**: add the repository to `lib_deps`.

## Wiring

Voltage divider: `Vcc — NTC — A(pin) — R — GND`, with an optional resistor in parallel
to the NTC. Defaults assume a 10 kΩ NTC with a 10 kΩ resistor and `V_IN = 5 V`.

## Usage

```cpp
#include <SubniAnalogTools.h>
#include <SubniSimpleNTC.h>

// NTC on A0 (defaults: 10k parallel resistor, beta 4000, k 9.5 mW/°C)
SubniSimpleNTC ntc(A0);

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.print("Temp: ");
  Serial.print(ntc.getCelsius());
  Serial.println(" C");
  delay(1000);
}
```

See [`examples/BasicReading`](examples/BasicReading) for the full sketch.

## API

```cpp
SubniSimpleNTC(uint8_t reading_pin,
               double resistance = 10000.0,  // parallel resistor (ohm)
               double beta       = 4000.0,   // thermistor Beta coefficient
               double k          = 9.5);     // dissipation factor (mW/°C)

double getKelvin();
double getCelsius();
double getFahrenheit();
```

## License

[MIT](LICENSE) © 2013–2026 mdps

---

_Un proyecto de mdps · 2026 · desarrollado en Murcia._
