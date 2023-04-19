/*
 * Std_types.h
 *
 *  Created on: Dec 8, 2022
 *      Author: NO3M4N
 */

#ifndef STD_TYPES_H_
#define STD_TYPES_H_

#define TRUE	1
#define FALSE	0

#define NULL	((void*)0)


//typedef	void(*CallBackFunc)(void);

#define ISR_Custom(NUM)		void __vector_##NUM (void) __attribute__ ((signal));void __vector_##NUM (void)



typedef unsigned char  u8;
typedef unsigned short int u16;
typedef unsigned long int u32;
typedef signed long long int u64;


typedef signed char s8;
typedef signed short int s16;
typedef signed long int s32;
typedef signed long long int s64;


typedef float f32;
typedef double f64;


#endif /* STD_TYPES_H_ */
