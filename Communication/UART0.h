/*
UART 통신은 가장 많이 사용되는 통신 방식입니다.
이 통신은 AVR과 PC 간 통신을 활성시킵니다.
UART communication is a communication way in AVR system.
This enables a communication between AVR and PC.
*/

#ifndef UART0_H_
#define UART0_H_

void initUART0_default() 
{
	UBRR0H = 0x00;
	UBRR0L = 207;
	
	UCSR0A |= _BV(U2X0); 
	UCSR0C |= 0x06;
	UCSR0B |= _BV(RXEN0);
	UCSR0B |= _BV(TXEN0);
	UCSR0B |= _BV(RXCIE0); 
	UCSR0B |= _BV(TXCIE0);
	
}

void transmitUART0(char data) 
{
	while(!(UCSR0A & (1<<UDRE0)));
	UDR0 = data;
}

void transmitUART0_string(char* str)
{
	int i;
	for(i=0;str[i]!='\0';i++)
	{
		transmitUART0(str[i]);
	}
}

unsigned char receiveUART0()
{
	while(! (UCSR0A & (1<<RXC0)) );
	return UDR0;
}

int isUART0Received()
{
	return ((UCSR0A >> TXEN0) & 1);
}

#ifndef STANDARD_IO_ENABLE
#define STANDARD_IO_ENABLE
#include <stdio.h>

FILE OUTPUT \
= FDEV_SETUP_STREAM(transmitUART0, NULL, _FDEV_SETUP_WRITE);
FILE INPUT \
= FDEV_SETUP_STREAM(NULL, receiveUART0, _FDEV_SETUP_READ);

#endif STANDARD_IO_ENABLE


#endif /* UART0_H_ */