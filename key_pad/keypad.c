<<<<<<< HEAD
/*
 * keypad.c
 *
 *  Created on: Dec 29, 2019
 *      Author: dardeery
 */
#include "keypad.h"
#include "gpio.h"

unsigned char keypad[4][4] ={{'7','8','9','/'},
							 {'4','5','6','*'},
							 {'1','2','3','-'},
							 {' ','0','=','+'}};
								 
	/*							 
unsigned char keypad[4][4] ={{'1','2','3','/'},
							 {'4','5','6','*'},
							 {'7','8','9','-'},
							 {' ','0','=','+'}};
			*/					 

unsigned char colloc, rowloc;

char keyfind()
{
	while(1)
	{
		KEY_DDR = 0xF0;           /* set port direction as input-output */
		KEY_PRT = 0xFF;

		do
		{
			KEY_PRT &= 0x0F;      /* mask PORT for column read only */
			asm("NOP");
			colloc = (KEY_PIN & 0x0F); /* read status of column */
		}while(colloc != 0x0F);
		
		do
		{
			do
			{
				_delay_ms(20);             /* 20ms key debounce time */
				colloc = (KEY_PIN & 0x0F); /* read status of column */
				}while(colloc == 0x0F);        /* check for any key press */
				
				_delay_ms (40);	            /* 20 ms key debounce time */
				colloc = (KEY_PIN & 0x0F);
			}while(colloc == 0x0F);

			/* now check for rows */
			KEY_PRT = 0xEF;            /* check for pressed key in 1st row */
			asm("NOP");
			colloc = (KEY_PIN & 0x0F);
			if(colloc != 0x0F)
			{
				rowloc = 0;
				break;
			}

			KEY_PRT = 0xDF;		/* check for pressed key in 2nd row */
			asm("NOP");
			colloc = (KEY_PIN & 0x0F);
			if(colloc != 0x0F)
			{
				rowloc = 1;
				break;
			}
			
			KEY_PRT = 0xBF;		/* check for pressed key in 3rd row */
			asm("NOP");
			colloc = (KEY_PIN & 0x0F);
			if(colloc != 0x0F)
			{
				rowloc = 2;
				break;
			}

			KEY_PRT = 0x7F;		/* check for pressed key in 4th row */
			asm("NOP");
			colloc = (KEY_PIN & 0x0F);
			if(colloc != 0x0F)
			{
				rowloc = 3;
				break;
			}
		}

		if(colloc == 0x0E)
		return(keypad[rowloc][0]);
		else if(colloc == 0x0D)
		return(keypad[rowloc][1]);
		else if(colloc == 0x0B)
		return(keypad[rowloc][2]);
		else
		return(keypad[rowloc][3]);
	}












/*
uint8 key_row[]={row_0,row_1,row_2,row_3};
uint8 key_col[]={col_0,col_1,col_2,col_3};
void keypad_init(void)
{
	SET_PIN_DIRECTION(keypad_port,row_0,IN);
	SET_PIN_DIRECTION(keypad_port,row_1,IN);
	SET_PIN_DIRECTION(keypad_port,row_2,IN);
	SET_PIN_DIRECTION(keypad_port,row_3,IN);

	SET_PIN_DIRECTION(keypad_port,col_0,OUT);
	SET_PIN_DIRECTION(keypad_port,col_1,OUT);
	SET_PIN_DIRECTION(keypad_port,col_2,OUT);
	SET_PIN_DIRECTION(keypad_port,col_3,OUT);

	WRITE_PORT_VAL(keypad_port,0xff);
}
uint8 keypad_get_key (void)
{
	uint8 i,j;
	for(i=0;i<4;i++)
	{
		WRITE_PIN_HIGH(keypad_port,key_col[0]);
		WRITE_PIN_HIGH(keypad_port,key_col[1]);
		WRITE_PIN_HIGH(keypad_port,key_col[2]);
		WRITE_PIN_HIGH(keypad_port,key_col[3]);

		WRITE_PIN_LOW(keypad_port,key_col[i]);
		for(j=0;j<4;j++)
		{
			if(!(READ_PORT(keypad_port)&(1<<key_row[j])))
			{
				while(!(READ_PORT(keypad_port)&(1<<key_row[j])))
				{
					switch(i)
					{
					case (0):
	{
						if(j==0)  return '7';
						else if(j==1)  return '4';
						else if(j==2)  return '1';
						else if(j==3)  return '?';
						break ;
	}
					case (1):
	{
						if(j==0)  return '8';
						else if(j==1)  return '5';
						else if(j==2)  return '2';
						else if(j==3)  return '0';
						break ;
	}
					case (2):
	{
						if(j==0)  return '9';
						else if(j==1)  return '6';
						else if(j==2)  return '3';
						else if(j==3)  return '=';
						break ;
	}

					case (3):
	{
						if(j==0)  return '/';
						else if(j==1)  return '*';
						else if(j==2)  return '-';
						else if(j==3)  return '+';
						break ;
	}
					}
				}
			}
		}
	}
	return 'A';
}
=======
/*
 * keypad.c
 *
 *  Created on: Dec 29, 2019
 *      Author: dardeery
 */
