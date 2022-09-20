/*
 * dio.c
 *
 * Created: 9/10/2022 11:00:20 AM
 *  Author: Mohamed Emara
 */ 

#include "dio.h"

// function definitions

void DIO_init(unit8_t portNumber, unit8_t pinNumber, unit8_t direction)
{
	switch(portNumber){
		case PORT_A:
			if(direction == IN){
				CLEAR_BIT(DDRA,pinNumber);
			}else if (direction == OUT){
				SET_BIT(DDRA,pinNumber);
			}
			else{}
			break;
		case PORT_B:
			if(direction == IN){
				CLEAR_BIT(DDRB,pinNumber);
			}else if (direction == OUT){
				SET_BIT(DDRB,pinNumber);
			}
			else{}
			break;
		case PORT_C:
			if(direction == IN){
				CLEAR_BIT(DDRC,pinNumber);
			}else if (direction == OUT){
				SET_BIT(DDRC,pinNumber);
			}
			else{}
			break;
		case PORT_D:
			if(direction == IN){
				CLEAR_BIT(DDRD,pinNumber);
			}else if (direction == OUT){
				SET_BIT(DDRD,pinNumber);
			}
			else{}
			break;
	}
}
void DIO_write(unit8_t portNumber, unit8_t pinNumber, unit8_t value)
{
	switch(portNumber){
		case PORT_A:
			if(value == LOW)
			{
				CLEAR_BIT(PORTA,pinNumber);
			}else if (value == HIGH)
			{
				SET_BIT(PORTA,pinNumber);
			}
			else{}
		break;
		case PORT_B:
			if(value == LOW)
			{

				CLEAR_BIT(PORTB,pinNumber);
			}else if (value == HIGH)
			{

				SET_BIT(PORTB,pinNumber);
			}
			else{}
		break;
		case PORT_C:
			if(value == LOW)
			{
				CLEAR_BIT(PORTC,pinNumber);
			}else if (value == HIGH)
			{
				SET_BIT(PORTC,pinNumber);
			}
			else{}
		break;
		case PORT_D:
			if(value == LOW)
			{
				CLEAR_BIT(PORTD,pinNumber);
			}else if (value == HIGH)
			{

				SET_BIT(PORTD,pinNumber);
			}
			else{}
		break;
	}
}
void DIO_toggle(unit8_t portNumber, unit8_t pinNumber)
{
	switch(portNumber)
	{
		case PORT_A:
			TOGGLE_BIT(PORTA,pinNumber);
		break;
		case PORT_B:
			TOGGLE_BIT(PORTB,pinNumber);
		break;
		case PORT_C:
			TOGGLE_BIT(PORTC,pinNumber);
		break;
		case PORT_D:
			TOGGLE_BIT(PORTD,pinNumber);
		break;
	}
}
void DIO_read(unit8_t portNumber, unit8_t pinNumber, unit8_t* value)
{
	switch(portNumber)
	{
		case PORT_A:
			*value = READ_BIT(PINA,pinNumber);
		break;
		case PORT_B:
			*value = READ_BIT(PINB,pinNumber);
		break;
		case PORT_C:
			*value = READ_BIT(PINC,pinNumber);
		break;
		case PORT_D:
			*value = READ_BIT(PIND,pinNumber);
		break;
	}
}


