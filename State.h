#pragma once
#include <stdint.h>

/********************************************
   Global Typedefs and Structure Definitions
********************************************/

typedef enum _TE_STATE_MESSAGE
{
	sm_NONE,
	sm_INIT,
	sm_TOTAL_STATE_MESSAGES
}TE_STATE_MESSAGE;

struct _TS_STATE_INFO;
typedef struct _TS_STATE_INFO TS_STATE_INFO;
typedef uint8_t(*TD_STATE_PROTO)(TS_STATE_INFO* pStateInfo);

struct _TS_STATE_INFO
{
	int stateEvent;
	int stateMessage;
	TD_STATE_PROTO pNextState;

	void* pData;  /*Extra data that a state may need.*/
};

/********************************************
   Global Function Definitions
********************************************/

uint8_t CallState(TS_STATE_INFO* StateInfo);
