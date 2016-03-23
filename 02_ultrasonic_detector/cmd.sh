avr-g++ -I/opt/arduino-1.6.8/hardware/tools/avr/avr/include -I/opt/arduino-1.6.8/hardware/arduino/avr/cores/arduino/ -Wall -Os -DF_CPU=16000000UL -mmcu=atmega2560 main.cpp -o main.o
avr-g++ -I/opt/arduino-1.6.8/hardware/tools/avr/avr/include -I/opt/arduino-1.6.8/hardware/arduino/avr/cores/arduino/ -Wall -Os -DF_CPU=16000000UL -mmcu=atmega2560 ledManager.cpp -c
