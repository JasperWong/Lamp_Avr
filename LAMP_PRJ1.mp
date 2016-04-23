NOTE: AVR Code addresses are word addresses
All other addresses (including ones in FLASH) are byte addresses

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                             lit   0054   0004 =      4. bytes (rel,con,rom)

       Addr  Global Symbol
      -----  --------------------------------
       0054  __lit_start
       0058  __lit_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            text   0058   063E =   1598. bytes (rel,con,rom)

       Addr  Global Symbol
      -----  --------------------------------
       002C  __text_start
       002C  __start
       004E  _exit
       004F  _delay_nms
       005E  _delay_nus
       006C  _main
       00B5  _MPU_6050_init
       00C9  _Get_data
       00DE  _hc05_init
       00EE  _sent
       00F7  _twi_init
       0100  _twi_write
       013D  _twi_read
       018B  _Usart_init
       0196  _USART_Transmit
       019A  _USART_Receive
       019E  _newline
       01A2  _blank
       01A4  push_xgset303C
       01AB  pop_xgset303C
       01B2  neg32
       01BB  lpm32
       01CF  fpint
       0201  uint2fp
       0203  int2fp
       020C  ulong2fp
       020E  long2fp
       0225  fpdiv1
       022E  fpdiv2
       0238  fpdiv1x
       0244  fpdiv2x
       02BF  unpacks
       02C7  tstR16_R19
       02CF  unpacku
       02E8  normalize_and_pack
       031D  pack
       032D  saveFPRegs
       033C  restoreFPRegs
       034B  __text_end

Area                               Start  End    Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                          vector   0000   0004 =      4. bytes (abs,ovr,rom)

Files Linked      [ module(s) ]

D:\iccv7avr\lib\crtatmega.o	[ crtatmega.s ]
delay.o	[ delay.c ]
main.o	[ main.c ]
MPU_6050.o	[ MPU_6050.c ]
sent.o	[ sent.c ]
twi.o	[ twi.c ]
usart.o	[ usart.c ]
<library>	[ gpusha.s, lneg.s, lpm32.s, fpint.s, int2fp.s, fpdiv_new.s, fputil.s ]

User Global Definitions

ram_end = 0x45f
hwstk_size = 0x1e

User Base Address Definitions

func_lit = 0x54
data = 0x60
eeprom:0.512

