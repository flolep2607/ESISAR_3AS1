## Change your name here:
MYNAME=MoncorgeLeprat

## DO NOT change below
SRC=FSMIOString
HERE=$(PWD)
MAINCLASS=TestFSMIOString
SRCJAVA=$(wildcard $(SRC)/*.java)
CLASSFILES = $(SRCJAVA:.java=.class)
CLASSPATH=$(SRC):../V2/FSMIO

all: run

# Compile
$(SRC)/FSMIOString.class: $(SRC)/FSMIOString.class
	javac  $(SRC)/FSMIOString.java -d $(SRC)

$(SRC)/TestFSMIOString.class: $(SRC)/TestFSMIOString.class $(SRC)/FSMIOString.class
	javac  $(SRC)/TestFSMIOString.java -d $(SRC)

# Run
run: $(SRC)/$(MAINCLASS).class
	java $(SRC)/$(MAINCLASS)

tar: clean
	dir=$$(basename $$PWD/$$SRC) && cd .. && \
	tar cvfz "TP04-$(MYNAME).tgz" --exclude=".git" "$$dir"

clean:
	rm -f $(SRC)/*.class $(SRC)/*~ *~

