SOURCES=src/*.c
PROG=libtc.so
INC_PATH=./include
CFLAGS=-Wall -fPIC -shared

linux-x86_64: $(SOURCES)
	$(CC) -o $@/$(PROG) $(SOURCES) $(CFLAGS) -I$(INC_PATH)


check:
	$(MAKE) -C tests
