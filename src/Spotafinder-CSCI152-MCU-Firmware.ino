/*
 * Project Spotafinder-CSCI152-MCU-Firmware
 * Description:
 * Author:
 * Date:
 */

#include "SHT15.h"

#define RefreshRate 10000

SHT15 sensorSHT15(D1, D0);
double tempF, tempC, humidityLinear, humidityTrue, GMoisturePercentage;

SYSTEM_MODE(MANUAL);

void setup() {
  
 Serial.begin(9600);

}


void loop() {

  sensorSHT15.readSensor();
  tempF = sensorSHT15.getTemperatureF();
  Serial.println(tempF);

  tempC = sensorSHT15.getTemperatureC();
  Serial.println(tempC);

  humidityLinear = sensorSHT15.getHumidityLinear();
  Serial.println(humidityLinear);

  humidityTrue = sensorSHT15.getHumidityTrue();
  Serial.println(humidityTrue);

  delay(RefreshRate);
}