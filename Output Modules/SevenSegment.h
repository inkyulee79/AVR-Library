/*
MCU와 7 세그먼트 모듈이 알파벳 순서대로 연결되어 있을 때 정확히 작동합니다.
This header needs an alphabetic connection between 7-Segment and MCU.
*/

#ifndef SEVENSEGMENT_H_
#define SEVENSEGMENT_H_

uint8_t sevenSegmentInit(char portVal)
{
	uint8_t isInitSuccessed = 1;
	switch(portVal)
	{
		case 'A':
		case 'a':
			DDRA = 0xFF;
			break;
		case 'B':
		case 'b':
			DDRB = 0xFF;
			break;
		case 'C':
		case 'c':
			DDRC = 0xFF;
			break;
		case 'D':
		case 'd':
			DDRD = 0xFF;
			break;
		case 'E':
		case 'e':
			DDRE = 0xFF;
			break;
		default:
			isInitSuccessed = 0;
	}
	return isInitSuccessed;
}


uint8_t sevenSegmentPrint(char portVal, char printCharVal)
{
	uint8_t isPrintSuccessed = 1;
	uint8_t pattern = 0x00;
	
	switch(printCharVal)
	{
		case '0':
			pattern = 0x3F; //0011 1111
			break;
		case '1':
			pattern = 0x06; //0000 0110
			break;
		case '2':
			pattern = 0x5B; //0101 1011
			break;
		case '3':
			pattern = 0x4F; //0100 1111
			break;
		case '4':
			pattern = 0x66; //0110 0110
			break;
		case '5':
			pattern = 0x6D; //0110 1101
			break;
		case '6':
			pattern = 0x7D; //0111 1101
			break;
		case '7':
			pattern = 0x27; //0010 0111
			break;
		case '8':
			pattern = 0x7F; //0111 1111
			break;
		case '9':
			pattern = 0x6F; //0110 1111
			break;
		case 'A':
			pattern = 0x77; //0111 0111
			break;
		case 'C':
			pattern = 0x39; //0011 1001
			break;
		case 'E':
			pattern = 0x79; //0111 1001
			break;
		default:
			isPrintSuccessed = 0;
	}
	
	switch(portVal)
	{
		case 'A':
		case 'a':
			PORTA = pattern;
			break;
		case 'B':
		case 'b':
			PORTB = pattern;
			break;
		case 'C':
		case 'c':
			PORTC = pattern;
			break;
		case 'D':
		case 'd':
			PORTD = pattern;
			break;
		case 'E':
		case 'e':
			PORTE = pattern;
			break;
		default:
			isPrintSuccessed = 0;
	}
	return isPrintSuccessed;
}

uint8_t sevenSegmentPrint_CustomPattern(char portVal, uint8_t pattern)
{
	uint8_t isPrintSuccessed = 1;
	switch(portVal)
	{
		case 'A':
		case 'a':
			PORTA = pattern;
			break;
		case 'B':
		case 'b':
			PORTB = pattern;
			break;
		case 'C':
		case 'c':
			PORTC = pattern;
			break;
		case 'D':
		case 'd':
			PORTD = pattern;
			break;
		case 'E':
		case 'e':
			PORTE = pattern;
			break;
		default:
			isPrintSuccessed = 0;
	}
	return isPrintSuccessed;
}

#endif /* SEVENSEGMENT_H_ */