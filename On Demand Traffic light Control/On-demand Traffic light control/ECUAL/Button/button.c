/*
 * button.c
 *
 * Created: 9/10/2022 11:01:36 AM
 *  Author: Mohamed Emara
 */ 

#include "button.h"

void BUTTON_init(unit8_t buttonPort,unit8_t buttonPin)//initialize		
{
	DIO_init(buttonPort,buttonPin,OUT);
}

void BUTTON_read(unit8_t buttonPort,unit8_t buttonPin,unit8_t *value)//read
{
	DIO_read(buttonPort,buttonPin,value);
}

/*void main()
{
	BUTTON_init(BUTTON_PORT,BUTTON_PIN);
}*/