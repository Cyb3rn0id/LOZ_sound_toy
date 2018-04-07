/* 
 * LOZ (Legend Of Zelda) Sound Toy with PIC12F1572
 * 
 * (c) Giovanni Bernardo
 * http://www.settorezero.com
 * 
 * I've used a PIC12F1572 with 5 buttons connected on RA1 to RA5.
 * RA0/TX is connected to a cheap mp3/wav player module from China
 * based on JQ8400TF or QJ004-16S.
 * You need a microsd with some wav files on it numbered from 1 to 5
 * better have mono wav with a 44100Hz sampling rate.
 * Module has an integrated amplifier.
 *  * 
 * Tool for converting audio files on line:
 * https://audio.online-convert.com/convert-to-wav
 * 
 *  
 */

#include <xc.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include "usart.h"
#include "mp3serial.h"

#define _XTAL_FREQ  16000000
#pragma warning disable 520 // disable warnings: function "xyz" is never called

// config word is contained in config.c
// RA3 is used as Input, not as MCLR, so when you program
// the PICmicro, you must select "apply Vpp first than Vdd" in
// the PICkit options
// the USART module uses only TX, RA1 is disabled as RX
// so you can use it as GPIO
void system_init(void)
    {
    ANSELA=0; // no analog function
    TRISA=0x3F; // all port as inputs
    OPTION_REGbits.nWPUEN=0; // pullups enabled by individual WPUx register
    WPUA=0xFF; // pullups enabled on all ports
    ODCONA=0; // no open drain
    APFCON=0; // no alternate pin functions
    
    // oscillator config:
    OSCCONbits.SPLLEN=0; // PLL disabled
    OSCCONbits.IRCF=0b1111; // 16MHz
    OSCCONbits.SCS=0b10; // internal oscillator used
    __delay_ms(20);
    }

void main(void) 
    {
    system_init();
    usart_init();
    __delay_ms(20);
    mp3s_init();
    __delay_ms(700); // if this delay is less than 700mS, the setVolume command will not work...
    mp3s_setVolume(15);
    __delay_ms(10);
    
    while(1)
        {
        // check if a button is pressed
        // buttons are mounted on RA1 to to RA5 
        // and normally are tied to Vdd by internal pullups
        if ((PORTA & 0b00111110) != 0b00111110)
            {
            if (PORTAbits.RA1==0)
                {
                mp3s_playIndex(1);
                }
            else if (PORTAbits.RA2==0)
                {
                mp3s_playIndex(2);
                }
            else if (PORTAbits.RA3==0)
                {
                mp3s_playIndex(3);
                }
            else if (PORTAbits.RA4==0)
                {
                mp3s_playIndex(4);
                }
            else if (PORTAbits.RA5==0)
                {
                mp3s_playIndex(5);
                }
            // 2 seconds delay
            uint8_t c=10;
            while (c--)
                {
                __delay_ms(200);
                }         
            } // \at least 1 button pressed
        } // \while
    } // \main