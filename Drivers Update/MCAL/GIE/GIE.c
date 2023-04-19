/*******************************************/
/*GIE Driver*/
/* Target: ATMEGA32                        */
/* Ahmed Noaman */
/* Date:2023-01-25                         */
/*******************************************/

#include "../../LIB/Std_types.h"
#include "../../LIB/Bit_math.h"


#include "GIE.h"
#include "GIE_Cfg.h"
#include "GIE_Prv.h"


/**************************************************************
GIE Interrupt Enable Function
Input: Void
Output: GIE_tenuErrorStatus To report Error status through enum
****************************************************************/
GIE_tenuErrorStatus GIE_enuGlobalInterruptEnable(void)
{
	GIE_tenuErrorStatus Loc_GIEErrorStatus = GIE_enuOk;
	
	SET_BIT(SREG,GIE);
	
	return Loc_GIEErrorStatus;
	
}



/**************************************************************
GIE Interrupt Disable Function
Input: Void
Output: GIE_tenuErrorStatus To report Error status through enum
****************************************************************/
GIE_tenuErrorStatus GIE_enuGlobalInterruptDisable(void)
{
	GIE_tenuErrorStatus Loc_GIEErrorStatus = GIE_enuOk;
	
	CLR_BIT(SREG,GIE);
	
	return Loc_GIEErrorStatus;
	
}

