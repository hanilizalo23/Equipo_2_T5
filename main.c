/**
	\file
	\brief
		This is the main application of this homework, where all the layers are includen
		for making the code more visible
	\author Nelida Paulina Hernández Moya and Mauricio Peralta Osorio
	\date	15/02/2022
 */

#include "MK64F12.h"
#include "GPIO.h"
#include "RGB.h"
#include "Delay.h"
#include "Bits.h"

#define GPIO_OFF_CONST (0xFFFFFFFFU) /**To turn off the ports*/
#define GPIO_ON_CONST (0U) /**To turn on the ports*/
#define DELAY_CONST 600000 /**To wait*/

gpio_pin_control_register_t pcr_gpiob_pin_21 = GPIO_MUX1; /**Blue LED*/
gpio_pin_control_register_t pcr_gpiob_pin_22 = GPIO_MUX1; /**Red LED*/
gpio_pin_control_register_t pcr_gpioe_pin_26 = GPIO_MUX1; /**Green LED*/

gpio_pin_control_register_t pcr_gpioc_pin_6 = GPIO_MUX1|GPIO_PE|GPIO_PS; /**Switch 2*/
gpio_pin_control_register_t pcr_gpioa_pin_4 = GPIO_MUX1|GPIO_PE|GPIO_PS; /**Switch 3*/


int main(void) {

	GPIO_clock_gating(GPIO_A); /**Clock of port A*/
	GPIO_clock_gating(GPIO_B); /**Clock of port B*/
	GPIO_clock_gating(GPIO_C); /**Clock of port C*/
	GPIO_clock_gating(GPIO_E); /**Clock of port E*/

	GPIO_pin_control_register(GPIO_B,bit_21,&pcr_gpiob_pin_21); /**Blue LED*/
	GPIO_pin_control_register(GPIO_B,bit_22,&pcr_gpiob_pin_22); /**Red LED*/
	GPIO_pin_control_register(GPIO_E,bit_26,&pcr_gpioe_pin_26); /**Green LED*/

	GPIO_pin_control_register(GPIO_C,bit_6,&pcr_gpioc_pin_6); /**Switch 2*/
	GPIO_pin_control_register(GPIO_A,bit_4,&pcr_gpioa_pin_4); /**Switch 3*/


	GPIO_write_port(GPIO_B, GPIO_OFF_CONST); /**Turn off the port of the blue and red LED*/
	GPIO_write_port(GPIO_E, GPIO_OFF_CONST); /**Turn off the port of the green LED*/

	GPIO_data_direction_pin(GPIO_B,GPIO_OUTPUT, bit_21); /**Blue LED*/
	GPIO_data_direction_pin(GPIO_B,GPIO_OUTPUT,bit_22); /**Red LED*/
	GPIO_data_direction_pin(GPIO_E,GPIO_OUTPUT,bit_26); /**Green LED*/

	GPIO_data_direction_pin(GPIO_C,GPIO_INPUT, bit_6); /**Switch 2*/
	GPIO_data_direction_pin(GPIO_A,GPIO_INPUT, bit_4); /**Switch 3*/

	/**Turning on and off the PDOR ports of the LEDs, part of the configuration*/
	GPIO_write_port(GPIO_B, GPIO_ON_CONST);
	GPIO_write_port(GPIO_B, GPIO_OFF_CONST);
	GPIO_write_port(GPIO_E, GPIO_ON_CONST);
	GPIO_write_port(GPIO_E, GPIO_OFF_CONST);

	uint8_t green_f  = 1; /**Flag for green color, turned on because is the initial state*/
	uint8_t blue_f   = 0; /**Flag for blue color*/
	uint8_t purple_f = 0; /**Flag for purple color*/
	uint8_t red_f    = 0; /**Flag for red color*/
	uint8_t yellow_f = 0; /**Flag for yellow color*/
	uint8_t white_f  = 0; /**Flag for white color*/

	uint8_t sw3_f = 0; /**Flag for switch 3*/
	uint8_t sw2_f = 0; /**Flag for switch 2*/



	while (1)
	{
		delay(DELAY_CONST); /**This delay is for avoiding that from the white LED goes to
								another case*/

		if((!GPIO_read_pin(GPIO_C, bit_6)) && (GPIO_read_pin(GPIO_A, bit_4))) /**Asking if the switch 2 is pressed*/
		{
			sw2_f = 1; /**Then turn on a flag for switch 2*/
		}

		if((!GPIO_read_pin(GPIO_A, bit_4)) && (GPIO_read_pin(GPIO_C, bit_6))) /**Asking if the switch 3 is pressed*/
		{
			sw3_f = 1; /**Then turn on a flag for switch 3*/
		}

		/**If the flag of the switch 2 or 3 is on, then, it asks for the flag of an specific
		 * LED, it always starts on green, then it turn off the LED_flag, calls the function
		 * of the color, turn on the LED_flag of the next color that corresponds and finally
		 * turn off the switch flag, the next both conditionals do the same, the only thing
		 * that changes in the white color is that both LEDs should be pressed.
		 */

		if(sw3_f)
		{
			if (green_f == 1)
			{
				green_f = 0;
				blue();
				blue_f = 1;
				sw3_f = 0;
			}
			else if (blue_f == 1)
			{
				blue_f = 0;
				purple();
				purple_f = 1;
				sw3_f = 0;
			}
			else if (purple_f == 1)
			{
				purple_f = 0;
				red();
				red_f = 1;
				sw3_f = 0;
			}
			else if (red_f == 1)
			{
				red_f = 0;
				yellow();
				yellow_f = 1;
				sw3_f = 0;
			}
			else if (yellow_f == 1 || white_f == 1)
			{
				yellow_f = 0;
				white_f = 0;
				green();
				green_f = 1;
				sw3_f = 0;
			}
		}

		if(sw2_f)
		{
			if (green_f == 1 || white_f == 1)
			{
				green_f = 0;
				white_f = 0;
				yellow();
				yellow_f = 1;
				sw2_f = 0;
			}
			else if (yellow_f == 1)
			{
				yellow_f = 0;
				red();
				red_f = 1;
				sw2_f = 0;
			}
			else if (red_f == 1)
			{
				red_f = 0;
				purple();
				purple_f = 1;
				sw2_f = 0;
			}
			else if (purple_f == 1)
			{
				purple_f = 0;
				blue();
				blue_f = 1;
				sw2_f = 0;
			}
			else if (blue_f == 1)
			{
				blue_f = 0;
				green();
				green_f = 1;
				sw2_f = 0;
			}
		}

		if ((!GPIO_read_pin(GPIO_C, bit_6)) && (!GPIO_read_pin(GPIO_A, bit_4)))
		{
			white();
			white_f = 1;
			sw2_f = 0;
			sw3_f = 0;
		}
	}
    return 0;
}
