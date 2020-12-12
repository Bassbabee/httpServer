CC=gcc

CFLAGS=-Wall -std=c99

FILES=main.c httplib/httplib.o

.PHONY: default build run
default: build run

build: $(FILES)
	$(CC) $(CFLAGS) $(FILES) -o main

run: main
	./main
