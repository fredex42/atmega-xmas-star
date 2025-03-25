#include <avr/io.h>

void setup_gpio() {
    DDRC = 0x0F;    //lower 4 bits of PORTC are output
    DDRD = 0x1F;    //lower 5 bits of PORTD are output
    PORTC = 0x0F;   //initialise port C (cathodes) to 'high'
    PORTD = 0x00;   //initialise port D (anodes) to 'low'

    //TBD - fix levels of unused pins as per manual
}