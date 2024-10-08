/*
 * GPIO_Program.c
 *
 * Created: 8/5/2024 7:01:33 AM
 *  Author: Abdallah
 */
#include "STD_TYPES.h"
#include "GPIO_Interface.h"
#include "GPIO_Private.h"
#include "BIT_MATH.h"



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
           //|||||||||||||||||||||||||||||||||||||||                          IO Pins                     |||||||||||||||||||||||||||||||||||||||
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//---------------------------------------------------------------------------------------------------------------------------------------------------
/*
 * @Breif : This Function set the direction of the Pin(INPUT || OUTPUT)
 * @Parameters :
  	  Copy_u8PORT--> Port Name { DIO_PORTA ,DIO_PORTB,DIO_PORTC,DIO_PORTD}
  	  Copy_u8PIN --> Pin Number{ DIO_PIN0 to DIO_PIN7}
  	  Copy_u8Direction--> Pin Direction{DIO_PIN_OUTPUT , DIO_PIN_INPUT}
 * @Ret : its status OF function (DIO_NOK || DIO_OK)
 */

DIO_ErrorStatus DIO_enumSetPinDirection    (u8 Copy_u8PORT , u8 Copy_u8PIN , u8 Copy_u8Direction ) 
{

	DIO_ErrorStatus LOC_enumState = DIO_OK ;

	/* Make sure that the Port ID and Pin ID are in the valid range */
	if ((Copy_u8PORT <= DIO_PORTD) && (Copy_u8PIN <= DIO_PIN7))
	{
		if ( Copy_u8Direction == DIO_PIN_OUTPUT )
		{
			/* Check on the Required PORT Number */
			switch (Copy_u8PORT)
			{
			case DIO_PORTA: SET_BIT(DDRA_Register,Copy_u8PIN); break;
			case DIO_PORTB: SET_BIT(DDRB_Register,Copy_u8PIN); break;
			case DIO_PORTC: SET_BIT(DDRC_Register,Copy_u8PIN); break;
			case DIO_PORTD: SET_BIT(DDRD_Register,Copy_u8PIN); break;
			}
		}

		else if ( Copy_u8Direction == DIO_PIN_INPUT )
		{
			/* Check on the Required PORT Number */
			switch (Copy_u8PORT)
			{
			case DIO_PORTA: CLR_BIT(DDRA_Register,Copy_u8PIN); break;
			case DIO_PORTB: CLR_BIT(DDRB_Register,Copy_u8PIN); break;
			case DIO_PORTC: CLR_BIT(DDRC_Register,Copy_u8PIN); break;
			case DIO_PORTD: CLR_BIT(DDRD_Register,Copy_u8PIN); break;
			}
		}

		else
		{
			LOC_enumState = DIO_NOK ;
		}
	}

	else
	{
		LOC_enumState = DIO_NOK ;
	}

	return LOC_enumState ;

}
/*--------------------------------------------------------------------------------------*/
/*
 * @Breif : This Function set the value of the Pin(HIGH || LOW)
 * @Parameters :
  	  Copy_u8PORT--> Port Name { DIO_PORTA ,DIO_PORTB,DIO_PORTC,DIO_PORTD}
  	  Copy_u8PIN --> Pin Number{ DIO_PIN0 to DIO_PIN7}
  	  Copy_u8Value--> Pin Direction{DIO_PIN_OUTPUT , DIO_PIN_INPUT}
 * @Ret : its status OF function (DIO_NOK || DIO_OK)
 */

