#include"GPIO.h"



/* External INT1 Interrupt Service Routine */
ISR(INT1_vect)
{
	// set the interrupt flag to indicate that INT1 occurs
	g_Interrupt_Flag =1;
}

void INT1_Init(void)
{
	    SREG  &= ~(1<<7);      // Disable interrupts by clearing I-bit
		DDRD  &= (~(1<<PD3));  // Configure INT1/PD3 as input pin
		PORTD |= (1<<PD3);     // Enable the internal pull up resistor at PD3 pin
		GICR  |= (1<<INT1);    // Enable external interrupt pin INT1
		// Trigger INT1 with the falling edge
		MCUCR |= (1<<ISC11)|(1<<ISC10);
		//MCUCR &= ~(1<<ISC10);
		SREG  |= (1<<7);       // Enable interrupts by setting I-bit
}

