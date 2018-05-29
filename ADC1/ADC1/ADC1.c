/*
 * ADC1.c
 *
 * Created: 5/22/2018 10:53:51 AM
 *  Author: Spondon
 */ 

#define F_CPU 1000000
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	unsigned char result ;
	DDRB = 0xFF ;
	ADMUX = 0xE0 ;
	ADCSRA = 0x87 ;
    while(1)
    {
		ADCSRA |= (1<<ADSC) ;
		while((ADCSRA & (1<<ADIF))== 0);
		
		result = ADCH ;
		PORTB = result ; 
		_delay_ms(500) ; 
    }
}