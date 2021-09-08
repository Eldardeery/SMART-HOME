<<<<<<< HEAD
/*
 * led.c
 *
 *  Created on: Sep 4, 2021
 *      Author: dardeery
 */

#include "led.h"

void Init_Led(PORT_BASE PORT,uint8 PIN_NUM)
{
	SET_PIN_DIRECTION(PORT, PIN_NUM, OUT);
}
void Led_On (PORT_BASE PORT,uint8 PIN_NUM)
{
	Set_bit(PORT,PIN_NUM);

}

void Led_Off(PORT_BASE PORT,uint8 PIN_NUM)
{
	Clear_bit(PORT,PIN_NUM);

}
=======
/*
 * led.c
 *
 *  Created on: Sep 4, 2021
 *      Author: dardeery
 */

#include "led.h"

void Init_Led(PORT_BASE PORT,uint8 PIN_NUM)
{
	SET_PIN_DIRECTION(PORT, PIN_NUM, OUT);
}
void Led_On (PORT_BASE PORT,uint8 PIN_NUM)
{
	Set_bit(PORT,PIN_NUM);

}

void Led_Off(PORT_BASE PORT,uint8 PIN_NUM)
{
	Clear_bit(PORT,PIN_NUM);

}
>>>>>>> 50770696eabc6891b153c0666b8d9d5b1191c063
