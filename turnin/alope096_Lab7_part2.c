/*	Author: lab
 *  Partner(s) Name: none
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 * Demo Link: https://drive.google.com/drive/folders/1CgwR2gvNUYymDPUC98qPOQr6-UoJOLAX?usp=sharing 
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

void ADC_init(){
    ADCSRA |= (1 << ADEN) | (1 << ADSC) | (1 << ADATE);
}

int main(void) {
    /* Insert DDR and PORT initializations */
    DDRA = 0x00; PORTA = 0xFF;
    DDRB = 0xFF; PORTB = 0x00;
    DDRD = 0xFF; PORTD = 0x00;
    /* Insert your solution below */
    
    ADC_init();

    while (1) {
        unsigned short x = ADC;
        //unsigned short my_short = 0xABCD;
        unsigned char portB = (char)x;
        PORTB=portB;
        unsigned char my_char = (char)(x >> 8);
        PORTD=my_char;
        
    }
    return 1;
}
