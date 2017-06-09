EXT_DIR=../../ext

PROG=tc.trim_comment
SOURCES=$(PROG).c
LD_PATH=.
INC_PATH=.
C_OPTIONS=-Wall -fPIC

darwin-x86_64: $(SOURCES)
	$(CC) -o "../../$@/$(PROG)" $(SOURCES) $(C_OPTIONS) -L$(LD_PATH) -I$(INC_PATH)

linux-x86_64: $(SOURCES)
	$(CC) -o "../../$@/$(PROG)" $(SOURCES) $(C_OPTIONS) -L$(LD_PATH) -I$(INC_PATH)
