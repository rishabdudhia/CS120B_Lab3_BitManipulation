/*	Author:Rishab Dudhia - rdudh001
 *  Partner(s) Name: None
 *	Lab Section:022
 *	Assignment: Lab #3  Exercise #1
 *	Exercise Description: [optional - include for your own benefit]
 *      count number of ones on ports A and B and output on C
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
    /* Insert DDR and PORT initializations */
    DDRA = 0x00; PORTA = 0xFF;
    DDRB = 0x00; PORTB = 0xFF;
    DDRC = 0xFF; PORTC = 0x00;
    unsigned char count = 0;
    unsigned char currBit = 0x00;
    unsigned char i;
    /* Insert your solution below */
    while (1) {
	currBit = 0x00;
	count = 0;
	for (i = 0; i < 8; ++i)
	{
	    currBit = PINA >> i;
	    currBit = currBit & 0x01;

	    if (currBit)
	    {
		++count;
	    }
	    currBit = 0x00;
	}
	
	for (i = 0; i < 8; ++i)
	{
	    currBit = PINB >> i;
	    currBit = currBit & 0x01;

	    if (currBit)
	    {
		++count;
	    }
	    currBit = 0x00;
	}
	PORTC = count;
    }
    return 0;
}
