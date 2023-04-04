## Change your name here:
MYNAME=LaureGonnord

## DO NOT change below
SRC=FSMIO
HERE=$(PWD)
MAINCLASS=TestFSMIO
SRCJAVA=$(wildcard $(SRC)/*.java)
CLASSFILES = $(SRCJAVA:.java=.class)

all: run

# Compile
%.class: %.java
	javac $^

# Run
run: $(SRC)/$(MAINCLASS).class
	java $(SRC)/$(MAINCLASS)

tar: clean
	dir=$$(basename $$PWD/$$SRC) && cd .. && \
	tar cvfz "TP04-$(MYNAME).tgz" --exclude=".git" "$$dir"

clean:
	rm -f $(SRC)/*.class $(SRC)/*~ *~
