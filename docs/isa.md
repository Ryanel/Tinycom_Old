# Instruction set
Tinycom's CPU runs on a CISC instruction set. Instruction size can range from
8 bits to 36 bits. However, there is more flexibility per opcode (due to conditional execution),
so the amount of instructions is less then a normal instruction set.

## Addresses
Tinycom has 24-bit addressing, up to `0xFFFFFF` in address space.
Addresses can point to ROM or RAM or MMIO. This is mapped by the
MMC (Memory Management Controller)
### Addressing Modes
Every instruction has a "mode" it puts the processor into. This determines how
memory accesses are handled.
#### None
No memory access is done, so the CPU saves cycles by not doing anything.
#### Direct
A simple memory access is done. No translation happens.
#### Indirect
The processor will add a register value to the address, as 24-bit values.
It then discards the top 8 bit, resulting in a 24-bit value. Carry is set if any of the
top 8 bits are set.

## Data
Tinycom's ALU can process 16-bit numbers, up to `0xFFFF`.
Some instructions (related to addresses) will do 24-bit addition / subtraction.
An exception is made when the processor is in Indirect Addressing Mode.

There is no support for Binary Coded Decimals (BCD)

## Instruction Layout
Tinycom instructions come in 4 flavors, ranging from 8 bits to 36 bits:
```
Legend:
o = opcode
1 = register 1
2 = register 2
v = value
a = address

Instruction  types:
|  8   |  16   |  24   |  32   |  36   |
oooooooo
oooooooo11112222
oooooooo11112222vvvvvvvvvvvvvvvv
oooooooo11112222aaaaaaaaaaaaaaaaaaaaaaaa
```

## Conditional execution
Some instructions support conditional execution. Instead of REG2 having a register,
a 4-bit condition code determines if the instruction is skipped or ran.

| Bits | FG |                      Description                        |
| ---- | -- | ------------------------------------------------------- |
| 0000 | EQ | Z flag set (equal)                                      |
| 0001 | NE | Z flag clear (not equal)                                |
| 0010 | HS | C flag set (unsigned higher or same)                    |
| 0011 | LO | C flag clear (unsigned lower)                           |
| 0100 | MI | N flag set (negative)                                   |
| 0101 | PL | N flag clear (non-negative)                             |
| 0110 | VS | V flag set (overflow)                                   |
| 0111 | VC | V flag clear (no overflow)                              |
| 1000 | HI | C flag set and Z flag clear                             |
| 1001 | LS | C flag clear or Z flag set                              |
| 1010 | GE | N flag set and V set or N clear and V clear             |
| 1011 | LT | N set and V clear or N clear and V set                  |
| 1100 | GT | Z clear with (either N or V set), or N clear and V set  |
| 1101 | LE | Z set or (N set and V clear), or N clear and V set      |
| 1110 | RS | Reserved                                                |
| 1111 | AL | Always (no condition)                                   |
