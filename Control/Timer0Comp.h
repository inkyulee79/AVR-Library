#ifndef TIMER0COMP_H_
#define TIMER0COMP_H_

#include <avr/interrupt.h>

volatile uint8_t timer0Cnt=0;

ISR(TIMER0_COMP_vect)
{
	timer0Cnt++; //cnt가 128이면 0.5초 경과
	TCNT0 = 0;
}

void timer0CompInit()
{
	TCCR0 |= 7; //분주비 1024, 0000 0111
	OCR0 = 64; 
	
	TIMSK |= (1<<OCIE0);
	sei();
}

#endif /* TIMER0COMP_H_ */