#include "Common.h"
#include "../ScreenData.h"
#include "StateMainScreen.h"

/********************************************
   Function Definitions
********************************************/

uint8_t StateMainScreen(TS_STATE_INFO* pSuper)
{
	uint8_t eventHandled = FALSE;

	if (pSuper->stateMessage == sm_INIT)
	{
		SetScreenData(ds_MAIN);
		printf("State Main Screen\n");
	}

	return eventHandled;
}
