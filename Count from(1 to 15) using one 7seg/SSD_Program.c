/*
 * SSD_Program.c
 *
 * Created: 8/5/2024 9:11:44 AM
 *  Author: Abdallah
 */ 
#include "STD_TYPES.h"
#include "SSD_Interface.h"
#include "GPIO_Interface.h"
#include "SSD_Private.h"

u8 Loc_SSD_Numbers[17] = SSD_Numbers_Arr;

void SSD_voidInitialDataPort  ( SSD_Configration Copy_StructData ){
	DIO_enumSetPortDirection(Copy_StructData.Data_Port,0xff);
}



void SSD_voidEnable ( SSD_Configration Copy_StructData ){
		if(Copy_StructData.Type_Connection == SSD_CommonCathod){
			DIO_enumSetPinDirection(Copy_StructData.Data_Port,Copy_StructData.EnablePin,DIO_PIN_OUTPUT);
			DIO_enumSetPinValue    (Copy_StructData.Data_Port,Copy_StructData.EnablePin,DIO_PIN_LOW);
		}
		else if(Copy_StructData.Type_Connection == SSD_CommonAnode){
			DIO_enumSetPinDirection(Copy_StructData.Data_Port,Copy_StructData.EnablePin,DIO_PIN_OUTPUT);
			DIO_enumSetPinValue    (Copy_StructData.Data_Port,Copy_StructData.EnablePin,DIO_PIN_HIGH);
		}
	
}
void SSD_voidDisable          ( SSD_Configration Copy_StructData ){
		if(Copy_StructData.Type_Connection == SSD_CommonCathod){
			DIO_enumSetPinDirection(Copy_StructData.Data_Port,Copy_StructData.EnablePin,DIO_PIN_INPUT);
			DIO_enumSetPinValue    (Copy_StructData.Data_Port,Copy_StructData.EnablePin,DIO_PIN_HIGH);
		}
		else if(Copy_StructData.Type_Connection == SSD_CommonAnode){
			DIO_enumSetPinDirection(Copy_StructData.Data_Port,Copy_StructData.EnablePin,DIO_PIN_OUTPUT);
			DIO_enumSetPinValue    (Copy_StructData.Data_Port,Copy_StructData.EnablePin,DIO_PIN_LOW);
		}
		     
}
void SSD_voidSendNumber       ( SSD_Configration Copy_StructData , u8 Copy_u8Number ){
	if(Copy_StructData.Type_Connection == SSD_CommonCathod){
		DIO_enumSetPortValue(Copy_StructData.Data_Port,Loc_SSD_Numbers[Copy_u8Number]);
	}
	else if(Copy_StructData.Type_Connection == SSD_CommonAnode){
		DIO_enumSetPortValue(Copy_StructData.Data_Port,~(Loc_SSD_Numbers[Copy_u8Number]));
	}
}