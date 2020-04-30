

#include "MAX9814.h"

MAX9814::MAX9814(int analogPin){
    sensorAnalogPin = analogPin;
}

double MAX9814::sensorRead(){

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

void MAX9814::soundLevelProcess(){
   
   //if one second of readings recorded
   if(indexSec >= size_1){
      indexSec = 0;
      secondSUM = 0;
      exendedSUM = 0;

      //get average over second
      for(int i=0;i<size_1;i++){
         secondSUM += soundLvlSec[i];
      }
      soundLvlExtended[indexExtended] = secondSUM/size_1;//recored 1 sec

      //get average over extended time
      for(int i=0;i<size_2;i++){
         exendedSUM += soundLvlExtended[i];
      }
      soundlevel = (exendedSUM/size_2)/voltageMax;
      indexExtended++;

   }

   //30 1 second averages recorded
   if(indexExtended >= size_2){
         indexExtended = 0;     
   }

   soundLvlSec[indexSec] = this->sensorRead();
   indexSec++;
}

void MAX9814::debugInfo(Stream& T){
   //add print stuff
   T.printlnf("MAX9814 Voltage: %f" , this->sensorRead());
   T.printlnf("peakToPeak: %f" , this->peakToPeak);
   T.printlnf("secondAVG: %f" , secondSUM/size_1);
   T.printlnf("ExendedAVG: %f" , exendedSUM/size_2);
   T.printlnf("SoundLvl: %f" , soundlevel);
   
}