DIO_ErrorStatus DIO_enumSetPinValue      (u8 Copy_u8PORT , u8 Copy_u8PIN , u8 Copy_u8Value ) 
{

	DIO_ErrorStatus LOC_enumState = DIO_OK ;

	/* Make sure that the Port ID and Pin ID are in the valid range */
	if ((Copy_u8PORT <= DIO_PORTD) && (Copy_u8PIN <= DIO_PIN7))
	{
		if (Copy_u8Value == DIO_PIN_HIGH)
		{
			/* Check on the Required PORT Number */
			switch (Copy_u8PORT)
			{
			case DIO_PORTA: SET_BIT(PORTA_Register,Copy_u8PIN); break;
			case DIO_PORTB: SET_BIT(PORTB_Register,Copy_u8PIN); break;
			case DIO_PORTC: SET_BIT(PORTC_Register,Copy_u8PIN); break;
			case DIO_PORTD: SET_BIT(PORTD_Register,Copy_u8PIN); break;
			}

		}

		else if (Copy_u8Value == DIO_PIN_LOW)
		{
			/* Check on the Required PORT Number */
			switch (Copy_u8PORT)
			{
			case DIO_PORTA: CLR_BIT(PORTA_Register,Copy_u8PIN); break;
			case DIO_PORTB: CLR_BIT(PORTB_Register,Copy_u8PIN); break;
			case DIO_PORTC: CLR_BIT(PORTC_Register,Copy_u8PIN); break;
			case DIO_PORTD: CLR_BIT(PORTD_Register,Copy_u8PIN); break;
			}
		}

		else
		{
			LOC_enumState = DIO_NOK ;
		}
	}

	else
	{
		LOC_enumState = DIO_NOK ;
	}

	return LOC_enumState ;

}

/*-------------------------------------------------------------------------------------------------*/
/*
 * @Breif : This Function Get the value of the Pin(HIGH || LOW)
 * @Parameters :
  	  Copy_u8PORT--> Port Name { DIO_PORTA ,DIO_PORTB,DIO_PORTC,DIO_PORTD}
  	  Copy_u8PIN --> Pin Number{ DIO_PIN0 to DIO_PIN7}
  	  *Copy_u8Value--> pointer use to return value of the pin
 * @Ret : its status OF function (DIO_NOK || DIO_OK)
 */

DIO_ErrorStatus DIO_enumGetPinValue          (u8 Copy_u8PORT, u8 Copy_u8PIN, u8 * Copy_PtrData   )
{

	DIO_ErrorStatus LOC_enumState = DIO_OK ;

	if ((Copy_u8PORT <= DIO_PORTD) && (Copy_u8PIN <= DIO_PIN7))
	{
		/* Check on the Required PORT Number */
		switch (Copy_u8PORT)
		{
		case DIO_PORTA: * Copy_PtrData = GET_BIT(PINA_Register,Copy_u8PIN); break;
		case DIO_PORTB: * Copy_PtrData = GET_BIT(PINB_Register,Copy_u8PIN); break;
		case DIO_PORTC: * Copy_PtrData = GET_BIT(PINC_Register,Copy_u8PIN); break;
		case DIO_PORTD: * Copy_PtrData = GET_BIT(PIND_Register,Copy_u8PIN); break;
		}
	}

	else
	{
		/* in case of error in the Pin ID or PORT ID */
		LOC_enumState = DIO_NOK ;
	}

	return LOC_enumState;
}

/*---------------------------------------------------------------------------------------------------*/
 /*
 * @Breif : This Function Toggle the value of the Pin(HIGH to LOW || LOW to HIGH)
 * @Parameters :
  	  Copy_u8PORT--> Port Name { DIO_PORTA ,DIO_PORTB,DIO_PORTC,DIO_PORTD}
  	  Copy_u8PIN --> Pin Number{ DIO_PIN0 to DIO_PIN7}
 * @Ret : its status OF function (DIO_NOK || DIO_OK)
 */
 
DIO_ErrorStatus DIO_enumTogglePinValue  ( u8 Copy_u8PORT, u8 Copy_u8PIN )
{
	DIO_ErrorStatus LOC_enumState = DIO_OK ;

	if (Copy_u8PIN <= DIO_PIN7)
	{
		switch (Copy_u8PORT)
		{
		case DIO_PORTA : TOG_BIT(PORTA_Register,Copy_u8PIN);
		break ;
		case DIO_PORTB : TOG_BIT(PORTB_Register,Copy_u8PIN);
		break ;
		case DIO_PORTC : TOG_BIT(PORTC_Register,Copy_u8PIN);
		break ;
		case DIO_PORTD : TOG_BIT(PORTD_Register,Copy_u8PIN);
		break ;
		}

	}
	else
	{
		/* in case of error in the Pin ID or PORT ID */
		LOC_enumState = DIO_NOK ;
	}

	return LOC_enumState;
}

