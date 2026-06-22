/*
 * SubniSimpleNTC.cpp - Read temperature from NTC thermistors on Arduino.
 *
 * Originally written in 2013. Legacy library, preserved as-is.
 */

#include "SubniSimpleNTC.h"

/**
 * Returns the temperature in Kelvin for the given (normalized) resistance
 * value using the Beta-model: 1/T = 1/T0 + (1/B) * ln(R/R0).
 */
double SubniSimpleNTC::simpleNTC(double r)
{
	double kelvin;
	kelvin = log(r);
	kelvin /= _beta;
	kelvin += 1.0 / ROOMTEMPK;
	kelvin = 1.0 / kelvin;
	return kelvin;
}

double SubniSimpleNTC::getKelvin()
{
	double adc_raw, voltage, resistance;

	adc_raw = (double)AnalogTools.read(_reading_pin);

	voltage = (adc_raw / 1024) * V_IN;

	// Resistance from the voltage divider, normalized to the nominal value (R/R0).
	adc_raw = (1023 / adc_raw) - 1;
	adc_raw = _resistance / adc_raw;
	resistance = adc_raw / THERMISTOR;

	// Subtract the self-heating offset (dissipation factor k).
	return (simpleNTC(resistance) - ((voltage * voltage) / (_k * _resistance)));
}

double SubniSimpleNTC::getCelsius()
{
	return getKelvin() - 273.15;
}

double SubniSimpleNTC::getFahrenheit()
{
	return getCelsius() * 9 / 5 + 32;
}
