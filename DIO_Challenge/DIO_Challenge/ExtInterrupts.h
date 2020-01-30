/*
 * ExtInterrupts.h
 *
 * Created: 1/29/2020 5:17:33 PM
 *  Author: EbrahimOseif
 */ 


#ifndef EXTINTERRUPTS_H_
#define EXTINTERRUPTS_H_



typedef enum En_INT0Edge_t{
	INT0_LOW_LEVEL = 0,
	INT0_HIGH_LEVEL,
	INT0_FALLING_EDGE,
	INT0_RISING_EDGE
}En_INT0Edge_t;

typedef enum En_INT1Edge_t{
	INT1_LOW_LEVEL = 0,
	INT1_HIGH_LEVEL,
	INT1_FALLING_EDGE,
	INT1_RISING_EDGE
}En_INT1Edge_t;

typedef enum En_INT2Edge_t{
	INT2_FALLING_EDGE,
	INT2_RISING_EDGE
}En_INT2Edge_t;


#endif /* EXTINTERRUPTS_H_ */