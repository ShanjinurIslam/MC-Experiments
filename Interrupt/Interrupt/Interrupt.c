/*
 * Interrupt.c
 *
 * Created: 5/4/2018 10:53:49 PM
 *  Author: Spondon
 */ 

#define F_CPU 1000000
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

ISR(INT0_vect)
{
	if(0x01&PORTB){
		PORTB = 0xFE & PORTB ;
	}else PORTB = 0x01 | PORTB ;	
}

ISR(INT1_vect)
{
	if(0x02&PORTB){
		PORTB = 0xFD & PORTB ;
	}else PORTB = 0x02 | PORTB ;
}
int main(void)
{	
	DDRB = 0xFF ;
	PORTB = 0x00 ;
	MCUCR = MCUCR & 0xF0 ;
	GICR = 0xFF ;
	sei() ;
    while(1)
    {
    }
}