/*---------------------------------------------------------------------------------------------------*/
/*
 * @Breif : This Function connected internal pull up
 * @Parameters :
  	  =>Copy_u8PORT --> Port Name [ DIO_PORTA ,	DIO_PORTB , DIO_PORTC , DIO_PORTD ]
  	  =>Copy_u8PIN  --> Pin Number [ DIO_PIN0 , DIO_PIN1 , DIO_PIN2 , DIO_PIN3 , DIO_PIN4 , DIO_PIN5 , DIO_PIN6 , DIO_PIN7 ]
 	  =>Copy_u8ConnectPullup --> [DIO_PIN_HIGH , DIO_PIN_LOW ]
 * @ret  : its status
 */
DIO_ErrorStatus DIO_enumConnectPullup (u8 Copy_u8PORT ,u8 Copy_u8PIN, u8 Copy_u8ConnectPullup)
{

	DIO_ErrorStatus LOC_enumState = DIO_OK ;

	if ((Copy_u8PORT <= DIO_PORTD) && (Copy_u8PIN <= DIO_PIN7))
	{
		switch(Copy_u8PORT)
		{
		/* Connect or disconnect the pull up resistance to the given pin in port A */
		case DIO_PORTA:
			if(Copy_u8ConnectPullup==DIO_PIN_HIGH)
			{
				CLR_BIT(SFIOR,PUD);
				CLR_BIT(DDRA_Register,Copy_u8PIN);
				SET_BIT(PORTA_Register,Copy_u8PIN);
			}
			else
			{
				CLR_BIT(PORTA_Register,Copy_u8PIN);
			}
			break;
			/* Connect or disconnect the pull up resistance to the given pin in port B */
		case DIO_PORTB:
			if(Copy_u8ConnectPullup==DIO_PIN_HIGH)
			{
				CLR_BIT(SFIOR,PUD);
				CLR_BIT(DDRB_Register,Copy_u8PIN);
				SET_BIT(PORTB_Register,Copy_u8PIN);
			}
			else
			{
				CLR_BIT(PORTB_Register,Copy_u8PIN);
			}
			break;
			/* Connect or disconnect the pull up resistance to the given pin in port C */
		case DIO_PORTC:
			if(Copy_u8ConnectPullup==DIO_PIN_HIGH)
			{
				CLR_BIT(SFIOR,PUD);
				CLR_BIT(DDRC_Register,Copy_u8PIN);
				SET_BIT(PORTC_Register,Copy_u8PIN);
			}
			else
			{
				CLR_BIT(PORTC_Register,Copy_u8PIN);
			}
			break;
			/* Connect or disconnect the pull up resistance to the given pin in port D */
		case DIO_PORTD:
			if(Copy_u8ConnectPullup==DIO_PIN_HIGH)
			{
				CLR_BIT(SFIOR,PUD);
				CLR_BIT(DDRD_Register,Copy_u8PIN);
				SET_BIT(PORTD_Register,Copy_u8PIN);
			}
			else
			{
				CLR_BIT(PORTD_Register,Copy_u8PIN);
			}
			break;
		}
	}

	else
	{
		LOC_enumState = DIO_NOK ;
	}

	return LOC_enumState ;


}



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
               //|||||||||||||||||||||||||||                          IO PORTS                  |||||||||||||||||||||||||||||||||||||||
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


/*---------------------------------------------------------------------------------------------------*/
 /*
 * @Breif : This Function Set port direction (INPUT || OUTPUT)
 * @Parameters :
  	  Copy_u8PORT--> Port Name { DIO_PORTA ,DIO_PORTB,DIO_PORTC,DIO_PORTD}
  	  Copy_u8PIN --> Pin Number{ DIO_PIN0 to DIO_PIN7}
  	  Copy_u8Direction--> determine direction(DIO_INPUT || DIO_OUTPUT)
 * @Ret : its status OF function (DIO_NOK || DIO_OK)
 */
 
DIO_ErrorStatus DIO_enumSetPortDirection   (u8 Copy_u8PORT , u8 Copy_u8Direction ) 
{

	DIO_ErrorStatus LOC_enumState = DIO_OK ;

	if ( (Copy_u8PORT <= DIO_PORTD) )
	{
		/* Check on the Required PORT Number */
		switch (Copy_u8PORT)
		{
		case     DIO_PORTA: DDRA_Register = Copy_u8Direction; break;
		case     DIO_PORTB: DDRB_Register = Copy_u8Direction; break;
		case     DIO_PORTC: DDRC_Register = Copy_u8Direction; break;
		case     DIO_PORTD: DDRD_Register = Copy_u8Direction; break;
		default: LOC_enumState =  DIO_NOK;    break;
		}	
	}
	else
	{
		LOC_enumState = DIO_NOK;
	}
	return LOC_enumState ;
}

