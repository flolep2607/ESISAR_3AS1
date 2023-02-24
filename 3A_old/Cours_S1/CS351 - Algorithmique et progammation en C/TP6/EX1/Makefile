#Compilation
Compilateur=gcc
CompFLAGS=-g -W -Wall -std=c99
LibsLoad=
#Paths
ObjPATH=obj/
#Sources
SOURCES=$(wildcard *.c)
OBJECTS=$(SOURCES:.c=.o)
#Executable name
EXEC=Executable

#Default: Build Object and Link them into a binairy executable 
all: mkdir $(OBJECTS) link

#Compile then run executable
run: all
	@./$(EXEC)

#Create folder for objects and binairy
mkdir:
	@mkdir -p $(ObjPATH) 

#Link Object files
link:
	$(Compilateur) $(ObjPATH)*.o $(LibsLoad) -o $(EXEC)

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
	rm -rf $(ObjPATH) $(EXEC) dist.tar
	
#Create a .tar distribution file
dist: clean
	tar cvf dist.tar *