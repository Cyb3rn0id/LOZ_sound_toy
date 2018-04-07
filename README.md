# LEGEND OF ZELDA (LOZ) Sound Toy

I'm preparing a gift for my Son. He's in love with Nintendo's "The Legend Of Zelda" (ゼルダの伝説 - Zeruda no densetsu) saga. After he have completed some episodes, he's now playing to "Phantom Hourglass" one, so I want he to find his gift in a treasure chest. I'll connect a switch to chest cover so when he will open it, the treasure fanfare will start, just as in the game he love!

Toy uses a PIC12F1572. 5 buttons are attached to RA1 to RA5 ports. Individual pull-up resistors are enabled on those ports. USART module uses only TX on RA0, RX is disabled so RA1 can be used as normal GPIO.

Also RA3 (MCRL/VPP) is used as Input, so if you encounter difficulties upon programming, remember to set "Enable VPP first VDD" in the PICkit options. I've used the PICkit 4 for programming it.

This is the WAV/MP3 module I've used:

![JQ8400TF module](https://github.com/Cyb3rn0id/mp3Serial_JQ8400TF/blob/master/documents/mp3wav_module.jpg)

Here is a video:
[![LOZ sound toy](https://img.youtube.com/vi/GNW5sxZnXtE/0.jpg)](https://www.youtube.com/watch?v=GNW5sxZnXtE)

More info on the module here: 
http://www.settorezero.com/wordpress/en/un-player-wavmp3-economico-controllabile-da-porta-seriale-libreria-per-arduino-e-esp8266/

I've also written a library for this module to be used with Arduino and ESP8266, you can find it here: https://github.com/Cyb3rn0id/mp3Serial_JQ8400TF
