CC = gcc
CFLAGS = -g -Wall
CLIB = -lpthread

build:
	$(CC) $(CFLAGS) main.c bitwise.c cache.c integer.c floating.c -o benchmark $(CLIB)

.PHONY: clean
clean:
	rm benchmark