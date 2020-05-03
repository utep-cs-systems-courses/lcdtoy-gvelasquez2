COMMON_OBJECTS 	=
CPU		= msp430g2553
CFLAGS		= -mmcu=${CPU} -I../h
LDFLAGS		= ../project/lib/libTimer.a -L/opt/ti/msp430_gcc/include


CC		= msp430-elf-gcc
AS		= msp430-elf-as
AR		= msp430-elf-ar

all: lcdtoy.elf

lcdtoy.elf:${COMMON_OBJECTS} main.o p1_interrupt_handler.o switches.o led.o assemblyCode.o buzzer.o lcddraw.o lcdutils.o toyShapes.o ../project/lib/libTimer.a
	${CC} $(CFLAGS) $^ $(LDFLAGS) -o $@

load: lcdtoy.elf
	msp430loader.sh lcdtoy.elf

clean:
	rm -f *.o *.elf

main.c: buzzer.h led.h switches.h
switches.c: switches.h assemblyCode.h toyShapes.h
led.c: led.h
buzzer.c: buzzer.h
p1_interrupt_handler.c: switches.h
assemblyCode.s: switches.h led.h
lcddraw.c: lcdutils.h lcddraw.h
lcdutils.c: lcdutils.h
toyShapes.c: lcdutils.h lcddraw.h
