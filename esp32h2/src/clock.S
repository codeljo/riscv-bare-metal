#
# ESP32-H2 (TRM 264, 317)
# 32 MHz default clock (XTAL_CLK / 1)
#

#include "../include/registers.inc"

.globl clock_set_cpu_freq

.equ CLK_XTAL_MAX,  32
.equ CLK_PLL_MAX,   96

.text

# a0: MHz (1, 2, 4, 8, 16, 32) (48, 96)
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

# a0: MHz (1, 2, 4, 8, 16, 32)
clock_set_cpu_freq_xtal:

    # calculate required divider
    # PCR_CPU_LS_DIV_NUM: 0, 1, 3, 7, 15, 31
    # PCR_AHB_LS_DIV_NUM: 0, 1, 3, 7, 15, 31
    
    # 1 MHz
    li   t0, 1
    li   a1, 31
    beq  a0, t0, .LX0

    # 2 MHz
    li   t0, 2
    li   a1, 15
    beq  a0, t0, .LX0

    # 4 MHz
    li   t0, 4
    li   a1, 7
    beq  a0, t0, .LX0

    # 8 MHz
    li   t0, 8
    li   a1, 3
    beq  a0, t0, .LX0

    # 16 MHz
    li   t0, 16
    li   a1, 1
    beq  a0, t0, .LX0

    # 32 MHz
    li   t0, 32
    li   a1, 0
    beq  a0, t0, .LX0

    # freq not supported for XTAL_CLK
    j    .LXR

    .LX0:

    # select clock source (XTAL_CLK)
    # PCR_SOC_CLK_SEL (bits 17, 16) (0: XTAL_CLK, 1: PLL_F96M_CLK, 2: RC_FAST_CLK, 3: PLL_F64M_CLK)
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

    # apply updated clock config
    li   t0, PCR_BUS_CLK_UPDATE_REG
    li   t1, 1
    sw   t1, (t0)

    .LXR:
    ret

# a0: MHz (48, 96)
clock_set_cpu_freq_pll:

    # calculate required divider for PLL_F96M_CLK
    # PCR_CPU_HS_DIV_NUM: 0, 1, 3
    # PCR_AHB_HS_DIV_NUM: 3, 7, 15
    # CPU_CLK frequency must be larger than or equal to AHB frequency, and must be an integer multiple of AHB_CLK frequency.
    # AHB_CLK frequency can not exceed 32 MHz.
    
    # 48 MHz
    li   t0, 48
    li   a1, 1
    li   a2, 3
    beq  a0, t0, .LP0

    # 96 MHz
    li   t0, 96
    li   a1, 0
    li   a2, 2
    beq  a0, t0, .LP0

    # freq not supported for PLL_CLOCK
    j    .LPR

    .LP0:

    # select clock source (PLL_F96M_CLK)
    # PCR_SOC_CLK_SEL (bits 17, 16) (0: XTAL_CLK, 1: PLL_F96M_CLK, 2: RC_FAST_CLK, 3: PLL_F64M_CLK)
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
    li   t2, ~(0xFF)
    and  t1, t1, t2
    or   t1, t1, a1
    sw   t1, (t0)

    # config divider of HP_ROOT_CLK to generate AHB_CLK
    li   t0, PCR_AHB_FREQ_CONF_REG
    lw   t1, (t0)
    li   t2, ~(0xFF)
    and  t1, t1, t2
    or   t1, t1, a2
    sw   t1, (t0)

    # apply updated clock config
    li   t0, PCR_BUS_CLK_UPDATE_REG
    li   t1, 1
    sw   t1, (t0)

    .LPR:
    ret