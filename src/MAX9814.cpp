

#include "MAX9814.h"

MAX9814::MAX9814(int analogPin){
    sensorAnalogPin = analogPin;
}

double MAX9814::SensorRead(){

    unsigned long startTime = millis();
    while (millis() - startTime < sampleFrame){

      sample = analogRead(sensorAnalogPin);
      if (sample < 4095) { //12-bit ADC
         if (sample > maxSignal){
            maxSignal = sample;  //find max
         }
         else if (sample < minSignal){
            minSignal = sample;  // find min
         }
      }
   }
    peakToPeak = maxSignal - minSignal;
    double voltage = (peakToPeak * 3.3) / 4095.0;
   return voltage;
}


void DebugInfo(){

   //add print stuff
}