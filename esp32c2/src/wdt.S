#
# ESP32-C2
#

#include "../include/registers.inc"

.globl wdt_feed
.globl wdt_disable

.equ WDT_WP_UNLOCK, 0x50D83AA1
.equ WDT_WP_LOCK,   0xFFFFFFFF

.text

wdt_feed:
      li   t0, TIMG0_WDTFEED_REG
      addi t1, t1, 1
      sw   t1, 0(t0)
      ret

wdt_disable:
      # TIMG0
      li   t0, TIMG0_WDTWPROTECT_REG
      li   t1, WDT_WP_UNLOCK
      sw   t1, (t0)
      li   t0, TIMG0_WDTCONFIG0_REG
      li   t1, 0
      sw   t1, (t0)

      # TIMG1
      #li   t0, TIMG1_WDTWPROTECT_REG
      #li   t1, WDT_WP_UNLOCK
      #sw   t1, (t0)
      #li   t0, TIMG1_WDTCONFIG0_REG
      #li   t1, 0
      #sw   t1, (t0)

      # RTC
      li   t0, RTC_CNTL_WDTWPROTECT_REG
      li   t1, WDT_WP_UNLOCK
      sw   t1, (t0)
      li   t0, RTC_CNTL_WDTCONFIG0_REG
      li   t1, 0
      sw   t1, (t0)

      # SWD - enable with auto feed
      li   t0, RTC_CNTL_SWD_WPROTECT_REG
      li   t1, WDT_WP_UNLOCK
      sw   t1, (t0)
      # RTC_CNTL_SWD_CONF_REG (reset: 0x4B00000)
      li   t0, RTC_CNTL_SWD_CONF_REG
      li   t1, ((1<<31) | 0x4B00000)
      sw   t1, (t0)

      ret