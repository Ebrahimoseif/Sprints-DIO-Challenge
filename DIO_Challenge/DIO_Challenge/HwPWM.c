/*
 * HwPWM.c
 *
 * Created: 1/30/2020 10:55:32 AM
 *  Author: EbrahimOseif
 */ 

#include "HwPWM.h"
#include "timers.h"

	
void HwPWMInit(void){
	
timer1Init(0x00,(T1_OC1A_CLEAR | T1_OC1B_CLEAR),T1_PRESCALER_64, 0, 0, 0, 0,T1_POLLING);
		
		TCCR1A |= 0xA2;
		TCCR1B |= 0x10;
		TCNT1 = 0 ;

			gpioPinDirection(GPIOD, BIT4, OUTPUT);
			gpioPinDirection(GPIOD, BIT5, OUTPUT);}

void HwPWMSetDuty(uint8_t a_u8_duty, uint32_t a_u32_frequency){
	
		uint32_t period;
		uint16_t Prescaler = 64;
		uint8_t inRange_Flage = 0;
		uint32_t onTime; 
		
		period = FCPU / (2 * Prescaler * a_u32_frequency);
		
		while( inRange_Flage == 0)
		{
		if (period > 255 && Prescaler == 64)
			{
			Prescaler = 256;
			}
		else if (period > 255 && Prescaler == 256)
			{
			Prescaler = 1024;
			}
		else{
			inRange_Flage = 1;
			}
		period = FCPU / (2 * Prescaler * a_u32_frequency);
		}
	 /* initializing the timer values */
	 
		onTime = period * (a_u8_duty /100.00);
		ICR1 = period;
		OCR1A = onTime;
		OCR1B = onTime;
		
		 /* starting the timer */
		if (Prescaler == 64 )
		{
			TCCR1B |= T1_PRESCALER_64;
		}
		else if (Prescaler == 256)
		{
			TCCR1B |= T1_PRESCALER_256;
		}
		else{
			TCCR1B |= T1_PRESCALER_1024;
			}
			
}
