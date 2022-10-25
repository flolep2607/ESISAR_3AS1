BIN = prog
OBJECTS = main.o pile.o
CFLAGS = -Wall
CC = gcc

all: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(BIN)
	rm $(OBJECTS)
	./$(BIN)
main.o: main.c
	$(CC) $(CFLAGS) -c main.c
pile.o: pile.c pile.h
	$(CC) $(CFLAGS) -c pile.c

clean:
	rm *.o