
Compilateur=gcc
CompFLAGS=-W -Wall -ansi -pedantic -std=c99
LibsLoad=
ObjPATH=obj/
BinPATH=bin/
EXEC=matrices

default: mkdir $(EXEC)


mkdir:
	@mkdir -p bin
	@mkdir -p obj

$(EXEC): module_matrice.o main.o link

link:
	$(Compilateur) $(ObjPATH)*.o $(LibsLoad) -o $(BinPATH)$(EXEC)


%.o: %.c
	$(CC) -o $(ObjPATH)$@ -c $< $(CompFLAGS)

clean:
	rm -rf $(ObjPATH) $(BinPATH)