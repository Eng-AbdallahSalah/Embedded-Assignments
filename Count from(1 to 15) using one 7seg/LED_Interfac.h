/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< LED_Interface.h >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Abdallah Salah Abdelmagied
 *  Layer  : HAL
 *  Date   :
 *
 */
 #include "STD_TYPES.h"
 #ifndef LED_Interface_H_
 #define LED_Interface_H_


 /*Define LEd ports*/
 #define LED_PORTA        0
 #define LED_PORTB        1
 #define LED_PORTC        2
 #define LED_PORTD        3


 /*Define Led pins*/
 #define LED_PIN0         0
 #define LED_PIN1         1
 #define LED_PIN2         2
 #define LED_PIN3         3
 #define LED_PIN4         4
 #define LED_PIN5         5
 #define LED_PIN6         6
 #define LED_PIN7         7


 /*Define status of Led pin*/
 #define LED_ACTIVE_LOW    1
 #define LED_ACTIVE_HIGH   1

 #define LED_LOW           0
 #define LED_HIGH          1


 /*LED Data*/
 typedef struct {
    u8 LED_PORT;
    u8 LED_PIN ;
    u8 LED_STATE;
 }LED_Configration;

 /*Declare function prototype*/
 void LED_VoidInit   (LED_Configration data);
 void LED_VoidOn     (LED_Configration data);
 void LED_VoidOff    (LED_Configration data);
 void LED_VoidToggle (LED_Configration data);


 #endif // LED_Interface_H_
