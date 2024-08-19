<br>

# RISC-V

<br>

# Table of Contents 
[ISA](#isa)  
[Registers](#registers)  
[Instruction Set](#risc-v-instruction-set)  
[CSR Registers](#csr---control-and-status-registers)  
[Compilers](#compilers)  
[Compiler Options](#compiler-options)  
[Assembly Language Example](#assembly-language-example)  
[Emulators](#risc-v-emulators)  
[Simulators](#risc-v-simulators)  
[References](#risc-v-references)  
<br>

# RISC-V

RISC-V is an instruction set architecture (ISA) based on the reduced instruction set computer (RISC) design.

<br>

# ISA

Consists of a base ISA  
`RV32I (32-bit)`, `RV64I (64-bit)`  
* `I` Integer Base

Optional extensions include:
* `M` Integer Multiplication, Division
* `A` Atomic Instructions
* `F` Single-Precision Floating-Point
* `D` Double-Precision Floating-Point
* `G` General - (IMAFD)
* `C` Compressed Instructions

<br>

# Registers

**Registers**  
x0 - x31  

**Register Size**  
`RV32E` 16-bit  
`RV32I` 32-bit   
`RV64I` 64-bit  

**Register Aliases**  

| Register      | Register Alias | Description        |
|---------------|----------------|--------------------|
| x0            | zero           | always zero        |
| x1            | ra             | return address     |
| x2            | sp             | stack pointer      |
| x3            | gp             | global pointer     |
| x4            | tp             | thread pointer     |
| x5-x7, x28-31 | t0-t6          | temporary          |
| x10-x17       | a0-a7          | function arguments |
| x8,x9,x18-x27 | s0-s11         | calle saved        |
| x10,x11       | a0-a1          | return value       |

<br>

# RISC-V Instruction Set

> Base Integer Instruction Set (RV32I)
 
[Load](#load)  
[Store](#store)  
[Arithmetic](#arithmetic)  
[Logical](#logical)  
[Shift](#shift)  
[Branch](#branch)  
[Memory Ordering](#memory-ordering)  
[System](#system)  
[CSR](#csr)  

### `Load`

> Load instructions allow the processor to fetch data from memory and store it in registers for further processing.

| Instruction | Description               | Usage                        |
| ----------- | ------------------------- | ---------------------------- |
| LB          | load byte                 | LB  rd, offset12(rs1)        |
| LH          | load halfword             | LH  rd, offset12(rs1)        |
| LW          | load word                 | LW  rd, offset12(rs1)        |
| LBU         | load byte unsigned        | LBU rd, offset12(rs1)        |
| LHU         | load halfword unsigned    | LHU rd, offset12(rs1)        |
| LWU         | load word unsigned        | LWU rd, offset12(rs1)        |

### `Load (Pseudo)`

| Instruction | Description            | Usage                        | Actual Instruction         |
| ----------- | -----------------------| ---------------------------- | -------------------------- |
| LA          | load address           | LA  rd, symbol               | AUIPC rd, symbol[31:12]<br>ADDI rd, rd, symbol[11:0]  |
| LI          | load immediate         | LI  rd, imm12                | ADDI  rd, zero, imm12      |
| LI          | load immediate         | LI  rd, imm                  | LUI   rd, imm[31:!2]<br>ADDI rd, rd, imm[11:0]    |
| MV          | copy register          | MV  rd, rs                   | ADDI  rd, rs, 0            |


### `Store`

> Store instructions allow the processor to write data from registers to memory locations.

| Instruction | Description            | Usage                        |
| ----------- | -----------------------| ---------------------------- |
| SB          | load byte              | SB rs1, offset12(rs2)        |
| SH          | load halfword          | SH rs1, offset12(rs2)        |
| SW          | load word              | SW rs1, offset12(rs2)        |

### `Arithmetic`

> Arithmetic instructions provide the basic operations for integer computation.

| Instruction | Description               | Usage                        |
| ----------- | ------------------------- | ---------------------------- |
| ADD         | add                       | ADD   rd, rs1, rs2           |
| ADDI        | add immediate             | ADDI  rd, rs1, imm12         |
| SUB         | subtract                  | SUB   rd, rs1, rs2           |
| LUI         | load upper immediate      | LUI   rd, imm20              |
| AUIPC       | add upper immediate to pc | AUIPC rd, imm20              |

### `Logical`

> Logic instructions provide the basic bitwise and shift operations.

| Instruction | Description            | Usage                        |
| ----------- | -----------------------| ---------------------------- |
| AND         | and                    | AND   rd, rs1, rs2           |
| ANDI        | and immediate          | ANDI  rd, rs1, imm12         |
| OR          | or                     | OR    rd, rs1, rs2           |
| ORI         | or immediate           | ORI   rd, rs1, imm12         |
| XOR         | xor                    | XOR   rd, rs1, rs2           |
| XORI        | xor immediate          | XORI  rd, rs1, imm12         |

### `Logical (Pseudo)`

| Instruction | Description                    | Usage                        | Actual Instruction         |
| ----------- | -------------------------------| ---------------------------- | -------------------------- |
| NOT         | not (one's complement)         | NOT  rd, rs                  | XORI rd, rs, -1            |
| NEG         | negate (two's complement)      | NEG  rd, rs                  | SUB  rd, zero, rs          |
| NEGW        | negate word (two's complement) | NEGW  rd, rs                 | SUBW rd, zero, rs          |

### `Shift`

| Instruction | Description                       | Usage                        |
| ----------- | --------------------------------- | ---------------------------- |
| SLL         | shift left logical                | SLL   rd, rs1, rs2           |
| SLLI        | shift left logical immediate      | SLLI  rd, rs1, imm           |
| SRL         | shift right logical               | SRL   rd, rs1, rs2           |
| SRLI        | shift right logical immediate     | SRI   rd, rs1, imm           |
| SRA         | shift right arithmetic            | SRA   rd, rs1, rs2           |
| SRAI        | shift right arithmetic immediate  | SRAI  rd, rs1, imm           |

### `Branch`

> Branch instructions allow the processor to conditionally change the control flow.

| Instruction | Description                                | Usage                        |
| ----------- | ------------------------------------------ | ---------------------------- |
| BEQ         | branch if equal                            | BEQ   rs1, rs2, imm12        |
| BNE         | branch if not equal                        | BNE   rs1, rs2, imm12        |
| BLT         | branch if less than                        | BLT   rs1, rs2, imm12        |
| BLTU        | branch if less than (unsigned)             | BLTU  rs1, rs2, imm12        |
| BGE         | branch if greater than or equal            | BGE   rs1, rs2, imm12        |
| BGEU        | branch if greater than or equal (unsigned) | BGEU  rs1, rs2, imm12        |
| JAL         | jump and link                              | JAL   rd, imm20              |
| JALR        | jump and link register                     | JALR  rd, imm12(rs)          |

### `Branch (Pseudo)`

| Instruction | Description            | Usage                        | Actual Instruction         |
| ----------- | -----------------------| ---------------------------- | -------------------------- |
| J           | jump                   | J     offset                 | JAL   zero, offset         |
| JAL         | jump and link          | JAL   offset                 | JAL   ra, offset           |
| CALL        | call                   | CALL  offset12               | JALR  ra, ra, offset12     |
| CALL        | call                   | CALL  offset                 | AUIPC ra, offset[31:12]<br>JALR ra, ra, offset[11:0] |
| RET         | return                 | RET                          | JALR  zero, 0(ra)          |

### `Memory Ordering`

> Memory ordering instructions are used to control the order in which memory accesses are performed, ensuring the correct execution of concurrent and multi-threaded programs.

| Instruction | Description                                           | Usage                        |
| ----------- | ----------------------------------------------------- | ---------------------------- |
| FENCE       | specify memory access types that must be ordered      |                              |
| FENCE.I     | specify instruction fetches are properly ordered      |                              |

### `System`

> System instructions

| Instruction | Description                                                        | Usage                        |
| ----------- | ------------------------------------------------------------------ | ---------------------------- |
| EBREAK      | system break - return control to a debugging environment           | EBREAK                       |
| ECALL       | system call  - service request to the execution environment        | ECALL                        |

### `CSR`

> Control and Status Registers (CSR) are accessed using the CSR instructions.  
> The set, clear instructions use a bitmask to set or clear individual bits.

| Instruction | Description                                  | Usage                        |
| ----------- | -------------------------------------------- | ---------------------------- |
| CSRRW       | CSR read, write                              | CSRRW  rd, csr, rs1          |
| CSRRS       | CSR read, set bits                           | CSRRS  rd, csr, rs1          |
| CSRRC       | CSR read, clear bits                         | CSRRC  rd, csr, rs1          |
| CSRRWI      | CSR read, write                              | CSRRWI rd, csr, imm          |
| CSRRSI      | CSR read, set bits                           | CSRRSI rd, csr, imm          |
| CSRRCI      | CSR read, clear bits                         | CSRRCI rd, csr, imm          |

### `CSR (Pseudo)`

| Instruction | Description            | Usage               | Actual Instruction           |
| ----------- | ---------------------- | ------------------- | ---------------------------- |
| CSRR        | CSR read               | CSRR  rd, csr       | CSRRS  rd, csr, x0           |
| CSRW        | CSR write              | CSRW  csr, rs       | CSRRW  x0, csr, rs           |
| CSRS        | CSR set bits           | CSRS  csr, rs       | CSRRS  x0, csr, rs           |
| CSRC        | CSR clear bits         | CSRC  csr, rs       | CSRRC  x0, csr, rs           |
| CSRWI       | CSR write              | CSRWI csr, imm 	 | CSRRWI x0, csr, imm          |
| CSRSI       | CSR set bits           | CSRSI csr, imm      | CSRRSI x0, csr, imm          |
| CSRCI       | CSR clear bits         | CSRCI csr, imm      | CSRRCI x0, csr, imm          |

<br>

# CSR - Control and Status Registers

> CSR are used for various purposes, such as managing interrupts, exceptions, and performance monitoring, as well as providing information about the processor implementation.

| Register      | Description                                |
|---------------|--------------------------------------------|
| mvendorid     | vendor id                                  |
| marchid       | architecture id                            |
| mimpid        | implementation id                          |
| mhartid       | hardware thread id                         |
| mstatus       | machine status                             |
| mie           | machine interrupt enable                   |
| mtvec         | machine trap handler address               |
| mscratch      | scratch register for machine trap handlers |
| mepc          | machine exception program counter          |
| mcause        | machine trap cause                         |
| mtval         | machine trap value                         |
| mcycle        | machine cycle counter                      |
| minstret      | machine instructions retired counter       |
| mtime         | machine time                               |
| mtimecmp      | machine time compare                       |

<br>

# Compilers

Cross compilers for RISC-V processors.  

**Linux**   
><br>apt install gcc-riscv64-unknown-elf  
<br>

<br>

**macOS**  
><br>brew tap riscv-software-src/riscv  
brew install riscv-tools  
<br>

<br>

**Windows, macOS, Linux**  
><br>The xPack GNU RISC-V Embedded GCC  
A standalone cross-platform (Windows, macOS, GNU/Linux) binary distribution of GNU RISC-V Embedded GCC.  <br>
https://github.com/xpack-dev-tools/riscv-none-elf-gcc-xpack  
<br>

<br>

**Using `gcc-riscv64-unknown-elf` as a cross compiler**  
```
show compile targets:
riscv64-unknown-elf-gcc --print-multi-lib

build:
riscv64-unknown-elf-gcc -Wall -Wextra -march=rv32i -mabi=ilp32 -nostdlib -Wl,--entry=_start -O main.S -o main
```  
<br>

**Using `clang` as a cross compiler**  
```
LLVM/Clang can be used as a cross compiler.

verify clang supports RISC-V (riscv32) as a target:
clang --print-targets

build:
clang -Wall -Wextra --target=riscv32 -march=rv32i -mabi=ilp32 -nostdlib -fuse-ld=lld -Wl,--entry=_start -O main.S -o main
```  
<br>

<br>

# Compiler Options
GCC command-line arguments all begin with `-m`, and are all specific to the RISC-V architecture port.  

`-march, -mabi, and -mtune`

<br>

`-march=ISA`  
**selects the architecture to target**  
This controls which instructions and registers are available for the compiler to use.

Base ISA's
* `RV32I` 32-bit registers
* `RV32E` 16-bit registers
* `RV64I` 64-bit registers

Base ISA
* `I` Integer Base

Extensions to the base ISA
* `M` Integer Multiplication, Division
* `A` Atomic Instructions
* `F` Single-Precision Floating-Point
* `D` Double-Precision Floating-Point
* `G` General - (IMAFD)
* `C` Compressed Instructions

Example   
`-march=RV32I`

<br>

`-mabi=ABI`  
**selects the ABI to target**  
This controls the calling convention (which arguments are passed in which registers) and the layout of data in memory.

>RISC-V defines 2 integer ABI's, and 3 floating-point ABI's.
The integer ABI's use the standard ABI naming scheme:
    ilp32: int, long, and pointers are all 32-bits long. long is a 64-bit type, char is 8-bit, and short is 16-bit.
    lp64: long, and pointers are 64-bits long, while int is a 32-bit type. The other types remain the same as ilp32.

>The floating-point ABI's are RISC-V specific:
    "" (the empty string): No floating-point arguments are passed in registers.
    f: 32-bit and smaller floating-point arguments are passed in registers. Requires the F extension.
    d: 64-bit and smaller floating-point arguments are passed in registers. Requires the D extension.

Example  
`-mabi=ilp32`

<br>

`-mtune=CODENAME`  
**selects the microarchitecture to target**

<br>

# Assembly Language Example
```S
#
# Basic Template
#

.globl _start

.text

_start:

loop:
    nop
    jal  zero, loop
```

<br>

# RISC-V Emulators

## QEMU
>Linux, macOS, Windows

[https://www.qemu.org/](https://www.qemu.org/)  
[https://github.com/xpack-dev-tools/qemu-riscv-xpack/](https://github.com/xpack-dev-tools/qemu-riscv-xpack/)  

<br>

# RISC-V Simulators

## qtrvsim
>Linux, macOS, Windows

[https://github.com/cvut/qtrvsim](https://github.com/cvut/qtrvsim)

web version  
[https://comparch.edu.cvut.cz/qtrvsim/app](https://comparch.edu.cvut.cz/qtrvsim/app)

## RARS
>Java

https://github.com/TheThirdOne/rars

## Ripes
>Linux, macOS, Windows

[http://ripes.me/Ripes/](http://ripes.me/Ripes/)

web version  
[https://ripes.me/](https://ripes.me/)

## Spike
[https://github.com/riscv-software-src/riscv-isa-sim](https://github.com/riscv-software-src/riscv-isa-sim)

<br>

# RISC-V References  

Instruction Set Manual  
[https://github.com/riscv/riscv-isa-manual/releases](https://github.com/riscv/riscv-isa-manual/releases)  

Assembly Programmer's Manual  
[https://github.com/riscv-non-isa/riscv-asm-manual/blob/main/riscv-asm.md](https://github.com/riscv-non-isa/riscv-asm-manual/blob/main/riscv-asm.md)  

Opcodes  
[https://github.com/riscv/riscv-opcodes](https://github.com/riscv/riscv-opcodes)

Glossary of Terms  
[https://github.com/riscv/riscv-glossary](https://github.com/riscv/riscv-glossary)

GNU Assembler, Binary Tools, and Linker Manuals  
[https://sourceware.org/binutils/docs/](https://sourceware.org/binutils/docs/)     
[https://sourceware.org/binutils/docs/as/RISC_002dV_002dDependent.html](https://sourceware.org/binutils/docs/as/RISC_002dV_002dDependent.html)

Misc  
[https://en.wikipedia.org/wiki/RISC-V](https://en.wikipedia.org/wiki/RISC-V)  
[https://en.wikipedia.org/wiki/Reduced_instruction_set_computer](https://en.wikipedia.org/wiki/Reduced_instruction_set_computer)  
[https://www.reddit.com/r/RISCV/](https://www.reddit.com/r/RISCV/)  
[https://wiki.debian.org/RISC-V](https://wiki.debian.org/RISC-V)  
[https://wiki.debian.org/RISC-V/32](https://wiki.debian.org/RISC-V/32)  
[https://gcc.gnu.org/onlinedocs/gcc/RISC-V-Options.html](https://gcc.gnu.org/onlinedocs/gcc/RISC-V-Options.html)  
[https://github.com/riscv-non-isa/riscv-toolchain-conventions](https://github.com/riscv-non-isa/riscv-toolchain-conventions)  
