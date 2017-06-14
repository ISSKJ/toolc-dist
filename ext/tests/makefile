SOURCES=*.c ../src/tc.string.c
PROG=test
LD_PATH=.
INC_PATH=../include/
C_OPTIONS=-Wall -fPIC

$(PROG): $(SOURCES)
	$(CC) -o $@ $(SOURCES) $(C_OPTIONS) -L$(LD_PATH) -I$(INC_PATH)

run:
	./$(PROG)

clean:
	rm -f ./$(PROG)


