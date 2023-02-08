#ifndef VoltageSensor_h
#define VoltageSensor_h

#include <Arduino.h>




class VoltageSensor {
public:
	VoltageSensor(ACS712_type type, uint8_t _pin);
	int calibrate();
	void setZeroPoint(int _zero);
	void setSensitivity(float sens);
  	void setVoltageReference(float volts);
  	void setAdcResolution(float adcResolution);

  	float getVoltage();


private:
	int zero = 512;
	float sensitivity;
	uint8_t pin;
  	float voltageReference = 5;      // Vcc of the MCU
  	float adcScale = 1024.0;         // ADC resolution
	float r1 = 30000.0;
	float r2 = 7500.0;

};

#endif