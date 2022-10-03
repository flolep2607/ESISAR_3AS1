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

graph: obj/TP3/exo4_mosaique/main obj/TP3/exo4_mosaique/dessin obj/TP3/exo4_mosaique/graphlib/graphlib
	mkdir -p obj/TP3/exo4_mosaique/graphlib/
	$(CC) $(CFLAGS) $(GRAPH) src/TP3/exo4_mosaique/graphlib/graphlib.c -o obj/TP3/exo4_mosaique/graphlib/graphlib
	$(CC) $(CFLAGS) $(GRAPH) src/TP3/exo4_mosaique/dessin.c src/TP3/exo4_mosaique/graphlib/graphlib.h  -o obj/TP3/exo4_mosaique/dessin
	$(CC) $(CFLAGS) $(GRAPH) src/TP3/exo4_mosaique/main.c src/TP3/exo4_mosaique/graphlib/graphlib.h src/TP3/exo4_mosaique/dessin.h -o obj/TP3/exo4_mosaique/main
	$(CC) $(CFLAGS) $(GRAPH) obj/TP3/exo4_mosaique/main obj/TP3/exo4_mosaique/dessin obj/TP3/exo4_mosaique/graphlib/graphlib -o obj/TP3/graph
	./obj/TP3/graph

obj/TP3/exo4_mosaique/main: src/TP3/exo4_mosaique/graphlib/graphlib.h src/TP3/exo4_mosaique/dessin.h
	$(CC) $(CFLAGS) $(GRAPH) src/TP3/exo4_mosaique/main.c src/TP3/exo4_mosaique/graphlib/graphlib.h src/TP3/exo4_mosaique/dessin.h -o obj/TP3/exo4_mosaique/main
obj/TP3/exo4_mosaique/dessin: src/TP3/exo4_mosaique/graphlib/graphlib.h 
	$(CC) $(CFLAGS) $(GRAPH) src/TP3/exo4_mosaique/dessin.c src/TP3/exo4_mosaique/graphlib/graphlib.h  -o obj/TP3/exo4_mosaique/dessin
obj/TP3/exo4_mosaique/graphlib/graphlib:
	$(CC) $(CFLAGS) $(GRAPH) src/TP3/exo4_mosaique/graphlib/graphlib.c -o obj/TP3/exo4_mosaique/graphlib/graphlib

test: $(PROGS)

clean:
	rm -rf obj/*

%: %.c
	mkdir -p $(subst src/,obj/,$(@D))
	$(CC) $(CFLAGS) -o $(subst src/,obj/,$@) $<
# $(CC) $(CFLAGS)  -o $@ $<
