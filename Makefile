CC = gcc

CFLAGS = -Wall
CFLAGS += -Wextra
CFLAGS += `pkg-config --cflags gtk+-3.0`

LIBS  = `pkg-config --libs gtk+-3.0`

all: gui

gui: init 
	 $(CC) $(CFLAGS) window.c -o bin/window $(LIBS)

init:
	mkdir -p bin

clean:
	rm -Rf bin

