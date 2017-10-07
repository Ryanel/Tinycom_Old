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
