/*
 * ADC.h
 *
 * Created: 2017-07-12 오전 11:58:50
 *  Author: Inkyu Lee
 */ 


#ifndef ADC_H_
#define ADC_H_

void initADC(unsigned char channel)
{
	ADMUX |= (1<<REFS0); //AVCC 5V
	ADCSRA |= 0x07; //분주비
	ADCSRA |= (1<<ADEN); //활성화
	ADCSRA |= (1<<ADFR); //free-running
	
	ADMUX = ((ADMUX & 0xE0) | channel);
	ADCSRA |= (1<<ADSC);
}

int readADC()
{
	while(!(ADCSRA&(1<<ADIF)));
	return ADC; // 0~1023
}

#endif /* ADC_H_ */
