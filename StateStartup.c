#include "Common.h"
#include "../ScreenData.h"
#include "StateOn.h"
#include <time.h>


#define STARTUP_TIME 2000

static clock_t startupTime;

/********************************************
   Function Definitions
********************************************/

uint8_t StateStartup(TS_STATE_INFO *pSuper)
{
    uint8_t eventHandled = FALSE;
    clock_t curTime = clock();

    if (pSuper->stateMessage == sm_INIT)
    {
        SetScreenData(ds_WELCOME);
        startupTime = clock();
        printf("State Startup\n");
    }

    if ((curTime - STARTUP_TIME) > startupTime)
    {
        pSuper->pNextState = StateOn;
    }

    return eventHandled;
}
