/*
 * MiniProject2SalahKhaled.c
 *
 *  Created on: Feb 11, 2022
 *      Author: 20101
 */

#include <avr/io.h>
#include<avr/interrupt.h>
#include <util/delay.h>

unsigned char sec1_tick = 0;
unsigned char sec2_tick = 0;
unsigned char min1_tick = 0;
unsigned char min2_tick = 0;
unsigned char hr1_tick = 0;
unsigned char hr2_tick = 0;


void INT0_Init(void) {
	SREG |= (1 << 7);
	DDRD &= ~(1 << 2);
	PORTD |= (1 << 2);
	GICR |= (1 << INT0);
	MCUCR |= (1 << ISC01);
	MCUCR &= ~(1 << ISC00);
}


ISR (INT0_vect) {
	sec1_tick = 0;
	sec2_tick = 0;
	min1_tick = 0;
	min2_tick = 0;
	hr1_tick = 0;
	hr2_tick = 0;
}


void INT1_Init(void)
{
	SREG |= (1<<7);
	DDRD &= ~(1<<3);
	MCUCR|=(1<<ISC11)|(ISC01);
	GICR |= (1<<INT1);
}


ISR (INT1_vect)
{
	TCCR1B &= ~(1<<CS10) & (1<<CS11) & (1<<CS12);
}


void INT2_Init(void)
{
  SREG |=(1<<7);
  DDRB &= ~(1<<2);
  PORTB |=(1<<2);
  MCUCR &= ~(1<<ISC2);
  GICR|=(1<<INT2);
}

void Timer1_CTC(void)
{
	TCCR1A = (1<<FOC1A);
	TCCR1B = (1<<CS12) | (1<<CS10) | (1<<WGM12);
	TCNT1= 0 ;
	OCR1A=1000;
	TIMSK = (1<<OCIE1A);
}

ISR(INT2_vect)
{
	Timer1_CTC();
}

ISR(TIMER1_COMPA_vect)
{
	sec1_tick++;
	if(sec1_tick==10)
	{
		sec2_tick++;
		sec1_tick=0;

		if(sec2_tick==6)
		{
			min1_tick++;
			sec2_tick=0;
		}

		if(min1_tick==10)
		{
			min2_tick++;
			min1_tick=0;
		}

		if(min2_tick==6)
		{
			hr1_tick++;
			min2_tick=0;
		}

		if(hr1_tick==10)
		{
			hr2_tick++;
			hr1_tick=0;

			if (hr2_tick == 3 && hr1_tick == 5) {
				sec1_tick = 0;
				sec2_tick = 0;
				min1_tick = 0;
				min2_tick = 0;
				hr1_tick = 0;
				hr2_tick = 0;
			}
		}

	}

}
int main(void) {

	DDRA = 0X3F;
	PORTA = 0;
	DDRC = 0X0F;
	PORTC = 0;
	Timer1_CTC();
	INT0_Init();
	INT1_Init();
	INT2_Init();

	while(1)
	{

		PORTA = (PORTA & 0X00) | (1 << 0);
		PORTC = sec1_tick;
		_delay_ms(5);

		PORTA = (PORTA & 0X00) | (1 << 1);
		PORTC = sec2_tick;
		_delay_ms(5);

		PORTA = (PORTA & 0X00) | (1 << 2);
		PORTC = min1_tick;
		_delay_ms(5);

		PORTA = (PORTA & 0X00) | (1 << 3);
		PORTC = min2_tick;
		_delay_ms(5);

		PORTA = (PORTA & 0X00) | (1 << 4);
		PORTC = hr1_tick;
		_delay_ms(5);

		PORTA = (PORTA & 0X00) | (1 << 5);
		PORTC = hr2_tick;
		_delay_ms(5);

	}
}

