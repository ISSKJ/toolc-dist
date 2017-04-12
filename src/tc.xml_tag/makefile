SOURCES=tc.xml_tag.c
PROG=../../linux-x86_64/tc.xml_tag
LD_PATH=../../ext/linux-x86_64
INC_PATH=../../ext/include
CFLAGS=-Wall -fPIC

linux-x86_64: $(SOURCES)
	$(CC) -o $(PROG) $(SOURCES) $(CFLAGS) -L$(LD_PATH) -ltc -I$(INC_PATH)

clean:
	rm -f $(PROG)

