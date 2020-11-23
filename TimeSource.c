//
//  TimeSource.c
//  ObserverPattern
//
//  Created by Balu Pillai on 23/05/2020.
//  Copyright © 2020 Balu Pillai. All rights reserved.
//

#include "TimeSource.h"
#include <assert.h>
#include "types.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode
{
    TimeObserver item;
    struct ListNode* next;
}listNode_t;

static listNode_t observers;



/* Local helper functions for managing the linked-list (implementation omitted). */
static void appendToList(const TimeObserver *observer)
{
    /* Append a copy of the observer to the linked-list. */
    listNode_t *head = &observers;
    
    while(NULL != head->next)
    {
        head = head->next;
    }
    
    head->next = (listNode_t *) malloc(sizeof(listNode_t));
    if(head->next !=NULL)
    {
        head->next->item = *observer;
        head->next->next = NULL;
    }
}

void getAllObservers()
{
    listNode_t *head = &observers;
    uint8_t id = 0;
    
    while(NULL != head->next)
    {
        printf("Observer %d instance address is %d", ++id, head->item.instance);
        head = head->next;
    }
    
}


static void removeFromList(const TimeObserver* observer)
{
 /* Identify the observer in the linked-list and remove that node. */
    listNode_t *head = &observers;
    listNode_t *prevNode = &observers;
    
    while(NULL != head->next)
     {
         if(head->item.instance == observer->instance)
         {
             printf("Found node to delete");
             prevNode->next = head->next->next;
             //printf("%d", observer->instance);
             free(head);
             break;
         }
         else
         {
             prevNode = head;
             head = head->next;
         }
     }
}

void attach(const TimeObserver* observer)
{
    assert(NULL != observer);
    appendToList(observer);
}

void detach(const TimeObserver* observer)
{
    assert(NULL != observer);
    removeFromList(observer);
}

void notifyObservers(uint32 time)
{
    struct ListNode* node = observers.next;
    /* Walk through the linked-list and notify every observer that another millisecond passed. */
    while(NULL != node)
    {
        TimeObserver* observer = &node->item;
        observer->notification(observer->instance, &time);
        node = node->next;
    }
}


static uint32 calculateNewTime(void)
{
    static uint32_t incrementVal;
    
    return ++incrementVal;
    
}

static boolean _setChanged()
{
    /* Logic to debounce */
    return TRUE;
}


/* Implementation of the original responsibility of the TimeSource (code for initialization, etc
omitted). */
void msTick()
{
    uint32 currentTime = 0U;
    static uint32 prevTime;
    boolean changed = FALSE;

    /* Invoke a function encapsulating the knowledge about time representation. */
    currentTime = calculateNewTime();
    if(currentTime!=prevTime)
    {
        /* Debouncing */
        changed = _setChanged();
        
        if(TRUE == changed)
        {
            /* Ready to send notification */
            notifyObservers(currentTime);
            prevTime = currentTime;
        }
    }
}