#include "keypad.h"
#include "gpio.h"

unsigned char keypad[4][4] ={{'7','8','9','/'},
							 {'4','5','6','*'},
							 {'1','2','3','-'},
							 {' ','0','=','+'}};
								 
	/*							 
unsigned char keypad[4][4] ={{'1','2','3','/'},
							 {'4','5','6','*'},
							 {'7','8','9','-'},
							 {' ','0','=','+'}};
			*/					 

unsigned char colloc, rowloc;

char keyfind()
{
	while(1)
	{
		KEY_DDR = 0xF0;           /* set port direction as input-output */
		KEY_PRT = 0xFF;

		do
		{
			KEY_PRT &= 0x0F;      /* mask PORT for column read only */
			asm("NOP");
			colloc = (KEY_PIN & 0x0F); /* read status of column */
		}while(colloc != 0x0F);
		
		do
		{
			do
			{
				_delay_ms(20);             /* 20ms key debounce time */
				colloc = (KEY_PIN & 0x0F); /* read status of column */
				}while(colloc == 0x0F);        /* check for any key press */
				
				_delay_ms (40);	            /* 20 ms key debounce time */
				colloc = (KEY_PIN & 0x0F);
			}while(colloc == 0x0F);

			/* now check for rows */
			KEY_PRT = 0xEF;            /* check for pressed key in 1st row */
			asm("NOP");
			colloc = (KEY_PIN & 0x0F);
			if(colloc != 0x0F)
			{
				rowloc = 0;
				break;
			}

			KEY_PRT = 0xDF;		/* check for pressed key in 2nd row */
			asm("NOP");
			colloc = (KEY_PIN & 0x0F);
			if(colloc != 0x0F)
			{
				rowloc = 1;
				break;
			}
			
			KEY_PRT = 0xBF;		/* check for pressed key in 3rd row */
			asm("NOP");
			colloc = (KEY_PIN & 0x0F);
			if(colloc != 0x0F)
			{
				rowloc = 2;
				break;
			}

			KEY_PRT = 0x7F;		/* check for pressed key in 4th row */
			asm("NOP");
			colloc = (KEY_PIN & 0x0F);
			if(colloc != 0x0F)
			{
				rowloc = 3;
				break;
			}
		}

		if(colloc == 0x0E)
		return(keypad[rowloc][0]);
		else if(colloc == 0x0D)
		return(keypad[rowloc][1]);
		else if(colloc == 0x0B)
		return(keypad[rowloc][2]);
		else
		return(keypad[rowloc][3]);
	}












/*
uint8 key_row[]={row_0,row_1,row_2,row_3};
uint8 key_col[]={col_0,col_1,col_2,col_3};
void keypad_init(void)
{
	SET_PIN_DIRECTION(keypad_port,row_0,IN);
	SET_PIN_DIRECTION(keypad_port,row_1,IN);
	SET_PIN_DIRECTION(keypad_port,row_2,IN);
	SET_PIN_DIRECTION(keypad_port,row_3,IN);

	SET_PIN_DIRECTION(keypad_port,col_0,OUT);
	SET_PIN_DIRECTION(keypad_port,col_1,OUT);
	SET_PIN_DIRECTION(keypad_port,col_2,OUT);
	SET_PIN_DIRECTION(keypad_port,col_3,OUT);

	WRITE_PORT_VAL(keypad_port,0xff);
}
uint8 keypad_get_key (void)
{
	uint8 i,j;
	for(i=0;i<4;i++)
	{
		WRITE_PIN_HIGH(keypad_port,key_col[0]);
		WRITE_PIN_HIGH(keypad_port,key_col[1]);
		WRITE_PIN_HIGH(keypad_port,key_col[2]);
		WRITE_PIN_HIGH(keypad_port,key_col[3]);

		WRITE_PIN_LOW(keypad_port,key_col[i]);
		for(j=0;j<4;j++)
		{
			if(!(READ_PORT(keypad_port)&(1<<key_row[j])))
			{
				while(!(READ_PORT(keypad_port)&(1<<key_row[j])))
				{
					switch(i)
					{
					case (0):
	{
						if(j==0)  return '7';
						else if(j==1)  return '4';
						else if(j==2)  return '1';
						else if(j==3)  return '?';
						break ;
	}
					case (1):
	{
						if(j==0)  return '8';
						else if(j==1)  return '5';
						else if(j==2)  return '2';
						else if(j==3)  return '0';
						break ;
	}
					case (2):
	{
						if(j==0)  return '9';
						else if(j==1)  return '6';
						else if(j==2)  return '3';
						else if(j==3)  return '=';
						break ;
	}

					case (3):
	{
						if(j==0)  return '/';
						else if(j==1)  return '*';
						else if(j==2)  return '-';
						else if(j==3)  return '+';
						break ;
	}
					}
				}
			}
		}
	}
	return 'A';
}
>>>>>>> 50770696eabc6891b153c0666b8d9d5b1191c063
*/