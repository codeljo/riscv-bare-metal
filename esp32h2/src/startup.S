#
# ESP32-H2
#

#include "../include/registers.inc"

.globl _start

.equ CPU_CLOCK_SPEED_MHZ, 32

.section .text.init

_start:
      la   sp, _stack_top

      la   t0, _interrupt_vector_table_base
      csrw mtvec, t0
      
      # zero .bss
      la   t0, _bss_start
      la   t1, _bss_end
      beq  t0, t1, .L2
      .L1:
      sw   x0, 0(t0)
      addi t0, t0, 4
      blt  t0, t1, .L1
      .L2:

      call wdt_disable

      li   a0, CPU_CLOCK_SPEED_MHZ
      call clock_set_cpu_freq

      call main
      j .

.bss
      .p2align 4
_stack_bottom:
      .space 0x1000
_stack_top: