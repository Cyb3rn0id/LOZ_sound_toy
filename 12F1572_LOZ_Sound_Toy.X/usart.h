/*
 * USART library
 * for Microchip PICmicro
 * 
 * (c) 2018 Giovanni Bernardo
 * http://www.settorezero.com
 *  
 */

#include <stdint.h>
#define  _XTAL_FREQ 16000000

#define BAUDRATE 9600
// with	SYNC=0 , BRG16=0 , BGRH=1
// baudrate is: FOSC/[16 (n+1)] where n= SPBRGH:SPBRGL
#define SPBRGVAL (int)(((long)_XTAL_FREQ-(long)BAUDRATE)/(16*(long)BAUDRATE))

extern void usart_init(void);
extern void putch(uint8_t byte);
extern uint8_t getch(void);