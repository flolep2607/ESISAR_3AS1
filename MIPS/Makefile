AUTEURS := Moncorge_Leprat
# PLUS_FLAGS = -fsanitize=address,leak,undefined -Wall -Wextra -Wshadow -Wdouble-promotion -Wundef -Wconversion
ARGS ?= -pas
CC = gcc
EXEC = emul-mips
DEBUG = yes
CFLAGS = -Wall -Wextra -O2 -ansi -std=c99  
#  -pedantic   -fsanitize=address,leak,undefined
STATICDEFINE = 
# TEST
lib = m

OBJDIR = obj
SRCDIR = src
INCDIR = includes
LIBDIR = lib
RESULTDIR = out
DATADIR = data
MAIN = main
# MAIN = test

D ?= 

SRCS=$(wildcard $(SRCDIR)/*.c)
OBJS= $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
HEADER =$(wildcard $(INCDIR)/*.h)

CFLAGS += $(foreach headerdir,$(INCDIR),-I$(headerdir)) 
CFLAGS += $(foreach librarydir,$(LIBDIR),-L$(librarydir))
CFLAGS += $(foreach library,$(lib),-l$(library))
CFLAGS += $(foreach defined,$(D),-D$(defined))

ifeq ($(DEBUG),yes)
	CFLAGS += -g
	CFLAGS += $(foreach defined,$(STATICDEFINE),-D$(defined))
endif


$(EXEC):$(OBJS) $(HEADER)
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) $(OBJS) -o $@


$(OBJDIR)/%.o: $(SRCDIR)/%.c $(HEADER)
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -o $@ -c $< 

.PHONY: clean run create debug tests doc filespas files pasapas test-cli
clean:
	@rm -rf $(OBJDIR)/*.o tests/*.swap __pycache__ .pytest_cache tests/*.hex tests/*.state

run: $(EXEC)
	@./$(EXEC) $(ARGS)

pasapas: $(EXEC)
	@./$(EXEC) tests/pow2.s -pas

valgrind: $(EXEC)
	@mkdir -p $(RESULTDIR)
	valgrind --track-origins=yes --leak-check=full ./$(EXEC) tests/labels.s $(RESULTDIR)/bin $(RESULTDIR)/stdout -pas

filespas: $(EXEC)
	@mkdir -p $(RESULTDIR)
	@./$(EXEC) tests/mat.s $(RESULTDIR)/bin $(RESULTDIR)/stdout -pas

files: $(EXEC)
	@mkdir -p $(RESULTDIR)
	# @./$(EXEC) tests/pow2.s $(RESULTDIR)/bin $(RESULTDIR)/stdout
	# @./$(EXEC) tests/arithmetic.s $(RESULTDIR)/bin $(RESULTDIR)/stdout
	# @./$(EXEC) tests/jump_ops.s $(RESULTDIR)/bin $(RESULTDIR)/stdout
	@./$(EXEC) tests/labels.s $(RESULTDIR)/bin $(RESULTDIR)/stdout

create: $(EXEC)
	@mkdir -p {$(DATADIR),$(SRCDIR),$(INCDIR),$(LIBDIR),$(LIBDIR),$(RESULTDIR)}

tests: $(EXEC)
	@python3 test.py -v

CLITMP := /tmp/emul-mips-test
test-cli: $(EXEC)
	@ [ -e ./$(EXEC) ] \
	  || echo "error: emul-mips does not exist!"; \
	touch $(CLITMP).in; \
	rm -f $(CLITMP).out1 $(CLITMP).out2; \
	./$(EXEC) $(CLITMP).in $(CLITMP).out1 $(CLITMP).out2 \
	  || echo "error: emul-mips in automatic mode returned $$?!"; \
	[ -e $(CLITMP).out1 ] \
	  || echo "error: assembled output file does not exist!"; \
	[ -e $(CLITMP).out2 ] \
	  || echo "error: final state output file does not exist!"; \
	rm -f $(CLITMP).out1 $(CLITMP).out2

tar: clean
	@ dir=$$(basename "$$PWD") && cd .. && touch $(AUTEURS).tgz && tar --exclude='*.pdf' --exclude='rendus/*' --exclude='docs/*' -czvf $(AUTEURS).tgz "$$dir"
	@ echo "==="; echo "Created ../$(AUTEURS).tgz"

doc:
	doxygen doxy_config
