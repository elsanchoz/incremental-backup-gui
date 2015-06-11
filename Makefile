CC = gcc

CFLAGS = -Wall
CFLAGS += -Wextra
CFLAGS += `pkg-config --cflags gtk+-3.0`

LIBS  = `pkg-config --libs gtk+-3.0`

all: gui

gui: init obj/window.o obj/assignments.o
	 $(CC) $(CFLAGS) obj/assignments.o obj/window.o -o bin/window $(LIBS)

init:
	mkdir -p bin
	mkdir -p obj

obj/window.o: window.c
	$(CC) $(CFLAGS) -c -o obj/window.o window.c $(LIBS)

obj/assingments.o: assignments.c
	$(CC) $(CFLAGS) -c -o obj/assignments.o assignments.c $(LIBS)

clean:
	rm -Rf bin

