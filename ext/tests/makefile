CC=gcc
SOURCES=*.c
INC_PATH=../include
LD_PATH=../linux-x86_64
CFLAGS=-Wall 

test1: $(SOURCES)
	$(CC) -o $@ $(SOURCES) $(CFLAGS) -I$(INC_PATH) -Wl,-rpath $(LD_PATH) -L$(LD_PATH) -ltc
	./$@

