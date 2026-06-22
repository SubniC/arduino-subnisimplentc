# Changelog

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.1.0/),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

## [1.0.0] - 2026-06-22

Documentation and packaging refresh of the original 2013 library. No behavior changes.

### Added
- `library.properties` for the Arduino Library Manager.
- `examples/BasicReading` sketch.
- Full README (features, dependency, wiring, usage, API).
- This changelog.

### Changed
- Cleaned up source comments; removed dead commented-out code. Logic unchanged.
- License notice normalized to MIT © mdps.

## [0.1.0] - 2013-09-16

First working version (legacy).

### Added
- `SubniSimpleNTC(pin, resistance, beta, k)` with `getKelvin()` / `getCelsius()` /
  `getFahrenheit()` and dissipation-factor (self-heating) correction.
- Depends on [SubniAnalogTools](https://github.com/SubniC/arduino-subnianalogtools).
