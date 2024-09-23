# @AryanKaizo ;)

CC=gcc
CFLAGS=-Wall -Wextra
NOOPT=-O0

CFILES=main.c linked_list.c
OFILES=main.o linked_list.o

EXECUTABLE=exec_prg


#all runs first

all:$(EXECUTABLE) run

run:
	./$(EXECUTABLE)

$(EXECUTABLE): $(OFILES)
	$(CC) $(CFLAGS) $(NOOPT) $(OFILES) -o $(EXECUTABLE)

main.o: main.c linked_list.h	#explicit defination
	$(CC) $(CFLAGS) $(NOOPT) -c main.c -o main.o

linked_list.o: linked_list.c linked_list.h 
	$(CC) $(CFLAGS) $(NOOPT) -c linked_list.c -o linked_list.o

clean:
	rm -f $(EXECUTABLE) $(OFILES)