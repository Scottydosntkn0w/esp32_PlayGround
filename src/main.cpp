
#include "Arduino.h"

int pinread = 33;
int reading = 0;
int oldReading = 0;
int consecutive_count = 0;
int countHigh = 0;
int latch = 0;
int counter = 0;

void setup()
{
    Serial.begin(250000);
    analogSetPinAttenuation(pinread, ADC_0db);
}
void loop()
{   
    int reading = analogRead(pinread);
    if (reading == oldReading)
    {
        consecutive_count++;
        if (consecutive_count > 5 and latch == 0)
        {   
            Serial.print(reading);
            counter++;
            Serial.println(counter);
            consecutive_count = 0;
            latch = 1;
        }
    }
    else
    {
        consecutive_count = 0;
    }

    if (latch == 1 and reading > 200)
    {
        countHigh++;
        if (countHigh > 5)
        {
            latch = 0;
        } 
    }
    else
    {
        countHigh = 0;
    }
    //Serial.println(reading);
}