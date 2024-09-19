/*
 * SSD_Interface.h
 *
 * Created: 8/5/2024 9:06:36 AM
 *  Author: Abdallah
 */ 

#include "STD_TYPES.h" 

#ifndef SSD_INTERFACE_H_
#define SSD_INTERFACE_H_

#define  SSD_CommonCathod   0
#define  SSD_CommonAnode    1

#define SSD_PIN0            0
#define SSD_PIN1            1
#define SSD_PIN2            2
#define SSD_PIN3            3
#define SSD_PIN4            4
#define SSD_PIN5            5
#define SSD_PIN6            6
#define SSD_PIN7            7

#define SSD_PORTA           0
#define SSD_PORTB           1
#define SSD_PORTC           2
#define SSD_PORTD           3

typedef struct{
	u8 Type_Connection;
	u8 Data_Port      ;
	u8 EnablePort	  ;                
	u8 EnablePin      ;
	}SSD_Configration; 
	
void SSD_voidInitialDataPort  ( SSD_Configration Copy_structConfig );
void SSD_voidEnable           ( SSD_Configration Copy_structConfig );
void SSD_voidDisable          ( SSD_Configration Copy_structConfig );
void SSD_voidSendNumber       ( SSD_Configration Copy_structConfig , u8 Copy_u8Number );



#endif /* SSD_INTERFACE_H_ */