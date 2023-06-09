// blink_mit_oszi.c

// 20 HMz crystal osc with 22 pF caps on XTAL1 (pin 9) and XTAL2 (pin 10)
// LED on PC5

// before running this code, set the chip's fuses as shown in the video or "ATmega328P fuse settings for 20 MHz external xtal osc.png"

#ifndef F_CPU						// if F_CPU was not defined in Project -> Properties
#define F_CPU 20000000UL			// define it now as 20 MHz unsigned long
#endif

#include <avr/io.h>				// this is always included in AVR programs
#include <util/delay.h>			// add this to use the delay function

///////////////////////////////////////////////////////////////////////////////////////////////////
int main(void) {
	
	DDRC |= (1 << PC5);			// set Port C pin PC5 for output
	
	while (1) {					// begin infinite loop
		PORTC ^= (1 << PC5);	// flip state of LED on PC5
		_delay_ms(500);			// delay 1/2 second
	}
	return(0);					// should never get here, this is to prevent a compiler warning
}

