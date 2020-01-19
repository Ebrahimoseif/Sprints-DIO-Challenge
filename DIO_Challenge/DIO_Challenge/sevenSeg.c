/*
 * sevenSeg.c
 *
 * Created: 1/17/2020 8:30:42 PM
 *  Author: EbrahimOseif
 */ 

#include "sevenSeg.h"

/**
 * Description:  initialize seven segment data port as output
 * @param a_segment_id
 */
void sevenSegInit(En_SevenSegId_t a_segment_id){
	
	gpioPortDirection(SEG_BCD_GPIO, OUTPUT);
	
	switch(a_segment_id){
		
		case SEG_0:
				gpioPinDirection(SEG_EN1_GPIO, SEG_EN1_BIT, OUTPUT);
				break;
				
		case SEG_1:
				gpioPinDirection(SEG_EN2_GPIO, SEG_EN2_BIT, OUTPUT);
		break;
		
		default: break;
	}
}
/**
 * Description:  enable the enable bits of the 7 segment to be able to write 
 * @param en_segment_id
 */
void sevenSegEnable(En_SevenSegId_t en_segment_id){
	
	switch(en_segment_id){
		
		case SEG_0:
					gpioPinWrite(SEG_EN1_GPIO, SEG_EN1_BIT, HIGH);
					break;
		case SEG_1:
					gpioPinWrite(SEG_EN2_GPIO, SEG_EN2_BIT, HIGH);
					break;
		default: break; 
		}
}

/**
 * Description: disable the enable bits of 7 segment 
 * @param en_segment_id
 */
void sevenSegDisable(En_SevenSegId_t en_segment_id){
	
		switch(en_segment_id){
			
			case SEG_0:
					gpioPinWrite(SEG_EN1_GPIO, SEG_EN1_BIT, LOW);
					break;
			case SEG_1:
					gpioPinWrite(SEG_EN2_GPIO, SEG_EN2_BIT, LOW);
					break;
			default: break;
		}
}

/**
 * Description: writes a digit on 7 segment 
 * @param en_segment_id, digit
 */
void sevenSegWrite(En_SevenSegId_t en_segment_id , uint8_t digit ){
	
	switch(en_segment_id){
		
		case SEG_0:
					gpioPortWrite(SEG_BCD_GPIO, LOW);
					gpioPortWrite(SEG_BCD_GPIO, 0x0F & digit);
					break;
		case SEG_1:
					gpioPortWrite(SEG_BCD_GPIO, LOW);
					gpioPortWrite(SEG_BCD_GPIO, 0x0F & digit);
					break;
		default: break;
	}
}

