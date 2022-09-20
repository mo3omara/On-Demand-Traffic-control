/*
 * button.h
 *
 * Created: 9/10/2022 11:01:27 AM
 *  Author: Mohamed Emara
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_

#include "../../MCAL/DIO/dio.h"

//Button
#define BUTTON_PORT	PORT_D  //(PORTD PIN2) to use External Interrupt 0 "INT0"
#define BUTTON_PIN	PIN2


//initialize
void BUTTON_init(unit8_t buttonPort,unit8_t buttonPin);

// button read
void BUTTON_read(unit8_t buttonPort,unit8_t buttonPin,unit8_t *value);




#endif /* BUTTON_H_ */