/*******************************************/
/*         GIE Driver                 */
/*Target : ATMEGA32                        */
/*Author :Ahmed Noaman                    */
/*Date   :2023-01-25                         */
/*******************************************/

#ifndef GIE_H
#define GIE_H

#define		GIE		7


typedef enum
{
	GIE_enuOk =0,
	GIE_enuNotOk,
	
}GIE_tenuErrorStatus;




/**************************************************************
GIE Interrupt Enable Function
Input: Void
Output: GIE_tenuErrorStatus To report Error status through enum
****************************************************************/
GIE_tenuErrorStatus GIE_enuGlobalInterruptEnable(void);


/**************************************************************
GIE Interrupt Enable Function
Input: Void
Output: GIE_tenuErrorStatus To report Error status through enum
****************************************************************/
GIE_tenuErrorStatus GIE_enuGlobalInterruptDisable(void);





#endif /*GIE_H*/
