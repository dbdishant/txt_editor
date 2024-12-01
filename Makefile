all: strive

strive: strive.c
	$(CC) -o strive strive.c -Wall -W -pedantic -std=c99

clean:
	rm strive
