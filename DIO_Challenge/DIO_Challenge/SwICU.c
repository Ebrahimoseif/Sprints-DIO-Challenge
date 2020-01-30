/*
 * SwICU.c
 *
 * Created: 1/29/2020 2:33:58 PM
 *  Author: EbrahimOseif
 */ 

#include "SwICU.h"


void SwICU_Init(EN_SwICU_Edge_t a_en_inputCaptureEdge){
	
	SwICU_SetCfgEdge(a_en_inputCaptureEdge);
	SwICU_Enable();
	timer0Init(T0_NORMAL_MODE, T0_OC0_DIS, T0_PRESCALER_1024,
	0, 0, T0_INTERRUPT_NORMAL);
	sei();
	
}

EN_SwICU_Edge_t SwICU_GetCfgEdge(void){
	
	return ( MCUCSR & 0x40 );
}

void SwICU_SetCfgEdge(EN_SwICU_Edge_t a_en_inputCaptureEdge){
	
	
	if(a_en_inputCaptureEdge == 1)
	{
		MCUCSR |= (1 << 6 );
	}
	else
	{
		MCUCSR &= ~(1 << 6 );

	}
}

void SwICU_Read(volatile uint8_t * a_pu8_capt){
	
	a_pu8_capt = timer0Read();
	
}

void SwICU_Stop(void){
	
	timer0Stop();
}

void SwICU_Start(void){
	
	timer0Start();
}

void SwICU_Enable(void){
	GICR |= (1 << 5); 
}

void SwICU_Disable(void){
	GICR &= ~(1 << 5); 
}
