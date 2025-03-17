#include <avr/io.h>

void setup_gpio() {
    DDRC = 0x0F;    //lower 4 bits of PORTC are output
    DDRD = 0x1F;    //lower 5 bits of PORTD are output
    PORTC = 0x0;
    PORTD = 0x0;

    //TBD - fix levels of unused pins as per manual
}