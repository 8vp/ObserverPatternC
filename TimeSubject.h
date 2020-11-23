//
//  TimeSubject.h
//  ObserverPattern
//
//  Created by Balu Pillai on 12/11/2020.
//  Copyright © 2020 Balu Pillai. All rights reserved.
//

#ifndef TimeSubject_h
#define TimeSubject_h

#include "TimeObserver.h"

/* TimeSubject interface. */
void attach(const TimeObserver* observer);
void detach(const TimeObserver* observer);
void notifyObservers(uint32 time);


#endif /* TimeSubject_h */
