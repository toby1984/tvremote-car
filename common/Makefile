INCLUDE_DIRS = -I/home/tobi/apps/arduino_ide/hardware/tools/avr/avr/include -I../includes -I/home/tobi/apps/arduino_ide//hardware/tools/avr/avr/include/util
LIB_DIR = 

# AVRCC_CHIP=atmega88
# AVRDUDE_CHIP = m88p
# CPU_FREQ=8000000

AVRCC_CHIP=atmega328p
AVRDUDE_CHIP = m328p
CPU_FREQ=16000000

OBJECTS = crc.o radio_common.o uart.o radio_sender.o timer16.o radio_receiver.o i2c.o

COMPILE = avr-gcc

all: main

.c.o:
	$(COMPILE) -DF_CPU=$(CPU_FREQ) -mmcu=$(AVRCC_CHIP) -Wall -Os -Wno-main $(INCLUDE_DIRS) -c $< -o $@

main: $(OBJECTS)

clean:
	rm -f $(OBJECTS)
