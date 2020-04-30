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
void sendJsonData(Stream& T);
#line 10 "d:/Gilbert/Offline_Projects/Spotafinder-CSCI152-MCU-Firmware/src/Spotafinder-CSCI152-MCU-Firmware.ino"
#define MYDEBUG
#define RefreshRate 10000

MAX9814 sensorMAX9814(A5);
SHT15 sensorSHT15(D1, D0);
double tempF, tempC, humidityLinear, humidityTrue, soundlevel;
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
    soundlevel = sensorMAX9814.getSoundLevel();

    #ifdef MYDEBUG
    //sensorSHT15.serialSendDataJson(Serial);
    sendJsonData(Serial);
    #endif
    //sensorSHT15.serialSendDataJson(Serial1);
    sendJsonData(Serial1);
  }

  #ifdef MYDEBUG
  sensorMAX9814.debugInfo(Serial);
  #endif
  sensorMAX9814.soundLevelProcess();
}


void sendJsonData(Stream& T){
  T.printlnf("{\"tempF\": %f,\"tempC\": %f,\"humidityLinear\": %f,\"humidityTrue\": %f, \"soundlevel\": %f}" ,tempF, tempC, humidityLinear, humidityTrue, soundlevel);
}