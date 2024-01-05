#include "Common.h"
#include "../ScreenData.h"
#include "StateSubMenu.h"

/********************************************
   Function Definitions
********************************************/

uint8_t StateSubMenu(TS_STATE_INFO* pSuper)
{
    uint8_t eventHandled = FALSE;

	if (pSuper->stateMessage == sm_INIT)
	{
		SetScreenData(ds_SUB_MENU);
		printf("State Sub Menu\n");
	}

	return eventHandled;
}
