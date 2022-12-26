#include "Common.h"
#include "EventGenerator.h"
#include "StateMenu.h"
#include "StateSubMenu.h"
#include "StateTopMenu.h"

/********************************************
   Local Static Variables
********************************************/

static TS_STATE_INFO stateMenuInfo;

/********************************************
   Local Static Function Prototypes
********************************************/

static void InitStateMenu(void);

/********************************************
   Function Definitions
********************************************/

uint8_t StateMenu(TS_STATE_INFO* pSuper)
{
	TD_STATE_PROTO currentState;
	uint8_t eventHandled = FALSE;

	if (pSuper->stateMessage == sm_INIT)
	{
		printf("State Menu\n");
		InitStateMenu();
	}

	stateMenuInfo.stateEvent = pSuper->stateEvent;
	currentState = stateMenuInfo.pNextState;
	eventHandled = CallState(&stateMenuInfo);

	if(eventHandled == FALSE)
	{
		switch(stateMenuInfo.stateEvent)
		{
			case se_ENTER_MENU:
			{
				stateMenuInfo.pNextState = StateSubMenu;
				eventHandled = TRUE;
			}
			break;
			case se_EXIT_MENU:
			{
				if(stateMenuInfo.pNextState == StateSubMenu)
				{
					stateMenuInfo.pNextState = StateTopMenu;
					eventHandled = TRUE;
				}
			}
			break;
		}
	}

    stateMenuInfo.stateMessage = (stateMenuInfo.pNextState != currentState) ? sm_INIT : sm_NONE;
	return eventHandled;
}


static void InitStateMenu(void)
{
	stateMenuInfo.stateEvent = se_NONE;
	stateMenuInfo.stateMessage = sm_INIT;
	stateMenuInfo.pNextState = StateTopMenu;
}
