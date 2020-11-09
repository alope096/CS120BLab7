/*	Author: lab
 *  Partner(s) Name: none
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
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
    //DDRD = 0xFF; PORTD = 0x00;
    /* Insert your solution below */
  
    ADC_init();

    while (1) {
  unsigned short Max = 88; 
//the highest value i observed was 88 b0001011000 therefore each light is 88/8=11
    unsigned short perLed = 11; 
    unsigned char led=0x00;
    unsigned short x = ADC;
    unsigned char portB = (char)x;
    

        if (portB >= Max){
            led=0xFF;
        }
        else if(portB >= (Max-perLed)){
            led = 0x7F;
        }
        else if(portB >= (Max-(2*perLed)) ){
            led = 0x3F;
        }
        else if(portB >= (Max-(3*perLed)) ){
            led = 0x1F;
        }
        else if(portB >= (Max-(4*perLed))){
            led = 0x0F;
        }
        else if(portB >= (Max-(5*perLed)) ){
            led = 0x07;
        }
        else if(portB >= (Max-(6*perLed)) ){
            led = 0x03;
        }
        else if(portB >= (Max-(7*perLed)) ){
            led = 0x01;
        }
        else if(portB <= 0 ){
            led = 0x00;
        }
        PORTB = led;
    }
    return 1;
}
