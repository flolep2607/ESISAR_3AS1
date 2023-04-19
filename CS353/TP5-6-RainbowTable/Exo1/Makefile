SRC=.
HERE=$(PWD)
MAINCLASS=Exo1
SRCJAVA=$(wildcard $(SRC)/*.java)
CLASSFILES = $(SRCJAVA:.java=.class)

all: run

# Compilation
%.class: %.java
	javac $^

# Exécution
run: $(MAINCLASS).class
	java $(MAINCLASS)

clean:
	rm -f $(SRC)/*.class $(SRC)/*~ *~
