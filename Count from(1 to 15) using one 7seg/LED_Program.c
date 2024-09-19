#include "STD_TYPES.h"
#include"LED_Interfac.h"
#include"GPIO_Interface.h"


/*
 * @Breif : This Function set the direction of the Pin(INPUT || OUTPUT)
 * @Parameters :
  	  data--> is a type of struct define led data(port,pin number,status)
 * @Ret : NO Return value(VOID)
 */

 void LED_VoidInit(LED_Configration data){
     DIO_enumSetPinDirection(data.LED_PORT,data.LED_PIN,DIO_PIN_OUTPUT);
 }

 /*--------------------------------------------------------------------------------*/

 /*
 * @Breif : This Function use to turn on the led
 * @Parameters :
  	  data--> is a type of struct define led data(port,pin number,status)
 * @Ret : NO Return value(VOID)
 */

 void LED_VoidOn (LED_Configration data){
      if(data.LED_STATE == LED_ACTIVE_LOW){
        DIO_enumSetPinValue(data.LED_PORT,data.LED_PIN,LED_LOW);
      }
      else if(data.LED_STATE == LED_ACTIVE_HIGH){
        DIO_enumSetPinValue(data.LED_PORT,data.LED_PIN,LED_HIGH);
      }
 }

 /*-----------------------------------------------------------------------------------*/

  /*
 * @Breif : This Function use to turn off the led
 * @Parameters :
  	  data--> is a type of struct define led data(port,pin number,status)
 * @Ret : NO Return value(VOID)
 */

 void LED_VoidOff(LED_Configration data){
      if(data.LED_STATE == LED_ACTIVE_LOW){
        DIO_enumSetPinValue(data.LED_PORT,data.LED_PIN,LED_HIGH);
      }
      else if(data.LED_STATE == LED_ACTIVE_HIGH){
        DIO_enumSetPinValue(data.LED_PORT,data.LED_PIN,LED_LOW);
      }
 }

/*-------------------------------------------------------------------------------------*/

/*
 * @Breif : This Function use to toggle led value if(HIGH-->LOW || LOW-->HIGH)
 * @Parameters :
  	  data--> is a type of struct define led data(port,pin number,status)
 * @Ret : NO Return value(VOID)
 */

 void LED_VoidToggle (LED_Configration data){
        DIO_enumTogglePinValue(data.LED_PORT,data.LED_PIN);

 }
 /*------------------------------END----------------------------------------------------*/
