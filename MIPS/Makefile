# PLUS_FLAGS = -fsanitize=address,leak,undefined -Wall -Wextra -Wshadow -Wdouble-promotion -Wundef -Wconversion
ARGS ?= data/1.txt -pas
CC = gcc
EXEC = emul-mips
DEBUG = yes
CFLAGS = -Wall -Wextra -ansi -pedantic -std=c99  -fsanitize=address,leak,undefined 
STATICDEFINE = TEST
lib = m

OBJDIR = obj
SRCDIR = src
INCDIR = includes
LIBDIR = lib
DATADIR = data
MAIN = main

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

.PHONY: clean run create debug
clean:
	@rm -rf $(OBJDIR)/*.o

run: $(EXEC)
	@./$(EXEC) $(ARGS)

create:
	@mkdir -p {$(DATADIR),$(SRCDIR),$(INCDIR),$(LIBDIR)}

debug:
