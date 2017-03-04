#if ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif



#include "WaterFS.h"

void WaterFS::flow(){
	pulses++;
}

WaterFS::WaterFS(int pin){
	pinMode(pin, INPUT_PULLUP);
  	attachInterrupt(digitalPinToInterrupt(PIN_INPUT), flow, RISING);
}

double WaterFS::readWaterflow(){
	return pulses *1.0;
}


double WaterFS::readConverter(int type_unity){
	
}


