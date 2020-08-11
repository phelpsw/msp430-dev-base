#include "leds.h"

#include "driverlib.h"

void leds_configure()
{
    GPIO_setAsOutputPin(GPIO_PORT_P1, GPIO_PIN0);
    GPIO_setAsOutputPin(GPIO_PORT_P4, GPIO_PIN6);

    GPIO_setOutputLowOnPin(GPIO_PORT_P1, GPIO_PIN0);
    GPIO_setOutputHighOnPin(GPIO_PORT_P4, GPIO_PIN6);
    
    return;
}

void leds_toggle()
{
    GPIO_toggleOutputOnPin(GPIO_PORT_P1, GPIO_PIN0);
    GPIO_toggleOutputOnPin(GPIO_PORT_P4, GPIO_PIN6);

    return;
}
