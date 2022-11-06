AUTEURS := Moncorge_Leprat
# PLUS_FLAGS = -fsanitize=address,leak,undefined -Wall -Wextra -Wshadow -Wdouble-promotion -Wundef -Wconversion
ARGS ?= data/1.txt -pas
CC = gcc
EXEC = emul-mips
DEBUG = yes
CFLAGS = -Wall -Wextra -O2 -ansi -pedantic -std=c99  -fsanitize=address,leak,undefined 
STATICDEFINE = TEST
lib = m

OBJDIR = obj
SRCDIR = src
INCDIR = includes
LIBDIR = lib
RESULTDIR = out
DATADIR = data
# MAIN = main
MAIN = translate

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
	$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: clean run create debug tests doc filespas files pasapas test-cli
clean:
	@rm -rf $(OBJDIR)/*.o tests/*.swap __pycache__ .pytest_cache tests/*.hex tests/*.state

run: $(EXEC)
	@./$(EXEC) $(ARGS)

pasapas: $(EXEC) data/test.txt
	@./$(EXEC) data/test.txt -pas

filespas: $(EXEC) data/test.txt
	@mkdir -p $(RESULTDIR)
	@./$(EXEC) data/test.txt $(RESULTDIR)/bin $(RESULTDIR)/stdout -pas

files: $(EXEC) data/test.txt
	@mkdir -p $(RESULTDIR)
	@./$(EXEC) data/test.txt $(RESULTDIR)/bin $(RESULTDIR)/stdout

create:
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
	@ dir=$$(basename "$$PWD") && cd .. && tar --exclude='*.pdf' --exclude='docs/*' -cvfz $(AUTEURS).tgz  "$$dir"
	@ echo "==="; echo "Created ../$(AUTEURS).tgz"

doc:
	doxygen doxy_config
