/* This function reads the thermistor voltage and returns the temperature in Celsius
   using Steinhart Hart conversion from thermistor resistance
 */
#include "mbed.h"
#include "constants.h"
#include "lightlevel.h"

AnalogIn lightLevelVoltage( lightOut );
extern things_t myData;

void readLightLevel() {

    while(true) {
    // Read the light dependent resistor voltage
        myData.lightL = lightLevelVoltage.read() * 100; // Range of ADC.read 0->1
        if(myData.lightL < myData.setLightLevel - 5.0f){
        myData.lightState = true; //turn the light on if it gets below a certain light level
    }
        else if(myData.lightL > myData.setLightLevel + 5.0f){
        myData.lightState = false; //turn the heater off if below 16 degrees celsius
    }
        ThisThread::sleep_for(500);
    }
}
