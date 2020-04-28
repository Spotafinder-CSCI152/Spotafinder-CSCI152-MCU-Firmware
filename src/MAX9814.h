
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
    double voltage;
    double voltageMax = 2.45;
    double peakToPeak;
    unsigned int maxSignal;
    unsigned int minSignal;

};
