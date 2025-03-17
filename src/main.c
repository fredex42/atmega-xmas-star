#include <avr/interrupt.h>  //for sei()
#include <avr/sleep.h>
#include "timer.h"
#include "gpio.h"

int main(void)
{
    setup_gpio();
    setup_timer();
    sei();

    while(1) {
        set_sleep_mode(SLEEP_MODE_PWR_SAVE);    //hold the clock until there is an interrupt
        sleep_mode();
    }
}