/*
 * led.h
 *
 *  Created on: Sep 4, 2021
 *      Author: dardeery
 */

#ifndef LED_H_
#define LED_H_

#include"gpio.h"



void Init_Led(PORT_BASE PORT,uint8 PIN_NUM);
void Led_On (PORT_BASE PORT,uint8 PIN_NUM);
void Led_Off(PORT_BASE PORT,uint8 PIN_NUM);


#endif /* LED_H_ */
