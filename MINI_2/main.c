
#include "My_Keypad.h"
#include"My_Lcd.h"
#include"My_adc.h"
#include"Timer.h"
#include"GPIO.h"
unsigned char g_Interrupt_Flag = 0;
unsigned char duty_cycle=0;

int main()
{
	int state_Rotation=0;
	uint16 reader=0;
	INT1_Init();
	LCD_init();
	ADC_init();
	LCD_clearScreen();
	LCD_displayStringRowColumn(0,2,"ADC value=");
	DDRB|=(1<<PB0)|(1<<PB1);
	PORTB&=~(1<<PB0);
	PORTB&=~(1<<PB1);
	PWM_init();

	while(1)
	{
		reader=ADC_readChannel(0);
		LCD_goToRowColumn(0,12);
		LCD_intgerToString(reader);
		if(reader>0 && reader<=128)
		{
			OCR0=64;
		}
		else if(reader>128 && reader<=512)
		{
			OCR0=128;
		}
		else
		{
			OCR0=255;
		}

		if(g_Interrupt_Flag==1)
		{
            if(state_Rotation==1)
            {
            	state_Rotation=0;
            }
            else
            {
            	state_Rotation=1;
            }

			g_Interrupt_Flag=0;
		}
		if(state_Rotation==1)
		{
			// Rotate the motor --> clock wise
						PORTB &= (~(1<<PB0));
						PORTB |= (1<<PB1);
						// _delay_ms(1000);


		}
		else
		{
			PORTB &= (~(1<<PB1));
			PORTB |= (1<<PB0);
		}

	}
	return 0;
}


