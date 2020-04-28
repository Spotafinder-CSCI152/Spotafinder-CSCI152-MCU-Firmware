/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "d:/Gilbert/Offline_Projects/Spotafinder-CSCI152-MCU-Firmware/src/Spotafinder-CSCI152-MCU-Firmware.ino"
/*
 * Project Spotafinder-CSCI152-MCU-Firmware
 * Description:
 * Author:
 * Date:
 */

#include "SHT15.h"
#include "MAX9814.h"
void setup();
void loop();
#line 10 "d:/Gilbert/Offline_Projects/Spotafinder-CSCI152-MCU-Firmware/src/Spotafinder-CSCI152-MCU-Firmware.ino"
#define MYDEBUG
#define RefreshRate 10000

MAX9814 sensorMAX9814(A5);
SHT15 sensorSHT15(D1, D0);
double tempF, tempC, humidityLinear, humidityTrue, GMoisturePercentage;
unsigned long oldDelayTime = 0; 

SYSTEM_MODE(MANUAL);

void setup() {
  
 Serial.begin(9600);
 Serial1.begin(9600);

}


void loop() {
  
  //for the audio sesnor to work we need a high samplle rate
  //therefore we will use a non blocking delay 
  unsigned long currentDelayTime = millis();
  if (currentDelayTime - oldDelayTime >= RefreshRate) {
    oldDelayTime = currentDelayTime;
  
  sensorSHT15.readSensor();
  tempF = sensorSHT15.getTemperatureF();
  tempC = sensorSHT15.getTemperatureC();
  humidityLinear = sensorSHT15.getHumidityLinear();
  humidityTrue = sensorSHT15.getHumidityTrue();

 #ifdef MYDEBUG
  Serial.printlnf("tempF: %f" ,tempF);
  Serial.printlnf("tempC: %f" ,tempC);
  Serial.printlnf("humidityLinear: %f" ,humidityLinear);
  Serial.printlnf("humidityTrue: %f" ,humidityTrue);
  //Serial.printlnf("MAX9814 Voltage: %f" ,sensorMAX9814.SensorCalibration());
 #endif

  Serial1.printlnf("tempF: %f" ,tempF);
  Serial1.printlnf("tempC: %f" ,tempC);
  Serial1.printlnf("humidityLinear: %f" ,humidityLinear);
  Serial1.printlnf("humidityTrue: %f" ,humidityTrue);

  }

  //delay(RefreshRate);
  #ifdef MYDEBUG
   //Serial.printlnf("MAX9814 Voltage: %f" ,sensorMAX9814.SensorRead());
   sensorMAX9814.DebugInfo();
  #endif

}