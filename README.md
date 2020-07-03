# Reflective Brainfuck (aka obf)

A transpiler for a Brainfuck dialect that supports reflection through a 
Turing oracle.


## wat

Reflective Brainfuck extends regular Brainfuck by adding the 
*reflective oracle operator* `?`. In terms of C, its operators are

Operator | C Equivalent
-------- | ------------
`>`      | `++p`
`<`      | `--p`
`+`      | `++*p`
`-`      | `--*p`
`.`      | `putchar(*p)`
`,`      | `*p = getchar()`
`[`      | `while (*p) {`
`]`      | `}`
`?`      | `*p = reachable(i + *p)`

where `p` is a pointer to the current cell, `i` is the instruction pointer,
and `reachable` is a function that returns `0` if the instruction at `i + *p`
is unreachable, and `1` otherwise.

This repo provides a Reflective Brainfuck-to-C transpiler, with a highly 
efficient implementation of `reachable`.


## Usage

obf takes input from stdin, and outputs the generated C program to stdout.


## Implementation details

There are a few things to note about obf:
* the generated C code is optimized for size. 
* the generated program returns the value at the current cell when the program 
returns
* in order to maintain backwards compatability with decidability theory, 
the generated program will sometimes produce incorrect results when using the 
reflective oracle operator.