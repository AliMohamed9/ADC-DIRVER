/*
 * seven_segments.c
 *
 *  Created on: Jul 18, 2020
 *      Author: MeGa
 */

#include"seven_segments.h"
#include<avr/io.h>
#include<util/delay.h>


void seven_segment_init(void)
{

	DDRB=0x0F;
	DDRC=0b00111100;


}

void display_4_Digits_7Segment(unsigned int number)
{

	unsigned char digit1=0,digit2=0,digit3=0,digit4=0;
	unsigned int temp=0;


	digit4=number/1000;
	temp=number%1000;

	digit3=temp/100;
	temp=temp%100;

	digit2=temp/10;

	digit1=temp%10;


	if(number>1000)
	{


		PORTC &=~(1<<PC5);
		PORTC |=(1<<PC4);
		PORTC |=(1<<PC3);
		PORTC |=(1<<PC2);
		PORTB = digit4;
		_delay_ms(5);

	}

	if(number>100)
	{

		PORTC |=(1<<PC5);
		PORTC &=~(1<<PC4);
		PORTC |=(1<<PC3);
		PORTC |=(1<<PC2);

		PORTB = digit3;
		_delay_ms(5);
	}

	if(number>10)
	{

		PORTC |=(1<<PC5);
		PORTC |=(1<<PC4);
		PORTC &=~(1<<PC3);
		PORTC |=(1<<PC2);

		PORTB = digit2;
		_delay_ms(5);
	}


	PORTC |=(1<<PC5);
	PORTC |=(1<<PC4);
	PORTC |=(1<<PC3);
	PORTC &=~(1<<PC2);
	PORTB = digit1;
	_delay_ms(5);


}

