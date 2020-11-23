//
//  TimeSource.h
//  Subject (time source) interface
//
//  Created by Balu Pillai on 23/05/2020.
//  Copyright © 2020 Balu Pillai. All rights reserved.
//

#ifndef TimeSource_h
#define TimeSource_h

#include "TimeSubject.h"


/* Any other definitions can be done here */
void msTick(void);
static boolean _setChanged(void);
void getAllObservers(void);

#endif /* TimeSource_h */
