/*
 * _4BitCounterInturrupt.c
 *
 * Created: 5/12/2018 6:42:28 PM
 *  Author: Spondon
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>

unsigned char ch = 0 ;

ISR(INT0_vect){
	if(ch==(1<<4)){
		ch = 0 ;
		PORTA = ch ;
	}
	else{
		ch++ ;
		PORTA = ch ;
	}
}

ISR(INT1_vect){
	if(ch==0){
		ch = 0 ;
		PORTA = ch ; 
	}
	else{
		ch-- ;
		PORTA = ch ;
	}
}


int main(){
	DDRA = 0x0F ;
	PORTA = ch ;
	MCUCR = (MCUCR & 0xF0) ;
	GICR = 0xC0 ;
	sei() ;
	return 0 ;
}