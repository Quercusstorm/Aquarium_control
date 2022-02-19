#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>

int main(void) {
	DDRD |= (1<<PD6);									//pin D6 is OUTPUT
	TCCR0A |= (1<<COM0A1) | (1<<WGM00) | (1<<WGM01);	//COM0A1 is settings of "compare output mode", WGM is setting of "PWM mode"
	TCCR0B |= (1<<CS00);								//Prescaling settings
	while (1) {											
	
		for (int a=0; a<256; a++) {
			OCR0A = a;									//add numbers to OCR0A (edit PWM value)
			_delay_ms(10);
		}
		for (int a=0; a<256; a++) {						//sub numbers OCR0A (edit PWM value)
			OCR0A = 255-a;
			_delay_ms(10);
		}
	}
}