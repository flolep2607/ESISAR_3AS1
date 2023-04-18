## Change your name here:
MYNAME=MoncorgeLeprat

## DO NOT change below
HERE=$(PWD)
MAINCLASS=FSMIOString
SRCJAVA=$(wildcard *.java)
CLASSFILES = $(SRCJAVA:.java=.class)

all: run

# Run
run: 
	javac -cp ../V2/  FSMIOString.java TestFSMIOString.java
	java Test$(MAINCLASS) task.fsm

tar: clean
	dir=$$(basename $$PWD/$$SRC) && cd .. && \
	tar cvfz "TP04-$(MYNAME).tgz" --exclude=".git" "$$dir"

clean:
	rm -f *.class *~ *~
