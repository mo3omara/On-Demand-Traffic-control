/*
 * timer.c
 *
 * Created: 9/10/2022 11:01:07 AM
 *  Author: Mohamed Emara
 */
#include "timer.h"

 
 	void TIMER_init()
	 {
	TCCR0 = 0x00; //normal mode
	}
	
void TIMER_delay(unit16_t Delay_ms)
{
	SET_BIT(TCCR0,2); //set 256 prescaler
	
	unit16_t No_of_Overflows,Initial_Time;
	double Max_Delay,TICKS;
	unit32_t Overflows=0;
	
	TICKS = 256.0/1000.0; //ms    
	Max_Delay= 65.536; //ms		
	
	if(Delay_ms<Max_Delay)
	{
		Initial_Time = (Max_Delay-Delay_ms)/TICKS;
		No_of_Overflows = 1;
		
	}else if(Delay_ms == (int)Max_Delay)
	{
		Initial_Time=0;
		No_of_Overflows=1;
	}else
	{
		No_of_Overflows = mceil((double)Delay_ms ,Max_Delay);
		Initial_Time = 256 - ((double)Delay_ms/TICKS)/No_of_Overflows;
	}
	
	TCNT0 = Initial_Time;
	while(Overflows<No_of_Overflows)
	{
		while(READ_BIT(TIFR,0)==0);	//busy wait
		SET_BIT(TIFR,0);			//clear overflow flag
		Overflows++;				//increment counter
	}
	
	TCCR0 = 0x00;	//Timer stop
}