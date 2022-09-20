/*
 * app.c
 *
 * Created: 9/10/2022 10:55:32 AM
 *  Author: Mohamed Emara
 */ 
#include "app.h"

unit8_t mode=Nomral_Mode; //starts at normal mode
unit8_t Car_Next_Led=0; 
unit8_t Car_Last_Led=0; 
unit8_t Ped_Next_Led=0;
unit8_t Ped_Last_Led=0;


void APP_init(void)
{
	//Car leds
	LED_init(CAR_LED_PORT,CAR_RED_LED);
	LED_init(CAR_LED_PORT,CAR_YELLOW_LED);
	LED_init(CAR_LED_PORT,CAR_GREEN_LED);
	//Peds Leds
	LED_init(PED_LED_PORT,PED_RED_LED);
	LED_init(PED_LED_PORT,PED_YELLOW_LED);
	LED_init(PED_LED_PORT,PED_GREEN_LED);
	//Button
	BUTTON_init(BUTTON_PORT,BUTTON_PIN);
	//Timer
	TIMER_init();
	//Interrupts
	Interrups_control(INT_ON,INT0,rise);
	
}

void APP_Start(void)
{
	//check the mode
	switch(mode)
	{
		//*******************************************************************************************
		//NORMAL MODE *******************************************************************************
		case Nomral_Mode:
		LED_OFF(PED_LED_PORT,PED_GREEN_LED);
		LED_OFF(PED_LED_PORT,PED_RED_LED);
		LED_OFF(PED_LED_PORT,PED_YELLOW_LED);
		LED_OFF(CAR_LED_PORT,CAR_GREEN_LED);
		LED_OFF(CAR_LED_PORT,CAR_RED_LED);
		LED_OFF(CAR_LED_PORT,CAR_YELLOW_LED);
		
		//check which led has the turn to be on
		switch(Car_Next_Led)
		{
			case Green:
			Car_Last_Led=0;
			LED_ON(PED_LED_PORT,PED_RED_LED); //ped red on
			LED_OFF(CAR_LED_PORT,CAR_YELLOW_LED);
			LED_OFF(CAR_LED_PORT,CAR_RED_LED);
			LED_ON(CAR_LED_PORT,CAR_GREEN_LED); //green on
			TIMER_delay(5000);
			Car_Next_Led= Yellow;
			
			break;
			
			case Yellow:;
			unit8_t temp;
			temp = Car_Last_Led;
			Car_Last_Led = 1;
			LED_ON(PED_LED_PORT,PED_RED_LED); //ped red on
			LED_OFF(CAR_LED_PORT,CAR_GREEN_LED);
			LED_OFF(CAR_LED_PORT,CAR_RED_LED);
			for(int i = 0 ;i <4; i++)
			{
				LED_ON(CAR_LED_PORT,CAR_YELLOW_LED); //yellow blink
				TIMER_delay(1000);
				LED_OFF(CAR_LED_PORT,CAR_YELLOW_LED);
				TIMER_delay(250);
			}
			
			switch(temp) // Green->Yellow->Red->Yellow->Green
			{
			case Green: Car_Next_Led = Red; break;
			case Red: Car_Next_Led = Green; break;
			default: break;
			}

			break;
			
			case Red:
			Car_Last_Led=2;
			LED_ON(PED_LED_PORT,PED_RED_LED); //ped red on
			LED_OFF(CAR_LED_PORT,CAR_YELLOW_LED);
			LED_OFF(CAR_LED_PORT,CAR_GREEN_LED); 
			LED_ON(CAR_LED_PORT,CAR_RED_LED); //red on
			TIMER_delay(5000);
			Car_Next_Led=Yellow;
			
			break;
			
			default: break;
		
		}
		break;
		
		//*************************************************************************************************
		//Pedsedtrains MODE *******************************************************************************
		case Pedsedtrain_Mode: 
		LED_OFF(CAR_LED_PORT,CAR_GREEN_LED);
		LED_OFF(CAR_LED_PORT,CAR_RED_LED);
		LED_OFF(CAR_LED_PORT,CAR_YELLOW_LED);
		LED_OFF(PED_LED_PORT,PED_GREEN_LED);
		LED_OFF(PED_LED_PORT,PED_RED_LED);
		LED_OFF(PED_LED_PORT,PED_YELLOW_LED);
		
				if(Car_Last_Led == Red)
				{
				LED_OFF(CAR_LED_PORT,CAR_YELLOW_LED);
				LED_OFF(CAR_LED_PORT,CAR_GREEN_LED);
				LED_ON(CAR_LED_PORT,CAR_RED_LED); //red ped on
				LED_ON(PED_LED_PORT,PED_GREEN_LED); //green car on
				TIMER_delay(5000);
				}else if(Car_Last_Led == Green || Car_Last_Led == Yellow)
				{
				for(int i = 0 ;i <4; i++)
				{
					LED_ON(CAR_LED_PORT,CAR_YELLOW_LED); //car yellow blink
					LED_ON(PED_LED_PORT,PED_YELLOW_LED); //Ped yellow blink
					TIMER_delay(1000);
					LED_OFF(CAR_LED_PORT,CAR_YELLOW_LED);
					LED_OFF(PED_LED_PORT,PED_YELLOW_LED);
					TIMER_delay(250);
				}
				LED_ON(PED_LED_PORT,PED_GREEN_LED);
				LED_ON(CAR_LED_PORT,CAR_RED_LED);
				TIMER_delay(2000);
				Car_Next_Led=Yellow;
				Car_Last_Led=2;
				}
				mode=Nomral_Mode;
				
				
		default: break;
	}
	
}

ISR(EXT_INT0)
{
mode=Pedsedtrain_Mode;
}


/*switch(Ped_Next_Led)
				{
					case Green:
					LED_OFF(PED_LED_PORT,PED_YELLOW_LED);
					LED_OFF(PED_LED_PORT,PED_RED_LED);
					LED_ON(PED_LED_PORT,PED_GREEN_LED); //green on
					TIMER_delay(500);
					Ped_Next_Led=1;
					Ped_Last_Led=0;
					break;
					
					case Yellow:
					LED_OFF(PED_LED_PORT,PED_GREEN_LED);
					LED_OFF(PED_LED_PORT,PED_RED_LED);
					for(int i = 0 ;i <4; i++)
					{
						LED_ON(PED_LED_PORT,PED_YELLOW_LED); //yellow blink
						TIMER_delay(100);
						LED_OFF(PED_LED_PORT,PED_YELLOW_LED);
						TIMER_delay(25);
					}
					
					switch(Ped_Last_Led) // Green->Yellow->Red->Yellow->Green
					{
						case Green: Ped_Next_Led = Red;	break;
						case Red:	Ped_Next_Led = Green;	break;
						default: break;
					}
					Ped_Last_Led=1;
					break;
					
					case Red:
					LED_OFF(PED_LED_PORT,PED_YELLOW_LED);
					LED_OFF(PED_LED_PORT,PED_GREEN_LED);
					LED_ON(PED_LED_PORT,PED_RED_LED); //ped red on
					TIMER_delay(500);
					Ped_Next_Led=1;
					Ped_Last_Led=2;
					mode=Nomral_Mode;
					break;
					
					default: break;
					
				}*/