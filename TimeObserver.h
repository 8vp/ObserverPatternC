//
//  TimeObserver.h
//  This is the Time Observer interface
//
//  Created by Balu Pillai on 23/05/2020.
//  Copyright © 2020 Balu Pillai. All rights reserved.
//

#ifndef TimeObserver_h
#define TimeObserver_h
#include "types.h"



/* Notification function for the observer */
typedef void (*ChangeTimeNotification) (void* instance, const uint32* newTime);

/* Observer encapsulated. This is
 object that is used by the Time Subject interface */
typedef struct
{
    void* instance;
    ChangeTimeNotification notification;
} TimeObserver;


#endif /* TimeObserver_h */
