/*
 * main.cpp
 *
 *  Created on: Mar 14, 2016
 *      Author: Gaël Porté
 */

#include <avr/io.h>
#include <util/delay.h>
//#include "main.h"
#include "ledManager.h"

int main(void)
{

	// Create ledManager
	// LedManager *m_ledManager = new LedManager;

	/* set PORTB for output*/
	DDRB = 0xFF;

	while (1)
	{
		/* set PORTB.6 high */
		PORTB = 0x20;

		_delay_ms(5500);

		/* set PORTB.6 low */
		PORTB = 0x00;

		_delay_ms(500);
	}


	return 0;
}

