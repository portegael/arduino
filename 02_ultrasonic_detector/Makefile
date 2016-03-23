# Compiler, linker and arduino tools
CC=avr-gcc
CXX=avr-g++
LXX=avr-ld
OBJCOPY=avr-objcopy
AVRDUDE=avrdude -F -V

CFLAGS=-Wall -Os -DF_CPU=$(F_CPU) -mmcu=$(MCU)
CPPFLAGS=$(INCLUDE) $(CFLAGS)

LDFLAGS_XX= #-Wl,--gc-section

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

SRC_FILES=main.cpp ledManager.cpp

OBJECT_FILES=$(SRC_FILES:.cpp=.o)

detector: main.o ledManager.o
	$(CXX) $(CPPFLAGS) $(LDFLAGS_XX) main.o ledManager.o -o detector

main.o: main.cpp
	$(CXX) $(CPPFLAGS) main.cpp

ledManager.o: ledManager.cpp
	$(CXX) $(CPPFLAGS) ledManager.cpp -c

%.hex: detector
	$(OBJCOPY) -O $(BIN_FORMAT) -R .eeprom $< $@

# Commands
RM = rm -f

.PHONY: all
all: $(TARGET)

#$(TARGET): $(OBJECT_FILES)
#    $(CXX) $(LDFLAGS) $(OBJECTS) -o $@

#.cpp.o :
#    $(CXX) $(CPPFLAGS) $(OBJECT_FILES) $< -o $@

.PHONY: upload
upload: $(TARGET).hex
	$(AVRDUDE) -c $(PROTOCOL) -p $(PART) -P $(PORT) -b $(BAUD) -U flash:w:$<

.PHONY: clean
clean:
	@echo "****** Clean ******"
	$(RM) *.hex *.o *.obj


