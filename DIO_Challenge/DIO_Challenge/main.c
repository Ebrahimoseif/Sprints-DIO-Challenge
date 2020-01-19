/*
 * DIO_Challenge.c
 *
 * Created: 1/17/2020 1:56:15 PM
 * Author : EbrahimOseif
 */ 

#include "led.h"
#include "pushButton.h"
#include "sevenSeg.h"
#include "softwareDelay.h"


void REQ1_Start(void);
void REQ2_Start(void);
void REQ3_Start(void);

/* prototypes of	REQ3 functions */

void Go_State(void);
void Ready_State(void);
void Stop_State(void);

int main(void)
{
	/* dual inline package switch to choose the requirement to show */
	
	uint8_t REQ_Select = 0;
	
	gpioPinDirection(GPIOA, (BIT5 | BIT6 | BIT7), INPUT);
	gpioPortWrite(GPIOA, (BIT5 | BIT6 | BIT7));
	
	REQ_Select = gpioPortRead(GPIOA);
	
	switch(REQ_Select)
	{
		case 192: //110
			REQ1_Start();
			break;
		case 160: //101
			REQ2_Start();
			break;
		case 96:// 011
			REQ3_Start();
			break;
		default: break;
	}
    while (1) 
    {
    }
}




/**		requirement 1 
 * Description: makes a 00-99 count up counter using the two seven-segment
 displays with a 1-second delay from count to count
 * 
 *
 */
void REQ1_Start(void)
{
	sevenSegInit(SEG_0);
	sevenSegInit(SEG_1);
	uint8_t sevSegNumber = 0;
	while(1){
		for ( sevSegNumber = 0; sevSegNumber < 100 ; sevSegNumber++ )
		{
			for (int cnt=0; cnt<10; cnt++)
			{
				sevenSegEnable(SEG_0);
				sevenSegWrite(SEG_0, sevSegNumber / 10 );
				softwareDelayMs(50);
				sevenSegDisable(SEG_0);
				
				
				sevenSegEnable(SEG_1);
				sevenSegWrite(SEG_1, sevSegNumber % 10 );
				softwareDelayMs(50);
				sevenSegDisable(SEG_1);
			}
		}
	}
}
/**		requirement 2 

		button 1 is pressed, LED 1 will be on and stay lit for 1 sec then off.
		button 1 is pressed and released twice and the time between the first and
		second presses is less than 1s, the LED 1 will be on for 2 seconds then off
		If the time between them is more than 1s then the led will be turned off after 1s
 */
void REQ2_Start(void)
{
	Led_Init(LED_1);
	
	uint8_t pressCounts = 0 ;
	uint8_t internalPress = 0;
	
	while(1){
		pressCounts = 0 ;
		internalPress = 0;
		if (pushButtonGetStatus(BTN_1) == Prepressed)
		{
			softwareDelayMs(20);
			if (pushButtonGetStatus(BTN_1) == Prepressed)
			{
				if (pressCounts == 0)
				{
					pressCounts++;
					Led_On(LED_1);
					/* break the blocking time to be able to listen */
					
							for (int i = 0; i < 5; i++){
								
									softwareDelayMs(200);
								if (pushButtonGetStatus(BTN_1) == Prepressed){
										internalPress = 1;
											}
										  }
					
											if (internalPress == 0)
												{
													pressCounts = 0;
												}else {
														pressCounts++;
														softwareDelayMs(1000);
														}
					}
				} else {
				Led_Off(LED_1);
			}
			} else {
			Led_Off(LED_1);
		}
}

}


/**		requirement 3 
 * Description: Make a periodic state machine that changes with time (1 second) 
 with no external input.
  The state machine: GO->Stop->Get Ready->Go
 * 
 *
 */

void REQ3_Start(void)
{
	Led_Init(LED_1);
	Led_Init(LED_2);
	Led_Init(LED_3);
	
	uint8_t State = 0;
	for (;;)
	{
		switch(State){
			case 0:
			Go_State();
			State = 1;
			break;
			case 1:
			Ready_State();
			State = 2;
			break;
			case 2:
			Stop_State();
			State = 0;
			break;
			default: break;
		}
	}
	
}

void Go_State(void)
{
	Led_On(LED_1);
	softwareDelayMs(1000);
	Led_Off(LED_1);
}



void Ready_State(void)
{
	Led_On(LED_2);
	softwareDelayMs(1000);
	Led_Off(LED_2);
}


void Stop_State(void)
{
	Led_On(LED_3);
	softwareDelayMs(1000);
	Led_Off(LED_3);

}
