#
# ESP32-C6 (TRM 296, 303)
# 40 MHz default clock (XTAL_CLK / 1)
#

#include "../include/registers.inc"

.globl clock_set_cpu_freq

.equ CLK_XTAL_MAX,  40
.equ CLK_PLL_MAX,  160

.text

# a0: MHz (20, 40, 80, 160)
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

    # calculate required divider
    # supported frequencies for XTAL_CLK: 40, 20, 10, 5, 2.5, 1.25 MHz
    # PCR_CPU_LS_DIV_NUM: 0, 1, 3, 7, 15, 31
    # PCR_AHB_LS_DIV_NUM: 0, 1, 3, 7, 15, 31
    
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

    # select clock source (XTAL_CLK)
    # PCR_SOC_CLK_SEL (bits 17, 16) (0: XTAL_CLK, 1: PLL_CLOCK, 2: RC_FAST_CLK)
    li   t0, PCR_SYSCLK_CONF_REG
    lw   t1, (t0)
    li   t2, ~((1<<17) | (1<<16))
    and  t1, t1, t2
    sw   t1, (t0)

    # config divider of HP_ROOT_CLK to generate CPU_CLK
    li   t0, PCR_CPU_FREQ_CONF_REG
    lw   t1, (t0)
    andi t1, t1, ~(0xFF)
    or   t1, t1, a1
    sw   t1, (t0)

    # config divider of HP_ROOT_CLK to generate AHB_CLK
    li   t0, PCR_AHB_FREQ_CONF_REG
    lw   t1, (t0)
    andi t1, t1, ~(0xFF)
    or   t1, t1, a1
    sw   t1, (t0)

.LXR:
    ret

# a0: MHz (80, 160)
clock_set_cpu_freq_pll:

    # calculate required divider
    # supported frequencies for PLL_CLOCK: 160, 80, 40 MHz
    # PCR_CPU_HS_DIV_NUM: 0, 1, 3
    # PCR_AHB_HS_DIV_NUM: 3, 7, 15
    
    # 80 MHz
    li   t0, 80
    li   a1, (1<<8)
    li   a2, (3<<8)
    beq  a0, t0, .LP0

    # 160 MHz
    li   t0, 160
    li   a1, 0
    li   a2, (3<<8)
    beq  a0, t0, .LP0

    # freq not supported for PLL_CLOCK
    j    .LPR

.LP0:

    # select clock source (XTAL_CLK)
    # PCR_SOC_CLK_SEL (bits 17, 16) (0: XTAL_CLK, 1: PLL_CLOCK, 2: RC_FAST_CLK)
    li   t0, PCR_SYSCLK_CONF_REG
    lw   t1, (t0)
    li   t2, ~((1<<17) | (1<<16))
    and  t1, t1, t2
    li   t2, (1<<16)
    or   t1, t1, t2
    sw   t1, (t0)

    # config divider of HP_ROOT_CLK to generate CPU_CLK
    li   t0, PCR_CPU_FREQ_CONF_REG
    lw   t1, (t0)
    li   t2, ~(0xFF00)
    and  t1, t1, t2
    or   t1, t1, a1
    sw   t1, (t0)

    # config divider of HP_ROOT_CLK to generate AHB_CLK
    li   t0, PCR_AHB_FREQ_CONF_REG
    lw   t1, (t0)
    li   t2, ~(0xFF00)
    and  t1, t1, t2
    or   t1, t1, a2
    sw   t1, (t0)

.LPR:
    ret