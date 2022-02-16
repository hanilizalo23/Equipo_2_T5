
#include "MK64F12.h"
#include "GPIO.h"
#include "Delay.h"
#include "Bits.h"

#define GPIOB_OFF_CONST (0xFFFFFFFFU)
#define GPIOB_ON_CONST (0U)
#define DELAY_CONST 600000

gpio_pin_control_register_t pcr_gpiob_pin_21 = GPIO_MUX1;
gpio_pin_control_register_t pcr_gpiob_pin_22 = GPIO_MUX1;
gpio_pin_control_register_t pcr_gpioc_pin_6 = GPIO_MUX1|GPIO_PE|GPIO_PS;


int main(void) {


	GPIO_clock_gating(GPIO_B);
	GPIO_clock_gating(GPIO_C);

	GPIO_pin_control_register(GPIO_B,bit_21,&pcr_gpiob_pin_21);
	GPIO_pin_control_register(GPIO_B,bit_22,&pcr_gpiob_pin_22);
	GPIO_pin_control_register(GPIO_C,bit_6,&pcr_gpioc_pin_6);


	GPIO_write_port(GPIO_B, GPIOB_OFF_CONST);

	GPIO_data_direction_pin(GPIO_B,GPIO_OUTPUT, bit_21);
	GPIO_data_direction_pin(GPIO_B,GPIO_OUTPUT,bit_22);
	GPIO_data_direction_pin(GPIO_C,GPIO_INPUT, bit_6);

	GPIO_write_port(GPIO_B, GPIOB_ON_CONST);
	delay(DELAY_CONST);
	GPIO_write_port(GPIO_B, GPIOB_OFF_CONST);


	for (;;) {

		if(!GPIO_read_pin(GPIO_C, bit_6))
		{
			GPIO_clear_pin(GPIO_B, bit_21);
			delay(DELAY_CONST);
			GPIO_set_pin(GPIO_B, bit_21);
			delay(DELAY_CONST);
			GPIO_clear_pin(GPIO_B, bit_22);
			delay(DELAY_CONST);
			GPIO_set_pin(GPIO_B, bit_22);
		}

		}

    return 0 ;
}
