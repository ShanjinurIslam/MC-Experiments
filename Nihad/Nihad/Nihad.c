/*
 * Nihad.c
 *
 * Created: 5/23/2018 3:14:55 PM
 *  Author: Spondon
 */ 

#define F_CPU 1000000
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRB = 0xFF ;
    while(1)
    {
		PORTB = 0xFF ;
		_delay_ms(500) ;
		PORTB = 0x00 ;
		_delay_ms(500) ;
        //TODO:: Please write your application code 
    }
}