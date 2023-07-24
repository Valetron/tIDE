PROGNAME=exe
CC=gcc
CFLAGS=-lcurses -Wall -fpic -o $(PROGNAME)

debug:
	$(CC) -g3 -ggdb $(CFLAGS) main.c

release:
	$(CC) -O2 $(CFLAGS) main.c

clean:
	rm *.out $(PROGNAME)

test:
	echo $(PROGNAME)