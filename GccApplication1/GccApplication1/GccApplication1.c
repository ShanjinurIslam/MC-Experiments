/*
 * GccApplication1.c
 *
 * Created: 4/21/2018 9:13:48 PM
 *  Author: Spondon
 */
#define F_CPU 1000000
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

unsigned char c=0,ch ;
ISR(INT1_vect){
	if(c>3){
		c = 0 ;
	}
	c++ ;
	PORTB = c ;
	_delay_ms(1000) ;
}

int main(void)
{
	DDRB = 0XFF ;
	PORTB = 0x00 ;
	GICR = 1<<INT1 ;
	MCUCR = MCUCR & 0xF3 ;
	sei() ;
    while(1)
    {
    }
}