/*
 * led.c
 *
 * Created: 9/10/2022 11:01:46 AM
 *  Author: Mohamed Emara
 */ 

#include "led.h"

void LED_init(unit8_t portNumber, unit8_t pinNumber)
{
	DIO_init(portNumber,pinNumber,OUT);
}
void LED_ON(unit8_t portNumber, unit8_t pinNumber)
{
	DIO_write(portNumber,pinNumber,HIGH);
}
void LED_OFF(unit8_t portNumber, unit8_t pinNumber)
{
	DIO_write(portNumber,pinNumber,LOW);	
}
void LED_Toggle(unit8_t portNumber, unit8_t pinNumber)
{
	DIO_toggle(portNumber,pinNumber);
}

/*void main()
{
LED_init(CAR_LED_PORT,CAR_RED_LED);
LED_ON(CAR_LED_PORT,CAR_GREEN_LED);
}
*/