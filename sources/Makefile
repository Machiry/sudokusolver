CC = gcc
CPPFLAGS = -g -Wall
LDFLAGS = -g -Wall

all: sudokusolver

sudokusolver: main.o sudoku.o 
	$(CC) -o $@ $(LDFLAGS) $^

clean:
	rm -f *.o sudokusolver 
