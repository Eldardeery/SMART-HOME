/*
 * smart home.c
 *
 * Created: 8/25/2021 1:34:37 PM
 * Author : dardeery
 */ 

#include "main.h"


int main(void)
{

	INIT_SYSTEM();

	while (1) 
    {
		control_dispatcher();

    }
}

