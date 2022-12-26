
#include "EventGenerator.h"
#include <stdio.h>
#include <stdint.h>

/********************************************
   Local Defines
********************************************/

#define MAX_STRING_LEN 32

/********************************************
   Local Static Variables
********************************************/

static TE_SYSTEM_EVENT systemEvent;  /*Holds a single system event.  Make a FIFO to hold more than one event.*/

static uint8_t eventString[se_TOTAL_EVENTS][MAX_STRING_LEN] = 
{
	"No Event",
	"Turn ON",
	"Turn OFF",
	"Enter Menu",
	"Exit Menu",
	"Exit Program"
};

/********************************************
   Local Static Function Prototypes
********************************************/

static void GetUserInput(void);
static void AddEvent(TE_SYSTEM_EVENT sysEvent);

/********************************************
   Function Definitions
********************************************/

void EventGenUpdate(void)
{
	GetUserInput();
}

TE_SYSTEM_EVENT GetEvent(void)
{
	return systemEvent;
}

static void GetUserInput(void)
{
	int userInput = 0;
	printf("Enter Event:  ");
	scanf_s("%d", &userInput);
	AddEvent(((userInput > se_NONE) && (userInput < se_TOTAL_EVENTS)) ? (TE_SYSTEM_EVENT)userInput : se_NONE);
}

static void AddEvent(TE_SYSTEM_EVENT sysEvent)
{
	printf("Adding event: %s\n", eventString[sysEvent]);
	systemEvent = sysEvent;
}
