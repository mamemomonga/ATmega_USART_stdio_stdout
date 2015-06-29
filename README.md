# ATmegaのUSARTでSTDOUTと割り込み入力

## 概要

* USARTでSTDOUTを使えるようにする
* USARTからの入力で割り込みを受け付ける

printf()が使えて、同時に入力時の割り込みも可能になる。

## 環境

* CrossPack for AVR
* ATmega88(ATmega88V)
* AVRISPmk2
* FT-232R(UART-USB変換器)

## 接続と書き込み

28PinDIPのATmegaなら

* RX,PD0(ピン2) を UART-USB変換器のTXへ
* TX,PD1(ピン3) を UART-USB変換器のRXへ
* UART-USB変換器のGNDをGNDへ
* AVRISPmk2を接続

make fuse でフューズビットの書き込み、ATmega88, 内蔵クロック8MHz, 8分周なし
make でビルド、make flash で AVRISPmk2を使って書き込みという設定になっている。

フューズビットを書き込まず買ってきたままだと8分周有効になっているのでうまく動かない。

## 初期化

	serial_init(usart_recieve);
	sei();

で初期化する。usart\_recieveには受信時のコールバック用の関数を指定。

受信を使わない場合はNULLにする。

受信を使う場合は初期化後に sei() で割り込みを許可する必要がある。

## サンプルコード

* CPUクロックスピード(8MHz)とボーレート(38400)はMakefile(avr-gccの-Dオプション)もしくはヘッダファイルに設定。
* 「Hello World! 番号」を表示し続けて、受信があったら「recieved: 文字」を表示する。

## 参考URL
[Simple Serial Communications With AVR Libc](http://www.appelsiini.net/2011/simple-usart-with-avr-libc)

[Interrupt Driven UART Serial Communication for Atmel AVR](http://www.electroons.com/blog/2013/02/interrupt-driven-uart-serial-communication-for-atmel-avr/)

[WormFood's AVR Baud Rate Calculator](http://wormfood.net/avrbaudcalc.php)

[LUFA Serial_AVR8.c](https://github.com/abcminiuser/lufa/blob/master/LUFA/Drivers/Peripheral/AVR8/Serial_AVR8.c)

## Crosspack For AVR
[CrossPack for AVR](https://www.obdev.at/products/crosspack/index.html)

OSX向けAVR開発環境。avr-gcc, avrdudeなどがセットで入っている。

インストール後、/usr/local/CrossPack-AVR/bin にパスを通す。

## 必要なときだけパスを通したい

	#!/bin/sh -x
	export PATH=/usr/local/CrossPack-AVR/bin:$PATH
	cd ~/Documents/AVR
	pwd

というような avr.sh をHOMEディレクトリにおいて、ターミナルを開く毎に

	$ . ~/avr.sh

とすると必要なときにパスを追加できて便利。
3行目のcd のところにはドキュメントなどを置いている任意のフォルダを指定しておく。


