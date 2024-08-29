#
# ESP32-H2
# Systimer (TRM 382)
#

#include "../include/registers.inc"

.globl delay_us
.globl delay_ms

.equ SYSTIMER_TIMER_UNIT0_VALUE_VALID, 29
.equ SYSTIMER_TIMER_UNIT0_UPDATE,      30

.text

# a0: return
systimer_systick_get:
    li   t0, SYSTIMER_UNIT0_OP_REG
    li   t1, (1<<SYSTIMER_TIMER_UNIT0_UPDATE)
    sw   t1, 0(t0)
    nop
    nop
    li   t0, SYSTIMER_UNIT0_VALUE_LO_REG
    lw   a0, 0(t0)
    ret

# a0:delay in systicks
delay_systicks:
    addi sp, sp, -16
    sw   ra, 0(sp)
    sw   a0, 4(sp)

    # time #1 (t6)
    call systimer_systick_get
    mv   t6, a0

    # add delay time to time #1
    lw   t0, 4(sp)
    add  t6, t6, t0

    # time #2
    .LD2:
    call systimer_systick_get
    blt  a0, t6, .LD2

    lw   ra, 0(sp)
    addi sp, sp, 16
    ret

# a0:delay in microseconds (µs)
delay_us:
    addi sp, sp, -16
    sw   ra, 0(sp)

    # us to systicks
    li   t0, 16
    mul  a0, a0, t0

    call delay_systicks

    lw   ra, 0(sp)
    addi sp, sp, 16
    ret

# a0:delay in milliseconds (ms)
delay_ms:
    addi sp, sp, -16
    sw   ra, 0(sp)

    # ms to systicks
    li   t0, 16000
    mul  a0, a0, t0

    call delay_systicks

    lw   ra, 0(sp)
    addi sp, sp, 16
    ret