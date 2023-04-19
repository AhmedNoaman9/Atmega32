/*******************************************/
/*         EXTI Driver                 */
/*Target : ATMEGA32                        */
/*Author :Ahmed Noaman                    */
/*Date   :2023-01-27                         */
/*******************************************/




#ifndef EXTI_CFG_H
#define EXTI_CFG_H


#define INT0_MODE	INT_ENABLE
#define INT1_MODE	INT_ENABLE
#define INT2_MODE	INT_ENABLE


#define INT0_SENSECTRL	INT_RISING_EDGE
#define INT1_SENSECTRL	INT_RISING_EDGE

/* INT2 Only works On Rising Or Falling Edges Only */
#define INT2_SENSECTRL	INT2_RISING_EDGE




extern const EXTI_strEXTICfg_t EXTI_strExtiCfg[EXTI_enuEXTINumber];



#endif /*EXTI_CFG_H*/
