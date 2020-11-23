//
//  App.c
//  ObserverPattern
//
//  Created by Balu Pillai on 23/05/2020.
//  Copyright © 2020 Balu Pillai. All rights reserved.
//

#include "App.h"
#include "TimeObserver.h"
#include "types.h"
#include <stdlib.h>
#include <stdio.h>

static void changedTime(void* instance, const uint32* newTime)
{
    printf("Message from Digital Watch app: Time has changed by %lu secs\n", *newTime);
}


DigitalStopWatch_t* createDigitalWatch(void)
{
    DigitalStopWatch_t* watch = malloc(sizeof watch);

     if(NULL != watch)
     {
         /* Successfully created -> attach to the subject. */
         TimeObserver observer = {0};
         observer.instance = watch;
         observer.notification = changedTime;
         attach(&observer);
     }
    
    return watch;
}
void destroyDigitalWatch(DigitalStopWatch_t*  watch)
{
     /* Before deleting the instance we have to detach from the subject. */
     TimeObserver observer = {0};
     observer.instance = watch;
     observer.notification = changedTime;
     detach(&observer);
     free(watch);
}
