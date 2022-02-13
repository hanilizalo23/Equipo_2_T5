/**
	\file
	\brief
		This is the source file for the GPIO device driver for Kinetis K64.
		It contains all the implementation for configuration functions and runtime functions.
		i.e., this is the application programming interface (API) for the GPIO peripheral.
	\author Nelida Paulina Hernández Moya
	\date	18/02/2019
	\todo
	    Interrupts are not implemented in this API implementation.
 */
#include <stdio.h>
#include <stdint.h>
#include "MK64F12.h"
#include "GPIO.h"
#include "bits.h"

uint8_t GPIO_clock_gating(gpio_port_name_t port_name)
{
	switch(port_name)/** Selecting the GPIO for clock enabling*/
		{
			case GPIO_A: /** GPIO A is selected*/
				SIM->SCGC5 |= GPIO_CLOCK_GATING_PORTA; /** Bit 9 of SIM_SCGC5 is  set*/
				break;
			case GPIO_B: /** GPIO B is selected*/
				SIM->SCGC5 |= GPIO_CLOCK_GATING_PORTB; /** Bit 10 of SIM_SCGC5 is set*/
				break;
			case GPIO_C: /** GPIO C is selected*/
				SIM->SCGC5 |= GPIO_CLOCK_GATING_PORTC; /** Bit 11 of SIM_SCGC5 is set*/
				break;
			case GPIO_D: /** GPIO D is selected*/
				SIM->SCGC5 |= GPIO_CLOCK_GATING_PORTD; /** Bit 12 of SIM_SCGC5 is set*/
				break;
			case GPIO_E: /** GPIO E is selected*/
				SIM->SCGC5 |= GPIO_CLOCK_GATING_PORTE; /** Bit 13 of SIM_SCGC5 is set*/
				break;
			default: /**If doesn't exist the option*/
				return(FALSE);
		}// end switch
	/**Successful configuration*/
	return(TRUE);
}// end function

uint8_t GPIO_pin_control_register(gpio_port_name_t port_name, uint8_t pin,const gpio_pin_control_register_t*  pin_control_register)
{
	switch(port_name)
		{
		case GPIO_A:/** GPIO A is selected*/
			PORTA->PCR[pin] = *pin_control_register;
			break;
		case GPIO_B:/** GPIO B is selected*/
			PORTB->PCR[pin] = *pin_control_register;
			break;
		case GPIO_C:/** GPIO C is selected*/
			PORTC->PCR[pin] = *pin_control_register;
			break;
		case GPIO_D:/** GPIO D is selected*/
			PORTD->PCR[pin] = *pin_control_register;
			break;
		case GPIO_E: /** GPIO E is selected*/
			PORTE->PCR[pin] = *pin_control_register;
		default:/**If doesn't exist the option*/
			return(FALSE);
		break;
		}
	/**Successful configuration*/
	return(TRUE);
}

void GPIO_write_port(gpio_port_name_t port_name, uint32_t data)
{
	switch(port_name)
		{
		case GPIO_A:/** GPIO A is selected*/
			GPIOA->PDOR = data;
			break;
		case GPIO_B:/** GPIO B is selected*/
			GPIOB->PDOR = data;
			break;
		case GPIO_C:/** GPIO C is selected*/
			GPIOC->PDOR = data;
			break;
		case GPIO_D:/** GPIO D is selected*/
			GPIOD->PDOR = data;
			break;
		case GPIO_E: /** GPIO E is selected*/
			GPIOE->PDOR = data;
		default:/**If doesn't exist the option do nothing*/
		break;
		}
}

uint32_t GPIO_read_port(gpio_port_name_t port_name)
{
	switch(port_name)
		{
		case GPIO_A:/** GPIO A is selected*/
			return GPIOA->PDIR;
			break;
		case GPIO_B:/** GPIO B is selected*/
			return GPIOB->PDIR;
			break;
		case GPIO_C:/** GPIO C is selected*/
			return GPIOC->PDIR;
			break;
		case GPIO_D:/** GPIO D is selected*/
			return GPIOD->PDIR;
			break;
		case GPIO_E: /** GPIO E is selected*/
			return GPIOE->PDIR;
		default:/**If doesn't exist the option do nothing*/
		break;
		}
	return 0;
}

uint8_t GPIO_read_pin(gpio_port_name_t port_name, uint8_t pin)
{
	switch(port_name)
		{
		case GPIO_A:/** GPIO A is selected*/
			return (GPIOA->PDIR[pin] == 0x1) ? 1 : 0;
			break;
		case GPIO_B:/** GPIO B is selected*/
			return (GPIOB->PDIR[pin] == 1) ? 1 : 0;
			break;
		case GPIO_C:/** GPIO C is selected*/
			return (GPIOC->PDIR[pin] == 1) ? 1 : 0;
			break;
		case GPIO_D:/** GPIO D is selected*/
			return (GPIOD->PDIR[pin] == 1) ? 1 : 0;
			break;
		case GPIO_E: /** GPIO E is selected*/
			return (GPIOE->PDIR[pin] == 1) ? 1 : 0;
		default:/**If doesn't exist the option do nothing*/
		break;
		}
	return 0;
}

