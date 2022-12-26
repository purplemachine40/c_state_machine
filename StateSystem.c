#include "Common.h"
#include "EventGenerator.h"
#include "StateOff.h"
#include "StateSystem.h"

/********************************************
   Local Static Variables
********************************************/

static TS_STATE_INFO stateSysInfo;

/********************************************
   Function Definitions
********************************************/

void InitStateSystem(void)
{
	stateSysInfo.stateEvent = se_NONE;
	stateSysInfo.stateMessage = sm_INIT;
	stateSysInfo.pNextState = StateOff;
	stateSysInfo.pData = NULL;
}


void StateSystemUpdate(uint8_t *pShouldExit)
{
	TE_SYSTEM_EVENT sysEvent = GetEvent();
	TD_STATE_PROTO currentState = stateSysInfo.pNextState;	

	if(sysEvent == se_EXIT_PROGRAM)
	{
		*pShouldExit = TRUE;
		return;
	}

	stateSysInfo.stateEvent = sysEvent;	
    CallState(&stateSysInfo);
    stateSysInfo.stateMessage = (stateSysInfo.pNextState != currentState) ? sm_INIT : sm_NONE;
}
