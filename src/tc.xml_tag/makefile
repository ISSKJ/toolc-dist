EXT_DIR=../../ext

PROG=tc.xml_tag
SOURCES=$(PROG).c $(EXT_DIR)/src/tc.string.c
LD_PATH=.
INC_PATH=$(EXT_DIR)/include/
CFLAGS=-Wall -fPIC

darwin-x86_64: $(SOURCES)
	$(CC) -o "../../$@/$(PROG)" $(SOURCES) $(C_OPTIONS) -L$(LD_PATH) -I$(INC_PATH)

linux-x86_64: $(SOURCES)
	$(CC) -o "../../$@/$(PROG)" $(SOURCES) $(C_OPTIONS) -L$(LD_PATH) -I$(INC_PATH)
