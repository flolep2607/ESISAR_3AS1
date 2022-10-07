BIN = graph
OBJECTS = main.o module.o
CFLAGS = -Wall
CC = gcc

all: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(BIN)
	./$(BIN)
main.o: main.c
	$(CC) $(CFLAGS) -c main.c
module.o: module.c module.h
	$(CC) $(CFLAGS) -c module.c

clean:
	rm *.o