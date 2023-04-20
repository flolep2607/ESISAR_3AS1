## Change your name here:
MYNAME=MoncorgeLeprat

## DO NOT change below
HERE=$(PWD)
MAINCLASS=TestFSMIOString
CLASS_PATH=../V2/:.

all: run

# Compile
FSMIOString.class: FSMIOString.class
	javac -cp $(CLASS_PATH) FSMIOString.java

TestFSMIOString.class: TestFSMIOString.class FSMIOString.class
	javac -cp $(CLASS_PATH) TestFSMIOString.java

all: run
# Run
run: $(MAINCLASS).class
	java -cp $(CLASS_PATH) $(MAINCLASS) task.fsm

tar: clean
	dir=$$(basename $$PWD/$$SRC) && cd .. && \
	tar cvfz "TP04-$(MYNAME).tgz" --exclude=".git" "$$dir"

clean:
	rm -f *.class *~

