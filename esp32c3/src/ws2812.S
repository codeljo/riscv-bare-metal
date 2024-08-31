#
# ESP32-C3
# RGB - WS2812
# Requires 20 MHz CPU Clock
#

#include "../include/registers.inc"

.globl ws2812_write

.text

# a0:pin, a1:color(GRBx)
ws2812_write:
    li   t0, GPIO_OUT_W1TC_REG
    li   t1, GPIO_OUT_W1TS_REG
    li   t2, 1
    sll  t2, t2, a0

    li   t3, 24
    li   t4, 0

    mv   t5, a1
    li   t6, 0x80000000

.LNextBit:
    bge  t4, t3, .LRet

    addi t4, t4, 1
    sw   t2, (t1)         # HIGH
    and  a7, t6, t5
    srli t6, t6, 1
    bne  zero, a7, .L1

.L0:
    # high for 0.4 us
    # low for 0.85 us
    sw   t2, (t0)         # LOW
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    j .LNextBit

.L1:
    # high for 0.8 us
    nop
    nop
    nop
    nop
    nop
    # low for 0.45 us
    sw   t2, (t0)         # LOW
    j .LNextBit

.LRet:
    sw   t2, (t0)
    ret

# WS2812B - GRB, MSBit first, send 24 bits for each led in the chain
# 0     (0.4 us high, then 0.85 us low) (1.25 us total period) (32% duty)
# 1     (0.8 us high, then 0.45 us low) (1.25 us total period) (64% duty)
# reset (>=50 us low)
#
#  1000000 ÷ 1.25 = 800000 (800 kHz bit stream)
# 20000000 ÷ 800000 = 25 us per bit @ 20 MHz CPU Clock