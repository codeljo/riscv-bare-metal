#
# ESP32-C2
#

#include "../include/registers.inc"

.globl gpio_input_enable
.globl gpio_read

.globl gpio_output_enable
.globl gpio_output_func_select
.globl gpio_write
.globl gpio_toggle

.globl random

.text

# a0:pin
gpio_input_enable:
      li   t0, IO_MUX_GPIO0_REG
      slli t1, a0, 2
      add  t0, t0, t1
      li   t1, (1 << 8 | 1 << 9)
      sw   t1, 0(t0)
      ret

# a0:pin
gpio_output_enable:
      li   t0, GPIO_ENABLE_REG
      lw   t1, 0(t0)
      li   t2, 1
      sll  t2, t2, a0
      or   t1, t1, t2
      sw   t1, 0(t0)
      ret

# a0:pin, a1:value
gpio_output_func_select:
      li   t0, GPIO_FUNC0_OUT_SEL_CFG_REG
      slli t1, a0, 2
      add  t0, t0, t1
      sw   a1, 0(t0)
      ret

# a0:pin - a0:return
gpio_read:
      li   t0, GPIO_IN_REG
      lw   t1, 0(t0)
      li   t2, 1
      sll  t2, t2, a0
      and  t3, t2, t1
      li   a0, 1
      beq  t3, t2, .LRE
      li   a0, 0
.LRE:
      ret

# a0:pin, a1:value
gpio_write:
      li   t0, GPIO_OUT_W1TC_REG
      beq  zero, a1, .LC
      li   t0, GPIO_OUT_W1TS_REG
.LC:
      li   t1, 1
      sll  t1, t1, a0
      sw   t1, 0(t0)
      ret

# a0:pin
gpio_toggle:
      addi sp, sp, -16
      sw   ra, 0(sp)

      li   t0, GPIO_OUT_REG
      lw   t1, 0(t0)
      li   t2, 1
      sll  t2, t2, a0
      and  t3, t1, t2
      li   a1, 0
      bne  zero, t3, .L0
      li   a1, 1
.L0:
      call gpio_write

      lw   ra, 0(sp)
      addi sp, sp, 16
      ret

# a0:return
random:
      li   t0, RNG_DATA_REG
      lw   a0, 0(t0)
      ret
