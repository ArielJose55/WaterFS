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
  	attachInterrupt(digitalPinToInterrupt(pin), flow, RISING);
}

double WaterFS::readWaterflow(){
  double meters_per_hours = pulses * 60.0/6.65;
  pulses = 0;
	return meters_per_hours;
}

double WaterFS::readConverter(int type_unity){
  return 1;
}

double WaterFS::converterValue(double value, int type_unity){
  return 1;
}

double WaterFS::converter(double value, int type_unity){
  switch (type_unity) {
    case CUBIC_CENTERMETERS_PER_SECOND:{
      return (value*0.27777777);
    }
    case CUBIC_METERS_PER_HOUR:{
      return (value*0.001);
    }
    case CUBIC_METERS_PER_SECOND:{
      return (value*2.77777777778);
    }
  }
}
