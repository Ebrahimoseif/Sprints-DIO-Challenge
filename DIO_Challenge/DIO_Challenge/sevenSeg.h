/*
 * sevenSeg_BCD.h
 *
 *  *  Author: EbrahimOseif
 */

#ifndef SEVENSEG_H_
#define SEVENSEG_H_

#include "sevenSegConfig.h"


typedef enum En_SevenSegId_t{
	SEG_0,
	SEG_1,
}En_SevenSegId_t;

/**
 * Description:  initialize seven segment data port as output
 * @param a_segment_id
 */
void sevenSegInit(En_SevenSegId_t a_segment_id);

/**
 * Description:  enable the enable bits of the 7 segment to be able to write 
 * @param en_segment_id
 */
void sevenSegEnable(En_SevenSegId_t en_segment_id);

/**
 * Description: disable the enable bits of 7 segment 
 * @param en_segment_id
 */
void sevenSegDisable(En_SevenSegId_t en_segment_id);

/**
 * Description: writes a digit on 7 segment 
 * @param en_segment_id, digit
 */
void sevenSegWrite(En_SevenSegId_t en_segment_id, uint8_t u8_number);


#endif /* SEVENSEG_BCD_H_ */
