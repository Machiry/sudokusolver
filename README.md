sudokusolver
============

YASS: Yet Another SUDOKU solver

This is a simple sudoku solver written using C in less than an hour.

This program tries to read 81 numbers. Each corresponding to 81 cells of the SUDOKU grid. Entered in row majoring order.
A missing value in a cell is indicated with 0.

Cleaning:

make clean

Building:

make

Usage:

./sudokusolver < input_file

input_file contents:

5 3 0 0 7 0 0 0 0

6 0 0 1 9 5 0 0 0

0 9 8 0 0 0 0 6 0

8 0 0 0 6 0 0 0 3

4 0 0 8 0 3 0 0 1

7 0 0 0 2 0 0 0 6

0 6 0 0 0 0 2 8 0

0 0 0 4 1 9 0 0 5

0 0 0 0 8 0 0 7 9

Output:

Solved Successfully

Result:
Number of rounds:3, Elapsed Time:0.034000 sec (0.000034 msec)

Result Matrix:

5 3 4   6 7 8   9 1 2

6 7 2   1 9 5   3 4 8

1 9 8   3 4 2   5 6 7


8 5 9   7 6 1   4 2 3

4 2 6   8 5 3   7 9 1

7 1 3   9 2 4   8 5 6


9 6 1   5 3 7   2 8 4

2 8 7   4 1 9   6 3 5

3 4 5   2 8 6   1 7 9
