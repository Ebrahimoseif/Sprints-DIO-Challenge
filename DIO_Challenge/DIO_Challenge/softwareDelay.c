/*
 * softwareDelay.c
 *
 * Created: 1/17/2020 8:28:11 PM
 *  Author: EbrahimOseif
 */ 

#include "softwareDelay.h"

/**
 * Description: this delay function operate in a polling manner
 * 				don't use it with RTOSs
 * @param a_delay_in_ms: the milli-seconds
 */
void softwareDelayMs(uint32_t u32_delay_in_ms){
	/* int counter = 0 ;
		 clock cycle time  = 1/ FCPU
			1 / 8000 000 = 0.125us
	 4	INTRUCTIONS inside the loop  TAKE .500us
			
		
	uint8_t NumOfCounts = u32_delay_in_ms / ( 4 * 1 / 8000000);
			*/
		uint32_t numbersOfmsCounter = 0 ; 
		uint32_t counter1 = 0;
	for (numbersOfmsCounter = 0; numbersOfmsCounter < u32_delay_in_ms ; numbersOfmsCounter++)
	{
	 for (counter1 = 0 ; counter1 < 1000 ; counter1++)
	  {
		  asm("NOP"); // takes one clock cycle	 
	 }
  }
	
}