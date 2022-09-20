/*
 * app.h
 *
 * Created: 9/10/2022 10:55:42 AM
 *  Author: Mohamed Emara
 */ 


#ifndef APP_H_
#define APP_H_

#include "../ECUAL/Button/button.h"
#include "../ECUAL/LED/led.h"
#include "../Utilities/Interrupts/interrupts.h"
#include "../Utilities/Timer/timer.h"

#define Nomral_Mode			0
#define Pedsedtrain_Mode	1

#define Green	0
#define Yellow	1
#define Red		2


void APP_init(void);	//call all init functions
void APP_Start(void);	//Start the logic and control




#endif /* APP_H_ */