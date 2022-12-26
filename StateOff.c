#include "Common.h"
#include "EventGenerator.h"
#include "StateOff.h"
#include "StateOn.h"

/********************************************
   Function Definitions
********************************************/

uint8_t StateOff(TS_STATE_INFO* pSuper)
{
    uint8_t eventHandled = FALSE;

	if (pSuper->stateMessage == sm_INIT)
	{
        printf("State OFF\n");
	}
    
    if(pSuper->stateEvent == se_TURN_ON)
    {
        pSuper->pNextState = (TD_STATE_PROTO) StateOn;
        eventHandled = TRUE;
    }

    return eventHandled;
}
