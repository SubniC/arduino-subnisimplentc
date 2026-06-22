/*
 * SubniSimpleNTC.h - Read temperature from NTC thermistors on Arduino.
 *
 * Computes temperature from an NTC thermistor using a Beta-model and applies a
 * self-heating correction based on the thermistor's dissipation factor.
 * ADC reads go through the SubniAnalogTools library.
 *
 * Originally written in 2013. Legacy library, preserved as-is.
 */

#if ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

#ifndef SubniSimpleNTC_h
#define SubniSimpleNTC_h

#include <inttypes.h>
#include <math.h>
#include <SubniAnalogTools.h>

#define V_IN 5.0          // ADC reference / supply voltage (volts)
#define ROOMTEMPK 298.15  // Reference temperature in Kelvin (25 °C)
#define THERMISTOR 10000  // Thermistor nominal resistance at ROOMTEMPK (ohm)

// Note: the dissipation factor `k` is given in mW/°C (equivalently mW/K).

class SubniSimpleNTC {
	public:
		/**
		 * The reading pin has to be specified.
		 * If no other parameters are given default values will be used.
		 * These values are for a NTC 10k thermistor with a 10k resistor
		 * put in parallel.
		 */
		SubniSimpleNTC(
			uint8_t reading_pin,
			double resistance = 10000.0f,
			double beta = 4000.0f,
			double k = 9.5f) :
			_reading_pin(reading_pin),
			_resistance(resistance),
			_beta(beta),
			_k(k) {};

		double getKelvin();
		double getCelsius();
		double getFahrenheit();

	private:
		double simpleNTC(double);

		// Value of the resistor put in parallel
		double _resistance;

		uint8_t _reading_pin;

		// Manufacturing constants
		double _beta;
		double _k; // Dissipation factor (mW/°C)
};

#endif
