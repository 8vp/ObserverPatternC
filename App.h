//
//  App.h
//  ObserverPattern
//
//  Created by Balu Pillai on 23/05/2020.
//  Copyright © 2020 Balu Pillai. All rights reserved.
//

#ifndef App_h
#define App_h

#include "types.h"

/* Digital stop watch encapsulation */
typedef struct DigitalStopWatch
{
    uint8 watchDisplay;
}DigitalStopWatch_t;

/* Constructor */
DigitalStopWatch_t* createDigitalWatch(void);
/* Destructor */
void destroyDigitalWatch(DigitalStopWatch_t*);

#endif /* App_h */
