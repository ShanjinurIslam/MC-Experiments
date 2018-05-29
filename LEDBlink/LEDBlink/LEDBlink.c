#include <avr/io.h>
#define F_CPU 100000
#include <util/delay.h>

unsigned char c = 0 ;
int main(){
	DDRD = 0x0F;
	DDRB = 0xFB ;
	PORTD = 0xFF ;
	while(1){
		if((PINB & 0x01)){
			if(c==(1<<4)){
				c = 0 ;
			}
			else c++ ;
			PORTD = c ;
		}
		else if((PINB & 0x02)){
			if(c==0){
				c = 0 ;
			}
			else c-- ;
			PORTD = c ;
		}
		_delay_ms(2000) ;
	}
}