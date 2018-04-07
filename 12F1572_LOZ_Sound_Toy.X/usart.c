/*
 * USART library
 * for Microchip PICmicro
 * 
 * (c) 2018 Giovanni Bernardo
 * http://www.settorezero.com
 *  
 */

#include <xc.h>
#include <stdio.h>
#include <stdint.h>
#include "usart.h"

void putch(uint8_t byte) 
	{
	/* output one byte */
	while(!TXIF)	/* set when register is empty */
		continue;
	TXREG = byte;
	}

uint8_t getch(void) 
	{
	/* retrieve one byte */
	while(!RCIF)	/* set when register is not empty */
		continue;
	return RCREG;	
	}

void usart_init(void)
    {
    BAUDCONbits.ABDEN=0; // no autobaud
    BAUDCONbits.ABDOVF=0; // no overflow
    BAUDCONbits.BRG16=0; // 8bit baudrate generator
    BAUDCONbits.SCKP=0; // non-inverted polarity
    BAUDCONbits.WUE=0; // normal receive, no wakeup

    RCSTAbits.ADDEN=0; // no addressing
    RCSTAbits.CREN=0; // RX not enabled
    RCSTAbits.RX9=0; // 8 bit receive
    RCSTAbits.SPEN=1; // serial port enabled
    
    TXSTAbits.BRGH=1; // high speed
    TXSTAbits.SENDB=0; // sync break transmission complete
    TXSTAbits.SYNC=0; // asynchronous
    TXSTAbits.TX9=0; // 8 bit transmit
    TXSTAbits.TXEN=1; // TX enabled

    // baud rate 9600, calculated in usart.h
    SPBRGL=SPBRGVAL & 0xFF;
	SPBRGH=SPBRGVAL << 8;
    }
