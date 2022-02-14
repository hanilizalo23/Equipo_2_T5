#include "MK64F12.h"
#include "GPIO.h"
#include "Bits.h"

int main(void)
{
	//inicializar todos los puertos de LEDs y SWs, así como sus relojes

	green(); //Estado inicial

	while(1)
	{
		uint8_t green_f  = 1;
		uint8_t blue_f   = 0;
		uint8_t purple_f = 0;
		uint8_t red_f    = 0;
		uint8_t yellow_f = 0;
		uint8_t white_f  = 0;

		uint8_t sw3_f = 0;
		uint8_t sw2_f = 0;

		if(switch3 == 1) //Poner valor y variable correcta
		{
			sw3_f = 1;
			sw2_f = 0;
		}

		if(switch2 == 1) //Poner valor y variable correcta
		{
			sw2_f = 1;
			sw3_f = 0;
		}

		if(sw3_f)
		{
			if (green_f == 1)
			{
				green_f = 0;
				blue();
				blue_f = 1;
			}
			else if (blue_f == 1)
			{
				blue_f = 0;
				purple();
				purple_f = 1;
			}
			else if (purple_f == 1)
			{
				purple_f = 0;
				red();
				red_f = 1;
			}
			else if (red_f == 1)
			{
				red_f = 0;
				yellow();
				yellow_f = 1;
			}
			else if (yellow_f == 1 || white_f == 1)
			{
				yellow_f = 0;
				white_f = 0;
				green();
				green_f = 1;
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
			}
			else if (yellow_f == 1)
			{
				yellow_f = 0;
				red();
				red_f = 1;
			}
			else if (red_f == 1)
			{
				red_f = 0;
				purple();
				purpe_f = 1;
			}
			else if (purple_f == 1)
			{
				purple_f = 0;
				blue();
				blue_f = 1;
			}
			else if (yellow_f == 1)
			{
				blue_f = 0;
				green();
				green_f = 1;
			}
		}

		if (sw2 && sw3)
		{
			white();
			white_f = 1;
		}
	}

    return 0 ;
}
