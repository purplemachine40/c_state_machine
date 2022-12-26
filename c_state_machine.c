#include <stdint.h>
#include <stdio.h>
#include "CustomTypes.h"
#include "EventGenerator.h"
#include "StateSystem.h"

int main()
{
	static uint8_t exitProgram = FALSE;

	InitStateSystem();
	printf("Events:\n1 = Turn ON\n2 = Turn OFF\n3 = Enter Menu\n4 = Exit Menu\n5 = Exit Program\n");

	while (!exitProgram)
	{
		StateSystemUpdate(&exitProgram);
		EventGenUpdate();
		StateSystemUpdate(&exitProgram);
	}
	printf("Goodbye");

	return 0;
}
