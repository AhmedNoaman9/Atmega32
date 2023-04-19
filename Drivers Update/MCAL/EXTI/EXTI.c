/*******************************************/
/*EXTI Driver*/
/* Target: ATMEGA32                        */
/* Ahmed Noaman */
/* Date:2023-01-27                         */
/*******************************************/

#include "../../LIB/Std_types.h"
#include "../../LIB/Bit_math.h"

#include "EXTI.h"
#include "EXTI_Cfg.h"
#include "EXTI_Prv.h"





/***************************************************************
	Extrenal Interrupt Initialization 
	Input : void   ( Configurations In Cfg.c )
	Output : EXTI_tenuErrorStatus ( Enum with detailed errors provided)
************************************************************************/

EXTI_tenuErrorStatus EXTI_enuInit(void)
{
	EXTI_tenuErrorStatus Loc_EXTIErrorStatus = EXTI_enuOk;
	
	u8 Loc_u8TempReg =0;
	Loc_u8TempReg = GICR;
	
	
	#if (INT0_MODE == INT_DISABLE )
		CLR_BIT(GICR,INT0);
		/* CLEAR the corresponding Pin in the GICR Register using the struct element*/
	#elif (INT0_MODE == INT_ENABLE )
		/*check INT Active Status*/
		SET_BIT(GICR,INT0);
		/* SET the corresponding Pin in the GICR Register using the struct element*/
		#if (INT0_SENSECTRL ==  INT_LOGIC_CHANGE || INT0_SENSECTRL == INT_LOW_LEVEL || INT0_SENSECTRL == INT_FALLING_EDGE || INT0_SENSECTRL == INT_RISING_EDGE)
			Loc_u8TempReg = MCUCR; /* Reg Copied to Local Temp REG*/
			Loc_u8TempReg&= EXTI_enuINT0SenseClear;	// 			CLR_FIELD(Loc_u8TempReg,ISC01,TWO_BIT_CLR); /* CLEAR FIELD USING PRESET MACRO*/
			Loc_u8TempReg|= (INT0_SENSECTRL);	// 			SET_FIELD(Loc_u8TempReg,ISC01,INT0_SENSECTRL);
			MCUCR = Loc_u8TempReg;
		#else
			Loc_EXTIErrorStatus = EXTI_enuInvalidSenseControl;
			return Loc_EXTIErrorStatus;
		#endif
	#else
		Loc_EXTIErrorStatus = EXTI_enuInvalidIntActStatus;
		return Loc_EXTIErrorStatus;
	#endif
	
	#if (INT1_MODE == INT_DISABLE) /*check INT Active Status*/
		CLR_BIT(GICR,INT1);
		/* CLEAR the corresponding Pin in the GICR Register using the struct element*/
	#elif( INT1_MODE == INT_ENABLE )/*check INT Active Status*/
		
		SET_BIT(GICR,INT1);
		/* SET the corresponding Pin in the GICR Register using the struct element*/
		#if (INT1_SENSECTRL == INT_LOGIC_CHANGE || INT1_SENSECTRL == INT_LOW_LEVEL || INT1_SENSECTRL == INT_FALLING_EDGE || INT1_SENSECTRL == INT_RISING_EDGE)
			Loc_u8TempReg = MCUCR; /* Reg Copied to Local Temp REG*/
			Loc_u8TempReg&= EXTI_enuINT1SenseClear;	// 			CLR_FIELD(Loc_u8TempReg,ISC01,TWO_BIT_CLR); /* CLEAR FIELD USING PRESET MACRO*/
			Loc_u8TempReg|= (INT1_SENSECTRL << ISC11);	// 			SET_FIELD(Loc_u8TempReg,ISC01,INT0_SENSECTRL);
			MCUCR = Loc_u8TempReg;
		#else
			Loc_EXTIErrorStatus = EXTI_enuInvalidSenseControl;
			return Loc_EXTIErrorStatus;
		#endif
	#else
		Loc_EXTIErrorStatus = EXTI_enuInvalidIntActStatus;
		return Loc_EXTIErrorStatus;
	#endif
	
	#if( INT2_MODE == INT_DISABLE) /*check INT Active Status*/
	/* CLEAR the corresponding Pin in the GICR Register using the MACRO*/
		CLR_BIT(GICR,INT2);
	
	#elif	(INT2_MODE == INT_ENABLE) /*check INT Active Status*/
		/* SET the corresponding Pin in the GICR Register using the MACRO*/
		SET_BIT(GICR,INT2);
		#if	(INT2_SENSECTRL == INT2_FALLING_EDGE)  /* Special sense options for INT2 Only 
		***SET the corresponding Pin in the MCUSR Register using the MACRO*/
			SET_BIT(MCUSR,ISC2);
		#elif	(INT2_SENSECTRL == INT2_RISING_EDGE)
			CLR_BIT(MCUSR,ISC2);
		#else
			Loc_EXTIErrorStatus = EXTI_enuInvalidSenseControl;
			return Loc_EXTIErrorStatus; 
		#endif
		
	#else 
		return Loc_EXTIErrorStatus;
	#endif
		
	return Loc_EXTIErrorStatus;
			
}

