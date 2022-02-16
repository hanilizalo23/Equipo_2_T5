/*
 * Delay.c
 *
 *  Created on: 15/02/2022
 *  	Author: PhD. José Luis Pizano Escalante
 *      Modified by: Nelida Paulina Hernández Moya and Mauricio Peralta Osorio
 */

#include <stdio.h>
#include <stdint.h>

void delay(uint32_t delay) /**Counter for wasting time*/
{
	volatile uint32_t j;

	for(j = delay; j > 0; j--)
	{
		__asm("nop");
	}
}
