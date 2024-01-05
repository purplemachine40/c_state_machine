#include "Common.h"
#include "EventGenerator.h"
#include "StateMainScreen.h"
#include "StateMenu.h"
#include "StateOff.h"
#include "StateOn.h"

/********************************************
   Local Static Variables
********************************************/

static TS_STATE_INFO stateOnInfo;

/********************************************
   Local Static Function Prototypes
********************************************/

static void InitStateOn(void);

/********************************************
   Function Definitions
********************************************/

uint8_t StateOn(TS_STATE_INFO* pSuper)
{
	TD_STATE_PROTO currentState;
	uint8_t eventHandled = FALSE;

    if (pSuper->stateMessage == sm_INIT)
    {
        printf("State ON\n");
		InitStateOn();
    }

	stateOnInfo.stateEvent = pSuper->stateEvent;
	currentState = stateOnInfo.pNextState;
	eventHandled = CallState(&stateOnInfo);

	if(eventHandled == FALSE)
	{
		switch(stateOnInfo.stateEvent)
		{
			case se_CENTER_BTN_PRESSED:
			{
				stateOnInfo.pNextState = StateMenu;
				eventHandled = TRUE;
			}
			break;
			case se_BACK_BTN_PRESSED:
			{
				stateOnInfo.pNextState = StateMainScreen;
				eventHandled = TRUE;
			}
			break;
			case se_POWER_BTN_PRESSED:
			{
				pSuper->pNextState = StateOff;
				eventHandled = TRUE;
			}
			break;
		}
	}

	stateOnInfo.stateMessage = (stateOnInfo.pNextState != currentState) ? sm_INIT : sm_NONE;
	return eventHandled;
}


static void InitStateOn()
{
	stateOnInfo.stateEvent = se_NONE;
	stateOnInfo.stateMessage = sm_INIT;
	stateOnInfo.pNextState = (TD_STATE_PROTO) StateMainScreen;
}
