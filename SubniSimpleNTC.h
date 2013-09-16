/**
 * SimpleNTC.h - Library for interacting with NTC thermistors
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

#define V_IN 5.0	// Input voltage
#define ROOMTEMPK 298.15  //standard room temperature in Kelvin //(25 Celsius).
#define THERMISTOR 10000 // The resistance of your thermistor at room //temperature


//K el factor de disipacion decia aquñi que era mW/ºC pero en el datasheet sale en mW/K 
//si son 7mw/k entiendo que son 0.02562694490206846055280981145891 mW/ºC
//NOTA 27/08/2013 Segun he leido ºC/W y K/W es lo mismo asi que ahora creo que mW/K y mW/ºC es lo
//mismo tambien,vamos a probarlo. http://www.diyaudio.com/forums/solid-state/34499-thermal-resistivity-k-w-c-w.html

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
		double _k; //Dissipation factor (mW/°C)
};

#endif