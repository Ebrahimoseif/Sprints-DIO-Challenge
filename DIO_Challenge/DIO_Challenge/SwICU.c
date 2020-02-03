/*
 * SwICU.c
 *
 * Created: 1/29/2020 2:33:58 PM
 *  Author: EbrahimOseif
 */ 

#include "SwICU.h"

 uint8_t SwICU_overflowCounter;
 uint8_t SwICU_Reading;




void SwICU_Init(EN_SwICU_Edge_t a_en_inputCaptureEdge){
	
	SwICU_SetCfgEdge(a_en_inputCaptureEdge);
	
	SwICU_Enable();
	
	timer0Init(T0_NORMAL_MODE, T0_OC0_DIS, T0_PRESCALER_1024,
				0, 0, T0_INTERRUPT_NORMAL);
	sei();
	
}

EN_SwICU_Edge_t SwICU_GetCfgEdge(void){
	
	return ( MCUCSR & ICS2_MASK );
}

void SwICU_SetCfgEdge(EN_SwICU_Edge_t a_en_inputCaptureEdge){
	
	
	if(a_en_inputCaptureEdge == 1)
	{
		MCUCSR |= (1 << ICS2_PIN );
	}
	else
	{
		MCUCSR &= ~(1 << ICS2_PIN );

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
	GICR |= (1 << INT2_EN_BIT ); 
}

void SwICU_Disable(void){
	GICR &= ~(1 << INT2_EN_BIT); 
}

/* SW ICU application */

ISR( INT2_vect) {
	
	static uint8_t edgeDetect = SwICU_EdgeRisiging;
	
	if (edgeDetect == SwICU_EdgeRisiging )
	{

		SwICU_Start();
		
		GICR &= ~(1 << INT2_EN_BIT);
		SwICU_SetCfgEdge(SwICU_EdgeFalling);
		GICR |= (1 <<  INT2_EN_BIT);
		
		edgeDetect = SwICU_EdgeFalling;	
	}
	
	else if (edgeDetect == SwICU_EdgeFalling )
	{
		SwICU_Stop();
		
		SwICU_Reading = TCNT0;
		//	TCNT0 = 0;
		GICR &= ~(1 << INT2_EN_BIT);
		SwICU_SetCfgEdge(SwICU_EdgeRisiging);
		GICR |= (1 <<  INT2_EN_BIT);
		
		edgeDetect = SwICU_EdgeRisiging;
	}
}

ISR(TIMER0_OVF_vect){
	
	SwICU_overflowCounter++;
}
/* End of SW ICU application */
