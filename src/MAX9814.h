
#include "Particle.h"

class MAX9814 {
    public:
    MAX9814(int analogPin);
    double SensorRead();
    void DebugInfo();

    private:
    int sensorAnalogPin;
    const unsigned int sampleFrame = 50; //ms
    unsigned int sample;
    double peakToPeak = 0;
    unsigned int maxSignal = 0;
    unsigned int minSignal = 4096;

};