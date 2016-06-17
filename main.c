/*
 * main.c
 *
 *  Created on: 8 cze 2016
 *      Author: Kamil Nonckiewicz
 */

#include <avr/interrupt.h>
#include <avr/io.h>
#include <avr/pgmspace.h>
#include <avr/eeprom.h>
#include <util/delay.h>
#include <avr/sleep.h>
#include "uc1601.h"
int main(void)

{
	_delay_ms(10);
	uc1601_init();
	_delay_ms(300);
	uc1601_clear_display();
	_delay_ms(300);
	//uc1601_drawstring_P(1,1,PSTR("MALE LITERY"));
	//uc1601_drawstring(2,2,"nie mam");
	  uc1601_send_buff_to_display(u1601c_buffer);
	  static int16_t licznik=256;
		uc1601_drawstring2_P(17,0,PSTR(" teskt off buffor :D LLLLLLLLLLLLLL"));
	while(1){

		licznik+=10;
		if(licznik>120){
			licznik=0;
			uc1601_drawstring2_P(0,2,PSTR("                               "));
		}

		uc1601_drawchar2(licznik,2,'B');


		//uc1601_send_buff_to_display(u1601c_buffer);
		_delay_ms(200);


	}
}
