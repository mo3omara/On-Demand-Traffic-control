/*
 * interrupts.h
 *
 * Created: 9/10/2022 11:03:12 AM
 *  Author: Mohamed Emara
 */ 


#ifndef INTERRUPTS_H_
#define INTERRUPTS_H_

#include "../datatypes.h"
#include "../bitmanip.h"

//int pins
#define INT0 0
#define INT1 1
#define INT2 2

//Interrupt vectors
#define EXT_INT0 __vector_1
#define EXT_INT1 __vector_2

//interrupts on/off
#define INT_ON  1
#define INT_OFF 0

//Senses
#define lowlevel 0
#define logic 1
#define rise 2
#define fall 3

// Interrupt REGISTERS
#define SREG (*(volatile unit8_t*)(0x5F))
#define GICR (*(volatile unit8_t*)(0x5B))
#define MCUCR (*(volatile unit8_t*)(0x55))
#define MCUCSR (*(volatile unit8_t*)(0x54))

//Enable/Disable interrupts
#define sei()  __asm__ __volatile__ ("sei" ::: "memory")
#define cli()  __asm__ __volatile__ ("cli" ::: "memory")


#define ISR(INT_VECT) void INT_VECT(void) __attribute__ ((signal,used)); void INT_VECT(void)


//function prototypes
void Interrups_control(unit8_t state_OnOff,unit8_t INT_Number, unit8_t sense);




#endif /* INTERRUPTS_H_ */