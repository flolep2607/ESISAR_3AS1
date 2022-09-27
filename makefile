# SRC = $(wildcard src/*.cpp)
# OBJ = $(patsubst src/%.cpp, obj/%.o, $(SRC))

# prog: $(OBJ)
#   $(CC) $(CFLAGS) $(LDFLAGS) $(LIBS) $(OBJ) -o prog 

# obj/%/%.o: src/%/%.c
#   $(CC) $(CFLAGS) -c $< -o $@
CFLAGS = -Wall

SRCS = $(wildcard src/*/*.c)

PROGS = $(patsubst %.c,%,$(SRCS))
# PROGS = $(subst src/,obj/,$(PROGS_TMP))

all: $(PROGS)

test: $(PROGS)


clean:
	rm -rf obj/*

%: %.c
	mkdir -p $(subst src/,obj/,$(@D))
	$(CC) $(CFLAGS) -o $(subst src/,obj/,$@) $<
# $(CC) $(CFLAGS)  -o $@ $<
