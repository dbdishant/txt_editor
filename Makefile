CC = cc
CFLAGS = -Wall -W -pedantic -std=c99

all: strive

strive: strive.c save_as.c
	$(CC) -o strive strive.c save_as.c find_and_replace.c word_char_count.c $(CFLAGS)

clean:
	rm -f strive
