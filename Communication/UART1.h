/*
UART 통신은 가장 많이 사용되는 통신 방식입니다.
이 통신은 AVR과 PC 간 통신을 활성시킵니다.
UART communication is a communication way in AVR system.
This enables a communication between AVR and PC.
*/


#ifndef UART1_H_
#define UART1_H_

void initUART1_default()
{
	UBRR1H = 0x00;
	UBRR1L = 207;
	
	UCSR1A |= _BV(U2X1);
	UCSR1C |= 0x06;
	UCSR1B |= _BV(RXEN1);
	UCSR1B |= _BV(TXEN1);
	UCSR1B |= _BV(RXCIE1);
	UCSR1B |= _BV(TXCIE1);
	
}

void transmitUART1(char data)
{
	while(!(UCSR1A & (1<<UDRE1)));
	UDR1 = data;
}

void transmitUART1_string(char* str)
{
	int i;
	for(i=0;str[i]!='\0';i++)
	{
		transmitUART1(str[i]);
	}
}

unsigned char receiveUART1()
{
	while(! (UCSR1A & (1<<RXC1)) );
	return UDR1;
}

int isUART1Received()
{
	return ((UCSR1A >> TXEN1) & 1);
}

FILE OUTPUT \
= FDEV_SETUP_STREAM(transmitUART1, NULL, _FDEV_SETUP_WRITE);
FILE INPUT \
= FDEV_SETUP_STREAM(NULL, receiveUART1, _FDEV_SETUP_READ);



#endif /* UART1_H_ */