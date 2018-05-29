/*
 * CT1.c
 *
 * Created: 4/23/2018 2:19:28 PM
 *  Author: Spondon
 */ 


#include <avr/io.h>
#define F_CPU 1000000 
#include <util/delay.h>

unsigned char ch ;
int main(void)
{
	DDRA = 0x0F ;
	PORTA = 0x00 ;
    while(1)
    {
		ch = PINA ;
		if(ch&0x40){
			if(PORTA&0x01){
				PORTA = PORTA & 0x0E ; 
			}
			else PORTA = PORTA | 0x01 ;
			_delay_ms(500) ;
		}
		
		else if(ch&0x80){
			if(PORTA&0x02){
				PORTA = PORTA & 0x0D ;
			}
			else PORTA = PORTA | 0x02 ;
			_delay_ms(500) ;
		}
        //TODO:: Please write your application code 
    }
}