

#include "MAX9814.h"

MAX9814::MAX9814(int analogPin){
    sensorAnalogPin = analogPin;
}

double MAX9814::SensorRead(){

   maxSignal = 0;
   minSignal = 4095;
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
   voltage = (peakToPeak * 3.3) / 4095;
   return voltage;
}


void MAX9814::DebugInfo(){

   //add print stuff
   Serial.printlnf("MAX9814 Voltage: %f" , this->SensorRead());
   Serial.printlnf("peakToPeak: %f" , this->peakToPeak);
   Serial.printlnf("maxSignal: %f" , this->maxSignal);
   Serial.printlnf("minSignal: %f" , this->minSignal);
   
}
