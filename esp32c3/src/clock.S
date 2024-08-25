#
# ESP32-C3 (TRM 187, 427, 428)
# 20 MHz default clock (XTAL_CLK / 2)
#

#include "../include/registers.inc"

.globl clock_set_cpu_freq

.text

# a0: MHz (20, 40, 80, 160)
clock_set_cpu_freq:
      li   t0, 20
      beq  a0, t0, .L20
      li   t0, 40
      beq  a0, t0, .L40
      li   t0, 80
      beq  a0, t0, .L80
      li   t0, 160
      beq  a0, t0, .L160
      jal  zero, .LRET
.L20:
      # 20 MHz clock (XTAL_CLK / 2) (reset default)
      li   t0, SYSTEM_SYSCLK_CONF_REG
      li   t1, (1<<0)
      sw   t1, 0(t0)
      li   t0, SYSTEM_CPU_PER_CONF_REG
      li   t1, (1<<3) | (1<<2)
      sw   t1, 0(t0)
      jal  zero, .LRET
.L40:
      # 40 MHz clock (XTAL_CLK / 1)
      li   t0, SYSTEM_SYSCLK_CONF_REG
      li   t1, 0
      sw   t1, 0(t0)
      li   t0, SYSTEM_CPU_PER_CONF_REG
      li   t1, (1<<3) | (1<<2)
      sw   t1, 0(t0)
      jal  zero, .LRET
.L80:
      li   t3, (1<<3) | (1<<2)
      j    .L80_160
.L160:
      li   t3, (1<<3) | (1<<2) | (1<<0)
.L80_160:
      li   t0, SYSTEM_SYSCLK_CONF_REG
      li   t1, (1<<10) | (1<<0)
      sw   t1, 0(t0)
      li   t0, SYSTEM_CPU_PER_CONF_REG
      sw   t3, 0(t0)
.LRET:
      ret
