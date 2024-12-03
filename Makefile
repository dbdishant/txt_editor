CC = cc
CFLAGS = -Wall -W -pedantic -std=c99

all: strive

strive: strive.c file_operations.c
	$(CC) -o strive strive.c file_operations.c $(CFLAGS)

clean:
	rm -f strive
