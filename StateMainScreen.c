#include "Common.h"
#include "StateMainScreen.h"

/********************************************
   Function Definitions
********************************************/

uint8_t StateMainScreen(TS_STATE_INFO* pSuper)
{
	uint8_t eventHandled = FALSE;

	if (pSuper->stateMessage == sm_INIT)
	{
		printf("State Main Screen\n");
	}

	return eventHandled;
}
