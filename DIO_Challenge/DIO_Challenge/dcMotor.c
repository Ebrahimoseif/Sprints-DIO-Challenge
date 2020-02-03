/*
 * dcMotor.c
 *
 * Created: 2/3/2020 1:03:20 AM
 *  Author: EbrahimOseif
 */ 

#include "dcMotor.h"



/**
 * Description:  initialize the two motors pins as output and enable bits
 * @param	en_motor_number
 */
void MotorDC_Init(En_motorType_t en_motor_number){
	
	switch (en_motor_number) {
		case (MOT_1):
		
					gpioPinDirection(MOTOR_EN_1_GPIO, MOTOR_EN_1_BIT, OUTPUT);
					gpioPinDirection(MOTOR_OUT_1A_GPIO, MOTOR_OUT_1A_BIT, OUTPUT);
					gpioPinDirection(MOTOR_OUT_1B_GPIO, MOTOR_OUT_1B_BIT, OUTPUT);
					break;
		case (MOT_2):
					
					gpioPinDirection(MOTOR_EN_2_GPIO, MOTOR_EN_2_BIT, OUTPUT);
					gpioPinDirection(MOTOR_OUT_2A_GPIO, MOTOR_OUT_2A_BIT, OUTPUT);
					gpioPinDirection(MOTOR_OUT_2B_GPIO, MOTOR_OUT_2B_BIT, OUTPUT);
					break;
		default:
					gpioPinDirection(MOTOR_EN_1_GPIO, MOTOR_EN_1_BIT, OUTPUT);
					gpioPinDirection(MOTOR_OUT_1A_GPIO, MOTOR_OUT_1A_BIT, OUTPUT);
					gpioPinDirection(MOTOR_OUT_1B_GPIO, MOTOR_OUT_1B_BIT, OUTPUT);
					break;
		}
	
}

/**
 * Description: set the direction of the motor
 * @param en_motor_number
 * @param en_motor_dir
 */
void MotorDC_Dir(En_motorType_t en_motor_number, En_motorDir_t en_motor_dir){
	
	switch (en_motor_number) {
		
		case (MOT_1):
					switch (en_motor_dir) {
						case STOP:
								gpioPinWrite(MOTOR_OUT_1A_GPIO, MOTOR_OUT_1A_BIT, LOW);
								gpioPinWrite(MOTOR_OUT_1B_GPIO, MOTOR_OUT_1B_BIT, LOW);
								break;
						case FORWARD:
								gpioPinWrite(MOTOR_OUT_1A_GPIO, MOTOR_OUT_1A_BIT, HIGH);
								gpioPinWrite(MOTOR_OUT_1B_GPIO, MOTOR_OUT_1B_BIT, LOW);
								break;
						case BACKWARD:
								gpioPinWrite(MOTOR_OUT_1A_GPIO, MOTOR_OUT_1A_BIT, LOW);
								gpioPinWrite(MOTOR_OUT_1B_GPIO, MOTOR_OUT_1B_BIT, HIGH);
								break;
					  default:	break;
						}
					break;
		
		case (MOT_2):
					switch (en_motor_dir) {
						case STOP:
							gpioPinWrite(MOTOR_OUT_2A_GPIO, MOTOR_OUT_2A_BIT, LOW);
							gpioPinWrite(MOTOR_OUT_2B_GPIO, MOTOR_OUT_2B_BIT, LOW);
							break;
						case FORWARD:
							gpioPinWrite(MOTOR_OUT_2A_GPIO, MOTOR_OUT_2A_BIT, HIGH);
							gpioPinWrite(MOTOR_OUT_2B_GPIO, MOTOR_OUT_2B_BIT, LOW);
							break;
					   case BACKWARD:
							gpioPinWrite(MOTOR_OUT_2A_GPIO, MOTOR_OUT_2A_BIT, LOW);
							gpioPinWrite(MOTOR_OUT_2B_GPIO, MOTOR_OUT_2B_BIT, HIGH);
							break;
					 default:break;
					}
					break;
			default:break;
	}
	
}

/**
 * Description: use the polling method to drive the motor 
 * @param u8_motor_speed
 */
void MotorDC_Speed_PollingWithT0(uint8_t u8_motor_speed){
	/* frequency of 1 khz */
	timer0SwPWM(u8_motor_speed, 1 );
}

/**
 * Description: set the port value (which is PORT register)
 * @param 
 */
void MotorDC_Speed_HwPWM(uint8_t u8_motor_speed){
	
	HwPWMSetDuty(u8_motor_speed, 100);
}	
