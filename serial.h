#ifndef _SERIAL_H_
#define _SERIAL_H_

#include <avr/io.h>
#include <stdio.h>

// F_CPU, BAUDはMakefileで設定
// avr-gcc -Wall -Os -DF_CPU=$(CLOCK)UL -DBAUD=$(BAUD) -mmcu=$(DEVICE) -std=c99

// #define F_CPU 160000000L
// #define BAUD  38400

typedef void (* T_USART_RECIEVE)(char);

void serial_init(T_USART_RECIEVE fp_ur);
void uart_putchar(char c);

#endif

