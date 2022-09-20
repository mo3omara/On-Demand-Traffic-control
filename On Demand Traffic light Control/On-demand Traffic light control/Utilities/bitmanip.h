/*
 * bitmanip.h
 *
 * Created: 9/10/2022 10:50:54 AM
 *  Author:  Mohamed Emara
 */ 


#ifndef BITMANIP_H_
#define BITMANIP_H_

#define CLEAR_BIT(Register,Bit)		Register&=~(1<<Bit)
#define SET_BIT(Register,Bit)		Register|=(1<<Bit)
#define TOGGLE_BIT(Register,Bit)	Register^=(1<<Bit)
#define READ_BIT(Register,Bit)		((Register&(1<<Bit))>>Bit)

#endif /* BITMANIP_H_ */