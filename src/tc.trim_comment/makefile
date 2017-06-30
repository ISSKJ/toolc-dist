EXT_DIR=../../ext

PROG=tc.trim_comment
SOURCES=$(PROG).c
LD_PATH=.
INC_PATH=.
C_OPTIONS=-Wall -fPIC

make: $(SOURCES)
	mkdir -p bin/
	$(CC) -o bin/$(PROG) $(SOURCES) $(C_OPTIONS) -L$(LD_PATH) -I$(INC_PATH)

clean:
	rm -f bin/*
