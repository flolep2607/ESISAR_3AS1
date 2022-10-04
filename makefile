# SRC = $(wildcard src/*.cpp)
# OBJ = $(patsubst src/%.cpp, obj/%.o, $(SRC))

# prog: $(OBJ)
#   $(CC) $(CFLAGS) $(LDFLAGS) $(LIBS) $(OBJ) -o prog 

# obj/%/%.o: src/%/%.c
#   $(CC) $(CFLAGS) -c $< -o $@
CFLAGS = -Wall
GRAPH = -lX11 -L/usr/include/X11 -nostartfiles
SRCS = $(wildcard src/*/*.c)

PROGS = $(patsubst %.c,%,$(SRCS))
# PROGS = $(subst src/,obj/,$(PROGS_TMP))

all: $(PROGS)

clean:
	rm -rf obj/*

%: %.c
	mkdir -p $(subst src/,obj/,$(@D))
	$(CC) $(CFLAGS) -o $(subst src/,obj/,$@) $<
# $(CC) $(CFLAGS)  -o $@ $<
