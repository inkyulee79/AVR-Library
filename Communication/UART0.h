

#ifndef UART0_H_
#define UART0_H_

void UART0_init() 
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

void UART0_transmit(char data) 
{
	while(!(UCSR0A & (1<<UDRE0)));
	UDR0 = data;
}

void UART0_transmit_string(char* str)
{
	int i;
	for(i=0;str[i]!='\0';i++)
	{
		UART0_transmit(str[i]);
	}
}

unsigned char UART0_receive()
{
	while(! (UCSR0A & (1<<RXC0)) );
	return UDR0;
}

int is_UART0_received()
{
	return ((UCSR0A >> TXEN0) & 1);
}

FILE OUTPUT \
= FDEV_SETUP_STREAM(UART0_transmit, NULL, _FDEV_SETUP_WRITE);
FILE INPUT \
= FDEV_SETUP_STREAM(NULL, UART0_receive, _FDEV_SETUP_READ);

#endif /* UART0_H_ */
