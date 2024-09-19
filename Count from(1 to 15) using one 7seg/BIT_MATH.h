/*
 * BIT_MATH.h
 *
 * Created: 8/5/2024 7:03:44 AM
 *  Author: Abdallah
 */ 

#include "GPIO_Private.h"
#ifndef BIT_MATH_H_
#define BIT_MATH_H_


/*Register Size*/

#define REGISTER_SIZE 8
#define SET_BIT(reg,bit)    reg|=(1<<bit);
#define CLR_BIT(reg,bit)    reg&=(~(1<<bit));
#define TOG_BIT(reg,bit)    reg^=(1<<bit);
#define GET_BIT(reg,bit)    (reg&(1<<bit))>>bit
#define IS_BIT_SET(reg,bit)  (reg&(1<<bit))>>bit
#define IS_BIT_CLR(reg,bit)  !((reg&(1<<bit))>>bit)
#define ROR(reg,num)         reg=(reg<<(REGISTER_SIZE-num))|(reg>>(num))
#define ROL(reg,num)        reg= (reg>>(REGISTER_SIZE-num))|(reg<<(num))




#endif /* BIT_MATH_H_ */