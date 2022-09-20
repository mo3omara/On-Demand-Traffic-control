/*
 * led.h
 *
 * Created: 9/10/2022 11:01:56 AM
 *  Author: Mohamed Emara
 */ 


#ifndef LED_H_
#define LED_H_

#include "../../MCAL/DIO/dio.h"

//cars leds
#define CAR_LED_PORT	PORT_A
#define CAR_GREEN_LED	PIN0
#define CAR_YELLOW_LED	PIN1
#define CAR_RED_LED		PIN2

//peds leds
#define PED_LED_PORT	PORT_B
#define PED_GREEN_LED	PIN0
#define PED_YELLOW_LED	PIN1
#define PED_RED_LED		PIN2

void LED_init(unit8_t portNumber, unit8_t pinNumber);	// Initialize LED direction
void LED_ON(unit8_t portNumber, unit8_t pinNumber);		//write data to LED "High"
void LED_OFF(unit8_t portNumber, unit8_t pinNumber);	//write data to LED "Low"
void LED_Toggle(unit8_t portNumber, unit8_t pinNumber);	//toggle LED






#endif /* LED_H_ */