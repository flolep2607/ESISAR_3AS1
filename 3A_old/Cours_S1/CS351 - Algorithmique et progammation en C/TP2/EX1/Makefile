# jeu multiplication

all: jeuMulti.o jeuMultiPoints.o
	gcc jeuMulti.o -o jeuMulti
	gcc jeuMultiPoints.o -o jeuMultiPoints
	
default: jeuMulti.o
	gcc jeuMulti.o -o jeuMulti
	
jeuMulti.o: jeuMulti.c
	gcc -c jeuMulti.c -Wall -ansi -pedantic -o jeuMulti.o
	
jeuMultiPoints.o: jeuMultiPoints.c
	gcc -c jeuMultiPoints.c -Wall -ansi -pedantic -o jeuMultiPoints.o
	
clean: 
	rm -f jeuMulti jeuMulti.o jeuMultiPoints jeuMultiPoints.o