/*
 * pushButton.c
 *
 * Created: 1/17/2020 7:40:52 PM
 *  Author: EbrahimOseif
 */ 
 
 #include "pushButton.h"
 
/**
 * Description: Initialize the BTN_x Pin state (where x 0, 1, 2, 3) to Input
 * @param btn_id: The btn to be initialized and it takes
 * 				  one of the enum (En_buttonId) parameters
 *
 */
void pushButtonInit(En_buttonId_t en_butotn_id){
	
	switch(en_butotn_id){
		
		case BTN_0:
				gpioPinDirection( BTN_0_GPIO, BTN_0_BIT, INPUT );
				break;
		case BTN_1:
				gpioPinDirection( BTN_1_GPIO, BTN_1_BIT, INPUT );
				break;
		case BTN_2:
				gpioPinDirection( BTN_2_GPIO, BTN_2_BIT, INPUT );
				break;
		case BTN_3:
				gpioPinDirection( BTN_3_GPIO, BTN_3_BIT, INPUT );
				break;
		default:break;

	}
}
/**
 * Description: read all BTN_x (where x 0, 1, 2, 3) states and store it in the program
 *
 * @note : this function must be called in the system tick handler or in the super loop handler
 */
void pushButtonUpdate(void);
/**
 * Description: read BTN_x (where x 0, 1, 2, 3) state which is stored in the program
 * 				in the update function
 *
 */
En_buttonStatus_t pushButtonGetStatus(En_buttonId_t en_butotn_id){
		
	uint8_t current_state = 0;
		
	switch(en_butotn_id){
		
		case BTN_0:
				current_state = gpioPinRead( BTN_0_GPIO, BTN_0_BIT );
				break;
		case BTN_1:
				current_state =	gpioPinRead( BTN_1_GPIO, BTN_1_BIT );
				break;
		case BTN_2:
				current_state = gpioPinRead( BTN_2_GPIO, BTN_2_BIT );
				break;
		case BTN_3:
				current_state = gpioPinRead( BTN_3_GPIO, BTN_3_BIT );
				break;
		default:break;
	}
	return current_state;
}