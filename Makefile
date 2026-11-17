CC ?= gcc
CFLAGS ?= -std=c17 -Wall -Wextra -Wpedantic -O2
CPPFLAGS ?= -Iinclude
SRC = src/main.c src/parking.c src/algorithms.c src/graph.c src/benchmark.c
OBJ = $(SRC:.c=.o)
.PHONY: all clean test
all: smartpark
smartpark: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ)
test: smartpark
	$(CC) $(CFLAGS) $(CPPFLAGS) -o tests/test_algorithms tests/test_algorithms.c src/algorithms.c src/graph.c src/parking.c
	./tests/test_algorithms
clean:
	rm -f $(OBJ) smartpark tests/test_algorithms
