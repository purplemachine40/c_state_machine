#include "CustomTypes.h"
#include "State.h"

/********************************************
   Function Definitions
********************************************/

uint8_t CallState(TS_STATE_INFO* pStateInfo)
{
    uint8_t eventHandled = FALSE;

    if (pStateInfo->pNextState != NULL)
    {
        eventHandled = pStateInfo->pNextState(pStateInfo);
    }

    return eventHandled;
}
