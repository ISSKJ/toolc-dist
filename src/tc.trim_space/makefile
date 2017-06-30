EXT_DIR=../../ext

PROG=tc.trim_space
SOURCES=$(PROG).c $(EXT_DIR)/src/tc.string.c
LD_PATH=.
INC_PATH=$(EXT_DIR)/include
C_OPTIONS=-Wall -fPIC

make: $(SOURCES)
	mkdir -p bin/
	$(CC) -o bin/$(PROG) $(SOURCES) $(C_OPTIONS) -L$(LD_PATH) -I$(INC_PATH)

clean:
	rm -f bin/*
