#include "unity.h"
#include "mock_gpio.h"
#include "leds.h"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void test_leds(void) {

    GPIO_setAsOutputPin_Expect(GPIO_PORT_P1, GPIO_PIN0);
    GPIO_setAsOutputPin_Expect(GPIO_PORT_P4, GPIO_PIN6);
    GPIO_setOutputLowOnPin_Expect(GPIO_PORT_P1, GPIO_PIN0);
    GPIO_setOutputHighOnPin_Expect(GPIO_PORT_P4, GPIO_PIN6);
    leds_configure();

    GPIO_toggleOutputOnPin_Expect(GPIO_PORT_P1, GPIO_PIN0);
    GPIO_toggleOutputOnPin_Expect(GPIO_PORT_P4, GPIO_PIN6);
    leds_toggle();
}