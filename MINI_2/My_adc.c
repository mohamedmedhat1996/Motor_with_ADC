 /******************************************************************************
 *
 * Module: ADC
 *
 * File Name: Myadc.c
 *
 * Description: Source file for the ATmega16 ADC driver
 *
 * Author: Mohamed Medhat
 *
 *******************************************************************************/

#include"My_adc.h"
/*******************************************************************************
 *                          Global Variables                                   *
 *******************************************************************************/

volatile uint16 g_adcResult = 0;

/*******************************************************************************
 *                          ISR's Definitions                                  *
 *******************************************************************************/

ISR(ADC_vect)
{
	/* Read ADC Data after conversion complete */
	g_adcResult = ADC;
}
/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/
void ADC_init(void)
{
	ADMUX=0;

	ADCSRA = (1<<ADEN) | (1<<ADPS1) | (1<<ADPS0);/* Polling*/
	//ADCSRA = (1<<ADEN) | (1<<ADPS1) | (1<<ADPS0)| (1<<ADIE);

}

uint16 ADC_readChannel(uint8 channel_num)
{
	channel_num &= 0x07; /* channel number must be from 0 --> 7 */
	ADMUX&=0xE0;
	ADMUX = ADMUX | channel_num;
	SET_BIT(ADCSRA,ADSC);
	while(BIT_IS_CLEAR(ADCSRA,ADIF));
	SET_BIT(ADCSRA,ADIF); /* clear ADIF by write '1' to it :) */
	//CLEAR_BIT(ADCSRA,ADIF);/*in case of interrupt  write 0 */
	return ADC; /* return the data register */

}

