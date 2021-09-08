<<<<<<< HEAD
/*
 * GccApplication5.c
 *
 * Created: 8/25/2021 1:33:32 PM
 * Author : dardeery
 */ 
#include <avr/io.h>
#include <util/delay.h>
#include "lcd.h"
#include"keypad.h"
int main()
{

	lcd_init();
	lcd_goto_xy(1,1);
	lcd_send_str("press key");
	lcd_goto_xy(1,2);
	while(1)
	{
		lcd_send_ch(keyfind());
		lcd_goto_xy(1,2);
	}
}
=======
/*
 * GccApplication5.c
 *
 * Created: 8/25/2021 1:33:32 PM
 * Author : dardeery
 */ 
#include <avr/io.h>
#include <util/delay.h>
#include "lcd.h"
#include"keypad.h"
int main()
{

	lcd_init();
	lcd_goto_xy(1,1);
	lcd_send_str("press key");
	lcd_goto_xy(1,2);
	while(1)
	{
		lcd_send_ch(keyfind());
		lcd_goto_xy(1,2);
	}
}
>>>>>>> 50770696eabc6891b153c0666b8d9d5b1191c063
