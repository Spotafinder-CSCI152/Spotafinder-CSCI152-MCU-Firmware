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

SYSTEM_MODE(MANUAL);

void setup() {
  
 Serial.begin(9600);
 Serial1.begin(9600);

}


void loop() {

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
  Serial.printlnf("MAX9814 Voltage: %f" ,sensorMAX9814.SensorCalibration());
 #endif

  Serial1.printlnf("tempF: %f" ,tempF);
  Serial1.printlnf("tempC: %f" ,tempC);
  Serial1.printlnf("humidityLinear: %f" ,humidityLinear);
  Serial1.printlnf("humidityTrue: %f" ,humidityTrue);

  delay(RefreshRate);
}