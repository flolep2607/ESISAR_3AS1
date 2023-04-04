Compilateur=gcc
CompFLAGS=-W -Wall -ansi -pedantic -std=c99
LibsLoad=
ObjPATH=obj/
BinPATH=bin/
EXEC=Poly

all: mkdir $(EXEC)

run: all
	@./$(BinPATH)/$(EXEC)

mkdir:
	@mkdir -p bin
	@mkdir -p obj

$(EXEC): Polynomes.o main.o link

link:
	$(Compilateur) $(ObjPATH)*.o $(LibsLoad) -o $(BinPATH)$(EXEC)


%.o: %.c
	$(Compilateur) -o $(ObjPATH)$@ -c $< $(CompFLAGS)
	

clean:
	rm -rf $(ObjPATH) $(BinPATH) dist.tar
	
dist: clean
	tar cvf dist.tar *