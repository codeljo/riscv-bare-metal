#
# ESP32-H2
#

#include "../include/registers.inc"

.globl interrupts_enable
.globl interrupts_disable

.text

interrupts_enable:
    csrs mstatus, (1<<3)        # set MIE (Machine Interrupt Enable) bit in mstatus register (bit 3)
    ret

interrupts_disable:
    csrc mstatus, (1<<3)
    ret
