#pragma once

/********************************************
   Global Typedefs and Structure Definitions
********************************************/

typedef enum _TE_SYSTEM_EVENT
{
	se_NONE,
	se_TURN_ON,
	se_TURN_OFF,
	se_ENTER_MENU,
	se_EXIT_MENU,	
	se_EXIT_PROGRAM,
	se_TOTAL_EVENTS,
	se_INVALID_EVENT
}TE_SYSTEM_EVENT;

/********************************************
   Global Function Definitions
********************************************/

void EventGenUpdate(void);
TE_SYSTEM_EVENT GetEvent(void);
