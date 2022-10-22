BIN = prog
OBJECTS = main.o listeTableau.o
CFLAGS = -Wall
CC = gcc

all: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(BIN)
	rm $(OBJECTS)
	./$(BIN)
main.o: main.c
	$(CC) $(CFLAGS) -c main.c
pile.o: listeTableau.c listeTableau.h
	$(CC) $(CFLAGS) -c listeTableau.c

clean:
	rm *.o