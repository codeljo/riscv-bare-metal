#
# ESP32-C3
#

#include "../include/registers.inc"

.globl clock_set_cpu_freq

.text

# a0: MHz (20, 80, 160)
clock_set_cpu_freq:
      li   t0, 20
      beq  a0, t0, .L20
      li   t0, 80
      beq  a0, t0, .L80
      li   t0, 160
      beq  a0, t0, .L160
      jal  zero, .LRET
.L20:
      # reset default 20 MHz clock: (XTAL_CLK / 2)
      li   t0, SYSTEM_SYSCLK_CONF_REG
      li   t1, 0x1
      sw   t1, 0(t0)
      li   t0, SYSTEM_CPU_PER_CONF_REG
      li   t1, 0x1C
      sw   t1, 0(t0)
      jal  zero, .LRET
.L80:
      li   t3, 0x18
      j    .L80_160
.L160:
      li   t3, 0x19
.L80_160:
      li   t0, SYSTEM_SYSCLK_CONF_REG
      li   t1, 0x401
      sw   t1, 0(t0)
      li   t0, SYSTEM_CPU_PER_CONF_REG
      sw   t3, 0(t0)
.LRET:
      ret
