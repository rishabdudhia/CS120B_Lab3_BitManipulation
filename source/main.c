/*	Author:Rishab Dudhia - rdudh001
 *  Partner(s) Name: None
 *	Lab Section:022
 *	Assignment: Lab #3  Exercise #3
 *	Exercise Description: [optional - include for your own benefit]
 *      PA (input) reads fuel level; PC (output) 6 lights showing level of fuel; Added 7th to detect seatbelt
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
    //DDRB = 0x00; PORTB = 0xFF;
    DDRC = 0xFF; PORTC = 0x00;
    unsigned char count = 0x00;
    unsigned char currBit = 0x00;
    unsigned char check = 0x00;
    //unsigned char i;
    /* Insert your solution below */
    while (1) {
	count = 0x00;
	check = 0x00;
	currBit = 0x00;
	count = PINA & 0x0F;
	check = PINA & 0x70;

	if (count >= 0x01)
	{
	    currBit = currBit | 0x20;
	}
	if (count >= 0x03)
	{
	    currBit = currBit | 0x10;
	}
	if (count >= 0x05)
	{
	    currBit = currBit | 0x08;
	}
	if (count >= 0x07)	
	{
	    currBit = currBit | 0x04;
	}
	if (count >= 0x0A)
	{
	    currBit = currBit | 0x02;
	}
	if (count >= 0x0D)
	{
	    currBit = currBit | 0x01;
	}
	
	if (count <= 0x04)
	{
	    currBit = currBit | 0x40;
	}

	if (check == 0x30)
	{
	    currBit = currBit | 0x80;
	}
	
	PORTC = currBit;
    }
    return 0;
}
