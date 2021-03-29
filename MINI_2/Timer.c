#include"Timer.h"

void PWM_init(void)
{
	/*INItial value of timer = 0*/
	TCNT0=0;
	/*set your desired duty cycle*/
		//OCR0=duty_cycle;
	/*output generated PWM*/
	DDRB|=(1<<PB3);
	/*
	* TCCRO
	* WGM01 and WGM01 fast PWM
	* COM01  to clear OC0
	* CS01 presaler   CPU/8
	*/
	TCCR0|=(1<<WGM01)|(1<<WGM00)|(1<<COM01)|(1<<CS01);


}

