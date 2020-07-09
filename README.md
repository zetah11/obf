# Reflective Brainfuck (aka obf)

A transpiler for a Brainfuck dialect that supports reflection through a 
Turing oracle.


## Usage

obf takes input from stdin, and outputs the generated C program to stdout.

As an example, the halting problem is neatly encoded in Reflective Brainfuck
with just seven characters of code:

```
+++?[]-
```

First, this increments the current cell to 3. Then, it checks whether the
instruction at the current instruction + 3 (the final -) is reachable. If so, it
enters an infinite loop, thereby never reaching the -. Otherwise, it skips the
loop, reaching the -.

Calculating the correct behaviour for this program is left as an exercise to the
reader.


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


## Implementation details

* In order to maintain backwards compatibility with decidability theory, 
the generated program will sometimes produce incorrect results when using the 
reflective oracle operator.
