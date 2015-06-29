# ATmegaでUSARTでSTDOUTと割り込み入力

## 概要

* USARTでSTDOUTを使えるようにする
* USARTからの入力で割り込みを受け付ける

## 環境

* CrossPack for AVR
* ATmega88(ATmega88V)
* AVRISP2
* FT-232R(UART-USB変換器)

## 接続

28PinDIPのATmegaなら

* RX,PD0(ピン2) を UART-USB変換器のTXへ
* TX,PD1(ピン3) を UART-USB変換器のRXへ
* UART-USB変換器のGNDをGNDへ

## 初期化

	serial_init(usart_recieve);
	sei();

で初期化する。usart\_recieveには受信時のコールバック用の関数を指定。

受信を使わない場合はNULLにする。

受信を使う場合は初期化後に sei() で割り込みを許可する必要がある。

## サンプルコード

* CPUクロックスピードとボーレートはMakefile(avr-gccの-Dオプション)もしくはヘッダファイルに設定。
* 「Hello World! 番号」を表示し続けて、受信があったら「recieved: 文字」を表示する。


## 参考URL
[Simple Serial Communications With AVR Libc](http://www.appelsiini.net/2011/simple-usart-with-avr-libc)

[Interrupt Driven UART Serial Communication for Atmel AVR](http://www.electroons.com/blog/2013/02/interrupt-driven-uart-serial-communication-for-atmel-avr/)

[WormFood's AVR Baud Rate Calculator](http://wormfood.net/avrbaudcalc.php)

[LUFA Serial_AVR8.c](https://github.com/abcminiuser/lufa/blob/master/LUFA/Drivers/Peripheral/AVR8/Serial_AVR8.c)

