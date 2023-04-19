/*******************************************/
/*         SSEG Driver                 */
/*Target : ATMEGA32                        */
/*Author :NO3M4N                    */
/*Date   :2023-01-20                         */
/*******************************************/

#ifndef SSEG_CFG_H
#define SSEG_CFG_H

#include "SSEG.h"


#define ACTIVE_LOW	0
#define ACTIVE_HIGH	1





/* ENTER NAMES FOR YOUR SSEGs AND THEIR NUMBER */
#define SSEG1	0
#define SSEG2	1


#define NUMBER_OF_SSEG 2


#define SSEG_MAX_LEDS 7


extern const SSEG_tstrSSEGCfg_t SSEG_tstrSsegCfg[NUMBER_OF_SSEG];


#endif /*SSEG_CFG_H*/
