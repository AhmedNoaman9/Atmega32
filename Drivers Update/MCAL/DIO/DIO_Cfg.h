/*************************************************/
/*DIO Config FILE								 */ 
/*************************************************/



#ifndef DIO_CFG_H
#define DIO_CFG_H

#define conc_help(c7,c6,c5,c4,c3,c2,c1,c0)	(c7##c6##c5##c4##c3##c2##c1##c0)
#define conc(b0,b1,b2,b3,b4,b5,b6,b7)	conc_help(b0,b1,b2,b3,b4,b5,b6,b7)


#define DIO_DIR_INPUT	0
#define DIO_DIR_OUTPUT	1

#define DIO_INPUT_PULL_UP	0
#define DIO_INPUT_PULL_DOWN	1




extern const DIO_strPinCfg_t DIO_strPinCfg[32] ;

	 
#endif
	  