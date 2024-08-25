#
# ESP32-C6
#

#include "../include/registers.inc"

.globl wdt_feed
.globl wdt_disable

.equ WDT_WRITE_PROTECT, 0x50D83AA1
#.equ SWD_WRITE_PROTECT, 0x8F1D312A

.text

wdt_feed:
      li   t0, TIMG0_WDTFEED_REG
      addi t1, t1, 1
      sw   t1, 0(t0)
      ret

wdt_disable:
      # TIMG0
      li   t0, TIMG0_WDTWPROTECT_REG
      li   t1, WDT_WRITE_PROTECT
      sw   t1, (t0)
      li   t0, TIMG0_WDTCONFIG0_REG
      li   t1, 0
      sw   t1, (t0)

      # TIMG1
      li   t0, TIMG1_WDTWPROTECT_REG
      li   t1, WDT_WRITE_PROTECT
      sw   t1, (t0)
      li   t0, TIMG1_WDTCONFIG0_REG
      li   t1, 0
      sw   t1, (t0)

      # RWDT
      li   t0, LP_WDT_RWDT_WPROTECT_REG
      li   t1, WDT_WRITE_PROTECT
      sw   t1, (t0)
      li   t0, LP_WDT_RWDT_CONFIG0_REG
      li   t1, 0
      sw   t1, (t0)

      # SWD - enable with auto feed
      li   t0, LP_WDT_SWD_WPROTECT_REG
      li   t1, WDT_WRITE_PROTECT
      sw   t1, (t0)
      li   t0, LP_WDT_SWD_CONFIG_REG
      li   t1, ((1<<18) | 0x30000000)
      sw   t1, (t0)

      ret