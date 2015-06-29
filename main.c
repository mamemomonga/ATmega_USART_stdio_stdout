#include "main.h"

#include <avr/io.h>
#include <util/delay.h>
#include <avr/pgmspace.h>
#include <avr/interrupt.h>

#include "serial.h"

void usart_recieve(char buf) {
	printf("recieve: %c\r\n",buf);
}

int main(void) {

	serial_init(usart_recieve);
	sei();

	_delay_ms(1000);

	// printf_Pを使うとプログラムメモリからフォーマットを呼び出すことができる。
	printf_P(PSTR("\r\n --- start --- \r\n"));

	uint8_t count=0;
    for(;;){
		// 以下の cli() sei() はprint中に割り込みのprintが実行されると
		// 文字化けしてしまうので、それを防止するため。
		cli();
		printf_P(PSTR("Hello World! %2d\r\n"),count);
		sei();

		count++;
		_delay_ms(500);
	}

}

