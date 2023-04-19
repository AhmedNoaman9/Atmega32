/*
 * SWITCH_Cfg.c
 *
 * Created: 19-Jan-23 12:37:38 PM
 *  Author: NO3M4N
 */ 

#include "Std_types.h"
#include "SWITCH.h"
#include "SWITCH_Cfg.h"

SWITCH_Cfg_t SwitchConfig[NUMBER_OF_SWITCH] = {

	[0] = {
		.SW_Number = 15,
	},

	[1] = {
		.SW_Number = 9,
	},

	[2] = {
		.SW_Number = 2,
	}

};