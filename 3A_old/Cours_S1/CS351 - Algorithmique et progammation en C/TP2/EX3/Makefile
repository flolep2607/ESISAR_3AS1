
Compilateur=gcc
CompFLAGS=-W -Wall -ansi -pedantic -std=c99
ObjPATH=obj/
BinPATH=bin/
EXEC=BiblioMath

default: mkdir $(EXEC)

mkdir:
	@mkdir -p bin
	@mkdir -p obj

$(EXEC): libmath.o main.o
	$(Compilateur) $(ObjPATH)*.o -o $(BinPATH)$@
#                                             $@ 	  Le nom de la cible		(ici "fonctions")
#                        $^   La liste des dépendances  (ici "fonctions.o main.o")

#libmath.o: libmath.c
#	$(Compilateur) -c $^ -o $(ObjPATH)$@ $(CompFLAGS)

#main.o: main.c
#	$(Compilateur) -c $< -o $(ObjPATH)$@ $(CompFLAGS)
#                     $< 	Le nom de la première dépendance	(ici pas utile car une seule dépendance)

#autre notation pour compiler les .o plus aisément équivalent au deux précédent
%.o: %.c
	$(CC) -o $(ObjPATH)$@ -c $< $(CompFLAGS)

clean:
	rm -rf $(ObjPATH) $(BinPATH)
#               suppr les fichiers créé par make