void GPIO_set_pin(gpio_port_name_t port_name, uint8_t pin)
{
	switch(port_name)
		{
		case GPIO_A:/** GPIO A is selected*/
			GPIOA->PSOR[pin] = 1;
			break;
		case GPIO_B:/** GPIO B is selected*/
			GPIOB->PSOR[pin] = 1;
			break;
		case GPIO_C:/** GPIO C is selected*/
			GPIOC->PSOR[pin] = 1;
			break;
		case GPIO_D:/** GPIO D is selected*/
			GPIOD->PSOR[pin] = 1;
			break;
		case GPIO_E: /** GPIO E is selected*/
			GPIOE->PSOR[pin] = 1;
		default:/**If doesn't exist the option do nothing*/
		break;
		}
}

void GPIO_clear_pin(gpio_port_name_t port_name, uint8_t pin)
{
	switch(port_name)
		{
		case GPIO_A:/** GPIO A is selected*/
			GPIOA->PCOR[pin] = 0b1;
			break;
		case GPIO_B:/** GPIO B is selected*/
			GPIOB->PCOR[pin] = 0b1;
			break;
		case GPIO_C:/** GPIO C is selected*/
			GPIOC->PCOR[pin] = 0b1;
			break;
		case GPIO_D:/** GPIO D is selected*/
			GPIOD->PCOR[pin] = 0b1;
			break;
		case GPIO_E: /** GPIO E is selected*/
			GPIOE->PCOR[pin] = 0b1;
		default:/**If doesn't exist the option do nothing*/
		break;
		}
}

void GPIO_toogle_pin(gpio_port_name_t port_name, uint8_t pin)
{
	switch(port_name)
		{
		case GPIO_A:/** GPIO A is selected*/
			GPIOA->PTOR[pin] = 1;
			break;
		case GPIO_B:/** GPIO B is selected*/
			GPIOB->PTOR[pin] = 1;
			break;
		case GPIO_C:/** GPIO C is selected*/
			GPIOC->PTOR[pin] = 1;
			break;
		case GPIO_D:/** GPIO D is selected*/
			GPIOD->PTOR[pin] = 1;
			break;
		case GPIO_E: /** GPIO E is selected*/
			GPIOE->PTOR[pin] = 1;
		default:/**If doesn't exist the option do nothing*/
		break;
		}
}

void GPIO_data_direction_port(gpio_port_name_t port_name,uint32_t direction)
{
	switch(port_name)
		{
		case GPIO_A:/** GPIO A is selected*/
			(direction == GPIO_OUTPUT) ? GPIOA->PDDR = 0xFFFFFFFF : GPIOA->PDDR = 0x00000000;
			break;
		case GPIO_B:/** GPIO B is selected*/
			(direction == GPIO_OUTPUT) ? GPIOB->PDDR = 0xFFFFFFFF : GPIOB->PDDR = 0x00000000;
			break;
		case GPIO_C:/** GPIO C is selected*/
			(direction == GPIO_OUTPUT) ? GPIOC->PDDR = 0xFFFFFFFF : GPIOC->PDDR = 0x00000000;
			break;
		case GPIO_D:/** GPIO D is selected*/
			(direction == GPIO_OUTPUT) ? GPIOD->PDDR = 0xFFFFFFFF : GPIOD->PDDR = 0x00000000;
			break;
		case GPIO_E: /** GPIO E is selected*/
			(direction == GPIO_OUTPUT) ? GPIOE->PDDR = 0xFFFFFFFF : GPIOE->PDDR = 0x00000000;
		default:/**If doesn't exist the option do nothing*/
		break;
		}
}

void GPIO_data_direction_pin(gpio_port_name_t port_name, uint8_t state, uint8_t pin)
{
	switch(port_name)
		{
		case GPIO_A:/** GPIO A is selected*/
			(state == GPIO_INPUT) ? GPIOA->PDDR[pin] = 0 : GPIOA->PDDR[pin] = 1;
			break;
		case GPIO_B:/** GPIO B is selected*/
			(state == GPIO_INPUT) ? GPIOB->PDDR[pin] = 0 : GPIOB->PDDR[pin] = 1;
			break;
		case GPIO_C:/** GPIO C is selected*/
			(state == GPIO_INPUT) ? GPIOC->PDDR[pin] = 0 : GPIOC->PDDR[pin] = 1;
			break;
		case GPIO_D:/** GPIO D is selected*/
			(state == GPIO_INPUT) ? GPIOD->PDDR[pin] = 0 : GPIOD->PDDR[pin] = 1;
			break;
		case GPIO_E: /** GPIO E is selected*/
			(state == GPIO_INPUT) ? GPIOE->PDDR[pin] = 0 : GPIOE->PDDR[pin] = 1;
		default:/**If doesn't exist the option do nothing*/
		break;
		}
}
