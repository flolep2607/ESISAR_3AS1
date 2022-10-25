BIN = prog
OBJECTS = exo3.o pile.o
CFLAGS = -g
CC = gcc

all: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(BIN)
	rm $(OBJECTS)
	#./$(BIN)
main.o: exo3.c
	$(CC) $(CFLAGS) -c exo3.c -o exo3.o
pile.o: pile.c pile.h
	$(CC) $(CFLAGS) -c pile.c -o pile.o

clean:
	rm *.o