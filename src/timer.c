//note - need appropriate #define's for the register names to show up, specifically
//the chip type
#include <avr/io.h>
#include <avr/interrupt.h>

//Sets up Normal mode counting up on the 8-bit timer
//and signal an interrupt at wrap-around
void setup_timer() 
{
    TCCR2A = 0x0;
    TCCR2B = CS00;  //set CS00 => drive from clock, no prescaler  
    TIMSK2 = TOIE0; //set TOIE0 => enable overflow interrupt
}

//Interrupt handler for the timer. This should get called every 256 clock cycles.
//Manual says a default 1Mhz clock; that makes this called about 4,000 times per second.
ISR(TIMER2_OVF_vect) {
    //DEBUGGING - flash bit 0 of PORTD
    if(PORTD & 0x01) {
        PORTD &= 0xFE;
    } else {
        PORTD |= 0x01;
    }
}