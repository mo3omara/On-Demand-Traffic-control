/*
 * dio.h
 *
 * Created: 9/10/2022 11:00:30 AM
 *  Author: Mohamed Emara
 */ 


#ifndef DIO_H_
#define DIO_H_

#include "../../Utilities/bitmanip.h"	
#include "../../Utilities/datatypes.h"

//Pins and Ports
//pins
#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7

//ports
#define PORT_A 'A'
#define PORT_B 'B'
#define PORT_C 'C'
#define PORT_D 'D'


//Directions and Values
//Directions
#define IN	0
#define OUT 1

//Values
#define LOW	 0
#define HIGH 1

// DIO REGISTERS
//PortA registers
#define PORTA (*(volatile unit8_t*)(0x3B))
#define DDRA (*(volatile unit8_t*)(0x3A))
#define PINA (*(volatile unit8_t*)(0x39))

//PortB registers
#define PORTB (*(volatile unit8_t*)(0x38))
#define DDRB (*(volatile unit8_t*)(0x37))
#define PINB (*(volatile unit8_t*)(0x36))

//PortC registers
#define PORTC (*(volatile unit8_t*)(0x35))
#define DDRC (*(volatile unit8_t*)(0x34))
#define PINC (*(volatile unit8_t*)(0x33))

//PortD registers
#define PORTD (*(volatile unit8_t*)(0x32))
#define DDRD (*(volatile unit8_t*)(0x31))
#define PIND (*(volatile unit8_t*)(0x30))


//DIO functions' prototypes
void DIO_init(unit8_t portNumber, unit8_t pinNumber, unit8_t direction);	// Initialize DIO direction
void DIO_write(unit8_t portNumber, unit8_t pinNumber, unit8_t value);		//write data to DIO
void DIO_toggle(unit8_t portNumber, unit8_t pinNumber);						//toggle DIO
void DIO_read(unit8_t portNumber, unit8_t pinNumber, unit8_t* value);		//read DIO






#endif /* DIO_H_ */