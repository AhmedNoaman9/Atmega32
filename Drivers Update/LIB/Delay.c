/*
 * Delay.c
 *
 * Created: 07-Feb-23 6:52:22 PM
 *  Author: NO3M4N
 */ 

#include "Std_types.h"
#include "Delay.h"

#define F_CPU	8000000U

void Delay_ms(u32 Delay)
{
	Delay = (u32)((f32)Delay*((f32)F_CPU/1000000.0)*91.2);
	while(Delay)
	{
		asm("NOP");
		Delay--;
	}
	return;
}