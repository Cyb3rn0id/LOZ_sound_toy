/*
 * Config word for PIC12F1572
 * as used in Sound Toy Project
 * by Giovanni Bernardo
 * http://www.settorezero.com
 *  
 */

// CONFIG1
#pragma config FOSC = INTOSC    // ->INTOSC oscillator; I/O function on CLKIN pin
#pragma config WDTE = OFF    // Watchdog Timer Enable->WDT disabled
#pragma config PWRTE = ON    // Power-up Timer Enable->PWRT enabled
#pragma config MCLRE = OFF    // MCLR Pin Function Select->MCLR/VPP pin function is GPIO
#pragma config CP = OFF    // Flash Program Memory Code Protection->Program memory code protection is disabled
#pragma config BOREN = ON    // Brown-out Reset Enable->Brown-out Reset enabled
#pragma config CLKOUTEN = OFF    // Clock Out Enable->CLKOUT function is disabled. I/O or oscillator function on the CLKOUT pin

// CONFIG2
#pragma config WRT = OFF    // Flash Memory Self-Write Protection->Write protection off
#pragma config PLLEN = OFF    // PLL Enable->4x PLL disabled
#pragma config STVREN = ON    // Stack Overflow/Underflow Reset Enable->Stack Overflow or Underflow will cause a Reset
#pragma config BORV = LO    // Brown-out Reset Voltage Selection->Brown-out Reset Voltage (Vbor), low trip point selected.
#pragma config LPBOREN = OFF    // Low Power Brown-out Reset enable bit->LPBOR is disabled
#pragma config LVP = OFF    // Low-Voltage Programming Enable->High-voltage on MCLR/VPP must be used for programming