/*------------------------------------------------------------------------------------------------------*/
  /*
 * @Breif : This Function Set port value (HIGH || LOW)
 * @Parameters :
  	  Copy_u8PORT--> Port Name { DIO_PORTA ,DIO_PORTB,DIO_PORTC,DIO_PORTD}
  	  Copy_u8Value --> value of port (HIGH || LOW)

 * @Ret : its status OF function (DIO_NOK || DIO_OK)
 */
  
DIO_ErrorStatus DIO_enumSetPortValue       (u8 Copy_u8PORT , u8 Copy_u8Value )
{

	DIO_ErrorStatus LOC_enumState = DIO_OK ;

	if ( (Copy_u8PORT <= DIO_PORTD) && ( (Copy_u8Value<=255) || (Copy_u8Value==DIO_PORT_LOW) || (Copy_u8Value==DIO_PORT_HIGH) ) )
	{
		/* Check on the Required PORT Number */
		switch (Copy_u8PORT)
		{
		case     DIO_PORTA: PORTA_Register = Copy_u8Value; break;
		case     DIO_PORTB: PORTB_Register = Copy_u8Value; break;
		case     DIO_PORTC: PORTC_Register = Copy_u8Value; break;
		case     DIO_PORTD: PORTD_Register = Copy_u8Value; break;
		default: LOC_enumState = DIO_NOK;       break;
		}	
	}
	else
	{
		LOC_enumState = DIO_NOK;
	}
	return LOC_enumState ;
}

 /*---------------------------------------------------------------------------------------------------*/
   /*
 * @Breif : This Function use to toggle port value ( HIGH--> LOw || LOW--> HiGH )
 * @Parameters :
  	  Copy_u8PORT--> Port Name { DIO_PORTA ,DIO_PORTB,DIO_PORTC,DIO_PORTD}
 * @Ret : its status OF function (DIO_NOK || DIO_OK)
 */

DIO_ErrorStatus DIO_enumTogglePortValue      (u8 Copy_u8PORT                       )
{
	DIO_ErrorStatus LOC_enumState = DIO_OK ;

	if (Copy_u8PORT <= DIO_PORTD)
	{
		switch (Copy_u8PORT)
		{
		case DIO_PORTA : PORTA_Register = ~PORTA_Register ;
		break ;
		case DIO_PORTB : PORTB_Register = ~PORTB_Register ;
		break ;
		case DIO_PORTC : PORTC_Register = ~PORTC_Register ;
		break ;
		case DIO_PORTD : PORTD_Register = ~PORTD_Register ;
		break ;
		}
	}
	else
	{
		LOC_enumState = DIO_NOK;
	}
	return LOC_enumState ;
}

 /*--------------------------------------------------------------------------------------------------*/
  /*
 * @Breif : This Function Get port value (HIGH || LOW)
 * @Parameters :
  	  Copy_u8PORT--> Port Name { DIO_PORTA ,DIO_PORTB,DIO_PORTC,DIO_PORTD}
  	  *Copy_u8PtrValue --> pointer use to return value of port (HIGH || LOW)

 * @Ret : its status OF function (DIO_NOK || DIO_OK)
 */
  
