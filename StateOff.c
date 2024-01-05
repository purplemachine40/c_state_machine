#include "Common.h"
#include "EventGenerator.h"
#include "../ScreenData.h"
#include "StateOff.h"
#include "StateStartup.h"

/********************************************
   Function Definitions
********************************************/

uint8_t StateOff(TS_STATE_INFO *pSuper)
{
    uint8_t eventHandled = FALSE;

    if (pSuper->stateMessage == sm_INIT)
    {
        SetScreenData(ds_BLANK);
        printf("State OFF\n");
    }

    if (pSuper->stateEvent == se_POWER_BTN_PRESSED)
    {
        pSuper->pNextState = (TD_STATE_PROTO)StateStartup;
        eventHandled = TRUE;
    }

    return eventHandled;
}
