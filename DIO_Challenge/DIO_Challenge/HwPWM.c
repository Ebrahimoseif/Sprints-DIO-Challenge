/*
 * HwPWM.c
 *
 * Created: 1/30/2020 10:55:32 AM
 *  Author: EbrahimOseif
 */ 

#include "HwPWM.h"
#include "timers.h"

	
void HwPWMInit(void){
	
timer1Init(0x00,
(T1_OC1A_CLEAR | T1_OC1B_CLEAR),
	T1_PRESCALER_64,
		0,
		0,
		0,
		0,
		T1_POLLING);
		
		TCCR1A |= 0x03;
		TCCR1B |= 0x10;

gpioPinDirection(GPIOD, BIT4, OUTPUT);
gpioPinDirection(GPIOD, BIT5, OUTPUT);}

void HwPWMSetDuty(uint8_t a_u8_duty, uint32_t a_u32_frequency){
	
	//timer1Stop();
	uint32_t Period = 16000000/a_u32_frequency;
	uint32_t Ton = Period * (a_u8_duty/100.00);
	TCNT1 = 65536 - Period;
	OCR1A = 65536 - Period +Ton;
	OCR1B = 65536 - Period +Ton;
	timer1Start();
	 	
}
