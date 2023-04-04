BIN = prog
OBJECTS = main.o listechainee.o
CFLAGS = -Wall
CC = gcc

all: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(BIN)
	rm $(OBJECTS)
	./$(BIN)
main.o: main.c
	$(CC) $(CFLAGS) -c main.c
pile.o: listechainee.c listechainee.h
	$(CC) $(CFLAGS) -c listechainee.c

clean:
	rm *.o