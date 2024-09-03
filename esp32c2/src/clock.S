#
# ESP32-C2
# (TRM 142, 251, 259)
# 20 MHz default clock (XTAL_CLK / 2)
#

#include "../include/registers.inc"

.globl clock_set_cpu_freq

.equ CLK_XTAL_MAX,  40
.equ CLK_PLL_MAX,   120

.text

# a0: MHz (5, 10, 20, 40) (80, 120)
clock_set_cpu_freq:
    addi sp, sp, -16
    sw   ra, 0(sp)

    # XTAL_CLK
    li   t0, CLK_XTAL_MAX + 1
    bge  a0, t0, .LPLL
    call clock_set_cpu_freq_xtal

    .LPLL:
    # PLL_CLOCK
    li   t0, CLK_PLL_MAX + 1
    bge  a0, t0, .LRET
    call clock_set_cpu_freq_pll

    .LRET:
    lw   ra, 0(sp)
    addi sp, sp, 16
    ret

# a0: MHz (5, 10, 20, 40)
clock_set_cpu_freq_xtal:

    # 5 MHz
    li   t0, 5
    li   a1, 7
    beq  a0, t0, .LX0

    # 10 MHz
    li   t0, 10
    li   a1, 3
    beq  a0, t0, .LX0

    # 20 MHz
    li   t0, 20
    li   a1, 1
    beq  a0, t0, .LX0

    # 40 MHz
    li   t0, 40
    li   a1, 0
    beq  a0, t0, .LX0

    # freq not supported for XTAL_CLK
    j    .LXR

    .LX0:
    li   t0, SYSTEM_SYSCLK_CONF_REG
    sw   a1, 0(t0)

    .LXR:
    ret

# a0: MHz (80, 120)
clock_set_cpu_freq_pll:

    # 80 MHz
    li   t0, 80
    li   a1, 0
    beq  a0, t0, .LP0

    # 120 MHz
    li   t0, 120
    li   a1, 1
    beq  a0, t0, .LP0

    # freq not supported for PLL_CLK
    j    .LPR

    .LP0:
    # SYSTEM_SOC_CLK_SEL(bits 11, 10): 0: XTAL_CLK, 1: PLL_CLOCK, 2: RC_FAST_CLK
    li   t0, SYSTEM_SYSCLK_CONF_REG
    lw   t1, (t0)
    li   t2, ~((1<<11 | 1<<10))
    and  t1, t1, t2
    li   t2, (1<<10)
    or   t1, t1, t2
    sw   t1, 0(t0)

    # SYSTEM_CPUPERIOD_SEL(bits 1,0): 0: 80 MHz, 1: 120 MHz
    li   t0, SYSTEM_CPU_PER_CONF_REG
    lw   t1, (t0)
    andi t1, t1, ~(0b11)
    or   t1, t1, a1
    sw   t1, 0(t0)

    .LPR:
    ret
