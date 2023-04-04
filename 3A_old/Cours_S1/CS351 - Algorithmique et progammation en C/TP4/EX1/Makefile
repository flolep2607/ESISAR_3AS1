Compilateur=gcc
CompFLAGS=-W -Wall -ansi -pedantic -std=c99
LibsLoad=
ObjPATH=obj/
BinPATH=bin/
EXEC=manipulation_de_fichier

all: mkdir $(EXEC)

run: all
	@./bin/$(EXEC)

mkdir:
	@mkdir -p bin
	@mkdir -p obj

$(EXEC): module_tri_fichiers.o main.o link

link:
	$(Compilateur) $(ObjPATH)*.o $(LibsLoad) -o $(BinPATH)$(EXEC)


%.o: %.c
	$(Compilateur) -o $(ObjPATH)$@ -c $< $(CompFLAGS)
	

clean:
	rm -rf $(ObjPATH) $(BinPATH) dist.tar
	
dist: clean
	tar cvf dist.tar *