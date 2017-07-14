/*
ADC는 아날로그 값을 읽기 위해 사용되는 모듈입니다.
ADC is a module which is able to read an analog value.
*/

#ifndef ADC_H_
#define ADC_H_

void initADC_default(unsigned char channel)
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