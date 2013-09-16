/**
 * SimpleNTC.cpp - Library for interacting with NTC thermistors
 * 
 */

#include "SubniSimpleNTC.h"
	
/**
 * Returns the temperature in kelvin for the given resistance value
 * using the Steinhart-Hart polynom.
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
	uint16_t adc_read;
	double adc_raw, voltage, resistance;
	
/*	
adc_read =0;
	for(int i = 0; i < 16; i++)
	{    
		adc_read += analogRead(_reading_pin); 
		delay(10);
	}
	adc_read = adc_read >> 4;

	adc_raw = (double)adc_read;
*/
	adc_raw = (double)AnalogTools.read(_reading_pin);

	voltage = (adc_raw / 1024) * V_IN;
	//resistance = ((1024 * _resistance / adc_raw) - _resistance);
	
	adc_raw = (1023 / adc_raw) - 1;
	adc_raw = _resistance / adc_raw;
	resistance = adc_raw / THERMISTOR; 

	// Account for dissipation factor K
	return (simpleNTC(resistance) - ((voltage * voltage) / (_k * _resistance)));
}


double SubniSimpleNTC::getCelsius() 
{
	return getKelvin() - 273.15;
}


double SubniSimpleNTC::getFahrenheit()
{
	return getCelsius() * 9/5 + 32;
}
