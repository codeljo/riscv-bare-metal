#
# Example for use in QtRVSim (RISC-V Simulator)
# Turning the knobs will adjust the LED colors
#

#pragma qtrvsim show registers
#pragma qtrvsim show memory
#pragma qtrvsim show peripherals
#pragma qtrvsim show terminal

.globl _start

# memory mapped peripherals for dial knobs input, LED outputs
.equ SPILED_REG_BASE,          0xffffc100   # base of SPILED port region
.equ SPILED_REG_LED_LINE,      0xffffc104   # 32 bit word mapped as output
.equ SPILED_REG_LED_LINE_o,        0x0004   # Offset of the LED_LINE
.equ SPILED_REG_LED_RGB1,      0xffffc110   # RGB LED 1 color components
.equ SPILED_REG_LED_RGB1_o,        0x0010   # Offset of LED_RGB1
.equ SPILED_REG_LED_RGB2,      0xffffc114   # RGB LED 2 color components
.equ SPILED_REG_LED_RGB2_o,        0x0014   # Offset of LED_RGB2
.equ SPILED_REG_KNOBS_8BIT,    0xffffc124   # Three 8 bit knob values
.equ SPILED_REG_KNOBS_8BIT_o,      0x0024   # Offset of KNOBS_8BIT

.text

_start:
    li  t0, SPILED_REG_BASE
    li  x2, 0

loop:
	# read knobs (red, green, blue)
	lb  t1, SPILED_REG_KNOBS_8BIT_o+2(t0)
	lb  t2, SPILED_REG_KNOBS_8BIT_o+1(t0)
	lb  t3, SPILED_REG_KNOBS_8BIT_o(t0)
	
	# write to led's
	sb  t1, SPILED_REG_LED_RGB1_o+2(t0)
	sb  t2, SPILED_REG_LED_RGB1_o+1(t0)
	sb  t3, SPILED_REG_LED_RGB1_o(t0)
	
    jal zero, loop


#pragma qtrvsim tab core