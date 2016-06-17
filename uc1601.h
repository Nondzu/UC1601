/*
 * uc1601.h
 *
 *  Created on: 8 cze 2016
 *      Author: Kamil Nonckiewicz
 */

#ifndef UC1601_H_
#define UC1601_H_

#include <avr/interrupt.h>
#include <avr/io.h>
#include <avr/pgmspace.h>
#include <avr/eeprom.h>
#include <util/delay.h>
#include <avr/sleep.h>
#include <stdlib.h>


// SETTINGS

#define LCDWIDTH 		128
#define LCDHEIGHT 		32




#define BUFF_SIZE		(LCDHEIGHT/8)*LCDWIDTH
#define LCD_LINES		LCDHEIGHT/8
#define TRUE 			1
#define FALSE 			0

// Makra upraszczaj¹ce dostêp do portów (www.atnel.pl)
// *** PORT
#define PORT(x) SPORT(x)
#define SPORT(x) (PORT##x)
// *** PIN
#define PIN(x) SPIN(x)
#define SPIN(x) (PIN##x)
// *** DDR
#define DDR(x) SDDR(x)
#define SDDR(x) (DDR##x)

#define SDA_PIN		PC7
#define SCK_PIN		PC1
#define CD_PIN		PC2
#define RST_PIN		PC3
#define CS0_PIN		PC4
#define LIGHT_PIN	PC5

#define SDA_PORT	C
#define SCK_PORT	C
#define CD_PORT		C
#define RST_PORT	C
#define CS0_PORT	C
#define LIGHT_PORT	C

//CHANGE STATE
#define SDA_PIN_SET		PORT( SDA_PORT ) |= (1<<SDA_PIN)
#define SDA_PIN_RST		PORT( SDA_PORT ) &= ~(1<<SDA_PIN)
#define SDA_PIN_TOG		PORT( SDA_PORT ) ^= (1<<SDA_PIN)

#define SCK_PIN_SET		PORT( SCK_PORT ) |= (1<<SCK_PIN)
#define SCK_PIN_RST		PORT( SCK_PORT ) &= ~(1<<SCK_PIN)
#define SCK_PIN_TOG		PORT( SCK_PORT ) ^= (1<<SCK_PIN)

#define CD_PIN_SET		PORT( CD_PORT ) |= (1<<CD_PIN)
#define CD_PIN_RST		PORT( CD_PORT ) &= ~(1<<CD_PIN)
#define CD_PIN_TOG		PORT( CD_PORT ) ^= (1<<CD_PIN)

#define RST_PIN_SET		PORT( RST_PORT ) |= (1<<RST_PIN)
#define RST_PIN_RST		PORT( RST_PORT ) &= ~(1<<RST_PIN)
#define RST_PIN_TOG		PORT( RST_PORT ) ^= (1<<RST_PIN)

#define CS0_PIN_SET		PORT( CS0_PORT ) |= (1<<CS0_PIN)
#define CS0_PIN_RST		PORT( CS0_PORT ) &= ~(1<<CS0_PIN)
#define CS0_PIN_TOG		PORT( CS0_PORT ) ^= (1<<CS0_PIN)

#define LIGHT_PIN_SET	PORT( LIGHT_PORT ) |= (1<<LIGHT_PIN)
#define LIGHT_PIN_RST	PORT( LIGHT_PORT ) &= ~(1<<LIGHT_PIN)
#define LIGHT_PIN_TOG	PORT( LIGHT_PORT ) ^= (1<<LIGHT_PIN)
//

// COMMANDS
#define BLACK 1
#define WHITE 0

#define CMD_DISPLAY_OFF   0xAE
#define CMD_DISPLAY_ON    0xAF

#define CMD_SET_DISP_START_LINE  0x40
#define CMD_SET_PAGE  0xB0

#define CMD_SET_COLUMN_UPPER  0x10
#define CMD_SET_COLUMN_LOWER  0x00

#define CMD_SET_ADC_NORMAL  0xA0
#define CMD_SET_ADC_REVERSE 0xA1

#define CMD_SET_DISP_NORMAL 0xA6
#define CMD_SET_DISP_REVERSE 0xA7

#define CMD_SET_ALLPTS_NORMAL 0xA4
#define CMD_SET_ALLPTS_ON  0xA5
#define CMD_SET_BIAS_9 0xA2
#define CMD_SET_BIAS_7 0xA3

#define CMD_RMW  0xE0
#define CMD_RMW_CLEAR 0xEE
#define CMD_INTERNAL_RESET  0xE2
#define CMD_SET_COM_NORMAL  0xC0
#define CMD_SET_COM_REVERSE  0xC8
#define CMD_SET_POWER_CONTROL  0x28
#define CMD_SET_RESISTOR_RATIO  0x20
#define CMD_SET_VOLUME_FIRST  0x81
#define CMD_SET_VOLUME_SECOND  0
#define CMD_SET_STATIC_OFF  0xAC
#define CMD_SET_STATIC_ON  0xAD
#define CMD_SET_STATIC_REG  0x0
#define CMD_SET_BOOSTER_FIRST  0xF8
#define CMD_SET_BOOSTER_234  0
#define CMD_SET_BOOSTER_5  1
#define CMD_SET_BOOSTER_6  3
#define CMD_NOP  0xE3
#define CMD_TEST  0xF0
// END COMMANDS

uint8_t u1601c_buffer[BUFF_SIZE];

// FUNCTION FOR USER
uint8_t uc1601_init(void);
void uc1601_light(uint8_t state);	// TRUE-LIGHT ON, FALSE-LIGHT OF
void uc1601_reset(void);

//clear function
uint8_t uc1601_clear_display(void);
uint8_t uc1601_clear_buff(void);
uint8_t uc1601_clear_all(void);

uint8_t uc1601_send_buff_to_display(uint8_t * buff);

uint8_t c1601_drawchar(uint8_t x, uint8_t line, char c);

uint8_t uc1601_drawchar2(uint8_t x, uint8_t line, char c);
uint8_t uc1601_drawstring2_P(uint8_t x, uint8_t line,  const char  *str);
uint8_t uc1601_drawstring2(uint8_t x, uint8_t line, char  *str);
uint8_t uc1601_drawint2(uint8_t x, uint8_t line,int value, int radix);


uint8_t uc1601_drawstring_P(uint8_t x, uint8_t line,  const char  *str);
uint8_t uc1601_drawstring(uint8_t x, uint8_t line, char  *str);
uint8_t uc1601_drawint(uint8_t x, uint8_t line,int value, int radix);
void uc1601_setpixel(uint8_t x, uint8_t y, uint8_t color);
#endif /* UC1601_H_ */
