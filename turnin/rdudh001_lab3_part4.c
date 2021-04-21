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
    DDRB = 0xFF; PORTB = 0x00;
    DDRC = 0xFF; PORTC = 0x00;
    //unsigned char count = 0x00;
    //unsigned char currBit = 0x00;
    //unsigned char check = 0x00;
    //unsigned char i;
    unsigned char toB = 0x00;
    unsigned char toC = 0x00;
    /* Insert your solution below */
    while (1) {
	toB = PINA & 0xF0;
	toB = toB >> 4;
	PORTB = toB;

	toC = PINA & 0x0F;
	toC = toC << 4;
	PORTC = toC;
    }
    return 0;
}
