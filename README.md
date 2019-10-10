made in colaboration with [jlagos](https://github.com/jonnylagos115)
# fillit
fillit is an assignment from 42, the goal is to take Tetris pieces, and find the smallest possible square that the pieces can fit into.

fillit creates a `fillit` executable.
# How to use
run
`make` to compile the program.

run
`./fillit [source file]` to use the program. It will print the answer to the standard output.

run
`make debug` to compile and create .lldb directory for debug use.

run
`lldb fillit [source file]` to enter debug mode.

run
`make re` to recompile.

# Input
Tetris pieces should be written in a source file, each piece in a 4 by 4 square, seperated by a single newline, with `#` marking the blocks, and `.` marking the empty space in the square. Location in the square does not matter, but rotation does, pieces will retain their rotation in the final square.

example:
```
....
....
.##.
.##.

.#..
.#..
.#..
.#..

.###
..#.
....
....

....
..##
.##.
....
```
