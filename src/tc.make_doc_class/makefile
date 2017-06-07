EXT_DIR=../../ext

SOURCES=tc.make_doc_class.c
PROG=../../linux-x86_64/tc.make_doc_class
#PROG=tc.make_doc_class
LD_PATH=.
INC_PATH=.
C_OPTIONS=-Wall -fPIC

linux-x86_64: $(SOURCES)
	$(CC) -o $(PROG) $(SOURCES) $(C_OPTIONS) -L$(LD_PATH) -I$(INC_PATH)

clean:
	rm -f $(PROG)

