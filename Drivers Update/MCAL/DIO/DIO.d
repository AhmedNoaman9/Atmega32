MCAL/DIO/DIO.o: MCAL/DIO/DIO.c LIB/Std_types.h LIB/Bit_math.h \
 MCAL/DIO/DIO.h MCAL/DIO/DIO_Cfg.h MCAL/DIO/DIO_Prv.h
	avr-gcc -c -I./HAL/LED -I./HAL/SSEG -I./HAL/SWITCH -I./LIB -I./MCAL/ADC -I./MCAL/DIO -I./MCAL/EXTI -I./MCAL/GIE -w -std=gnu99 -mmcu=atmega32 -B "C:\Program Files (x86)\Microchip Studio\7.0\Packs\atmel\ATmega_DFP\1.7.374\gcc\dev\atmega32" -O0 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums MCAL/DIO/DIO.c -o MCAL/DIO/DIO.o