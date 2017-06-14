EXT_DIR=../../ext

PROG=tc.trim_space
SOURCES=$(PROG).c $(EXT_DIR)/src/tc.string.c
LD_PATH=.
INC_PATH=$(EXT_DIR)/include
C_OPTIONS=-Wall -fPIC

darwin-x86_64: $(SOURCES)
	$(CC) -o "../../$@/$(PROG)" $(SOURCES) $(C_OPTIONS) -L$(LD_PATH) -I$(INC_PATH)

linux-x86_64: $(SOURCES)
	$(CC) -o "../../$@/$(PROG)" $(SOURCES) $(C_OPTIONS) -L$(LD_PATH) -I$(INC_PATH)

test:
	$(CC) -o "$(PROG)" $(SOURCES) $(C_OPTIONS) -L$(LD_PATH) -I$(INC_PATH)
