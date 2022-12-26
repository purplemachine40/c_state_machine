#include "Common.h"
#include "StateSubMenu.h"

/********************************************
   Function Definitions
********************************************/

uint8_t StateSubMenu(TS_STATE_INFO* pSuper)
{
    uint8_t eventHandled = FALSE;

	if (pSuper->stateMessage == sm_INIT)
	{
		printf("State Sub Menu\n");
	}

	return eventHandled;
}
