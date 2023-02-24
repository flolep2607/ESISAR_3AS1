
Compilateur=gcc
CompFLAGS=-W -Wall -ansi -pedantic -std=c99
LibsLoad=-lm
ObjPATH=obj/
BinPATH=bin/
EXEC=notes

default: mkdir $(EXEC)

mkdir:
	@mkdir -p bin
	@mkdir -p obj

notes: fonctions.o main.o
	$(Compilateur) $(ObjPATH)*.o $(LibsLoad) -o $(BinPATH)$@
#                                             $@ 	  Le nom de la cible		(ici "fonctions")
#                        $^   La liste des dépendances  (ici "fonctions.o main.o")

#fonctions.o: fonctions.c
#	$(Compilateur) -c $^ -o $(ObjPATH)$@ $(CompFLAGS)

#main.o: main.c
#	$(Compilateur) -c $< -o $(ObjPATH)$@ $(CompFLAGS)
#                     $< 	Le nom de la première dépendance	(ici pas utile car une seule dépendance)

#autre notation pour compiler les .o plus aisément équivalent au deux précédent
%.o: %.c
	$(CC) -o $(ObjPATH)$@ -c $< $(CompFLAGS)

clean:
	rm -rf $(ObjPATH) $(BinPATH)