DIO_ErrorStatus   DIO_enumGetPortValue         ( u8 Copy_u8PORT  , u8 * Copy_PtrData )
{

	DIO_ErrorStatus LOC_enumState = DIO_OK ;

	if ( (Copy_u8PORT <= DIO_PORTD))
	{
		switch (Copy_u8PORT)
		{
		case DIO_PORTA :
			*Copy_PtrData = PINA_Register  ;
			break ;
		case DIO_PORTB :
			*Copy_PtrData = PINB_Register  ;
			break ;
		case DIO_PORTC :
			*Copy_PtrData = PINC_Register  ;
			break ;
		case DIO_PORTD :
			*Copy_PtrData = PIND_Register  ;
			break ;
		default : LOC_enumState = DIO_NOK ;
		break;
		}
	}
	else
	{
		LOC_enumState = DIO_NOK;
	}

	return LOC_enumState ;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            //|||||||||||||||||||||||||||||||||||||||                          IO NIBBLES                     |||||||||||||||||||||||||||||||||||
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

 /*------------------------------------------------------------------------------------------------------*/
  /*
 * @Breif : This Function write high nibble of a specific port
 * @Parameters :
  	  Copy_u8PORT--> Port Name { DIO_PORTA ,DIO_PORTB,DIO_PORTC,DIO_PORTD}
  	  Copy_u8value--> to set bits in high nibble in register
 * @Ret : its status OF function (DIO_NOK || DIO_OK)
                                 ***Take Care Dear,Programmer!!***
      -----------------------------------------------------------------------------
     | Bit (7) | Bit (6) | Bit (5)| Bit (4) | Bit (3)| Bit (2) | Bit (1) | Bit (0) |
      -----------------------------------------------------------------------------
       **          High Nibble            ** **         Low Nibble                **
 */

DIO_ErrorStatus DIO_voidWriteHighNibbles(u8 Copy_u8PORT,u8 Copy_u8value)
{

	DIO_ErrorStatus LOC_enumState = DIO_OK ;

	if ( (Copy_u8PORT <= DIO_PORTD))
	{
		Copy_u8value = (Copy_u8value<<4) ;
		switch(Copy_u8PORT)
		{
		case DIO_PORTA :                             /*                             pins[4,5,6,7] */
			PORTA_Register&=0x0f;                   /*Make sure that high nibble pins = 0 0 0 0  */
			PORTA_Register|=Copy_u8value;			//Set only the high nibble of the port A by the given value
			break ;
		case DIO_PORTB:
			PORTB_Register&=0x0f;                 //Set only the high nibble of the port B by the given value
			PORTB_Register|=Copy_u8value;
			break ;
		case DIO_PORTC :
			PORTC_Register&=0x0f;                 //Set only the high nibble of the port C by the given value
			PORTC_Register|=Copy_u8value;
			break ;
		case DIO_PORTD:
			PORTD_Register&=0x0f;                 //Set only the high nibble of the port D by the given value
			PORTD_Register|=Copy_u8value;
			break ;
		default: break ;

		}
	}
	else
	{
		LOC_enumState = DIO_NOK;
	}

	return LOC_enumState ;

}

 /*------------------------------------------------------------------------------------------------------*/
    /*
 * @Breif : This Function write Low nibble of a specific port(Take the four firt bits of the register 8 bits from bit(0) ot bit(3))
 * @Parameters :
  	  Copy_u8PORT--> Port Name { DIO_PORTA ,DIO_PORTB,DIO_PORTC,DIO_PORTD}
  	  Copy_u8value--> to set bits in Low nibble in register
 * @Ret : its status OF function (DIO_NOK || DIO_OK)
                                 ***Take Care Dear,Programmer!!***
      -----------------------------------------------------------------------------
     | Bit (7) | Bit (6) | Bit (5)| Bit (4) | Bit (3)| Bit (2) | Bit (1) | Bit (0) |
      -----------------------------------------------------------------------------
       **          High Nibble            ** **         Low Nibble                **
 */
	
DIO_ErrorStatus DIO_voidWriteLowNibbles(u8 Copy_u8PORT,u8 Copy_u8value)
{
	DIO_ErrorStatus LOC_enumState = DIO_OK ;


	if ( (Copy_u8PORT <= DIO_PORTD))
	{
		Copy_u8value&=0x0f;
		switch(Copy_u8PORT)
		{
		case DIO_PORTA :                              /*                             pins[4,5,6,7] */
			PORTA_Register &= 0xf0;                  /*Make sure that high nibble pins = 0 0 0 0  */
			PORTA_Register |= Copy_u8value;
			break ;
		case DIO_PORTB:
			PORTB_Register &= 0xf0;                 //Set only the high nibble of the port B by the given value
			PORTB_Register |= Copy_u8value;
			break ;
		case DIO_PORTC :
			PORTC_Register &= 0xf0;                 //Set only the high nibble of the port C by the given value
			PORTC_Register |= Copy_u8value;
			break ;
		case DIO_PORTD:
			PORTD_Register &= 0xf0;                 //Set only the high nibble of the port D by the given value
			PORTD_Register |= Copy_u8value;
			break ;
		default: break ;

		}


	}
	else
	{
		LOC_enumState = DIO_NOK;
	}

	return LOC_enumState ;

}
