#Compilation
Compilateur=gcc
CompFLAGS=-W -Wall -std=c99 -g
LibsLoad=
#Paths
ObjPATH=obj/
BinPATH=./
TestFile=test.txt
#Sources
SOURCES=$(wildcard *.c)
OBJECTS=$(SOURCES:.c=.o)
#Executable name
EXEC=emu-mips

#Default: Build Object and Link them into a binairy executable 
all: mkfiles $(OBJECTS) link

#Compile then run executable
run: all
	@./$(BinPATH)$(EXEC) $(TestFile)

#Create folder for objects and binairy
mkfiles:
	@mkdir -p $(ObjPATH) $(BinPATH) ./tests ./hexified
	#@touch $(TestFile)
	#@echo "ADDI D8,D0,1" > $(TestFile)
	#@echo "NOP" >> $(TestFile)

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
	rm -rf $(ObjPATH) $(BinPATH)$(EXEC) dist.tar $(TestFile)
	
#Create a .tar distribution file
dist: clean
	tar cvf dist.tar *