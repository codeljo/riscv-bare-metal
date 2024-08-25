#
# ESP32-C6 (TRM 296, 303)
# 40 MHz default clock (XTAL_CLK / 1)
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
    jal  zero, .LRET
.L20:
.L40:
    # select clock source (XTAL_CLK)
    # PCR_SOC_CLK_SEL (bits 17, 16) (0: XTAL_CLK, 1: PLL_CLOCK, 2: RC_FAST_CLK)
    li   t0, PCR_SYSCLK_CONF_REG
    lw   t1, (t0)
    li   t2, ~((1<<17) | (1<<16))
    and  t3, t1, t2
    sw   t3, (t0)

    # config divider of HP_ROOT_CLK to generate CPU_CLK
    li   t0, PCR_CPU_FREQ_CONF_REG
    lw   t1, (t0)
    # 40 MHz
    andi t1, t1, ~(0xFF)
    li   t2, 40
    beq  t2, a0, .L2040CDE
    # 20 MHz
    ori  t1, t1, 1
.L2040CDE:
    sw   t1, (t0)

    # config divider of HP_ROOT_CLK to generate AHB_CLK
    li   t0, PCR_AHB_FREQ_CONF_REG
    lw   t1, (t0)
    andi t1, t1, ~(0xFF)
    li   t2, 40
    beq  t2, a0, .L2040ADE
    ori  t1, t1, 1
.L2040ADE:    
    sw   t1, (t0)
.LRET:
    ret