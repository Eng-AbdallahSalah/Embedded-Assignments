/*
 * STD_TYPES.h
 *
 * Created: 8/5/2024 6:53:52 AM
 *  Author: Abdallah
 */ 


#ifndef STD_TYPES_H_
#define STD_TYPES_H_

/* Define New Data type to protect data types from compiler dependent */
/* Unsigned data type */
typedef  unsigned char             u8 ;
typedef  unsigned short int        u16;
typedef  unsigned long  int        u32;
typedef  unsigned long long int    u64;

/* Signed data type */
typedef  signed char               s8 ;
typedef  signed short int          s16;
typedef  signed long  int          s32;
typedef  signed long long int      s64;

/* Not Signed OR Unsigned data type */
typedef  float     f32;
typedef  double    f64;

/*BOOl status*/
typedef enum{
	false,
	true ,
}Bool_t;

#define NULL 0



#endif /* STD_TYPES_H_ */