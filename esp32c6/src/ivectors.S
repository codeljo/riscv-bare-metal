#
# ESP32-C6
#

#include "../include/registers.inc"

.option norelax
.option norvc

.globl _interrupt_vector_table_base

.weak interrupt_handler1
.weak interrupt_handler2
.weak interrupt_handler3
.weak interrupt_handler4
.weak interrupt_handler5
.weak interrupt_handler6
.weak interrupt_handler7
.weak interrupt_handler8
.weak interrupt_handler9
.weak interrupt_handler10
.weak interrupt_handler11
.weak interrupt_handler12
.weak interrupt_handler13
.weak interrupt_handler14
.weak interrupt_handler15
.weak interrupt_handler16
.weak interrupt_handler17
.weak interrupt_handler18
.weak interrupt_handler19
.weak interrupt_handler20
.weak interrupt_handler21
.weak interrupt_handler22
.weak interrupt_handler23
.weak interrupt_handler24
.weak interrupt_handler25
.weak interrupt_handler26
.weak interrupt_handler27
.weak interrupt_handler28
.weak interrupt_handler29
.weak interrupt_handler30
.weak interrupt_handler31

# align to a 256-byte boundary (2^8 = 256)
.p2align 8

.text

_interrupt_vector_table_base:

# trap vector address (mtvec + 0x00) is reserved for exceptions
interrupt_vector_0:
    j panic_handler
    j interrupt_handler1
    j interrupt_handler2
    j interrupt_handler3
    j interrupt_handler4
    j interrupt_handler5
    j interrupt_handler6
    j interrupt_handler7
    j interrupt_handler8
    j interrupt_handler9
    j interrupt_handler10
    j interrupt_handler11
    j interrupt_handler12
    j interrupt_handler13
    j interrupt_handler14
    j interrupt_handler15
    j interrupt_handler16
    j interrupt_handler17
    j interrupt_handler18
    j interrupt_handler19
    j interrupt_handler20
    j interrupt_handler21
    j interrupt_handler22
    j interrupt_handler23
    j interrupt_handler24
    j interrupt_handler25
    j interrupt_handler26
    j interrupt_handler27
    j interrupt_handler28
    j interrupt_handler29
    j interrupt_handler30
    j interrupt_handler31

panic_handler:
    j .

interrupt_handler1:
interrupt_handler2:
interrupt_handler3:
interrupt_handler4:
interrupt_handler5:
interrupt_handler6:
interrupt_handler7:
interrupt_handler8:
interrupt_handler9:
interrupt_handler10:
interrupt_handler11:
interrupt_handler12:
interrupt_handler13:
interrupt_handler14:
interrupt_handler15:
interrupt_handler16:
interrupt_handler17:
interrupt_handler18:
interrupt_handler19:
interrupt_handler20:
interrupt_handler21:
interrupt_handler22:
interrupt_handler23:
interrupt_handler24:
interrupt_handler25:
interrupt_handler26:
interrupt_handler27:
interrupt_handler28:
interrupt_handler29:
interrupt_handler30:
interrupt_handler31:
    # loop here to catch interrupts that are not handled
    # j interrupt_handler31
    mret
