#include "mbed.h"
#include "constants.h"
#include "display.h"
#include "vt100.h"

extern things_t myData;

void displayTask(){
    DigitalOut green(GREENLED);
    RIS;
    while(true){
        ThisThread::sleep_for(500);
        HOME;
        printf("The button is %s\n", myData.buttonState?"pressed    ":"not pressed");
        if (myData.buttonState ==true) green = true;
        else green = false;
        WHITE_TEXT;
        printf ("Temperature: %2.1fC\n", myData.tempC);
        WHITE_TEXT;
        printf("Light Level: %3.0f%c\n", myData.lightL, '%');
        WHITE_TEXT;
        printf("heater state%s\n", myData.heaterState? " off " : " on ");
        WHITE_TEXT;
        printf("light state%s\n", myData.lightState? " on " : " off ");
        WHITE_TEXT;
    }
}