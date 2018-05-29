/*
 * Tutorial_Bi_LED1.c
 *
 * Created: 5/23/2018 12:30:31 AM
 *  Author: Spondon
 */ 


#include <avr/io.h>

int main(void)
{
	DDRD = 0xFF ;
	DDRA = 0xFF ;
	
	PORTD = 0xFF ;
	PORTA = 0x00 ;
    while(1)
    {
        //TODO:: Please write your application code 
    }
}