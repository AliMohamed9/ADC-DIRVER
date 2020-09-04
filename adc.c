/*
 * adc.c
 *
 *  Created on: Jul 18, 2020
 *      Author: MeGa
 */

#include<avr/io.h>
#include<util/delay.h>

#include "LCD.h"
#include"seven_segments.h"


#define LCD_code          0
#define ADC_code          1



#if LCD_code




int main()
{

	LCD_init();

	_delay_ms(1000);


	LCD_Send_string("Hello from fab");
	//	LCD_Send_data('A');
	//		LCD_Send_data('h');
	//		LCD_Send_data('m');
	//		LCD_Send_data('e');
	//		LCD_Send_data('d');

	//		LCD_go_to(2,4);
	//	LCD_Send_string((unsigned char*)"ahmed saleh");

	while(1)
	{

		_delay_ms(300);
	}




	return 0;
}







#endif



#if ADC_code
#define TEMP 0
#define LDR  1

void ADC_init(void);
unsigned int ADC_Get_Reading_mv( unsigned char CH);



int main()
{
	unsigned int ADC_reading=0;
	unsigned int reading_in_mv=0;

	unsigned char temp=0;

	ADC_init();
	seven_segment_init();
	DDRD |=(1<<PD7);

#if TEMP
	while(1)
	{
		ADC_reading=ADC_Get_Reading_mv(6);
		reading_in_mv=ADC_reading*4.88;
		temp=reading_in_mv/10;
		display_4_Digits_7Segment(temp);

	}

#endif


#if LDR
	while(1)
	{
		ADC_reading=ADC_Get_Reading_mv(2);
		display_4_Digits_7Segment(ADC_reading);

		if(ADC_reading<50)
		{
			PORTD |=(1<<PD7);
		}
		else
		{

			PORTD &=~(1<<PD7);
		}

		//		_delay_ms(1000);

	}

#endif



	return 0;
}



void ADC_init(void)
{

	ADMUX=0b01000000;
	ADCSRA=0b10000111;
}

unsigned int ADC_Get_Reading_mv(unsigned char CH)
{
	ADCSRA |=(1<<ADIF);    // set to one when the conversion complete


	ADMUX=((ADMUX&0xF8)|CH);   //  enable channel of analog to digital conversion
	ADCSRA |=(1<<ADSC);


	while(!(ADCSRA&(1<<ADIF)));

	return ADC;   ///////////////// ????????????///
}



#endif

