#Compilation
Compilateur=gcc
CompFLAGS=-W -Wall -ansi -pedantic -std=c99
LibsLoad=-lX11 -L/usr/include/X11
#Paths
ObjPATH=obj/
BinPATH=bin/
#Sources
SOURCES=$(wildcard *.c)
OBJECTS=$(SOURCES:.c=.o)
#Executable name
EXEC=Executable

#Default: Build Object and Link them into a binairy executable 
all: mkdir $(OBJECTS) link

#Compile then run executable
run: all
	@./$(BinPATH)$(EXEC)

#Create folder for objects and binairy
mkdir:
	@mkdir -p $(ObjPATH) $(BinPATH)

#Link Object files
link:
	$(Compilateur) $(ObjPATH)*.o $(LibsLoad) -o $(BinPATH)$(EXEC)

#Compile Sources into Objects
%.o: %.c
	$(Compilateur) -o $(ObjPATH)$@ -c $< $(CompFLAGS)
# %  -> pattern rule.
#       It specifies one target and one dependency
# $@ -> name of the target
# $< -> first prerequisite
# $^ -> every prerequisite

#Remove everyfile that are not sources
clean:
	rm -rf $(ObjPATH) $(BinPATH)$(EXEC) $(BinPATH) dist.tar
	
#Create a .tar distribution file
dist: clean
	tar cvf dist.tar *