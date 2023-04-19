/*
 * SSEG_Cfg.c
 *
 * Created: 20-Jan-23 4:06:47 PM
 *  Author: NO3M4N
 */ 



#include "../../LIB/Std_types.h"

#include "SSEG.h"
#include "SSEG_Cfg.h"




const u8 SSEG_LookUpTable[10] = {
	
	[0] = SSEG_ZERO,
	[1] = SSEG_ONE,
	[2] = SSEG_TWO,
	[3] = SSEG_THREE,
	[4] = SSEG_FOUR,
	[5] = SSEG_FIVE,
	[6] = SSEG_SIX,
	[7] = SSEG_SEVEN,
	[8] = SSEG_EIGHT,
	[9] = SSEG_NINE
	
};



const SSEG_tstrSSEGCfg_t SSEG_tstrSsegCfg[NUMBER_OF_SSEG] =
{
	
	[SSEG1]=
	{
		.SSEG_enuPin =
		{
			SSEG_enuPin16,
			SSEG_enuPin22,
			SSEG_enuPin21,
			SSEG_enuPin20,
			SSEG_enuPin19,
			SSEG_enuPin18,
			SSEG_enuPin17
			/*SSEG_enuPin7,*/
		},
			.SSEG_u8ActiveState = ACTIVE_HIGH
	},

			[SSEG2]=
			{
				.SSEG_enuPin =
				{
					SSEG_enuPin25,
					SSEG_enuPin26,
					SSEG_enuPin27,
					SSEG_enuPin28,
					SSEG_enuPin29,
					SSEG_enuPin30,
					SSEG_enuPin31
				},
			.SSEG_u8ActiveState = ACTIVE_HIGH
			}

};		



/* [SSEG1]=
{
.SSEG_enuPin =
{
SSEG_enuPin16,
SSEG_enuPin22,
SSEG_enuPin21,
SSEG_enuPin20,
SSEG_enuPin19,
SSEG_enuPin18,
SSEG_enuPin17,
/*SSEG_enuPin7,
},
.SSEG_u8ActiveState = ACTIVE_LOW


},

[SSEG2]=
{
.SSEG_enuPin =
{
SSEG_enuPin24,
SSEG_enuPin25,
SSEG_enuPin26,
SSEG_enuPin27,
SSEG_enuPin28,
SSEG_enuPin29,
SSEG_enuPin30
},
.SSEG_u8ActiveState = ACTIVE_LOW  */