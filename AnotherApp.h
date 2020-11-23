//
//  AnotherApp.h
//  ObserverPattern
//
//  Created by Balu Pillai on 16/11/2020.
//  Copyright © 2020 Balu Pillai. All rights reserved.
//

#ifndef AnotherApp_h
#define AnotherApp_h

#include "types.h"

/*  Analogue watch encapsulation */
typedef struct AnalogueWatch
{
    uint8 watchDisplay;
}AnalogueWatch_t;

/* Constructor */
AnalogueWatch_t* createAnalogueWatch(void);
/* Destructor */
void destroyAnalogueWatch(AnalogueWatch_t*);

#endif /* AnotherApp_h */
