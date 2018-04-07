/*
 * JQ8400TF or QJ004-16S mp3/wav player module
 * for Microchip PICmicro
 * 
 * (c) 2018 Giovanni Bernardo
 * http://www.settorezero.com
 *  
 */

#include <stdint.h>
#include <stdio.h>

#define	BYTE_START		0x7E
#define BYTE_STOP		0xEF

// 1 bytes commands
#define CMD_PLAY            0x01
#define CMD_PAUSE           0x02
#define CMD_NEXT_SONG		0x03
#define CMD_PREV_SONG		0x04
#define CMD_VOLUME_UP   	0x05
#define CMD_VOLUME_DOWN 	0x06
#define CMD_FORWARD 		0x0A
#define CMD_REWIND  		0x0B
#define CMD_STOP            0x0E
#define CMD_STOP_INJECT 	0x0F

// 2 bytes commands
#define CMD_SET_VOLUME 		0x31	// Set Volume: second byte is volume level: 0x00 to 0x30
#define CMD_SEL_DEV 		0x35	// Select Device
    #define DEV_TF              0x01	// second of "Select Device" command: only Trans-Flash is selectable on this chip revision (JQ8400TF)

#define CMD_IC_MODE 		0x35
    #define MODE_WAKE_UP        0x02	// second byte of "IC Mode" command 	
    #define MODE_SLEEP          0x03	// ""	
    #define MODE_RESET          0x05	// ""

// 3 bytes commands
#define CMD_PLAY_W_VOL 		0x31	// 2nd byte is volume level: 0x00 to 0x30, 3rd byte is song index (0x00 to 0xFF)
#define CMD_PLAY_INDEX   	0x41	// after 0x41, 2 bytes are expected: high byte and low byte of song index (0x0001 - 0xFFFF)
#define CMD_PLAY_DIR_INDEX 	0X42	// after 0x42, 2 bytes are expected: first byte is the directory index, second byte is the song index
#define CMD_INJECT_INDEX 	0X43	// Same as 0x41, but "inject" (prepare the song) without playing it, you must use play command after

// Special commands
#define	CMD_SET_PLAY_MODE		0x33
	#define PLAY_MODE_ALL		0x00	// starts from first song, plays all and then return to first, continuously
	#define PLAY_MODE_STUP		0x01	// ? don't works
	#define PLAY_MODE_REPEAT	0x00	// ! warning: this is a 3 bytes command: 0x33, 0x00 and then the song index to repeat
	
#define CMD_PLAY_COMBINE        0x45	// play combination up to 15 songs, followed by folder index and song index, up to 15. Example:
										// 7E 08 45 01 05 02 01 01 03 EF : plays song 5 in folder 1, then song 1 in folder 2 and then song 3 in folder 1

extern void mp3s_init(uint8_t v); // init module with volume v
extern void mp3s_setVolume(uint8_t v); // set volume to v (0x00 to 0x30)
extern void mp3s_playIndex(uint16_t i); // play i
extern void mp3s_play(void);
extern void mp3s_pause(void);
extern void mp3s_next(void);
extern void mp3s_prev(void);
extern void mp3s_volumeUp(void);
extern void mp3s_volumeDown(void);
extern void mp3s_forward(void);
extern void mp3s_rewind(void);
extern void mp3s_stop(void);
extern void mp3s_stopInject(void);
extern void mp3s_playWithVolume(uint8_t i, uint8_t v); // play i with volume v
extern void mp3s_injectSong(uint16_t i); // inject i
extern void mp3s_playFromFolder(uint8_t i, uint8_t f); // play i from folder f

extern void _mp3s_w1(uint8_t c);    
extern void _mp3s_w2(uint8_t c, uint8_t d);	
extern void _mp3s_w3(uint8_t c, uint16_t d);    
