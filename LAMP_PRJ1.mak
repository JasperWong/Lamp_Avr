CC = iccavr
LIB = ilibw
CFLAGS =  -e -D__ICC_VERSION=722 -DATMega16  -l -g -MLongJump -MHasMul -MEnhanced 
ASFLAGS = $(CFLAGS) 
LFLAGS =  -g -e:0x4000 -ucrtatmega.o -bfunc_lit:0x54.0x4000 -dram_end:0x45f -bdata:0x60.0x45f -dhwstk_size:30 -beeprom:0.512 -fihx_coff -S2
FILES = delay.o main.o MPU_6050.o sent.o twi.o usart.o 

LAMP_PRJ1:	$(FILES)
	$(CC) -o LAMP_PRJ1 $(LFLAGS) @LAMP_PRJ1.lk   -lcatmega
delay.o: .\delay.h D:\iccv7avr\include\iom16v.h .\twi.h .\MPU_6050.h .\sent.h
delay.o:	delay.c
	$(CC) -c $(CFLAGS) delay.c
main.o: D:\iccv7avr\include\iom16v.h .\twi.h .\delay.h .\MPU_6050.h .\sent.h .\usart.h
main.o:	main.c
	$(CC) -c $(CFLAGS) main.c
MPU_6050.o: .\MPU_6050.h D:\iccv7avr\include\iom16v.h .\delay.h .\twi.h .\sent.h
MPU_6050.o:	MPU_6050.c
	$(CC) -c $(CFLAGS) MPU_6050.c
sent.o: .\sent.h D:\iccv7avr\include\iom16v.h .\twi.h .\delay.h .\MPU_6050.h
sent.o:	sent.c
	$(CC) -c $(CFLAGS) sent.c
twi.o: .\twi.h D:\iccv7avr\include\iom16v.h .\delay.h .\MPU_6050.h .\sent.h
twi.o:	twi.c
	$(CC) -c $(CFLAGS) twi.c
usart.o: D:\iccv7avr\include\iom16v.h D:\iccv7avr\include\macros.h D:\iccv7avr\include\AVRdef.h .\usart.h
usart.o:	usart.c
	$(CC) -c $(CFLAGS) usart.c
