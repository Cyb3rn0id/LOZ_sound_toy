/*
 * JQ8400TF or QJ004-16S mp3/wav player module
 * for Microchip PIC micro controllers
 * 
 * (c) 2018 Giovanni Bernardo
 * http://www.settorezero.com
 *  
 */

#include "mp3serial.h"
#include "usart.h"

void _mp3s_w1(uint8_t c)
	{
	putch(BYTE_START);
	putch(2);
	putch(c); 
	putch(BYTE_STOP);
	};
    
void _mp3s_w2(uint8_t c, uint8_t d)
	{
	putch(BYTE_START);
    putch(3);
    putch(c);
    putch(d);
    putch(BYTE_STOP);
	};
	
void _mp3s_w3(uint8_t c, uint16_t d)
	{
	putch(BYTE_START);
	putch(4);
	putch(c); 
	putch((uint8_t)(d>>8));
	putch((uint8_t) d);
	putch(BYTE_STOP);
	};
    
 void mp3s_init(void)
	{
	_mp3s_w2(CMD_SEL_DEV,DEV_TF);
	};

 void mp3s_setVolume(uint8_t v)
	{
	_mp3s_w2(CMD_SET_VOLUME, v);
	};

// Play song index (0x0000 - 0xFFFF)    
 void mp3s_playIndex(uint16_t i)
	{
	_mp3s_w3(CMD_PLAY_INDEX, i);
	};
    
void mp3s_play(void)
	{
	_mp3s_w1(CMD_PLAY);
	}
	
void mp3s_pause(void)
	{
	_mp3s_w1(CMD_PAUSE);
	}

void mp3s_next(void)
	{
	_mp3s_w1(CMD_NEXT_SONG);
	}

void mp3s_prev(void)
	{
	_mp3s_w1(CMD_PREV_SONG);
	}

void mp3s_volumeUp(void)
	{
	_mp3s_w1(CMD_VOLUME_UP);
	}
	
void mp3s_volumeDown(void)
	{
	_mp3s_w1(CMD_VOLUME_DOWN);
	}

void mp3s_forward(void)
	{
	_mp3s_w1(CMD_FORWARD);
	}
	
void mp3s_rewind(void)
	{
	_mp3s_w1(CMD_REWIND);
	}
	
void mp3s_stop(void)
	{
	_mp3s_w1(CMD_STOP);
	}
	
void mp3s_stopInject(void)
	{
	_mp3s_w1(CMD_STOP_INJECT);
	}

// play song INDEX with volume VOLUME
void mp3s_playWithVolume(uint8_t i, uint8_t v)
	{
	_mp3s_w3(CMD_PLAY_W_VOL, (uint16_t)((v<<8)|i)); 
	};

// inject song INDEX (0x0000 - 0xFFFF)
void mp3s_injectSong(uint16_t i)
	{
	_mp3s_w3(CMD_INJECT_INDEX, i); 
	};

// play song INDEX from folder FOLDER
void mp3s_playFromFolder(uint8_t i, uint8_t f)
	{
	_mp3s_w3(CMD_PLAY_DIR_INDEX, (uint16_t)((f<<8)|i)); 
	};
