# $(BIN) est le nom du fichier binaire généré
BIN = graph
# $(OBJECTS) sont les objets qui seront générés
# après la compilation
OBJECTS = main.o dessin.o graphlib/graphlib.o
CFLAGS = -Wall
GRAPH = -lX11 -L/usr/include/X11 
# $(CC) est le compilateur utilisé
CC = gcc
# all est la première règle à être exécutée car elle est
# la première dans le fichier Makefile. Notons que les
# dépendances peuvent être remplacées par une variable,
# ainsi que n’importe quelle chaîne de caractères des
# commandes
all: $(OBJECTS)
	$(CC) $(CFLAGS) $(GRAPH) $(OBJECTS) -o $(BIN)
	./$(BIN)
main.o: main.c
	$(CC) $(CFLAGS) $(GRAPH) -c main.c
dessin.o: dessin.c dessin.h graphlib/graphlib.h
	$(CC) $(CFLAGS) $(GRAPH) -c dessin.c
graphlib.o: graphlib/graphlib.c graphlib/graphlib.h
	$(CC) $(CFLAGS) $(GRAPH) -c graphlib/graphlib.c

clean:
	rm *.o