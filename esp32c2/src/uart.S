#
# ESP32-C2
# (TRM 303, 319)
# XTAL_CLK: 26 MHz, 40 MHz
#
# NOTE - must define XTAL_26MHZ if esp32-c2 dev board has 26 MHz external crystal instead of 40 MHZ.
#

#include "../include/registers.inc"

.globl uart_0_init

# CLKDIV for 115200 baud rate
#ifdef XTAL_26MHZ
.equ UART_CLKDIV_REG_VAL, 0x000000E2
#else
.equ UART_CLKDIV_REG_VAL, 0x0000015B
#endif

.text

uart_0_init:

    # set UART0 registers to reset defaults except for baud rate via UART0_CLKDIV_REG

    # UART0_ID_REG
    #    UART_REG_UPDATE  (bit 31)
    #    UART_UPDATE_CTRL (bit 30)

    # clear UART_UPDATE_CTRL (bit 30)
    li   t0, UART0_ID_REG
    lw   t1, (t0)
    li   t2, ~(1<<30)
    and  t1, t1, t2
    sw   t1, (t0)

    # wait for UART_REG_UPDATE (bit 31) to be 0
    li   t0, UART0_ID_REG
    li   t1, (1<<31)
    .L0:
    lw   t2, (t0)
    and  t2, t2, t1
    bne  t2, zero, .L0

    # config uart clock source, divisor
    # (reset: 0x03700000)
    li   t0, UART0_CLK_CONF_REG
    li   t1, 0x03700000
    sw   t1, (t0)

    # config uart baud rate
    # (reset: 0x000002B6)
    li   t0, UART0_CLKDIV_REG
    li   t1, UART_CLKDIV_REG_VAL
    sw   t1, (t0)

    # config UART0_CONF0_REG 
    # (reset: 0x1000001C)
    li   t0, UART0_CONF0_REG
    li   t1, 0x1000001C
    sw   t1, (t0)

    # config UART0_CONF1_REG
    # (reset: 0x0000C060)
    li   t0, UART0_CONF1_REG
    li   t1, 0x0000C060
    sw   t1, (t0)

    # sync config by writing 1 to UART_REG_UPDATE (bit 31)
    li   t0, UART0_ID_REG
    lw   t1, (t0)
    li   t2, (1<<31)
    or   t1, t1, t2
    sw   t1, (t0)

    ret