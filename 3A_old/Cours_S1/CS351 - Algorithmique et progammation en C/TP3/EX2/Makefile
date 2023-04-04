
Compilateur=gcc
CompFLAGS=-W -Wall -ansi -pedantic -std=c99
LibsLoad=-lm
ObjPATH=obj/
BinPATH=bin/
EXEC=polynomes

default: mkdir $(EXEC)

#debug:
#	CompFLAGS="$(CompFLAGS) -D DEBUG"
#     [-> ne marche pas

mkdir:
	@mkdir -p bin
	@mkdir -p obj

$(EXEC): fonctions.o main.o link
#	$(Compilateur) $(ObjPATH)*.o $(LibsLoad) -o $(BinPATH)$@
#                                             $@ 	  Le nom de la cible		(ici "fonctions")
#                        $^   La liste des dépendances  (ici "fonctions.o main.o")
link:
	$(Compilateur) $(ObjPATH)*.o $(LibsLoad) -o $(BinPATH)$(EXEC)


%.o: %.c
	$(CC) -o $(ObjPATH)$@ -c $< $(CompFLAGS)

clean:
	rm -rf $(ObjPATH) $(BinPATH)