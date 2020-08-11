#include "delay.h"

void sleep(unsigned int c)
{
	volatile unsigned int i;

	for(i = 0; i < c; i++);
}
