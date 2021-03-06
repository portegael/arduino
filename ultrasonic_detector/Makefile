# Compiler, linker and arduino tools
CC=avr-gcc
CXX=avr-g++
LXX=avr-ld
OBJCOPY=avr-objcopy
AVRDUDE=avrdude -F -V

CFLAGS=-Wall -Os -DF_CPU=$(F_CPU) -mmcu=$(MCU)
CPPFLAGS=$(INCLUDE) $(CFLAGS)

LDFLAGS_XX= -Wl,--gc-section

INCLUDE=-I/opt/arduino-1.6.8/hardware/tools/avr/avr/include -I/opt/arduino-1.6.8/hardware/arduino/avr/cores/arduino/
BIN_FORMAT=ihex

# Arduino parameters
MCU=atmega2560
F_CPU=16000000UL


PORT=/dev/ttyACM0
BAUD=115200
PROTOCOL=stk500v2
PART=$(MCU)

# Input / output files
TARGET=detector

SRC_FILES=ledManager.cpp main.cpp

OBJECT_FILES=$(SRC_FILES:.cpp=.o)

$(TARGET): $(OBJECT_FILES)
	$(CXX) $(CPPFLAGS) $(LDFLAGS_XX) $(OBJECT_FILES) -o detector

$(OBJECT_FILES):$(SRC_FILES)
	$(CXX) $(CPPFLAGS) $(LDFLAGS_XX) -c $^
	
%.hex: $(TARGET)
	$(OBJCOPY) -O $(BIN_FORMAT) -R .eeprom $< $@

# Commands
RM=rm -f
SUDO=sudo
.PHONY: all
all: $(TARGET)

.PHONY: upload
upload: $(TARGET).hex
	$(SUDO) $(AVRDUDE) -c $(PROTOCOL) -p $(PART) -P $(PORT) -b $(BAUD) -U flash:w:$<

.PHONY: clean
clean:
	@echo "****** Clean ******"
	$(RM) *.hex *.o *.obj *.out $(TARGET)