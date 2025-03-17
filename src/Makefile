MMCU_TYPE = atmega48
CFLAGS = -I/usr/lib/avr/include -D__AVR_ATmega48P__
all: atmega-xmas-star.hex

clean:
	rm -f *.o *.elf *.hex

main.o: main.c gpio.h timer.h
	avr-gcc -g -Os -mmcu=$(MMCU_TYPE) $(CFLAGS) -c main.c

timer.o: timer.c timer.h
	avr-gcc -g -Os -mmcu=$(MMCU_TYPE) $(CFLAGS) -c timer.c

gpio.o: gpio.c gpio.h
	avr-gcc -g -Os -mmcu=$(MMCU_TYPE) $(CFLAGS) -c gpio.c

atmega-xmas-star.elf: main.o timer.o gpio.o
	avr-gcc -g -mmcu=$(MMCU_TYPE) -o atmega-xmas-star.elf main.o timer.o gpio.o

atmega-xmas-star.hex: atmega-xmas-star.elf
	avr-objcopy -j .text -j .data -O ihex atmega-xmas-star.elf atmega-xmas-star.hex

