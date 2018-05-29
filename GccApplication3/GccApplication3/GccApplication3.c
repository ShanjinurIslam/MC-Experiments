/*
 * GccApplication2.c
 *
 * Created: 5/15/2018 12:45:11 AM
 *  Author: Spondon
 */ 
#define F_CPU 1000000 
#include <util/delay.h>
#include <avr/io.h>
#include <avr/interrupt.h>


unsigned char ch = 0x00 ;
ISR(INT0_vect){
	if(ch==(1<<4)){
		ch = 0 ;
		PORTA = ch ;
	}
	else{
		ch++ ;
		PORTA = ch ;
	}
	_delay_ms(1000) ;
	GIFR = 0xFF ;
}

ISR(INT1_vect){
	if(ch!=0){
		ch-- ;
		PORTA = ch ;
	}
	_delay_ms(1000) ;
	GIFR = 0xFF ;
}

int main(void)
{
	DDRA = 0x0F ;
	PORTA = ch ;
	MCUCR = (MCUCR & 0xF0) ;
	GICR = 0xC0 ;
	sei() ;
    while(1)
    {
    }
}