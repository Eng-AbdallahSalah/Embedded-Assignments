/*
 * Count_from_1_to_15__using_one_7seg.c
 *
 * Created: 9/19/2024 9:05:48 AM
 *  Author: Abdallah
 */ 

#define F_CPU 8000000UL
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "GPIO_Interface.h"
#include "SSD_Interface.h"
#include "util/delay.h"

SSD_Configration SSD1 ={SSD_CommonCathod,SSD_PORTA,SSD_PORTA};
SSD_Configration SSD2 ={SSD_CommonAnode,SSD_PORTB,SSD_PORTB};
int main(void)
{
	SSD_voidInitialDataPort(SSD1);
	SSD_voidInitialDataPort(SSD2);

	
    while(1)
    {
        for(u8 count = 0; count <=17 ; count++){
			SSD_voidSendNumber(SSD1,count);
			SSD_voidSendNumber(SSD2,count);
			_delay_ms(1000);
			
			
		} 
    }
}