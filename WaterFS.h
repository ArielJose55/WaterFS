#ifndef WaterFS_h
#define WaterFS_h

#if ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

#include <avr/interrupt.h>
#include <stdint.h>

#define CUBIC_METERS_PER_SECOND 		-1
#define CUBIC_METERS_PER_HOUR			-2
#define CUBIC_CENTERMETERS_PER_SECOND	-3
#define LETERS_PER_HOUR					-4


volatile static int pulses = 0;

class WaterFS{
	public:
		WaterFS(int pin);
		double readWaterflow();
		double readConverter(int type_unity);
    double converterValue(double value, int type_unity);
	private:
		static void flow();
    double converter(double value, int type_unity);
};
#endif
