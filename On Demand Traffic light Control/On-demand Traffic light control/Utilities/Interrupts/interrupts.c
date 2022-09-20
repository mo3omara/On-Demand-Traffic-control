/*
 * interrupts.c
 *
 * Created: 9/10/2022 11:03:29 AM
 *  Author: Mohamed Emara
 */ 

#include "interrupts.h"

void Interrups_control(unit8_t state_OnOff,unit8_t INT_Number, unit8_t sense)
{
	
if(state_OnOff==INT_ON)
{
	sei();//enable global interrupts
	
	switch(INT_Number)
	{
		case INT0: 
		switch(sense)//choose interrupt sense
		{
			case lowlevel:	CLEAR_BIT(MCUCR,0);	CLEAR_BIT(MCUCR,1);	break;
			case logic:		SET_BIT(MCUCR,0);	CLEAR_BIT(MCUCR,1);	break;
			case fall:		CLEAR_BIT(MCUCR,0);	SET_BIT(MCUCR,1);	break;
			case rise:		SET_BIT(MCUCR,0);	SET_BIT(MCUCR,1);	break;
			default:												break;
		}
		break;
		
		case INT1:
		switch(sense)//choose interrupt sense
		{
			case lowlevel:	CLEAR_BIT(MCUCR,2);	CLEAR_BIT(MCUCR,3);	break;
			case logic:		SET_BIT(MCUCR,2);	CLEAR_BIT(MCUCR,3);	break;
			case fall:		CLEAR_BIT(MCUCR,2);	SET_BIT(MCUCR,3);	break;
			case rise:		SET_BIT(MCUCR,2);	SET_BIT(MCUCR,3);	break;
			default:												break;
		}
		break;
		
		case INT2:
		switch(sense)//choose interrupt sense
		{
			case fall:	CLEAR_BIT(MCUCSR,6);	break;
			case rise:	SET_BIT(MCUCSR,6);		break;
			default:							break;
		}
		break;
		
		default: break;
		}
		
		SET_BIT(GICR,6);//Enable external interrupts
		
		
		}else if(state_OnOff==INT_OFF)
		{
			cli();
		}
		else{}
	
	
	
	
}


