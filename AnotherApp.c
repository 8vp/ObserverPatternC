//
//  AnotherApp.c
//  ObserverPattern
//
//  Created by Balu Pillai on 16/11/2020.
//  Copyright © 2020 Balu Pillai. All rights reserved.
//

#include <stdio.h>
#include "AnotherApp.h"
#include "TimeObserver.h"
#include "types.h"
#include <stdlib.h>


static void changedTime(void* instance, const uint32* newTime)
{
    printf("Message from Analogue Watch app: Time has changed by %lu secs\n", *newTime);
}


AnalogueWatch_t* createAnalogueWatch(void)
{
    AnalogueWatch_t* watch = malloc(sizeof watch);

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
void destroyAnalogueWatch(AnalogueWatch_t*  watch)
{
     /* Before deleting the instance we have to detach from the subject. */
     TimeObserver observer = {0};
     observer.instance = watch;
     observer.notification = changedTime;
     detach(&observer);
     free(watch);
}
