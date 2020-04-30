/*
 * Project Spotafinder-CSCI152-MCU-Firmware
 * Description:
 * Author:
 * Date:
 */

#include "SHT15.h"
#include "MAX9814.h"
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
  
  //for the audio sesnor to work we need a high sample rate
  //therefore non blocking delay 
  unsigned long currentDelayTime = millis();
  if (currentDelayTime - oldDelayTime >= RefreshRate) {
    oldDelayTime = currentDelayTime;
  
  sensorSHT15.readSensor();
  tempF = sensorSHT15.getTemperatureF();
  tempC = sensorSHT15.getTemperatureC();
  humidityLinear = sensorSHT15.getHumidityLinear();
  humidityTrue = sensorSHT15.getHumidityTrue();

 #ifdef MYDEBUG
  sensorSHT15.serialSendDataJson(Serial);
 #endif

  sensorSHT15.serialSendDataJson(Serial1);
  }

  #ifdef MYDEBUG
   sensorMAX9814.debugInfo(Serial);
  #endif
  sensorMAX9814.soundLevelProcess();
}
