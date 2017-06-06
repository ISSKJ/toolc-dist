EXT_DIR=../../ext

SOURCES=tc.xml_tag.c $(EXT_DIR)/src/tc.string.c
PROG=../../linux-x86_64/tc.xml_tag
LD_PATH=.
INC_PATH=$(EXT_DIR)/include/
CFLAGS=-Wall -fPIC

linux-x86_64: $(SOURCES)
	$(CC) -o $(PROG) $(SOURCES) $(CFLAGS) -L$(LD_PATH) -I$(INC_PATH)

clean:
	rm -f $(PROG)

