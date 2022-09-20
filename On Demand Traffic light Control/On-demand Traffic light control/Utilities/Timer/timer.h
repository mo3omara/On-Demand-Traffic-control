/*
 * timer.h
 *
 * Created: 9/10/2022 11:00:41 AM
 *  Author: Mohamed Emara
 */ 

#ifndef TIMER_H_
#define TIMER_H_

#include "../../Utilities/datatypes.h"
#include "../../Utilities/bitmanip.h"
#include "../../Utilities/my_math.h"
#include "../../Utilities/datatypes.h"
#include "../../Utilities/bitmanip.h"

//Timer0 REGISTERS
#define TCCR0 (*(volatile unit8_t*)(0x53))
#define TCNT0 (*(volatile unit8_t*)(0x52))
#define TIFR (*(volatile unit8_t*)(0x58))
#define TIMSK (*(volatile unit8_t*)(0x59))



void TIMER_init();//initialize Timer0
void TIMER_delay(unit16_t Delay_ms); //delay of specific amount default uses 256 prescalar


#endif /* TIMER_H_ */