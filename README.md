# LEGEND OF ZELDA (LOZ) Sound Toy

I'm preparing a gift for my Son. He's in love with Nintendo's "The Legend Of Zelda" (ゼルダの伝説 - Zeruda no densetsu) saga. After he have completed some episodes, he's now playing to "Phantom Hourglass" one, so I want he to find his gift in a treasure chest. I'll connect a switch to chest cover so when he will open it, the treasure fanfare will start, just as in the game he love!

Toy uses a PIC12F1572, project is for Microchip MPLAB X and XC8 compiler. In the SD folder are placed wav files I've used.
5 buttons are attached to RA1 to RA5 ports. Individual pull-up resistors are enabled on those ports. USART module uses only TX on RA0, RX is disabled so RA1 can be used as normal GPIO.

Also RA3 (MCRL/VPP) is used as Input, so if you encounter difficulties upon programming, remember to set "Enable VPP first VDD" in the PICkit options. I've used the PICkit 4 for programming it.

Module works also powered by an MT3608 switching step-up module and 2 AA batteries. If you want to sound on chest cover opening, is better to wire the switch on the batteries and hardwire the song play, so after the circuit is powered by the switch, the song starts. In this manner there is no power consumption in stand-by mode since batteries are completely disconnected.

This is the WAV/MP3 module I've used:

![JQ8400TF module](https://github.com/Cyb3rn0id/mp3Serial_JQ8400TF/blob/master/documents/mp3wav_module.jpg)

## Videos 
  
Sound toy made as code shows:  

[![LOZ sound toy](https://img.youtube.com/vi/GNW5sxZnXtE/0.jpg)](https://www.youtube.com/watch?v=GNW5sxZnXtE)

Variant for in-treasure chest: no buttons on I/Os, first song played at program start-up and then program stuck in infinite loop. The switch on the lid is attached directly on the batteries. There is a little voltage booster for converting the 3V from AA batteries to 5V (mp3 module doesn't work at 3V):  

[![LOZ trasure chest](https://img.youtube.com/vi/YiDNlb1nQaI/0.jpg)](https://www.youtube.com/watch?v=YiDNlb1nQaI)

## Links  
- Here you can find [more info about the module](http://www.settorezero.com/wordpress/en/un-player-wavmp3-economico-controllabile-da-porta-seriale-libreria-per-arduino-e-esp8266/)(sorry, italian language, but you can use google translate)
- I've also written a [library for this module to be used with Arduino and ESP8266](https://github.com/Cyb3rn0id/mp3Serial_JQ8400TF)
- [PIC12F1572 Datasheet](https://www.microchip.com/wwwproducts/en/PIC12F1572)
