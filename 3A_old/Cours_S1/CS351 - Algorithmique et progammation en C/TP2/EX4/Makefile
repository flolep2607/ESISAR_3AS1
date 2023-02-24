
Compilateur=gcc
CompFLAGS=-Wall -ansi -pedantic -std=c99
CompLIBS=-lX11 -L/usr/include/X11
LibPATH=graphlib/
ObjPATH=obj/
BinPATH=bin/
EXEC=mosaique

all: mkdir $(EXEC)

mkdir:
	@mkdir -p bin
	@mkdir -p obj

$(EXEC): graphlib.o fonctions.o main.o
	$(Compilateur) $(ObjPATH)*.o $(CompLIBS) -o $(BinPATH)$@ 
#                                             $@ 	  Le nom de la cible		(ici $(EXEC))
#                        $^   La liste des dépendances  (ici "fonctions.o main.o")

graphlib.o: 
	$(Compilateur) -c $(LibPATH)graphlib.c -o $(ObjPATH)$@ $(CompFLAGS)

fonctions.o:
	$(Compilateur) -c fonctions.c -o $(ObjPATH)$@ $(CompFLAGS)
	
main.o: main.c
	$(Compilateur) -c $< -o $(ObjPATH)$@ $(CompFLAGS)
#                     $< 	Le nom de la première dépendance	(ici pas utile car une seule dépendance)


clean:
	rm -rf $(ObjPATH) $(BinPATH)