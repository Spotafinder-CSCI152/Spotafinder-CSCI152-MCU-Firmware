
#include "Particle.h"

class MAX9814 {
    public:
    MAX9814(int analogPin);
    double sensorRead();
    void soundLevelProcess();
    void debugInfo(Stream& T);

    private:
    int sensorAnalogPin;
    static const unsigned int sampleFrame = 50; //ms
    unsigned int sample;
    double voltage;
    double voltageMax = 2.45;
    double peakToPeak;
    unsigned int maxSignal;
    unsigned int minSignal;
    //sound level processing variables
    int indexSec = 0;
    int indexExtended = 0;
    static const int size_1 = 1000/sampleFrame;
    static const int size_2 = 30;
    double soundLvlSec[size_1]; //sound readings over a second
    double soundLvlExtended[size_2]; //sound readings over 30 seconds
    double secondSUM = 0;
    double exendedSUM = 0;
    double soundlevel; //percentage of noise level
};
