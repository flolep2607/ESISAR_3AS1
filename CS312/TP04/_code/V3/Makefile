## Change your name here:
MYNAME=MoncorgeLeprat

## DO NOT change below
SRC=FSMIOString
HERE=$(PWD)
MAINCLASS=TestFSMIOString
SRCJAVA=$(wildcard $(SRC)/*.java)
CLASSFILES = $(SRCJAVA:.java=.class)

all: run

# Compile
%.class: %.java
	javac -cp ../V2/ -cp $(MAINCLASS) $^

# Run
run: $(SRC)/$(MAINCLASS).class
	java $(SRC)/$(MAINCLASS)

tar: clean
	dir=$$(basename $$PWD/$$SRC) && cd .. && \
	tar cvfz "TP04-$(MYNAME).tgz" --exclude=".git" "$$dir"

clean:
	rm -f $(SRC)/*.class $(SRC)/*~ *~

