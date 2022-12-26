#include "Common.h"
#include "EventGenerator.h"
#include "StateTopMenu.h"

/********************************************
   Function Definitions
********************************************/

uint8_t StateTopMenu(TS_STATE_INFO* pSuper)
{
    uint8_t eventHandled = FALSE;

    if (pSuper->stateMessage == sm_INIT)
    {
        printf("State Top Menu\n");	
    }

    return eventHandled;
}
