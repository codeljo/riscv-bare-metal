#
# ESP32-C3
# USB Serial/JTAG Controller CDC-ACM
#

#include "../../esp32c3/include/registers.inc"

.globl usb_cdc_read
.globl usb_cdc_write
.globl usb_cdc_write_flush

.text

# a0: returns byte read (todo)
usb_cdc_read:
    li   a0, 0
    ret

# a0: byte to send
usb_cdc_write:
    li   t0, USB_SERIAL_JTAG_EP1_REG
    sw   a0, 0(t0)
    ret

usb_cdc_write_flush:
    li   t0, USB_SERIAL_JTAG_EP1_CONF_REG
    li   t1, 1
    sw   t1, 0(t0)
    ret
