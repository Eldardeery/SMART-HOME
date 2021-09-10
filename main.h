/*
 * main.h
 *
 * Created: 9/8/2021 3:08:23 PM
 *  Author: dardeery
 */ 


#ifndef MAIN_H_
#define MAIN_H_

#include <util/delay.h>
#include <avr/io.h>

#include "gpio.h"
#include "ext_interrupt.h"
#include "lcd.h"
#include "SPI_Module.h"
#include "timer_module.h"
#include "led.h"
#include "EEPROM.H"


/*this function is used to initiate all modules in system*/
void INIT_SYSTEM(void);
/* is considered the dispatcher of control*/
void control_dispatcher();
/* sub control of room1*/
void control_room1(void);
/* sub control of room2*/
void control_room2(void);
/*to save password in eepom*/
bool_t get_password(void);



LED_CONFIG room1 ={PORTD_T,6};
LED_CONFIG room2 ={PORTD_T,7};



void INIT_SYSTEM(void)
{
	lcd_init();
	Init_Led(&room1);
	Init_Led(&room2);
	EEprom_Init();
}


void control_dispatcher()
{
	bool_t  check = E_FALSE;
	lcd_goto_xy(1,1);
	lcd_send_str("enter password");

	check = get_password();


	if(check != E_TRUE)
	{
	lcd_send_cmnd(lcd_clear);
	lcd_goto_xy(1,1);
	lcd_send_str("password error					");

	}

else
{
	lcd_goto_xy(1,1);
	lcd_send_str("1=Room1   2=Room2");
	uint8 pressed_key =keyfind();
	lcd_goto_xy(1,2);
	lcd_send_ch(pressed_key);	
	
	lcd_goto_xy(1,2);
	if (pressed_key ==49)
	{
		lcd_send_str("control room 1");
		control_room1();
	} 
	else if (pressed_key ==50)
	{
		lcd_send_str("control room 2");
		control_room2();		
	}
	else
	lcd_send_str("input error			");
}	

}

/*this function is used to control in rooms if selected*/

void control_room1(void)
{
	uint8 pressed = 0;
	lcd_send_cmnd(lcd_clear);			   // clear lcd
	lcd_goto_xy(1,2);
	lcd_send_str("press 1=off 2=on			");
	pressed =keyfind();
	
	if (pressed == 49)
	{
		lcd_send_str("room off			");	
		Led_Off(&room1);
	} 
	else if(pressed == 50)
	{
		Led_On(&room1);
		lcd_send_str("room on			");		
	}
	else 
	lcd_send_str("input error			");
}

void control_room2(void)
{
	uint8 pressed = 0;
	
	lcd_goto_xy(1,1);
	lcd_send_str("press 1=off 2=on			");
	pressed =keyfind();
	
	if (pressed == 49)
	{
		Led_Off(&room2);
		lcd_goto_xy(1,1);
		lcd_send_str("room off			");
	}
	else if(pressed == 50)
	{
		Led_On(&room2);
		lcd_goto_xy(1,1);
		lcd_send_str("room on			");
	}
	else
	lcd_goto_xy(1,1);
	lcd_send_str("input error			");
	
}

bool_t get_password(void)
{
	bool_t return_value = E_FALSE;
	uint8 pass[3]={'0','0','0','0'};

	uint8 enter_pass[3],i,j;
	EEprom_Write_Data(0x100,pass[3]);

	for (i=0; i<4; i++)
		{
			enter_pass[i] =keyfind();
		}
	for (j=0; j<4; j++)
{
	if (pass[j] !=enter_pass[j])
	{
		return_value = E_FALSE;
	break;
	} 
	else
	{
		return_value = E_TRUE;
	}
}
return return_value;

}

#endif /* MAIN_H_ */