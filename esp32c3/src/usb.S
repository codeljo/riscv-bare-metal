#
# ESP32-C3
# USB Serial/JTAG Controller CDC-ACM
#

#include "../include/registers.inc"

.globl usb_cdc_read
.globl usb_cdc_is_read_ready
.globl usb_cdc_write
.globl usb_cdc_is_write_ready
.globl usb_cdc_write_flush

.text

# a0: returns byte read
usb_cdc_read:
    li   t0, USB_SERIAL_JTAG_EP1_REG
    lw   a0, 0(t0)
    ret

# a0: returns 0:false 1:true
usb_cdc_is_read_ready:
    li   t0, USB_SERIAL_JTAG_EP1_CONF_REG
    lw   a0, 0(t0)
    andi a0, a0, (1<<2)
    srli a0, a0, 2
    ret

# a0: send byte
usb_cdc_write:
    li   t0, USB_SERIAL_JTAG_EP1_REG
    sw   a0, 0(t0)
    ret

# a0: returns 0:false 1:true
usb_cdc_is_write_ready:
    li   t0, USB_SERIAL_JTAG_EP1_CONF_REG
    lw   a0, 0(t0)
    andi a0, a0, (1<<1)
    srli a0, a0, 1
    ret

usb_cdc_write_flush:
    li   t0, USB_SERIAL_JTAG_EP1_CONF_REG
    li   t1, 1
    sw   t1, 0(t0)
    ret
