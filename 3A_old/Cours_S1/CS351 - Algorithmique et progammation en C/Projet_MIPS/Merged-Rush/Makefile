## Change this variable
MYNAME=ROUGE_PATARD
# and perhaps this one
SRCDOC=Devdoc.md
# testfiles are in TESTDIR and IGNORE = list of files to ignore when taring
TESTDIR = testfiles/
IGNORE = old_generate.c.old
## Do not change below please
BIN = emul-mips
PREFIX=MIPS3
CC = gcc
FLAGS = -Wall -g
C_FILES = $(wildcard *.c)
OBJ_FILES = $(C_FILES:.c=.o)

all: $(OBJ_FILES)
	$(CC) $(FLAGS) -o $(BIN) $^

%.o: %.c
	$(CC) $(FLAGS) -c $^

clean:
	rm -f *.o *~ $(BIN) *.hex *.s *.state *.pdf
#Edit de l'étudiant: j'ai raouté *.state à la liste des fichiers à supprimer lors du clean.

# a useful command to generate a pdf from a .md documentation file
doc : $(SRCDOC)
	pandoc -f markdown  $(SRCDOC) -o $(basename $(SRCDOC)).pdf
#Edit de l'étudiant: retiré le -t pdf


# A useful command to deliver your project while keeping me sane
tar: clean
	dir=$$(basename "$$PWD") && echo "compressing $(dir)" && cd .. && \
	tar cvfz "$(PREFIX)-$(MYNAME).tgz" \
	--transform="s,^$$dir,$(PREFIX)-$(MYNAME)," \
	--exclude="$(IGNORE)" "$$dir" --verbose --show-transformed-names
#Edit de l'étudiant: j'ai raouté des " autour de $$PWD pour prendre en compte les chemin avec des espaces
