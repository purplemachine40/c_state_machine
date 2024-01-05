#include "Common.h"
#include "EventGenerator.h"
#include "StateStartup.h"
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
	stateSysInfo.pNextState = StateStartup;
	stateSysInfo.pData = NULL;
}


void StateSystemUpdate(void)
{
	TE_SYSTEM_EVENT sysEvent = GetSysEvent();
	TD_STATE_PROTO currentState = stateSysInfo.pNextState;	

	stateSysInfo.stateEvent = sysEvent;	
    CallState(&stateSysInfo);
    stateSysInfo.stateMessage = (stateSysInfo.pNextState != currentState) ? sm_INIT : sm_NONE;
}
