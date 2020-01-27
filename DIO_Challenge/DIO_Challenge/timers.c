/*
 * timers.c
 *
 * Created: 1/20/2020 3:24:02 PM
 *  Author: EbrahimOseif
 */ 

#include "timers.h"



#define FULL_DUTY 100
#define FCPU 16000000UL



uint8_t prescaler = T0_NO_CLOCK;
uint8_t T1_prescaler;
uint8_t T2_prescaler;


/*===========================Timer0 Control===============================*/
/**
 * Description:
 * @param control
 * @param initialValue
 * @param outputCompare
 * @param interruptMask
 */
void timer0Init(En_timer0Mode_t en_mode, En_timer0OC_t en_OC0,
				En_timer0perscaler_t en_prescal,
			    uint8_t u8_initialValue, uint8_t u8_outputCompare,
			    En_timer0Interrupt_t en_interruptMask){
					
					
								
				TCCR0 |= en_mode | en_OC0 ;
				 
				timer0Set(u8_initialValue);
				
				//if( en_mode == T0_COMP_MODE){
					 OCR0 = u8_outputCompare;
				//}
				prescaler = en_prescal;
				TIMSK |= en_interruptMask;
					
	}				
					
				

/**
 * Description: set the value of timer/counter register 
 * @param value 
 */
void timer0Set(uint8_t u8_value){
	
	TCNT0 = u8_value;
	
}

/**
 * Description: read the value of timer/counter register 
 * @return uint8_t value
 */
uint8_t timer0Read(void){
	
	return TCNT0;
}

/**
 * Description: start the the timer 
 */
void timer0Start(void){
	
	TCCR0 |= prescaler;
}

/**
 * Description: stop the timer 
 */
void timer0Stop(void){
	/* clear the first three bits to provide no clock to the timer */
	
		TCCR0 &= T0_NO_CLOCK;
}

/**
 * Description: 
 * @param delay
 */
void timer0DelayMs(uint16_t u16_delay_in_ms){
		
			//uint16_t overflows;
			//clockCycleTime =    prescaler / FREQUENCY;
			//ticksNeeded =  u16_delay_in_ms  / clockCycleTime;
			//overflows =  u16_delay_in_ms * FREQUENCY / (1000 * 255 *prescaler);
		
		timer0Start();
		while(u16_delay_in_ms--){
			
			timer0Set(6); // Preload with 256 - 250 counts
			while(!(TIFR & (1 << 0)));
			TIFR |= (1 << 0); // clear with writing one 
		}
		timer0Stop();
}

/*
 * user defined
 */
void timer0DelayUs(uint32_t u32_delay_in_us);

/**
 * Description:
 * @param dutyCycle
 */
void timer0SwPWM(uint8_t u8_dutyCycle,uint8_t u8_frequency){
		
		uint16_t pwmTicks;
		uint8_t onTime ;
		pwmTicks = FCPU / (u8_frequency * 1000 );
		onTime = u8_dutyCycle * pwmTicks / 100;
		
		timer0Init(T0_NORMAL_MODE, T0_OC0_DIS, T0_PRESCALER_8,
				0, onTime, T0_INTERRUPT_NORMAL | T0_INTERRUPT_CMP);
		
		//OCR0 = onTime;
		timer0Start();
		
		
		/*OCR0*/
		
}









/*===========================Timer1 Control===============================*/
/**
 * Description:
 * @param controlA
 * @param controlB
 * @param initialValue
 * @param outputCompare
 * @param interruptMask
 */
void timer1Init(En_timer1Mode_t en_mode,En_timer1OC_t en_OC,
				En_timer1perscaler_t en_prescal, uint16_t u16_initialValue,
			    uint16_t u16_outputCompareA, uint16_t u16_outputCompareB,
				uint16_t u16_inputCapture, En_timer1Interrupt_t en_interruptMask){
					
					
						TCCR1 |= en_mode | en_OC ;
						
						timer1Set(u16_initialValue);
								
						T1_prescaler = en_prescal;
						
						OCR1A = u16_outputCompareA;
						OCR1B = u16_outputCompareB;
						ICR1 = u16_inputCapture;
						TIMSK |= en_interruptMask;
				}

/**
 * Description:
 * @param value
 */
void timer1Set(uint16_t value){
	TCNT1 = value;
}

/**
 * Description:
 * @return
 */
uint16_t timer1Read(void){
	return TCNT1;
}

/**
 * Description:
 */
void timer1Start(void){
	TCCR1B |= T1_prescaler;
}

/**
 * Description:
 */
void timer1Stop(void){
	TCCR1B &= ~((1 << 2) | (1 << 1) | (1 << 0));
}

/**
 * Description:
 * @param delay
 */
void timer1DelayMs(uint16_t u32_delay_in_ms){
	// Tick interval = 4 uS @ 16 MHz DIV_BY_64
	// 1 mS = 250 ticks.

	
		timer1Start();
		while(u32_delay_in_ms--){
			
			timer1Set(65286); // Preload with 65536 -250counts
			
			while(!(TIFR & (1 << 2)));
			TIFR |= (1 << 2);
		}
		timer1Stop();
	}	
	/*
 * user defined
 */
void timer1DelayUs(uint32_t u32_delay_in_us);

/**
 * Description:
 * @param dutyCycle
 */
void timer1SwPWM(uint8_t u8_dutyCycle,uint8_t u8_frequency);





/*===========================Timer2 Control===============================*/
/**
 * Description:
 * @param control
 * @param initialValue
 * @param outputCompare
 * @param interruptMask
 */
void timer2Init(En_timer2Mode_t en_mode,En_timer2OC_t en_OC,
				En_timer2perscaler_t en_prescal, uint8_t u8_initialValue,
			    uint8_t u8_outputCompare, uint8_t u8_assynchronous,
			    En_timer2Interrupt_t en_interruptMask){
					
									
									TCCR2 |= en_mode | en_OC ;
									
									timer2Set(u8_initialValue);
									
									if( en_mode == T0_COMP_MODE){
										OCR2 = u8_outputCompare;
									}
									T2_prescaler  = en_prescal;
									TIMSK |= en_interruptMask;
									
				}
/**
 * Description:
 * @param value
 */
void timer2Set(uint8_t u8_a_value){
	TCNT2 = u8_a_value;
}
/**
 * Description:
 * @return
 */
uint8_t timer2Read(void){
	 return TCNT2;
}

/**
 * Description:
 */
void timer2Start(void){
	TCCR2 |= T2_prescaler;
}

/**
 * Description:
 */
void timer2Stop(void){
	TCCR2 &= T2_NO_CLOCK;
}

/**
 * Description:
 * @param delay
 */
void timer2DelayMs(uint16_t u16_delay_in_ms){
	
	timer2Start();
	while(u16_delay_in_ms--){
		
		timer2Set(6); // Preload with 256 - 250 counts
		
		while(!(TIFR & (1 << 6)));
		TIFR |= (1 << 6); // clear with writing one
	}
	timer2Stop();
}

/*
 * user defined
 */
void timer2DelayUs(uint32_t u16_delay_in_us);

/**
 * Description:
 * @param dutyCycle
 */
void timer2SwPWM(uint8_t u8_dutyCycle,uint8_t u8_frequency);




// ISR(t0_){
// 	
// 	static uint8_t counter= 0 ; // it will be erased during build
// 	
// 	counter++;
// 	
// 	if (counter == g_duty)
// 	{
// 		clearbit
// 	}
// 	else if (counter == FULL_DUTY )
// 	{
// 		setbit
// 		counter = 0 ;
// 	}
// }