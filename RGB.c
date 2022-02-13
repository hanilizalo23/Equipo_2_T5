/*
 * RGB.c
 *
 *  Created on: 13 feb 2022
 *      Author: Mauricio Peralta O.
 */

void green(void)
{
	GPIO_clear_pin(GPIO_E, bit_26);
	GPIO_set_pin(GPIO_E, bit_26);
}


void blue(void)
{
	GPIO_clear_pin(GPIO_B, bit_21);
	GPIO_set_pin(GPIO_B, bit_21);
}


void purple(void)
{
	GPIO_clear_pin(GPIO_B, bit_21);
	GPIO_set_pin(GPIO_B, bit_21);
	GPIO_clear_pin(GPIO_B, bit_22);
	GPIO_set_pin(GPIO_B, bit_22);
}

void red(void)
{
	GPIO_clear_pin(GPIO_B, bit_22);
	GPIO_set_pin(GPIO_B, bit_22);
}

void yellow(void)
{
	GPIO_clear_pin(GPIO_E, bit_26);
	GPIO_set_pin(GPIO_E, bit_26);
	GPIO_clear_pin(GPIO_B, bit_22);
	GPIO_set_pin(GPIO_B, bit_22);
}


void white(void)
{
	GPIO_clear_pin(GPIO_B, bit_21);
	GPIO_set_pin(GPIO_B, bit_21);
	GPIO_clear_pin(GPIO_E, bit_26);
	GPIO_set_pin(GPIO_E, bit_26);
	GPIO_clear_pin(GPIO_B, bit_22);
	GPIO_set_pin(GPIO_B, bit_22);
}









