//
//  main.c
//  ObserverPattern
//
//  Created by Balu Pillai on 23/05/2020.
//  Copyright © 2020 Balu Pillai. All rights reserved.
//

#include <stdio.h>
// To use time library of C
#include <time.h>
#include "TimeSource.h"
#include "App.h"
#include "AnotherApp.h"
  
/* Delay function */
void delay(uint8_t number_of_seconds)
{
    /* Converting time into milli_seconds */
    uint32_t milli_seconds = 1000000UL * number_of_seconds;
  
    /* Storing start time */
    clock_t start_time = clock();
  
    /* looping till required time is not achieved */
    while (clock() < start_time + milli_seconds);
}
  
/* Entry point */
int main(int argc, const char * argv[]) {
    uint8_t i;
    /* 1 sec clock increment */
    const uint8_t delaySecs = 1;
    /* Digital stop watch object pointer */
    DigitalStopWatch_t *dwatch;
    AnalogueWatch_t *awatch;
    
    /* create a digital watch object */
    dwatch = createDigitalWatch();
    awatch = createAnalogueWatch();
    printf("Digital watch object address is %x", dwatch);
    printf("Analogue watch object address is %x", awatch);

    /* Verify the observers */
    getAllObservers();
    
    
    /* Update time every sec for 10 secs */
    for (i = 0; i < 10; i++)
    {
        delay(delaySecs);
        /* Increment seconds counter */
        msTick();
    }
    
    /* Destroy digital watch object */
    destroyDigitalWatch(dwatch);
    return 0;
}




