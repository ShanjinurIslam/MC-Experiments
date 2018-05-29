/*
 * BiLedMatrix.c
 *
 * Created: 5/18/2018 11:01:55 AM
 *  Author: Spondon
 */ 


#include <avr/io.h>
#define F_CPU 100000
#include <util/delay.h>

unsigned char ch = 1 ;
unsigned char a = 1;
unsigned char b = (1<<7) ;

void shift(){
	PORTD = ch ;	
	
	if(ch==(1<<7)){
		ch = 1;
	}
	else{
		ch = ch<<1 ;
	}
	_delay_ms(500) ;
}

void T(){
	if(ch<(1<<3) || ch>(1<<4)){
		PORTD = 1 ;
		PORTA = ~(a) ;
	}
	else{
		PORTD = 0xFF ;
		PORTA = ~(a) ;
	}
	if(ch==(1<<7)){
		ch = 1 ;
		a = 1 ;
	}
	else{
		ch = ch<<1 ;
		a = a<<1 ;
	}
	_delay_ms(20) ;
}
void A(){
	PORTD = b ;
	PORTA = ~(ch) ;
	if(ch==(1<<7)){
		PORTD = 0xFF ;
	}
	else if(ch>=(1<<3)&& ch<=(1<<6)){
		PORTD = (b|0b00010000) ;
	}
	else{
		PORTD = b ;
	}
	if(ch==(1<<7)){
		ch = 1 ;
		b = 1<<7 ;
	}
	else{
		ch = ch<<1 ;
		b = b>>1 ;
	}
	_delay_ms(20) ;
}

void E(){
	PORTD = ch ;
	if(ch==1){
		PORTA = 0x00 ;
	}
	else{
		PORTA = 0b01101110 ;
	}
	if(ch==(1<<7)){
		ch = 1 ;
	}
	else{
		ch = ch<<1 ;
	}
	_delay_ms(20) ;
}

void Z(){
	PORTD = ch ;
	if(ch==1 || ch==(1<<7)){
		PORTA = 0x00 ;
	}
	else{
		PORTA = ~(b) ;
	}
	if(ch==(1<<7)){
		ch = 1 ;
		b = 1<<7 ;
	}
	else{
		ch = ch<<1 ;
		b = b>>1 ;
	}
	_delay_ms(20) ;
}

void O(){
	if(ch==1 || ch==(1<<7)){
		PORTD = 0xFF ;
		PORTA = ~ch ;
	}
	else{
		PORTD = 0x81 ;
		PORTA = ~ch ;
	}
	if(ch==(1<<7)){
		ch = 1 ;
		b = 1<<7 ;
	}
	else{
		ch = ch<<1 ;
		b = b>>1 ;
	}
	_delay_ms(20) ;
}

void S(){
	PORTD = ch ;
	if(ch==1 || ch==(1<<7)){
		PORTA = 0x00 ;
	}
	else{
		PORTA = ~(a) ;
	}
	if(ch==(1<<7)){
		ch = 1 ;
		a = 1 ;
	}
	else{
		ch = ch<<1 ;
		a = a<<1 ;
	}
	_delay_ms(20) ;
}

void X(){
	PORTD = ch ;
	PORTA =  ~(a|b);
	if(ch==(1<<7)){
		ch = 1;
		a = 1;
		b = (1<<7) ;
	}
	else{
		ch = ch<<1 ;
		a = a<<1 ;
		b = b>>1 ;
	}
	_delay_ms(20) ;
}

void H(){
	if(ch==(1) || ch==(1<<7)){
		PORTD = 0xFF ;
		PORTA = ~ch ;
	}
	else{
		PORTD = 0b0011000 ;
		PORTA = ~ch ;
	}
	if(ch==(1<<7)){
		ch = 1;
	}
	else{
		ch = ch<<1 ;
	}
	_delay_ms(20) ;
}

void L(){
	PORTD = ch ;
	if(ch==1){
		PORTA = 0x00 ;
	}
	else{
		PORTA = ~(1) ;
	}
	if(ch==(1<<7)){
		ch = 1;
	}
	else{
		ch = ch<<1 ;
	}
}


int main(void)
{
	DDRA = 0xFF ;
	DDRD = 0xFF ;
	PORTA =0x00 ;
    while(1)
    {
		O() ;
    }
}