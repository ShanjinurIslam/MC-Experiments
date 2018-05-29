#include <avr/io.h>
#define F_CPU 100000
#include <util/delay.h>

unsigned char c = 0 ;
int main(){
	DDRA = 0x0F;
	PORTA = 0x00 ;
	
	DDRD = 0xF3 ;
	while(1){
		if((PIND & 0x04)){
			if(c==(1<<4)){
				c = 0 ;
			}
			else c++ ;
			PORTA = c ;
		}
		else if((PIND & 0x08)){
			if(c==0){
				c = 0 ;
			}
			else c-- ;
			PORTA = c ;
		}
		_delay_ms(2000) ;
	}
}