#include <stdint.h>
#include <msp430fr5969.h> 

#include "delay.h"
#include "leds.h"

int main(void)
{
	// Stop watchdog timer
	WDTCTL = WDTPW + WDTHOLD;

	leds_configure();

	PM5CTL0 &= ~LOCKLPM5;

	for (;;)
	{
		leds_toggle();
		sleep(20000);
	}
}
