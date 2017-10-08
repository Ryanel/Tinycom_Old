# Tinycom

Tinycom is a open source, C++, tiny console!
It gives modern utilities and easy access to programming a tiny, full powered console.

Tinycom is a fantasy console, or a console with no hardware. It has about the
same capabilities as the SNES / Genesis.

## What makes it different?

The PICO-8 has less **hardware** capabilities then even the NES, but has more raw power, and is easy to program; this is the dynamic the Tinycom has. It has similar capabilities to the SNES, but also has a lot more raw power, and is easier to program for then a NES or SNES.

The goal, however is different. The Tinycom isn't a tiny machine with some simulated quirks - the Tinycom VM runs it's own ISA, has bytecode, assemblers, and documentation. It's coded for in Assembly, and has strict runtime limits (the simulated CPU genuinely runs slower).

So, if the PICO-8's goal is to give people a taste of restrictive programming, Tinycom allows the programmer to flex all of his muscles, programming for a simulated small machine. Optimization is key -
you have limited cartridge space.

## How is programming for this made easier?
Tinycom comes with Tinyide: an Integrated Development Environment that uses the command line tools, and makes programming easier. It doesn't exist yet, so for now, you must use the command line tools.

Tinycom follows the UNIX method of having many utilities that do one thing very good.

It comes with:
* An Assembler
* A linker
* A resource converter

In the future, compilers (like clang) will be able to target Tinycom, as the assembly will be fully feature. Or, a compiler will be written specifically for Tinycom.

The assembly also is simple, with a small instruction set.

For instance
```
LDX $300 ; Load $300 into X
PHA ; Push A onto stack
TXA ; Transfer X to A
EOR $302 ; XOR
STA $302 ; Store A into $302
PLA
```

Could be respresented as:

```
mov r0, [300]
push r1
mov r1, r0
xor r1, [302]
mov [302], r1
pop r1
``

The code's the same, equivalent, but there's only 1 move command, with the same semantics (destination first, source second).
