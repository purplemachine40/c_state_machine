#include <stdint.h>
#include <stdio.h>
#include "CustomTypes.h"
#include "StateSystem.h"

void InitAppCode(void)
{
	InitStateSystem();
}

void AppCode(void)
{
	StateSystemUpdate();	
}
