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

void setup();
void loop();
#line 10 "d:/Gilbert/Offline_Projects/Spotafinder-CSCI152-MCU-Firmware/src/Spotafinder-CSCI152-MCU-Firmware.ino"
#define TickRate 10000

SHT15 sensorSHT15(D1, D0);
double tempF, tempC, humidityLinear, humidityTrue, GMoisturePercentage;

SYSTEM_MODE(MANUAL);

void setup() {
  
 Serial.begin(9600);


}


void loop() {

  sensorSHT15.Tick();
  tempF = sensorSHT15.getTemperatureF();
  Serial.println(tempF);

  tempC = sensorSHT15.getTemperatureC();
  Serial.println(tempC);

  humidityLinear = sensorSHT15.getHumidityLinear();
  Serial.println(humidityLinear);

  humidityTrue = sensorSHT15.getHumidityTrue();
  Serial.println(humidityTrue);

  delay(TickRate);
}