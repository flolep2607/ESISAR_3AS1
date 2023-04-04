CC = gcc
CC_FLAGS = -g -Wall
BIN = liste

all : liste.o
	$(CC) liste.o -o $(BIN)

liste.o : 
	$(CC) -o liste.o -c liste.c $(CC_FLAGS)

clean :
	rm $(BIN) *.o