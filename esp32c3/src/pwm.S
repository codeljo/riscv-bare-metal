#
# ESP32-C3
# PWM (TRM 805)
#

#include "../include/registers.inc"

.globl pwm_channel_0_init
.globl pwm_channel_1_init
.globl pwm_duty_update

.text

# a0: pwm_config_t *
pwm_channel_0_init:

      ##############################################
      # save registers
      ##############################################
      addi sp, sp, -32
      sw   ra, 0(sp)
      sw   a0, 4(sp)

      ##############################################
      # a0:pin, a1:value
      # select function for pin
      # (signal 45: ledc_ls_sig_out0)
      ##############################################
      lw   a0, 4(sp)
      lw   t0, 0(a0)
      mv   a0, t0
      li   a1, 45
      call gpio_output_func_select

      ##############################################
      # enable output on pin
      ##############################################
      lw   a0, 4(sp)
      lw   t0, 0(a0)
      mv   a0, t0
      call gpio_output_enable

      ##############################################
      # enable system peripheral clock for pwm
      # SYSTEM_PERIP_CLK_EN0_REG:
      #    SYSTEM_LEDC_CLK_EN (bit 11)
      ##############################################
      li   t0, SYSTEM_PERIP_CLK_EN0_REG
      lw   t1, 0(t0)
      li   t2, (1<<11)
      or   t1, t1, t2
      sw   t1, 0(t0)

      ##############################################
      # LEDC_CONF_REG
      # select clock source
      # 1: APB_CLK; 2: RC_FAST_CLK; 3: XTAL_CLK
      ##############################################
      li   t0, LEDC_CONF_REG
      lw   a0, 4(sp)
      lw   t1, 4(a0)
      andi t1, t1, 0b11
      sw   t1, 0(t0)

      ##############################################
      # LEDC_TIMER0_CONF_REG
      ##############################################
      li   t0, LEDC_TIMER0_CONF_REG
      # divisor
      lw   a0, 4(sp)
      lw   t1, 8(a0)
      li   t2, 0x3FFFF
      and  t1, t1, t2
      slli t1, t1, 4
      # resolution
      lw   a0, 4(sp)
      lw   t2, 12(a0)
      andi t2, t2, 0xF
      or   t1, t1, t2
      # set LEDC_TIMERx_PARA_UP (bit 25)
      li   t2, (1<<25)
      or   t1, t1, t2
      sw   t1, 0(t0)

      ##############################################
      # LEDC_CH0_HPOINT_REG
      # output to HIGH when the selected timer
      # for this channel has reached this value
      # (13 bits) max: 0x1FFF
      ##############################################
      li   t0, LEDC_CH0_HPOINT_REG
      li   t1, 0
      sw   t1, 0(t0)

      ##############################################
      # LEDC_CH0_DUTY_REG
      # output to LOW when the selected timer
      # for this channel has reached the Lpoint
      # (18 bits) max: 0x3FFFF
      ##############################################
      li   t0, LEDC_CH0_DUTY_REG
      lw   a0, 4(sp)
      lw   t1, 16(a0)
      li   t2, 0x3FFFF
      and  t1, t1, t2
      sw   t1, 0(t0)

      ##############################################
      # LEDC_CH0_CONF1_REG
      ##############################################
      li   t0, LEDC_CH0_CONF1_REG
      li   t1, (1<<31) | (1<<30) | (1<<20)| (1<<10)
      sw   t1, 0(t0)

      ##############################################
      # LEDC_CH0_CONF0_REG
      # update all settings               (bit 4)
      # enable signal output on channel 0 (bit 2)
      # select timer 0                 (bits 1-0)
      ##############################################
      li   t0, LEDC_CH0_CONF0_REG
      li   t1, (1<<4) | (1<<2)
      sw   t1, 0(t0)

      ##############################################
      # restore registers
      ##############################################
      lw   ra, 0(sp)
      addi sp, sp, 32
      ret

# a0: pwm_config_t *
pwm_channel_1_init:

      ##############################################
      # save registers
      ##############################################
      addi sp, sp, -32
      sw   ra, 0(sp)
      sw   a0, 4(sp)

      ##############################################
      # a0:pin, a1:value
      # select function for pin
      # (signal 46: ledc_ls_sig_out1)
      ##############################################
      lw   a0, 4(sp)
      lw   t0, 0(a0)
      mv   a0, t0
      li   a1, 46
      call gpio_output_func_select

      ##############################################
      # enable output on pin
      ##############################################
      lw   a0, 4(sp)
      lw   t0, 0(a0)
      mv   a0, t0
      call gpio_output_enable

      ##############################################
      # enable system peripheral clock for pwm
      # SYSTEM_PERIP_CLK_EN0_REG:
      #    SYSTEM_LEDC_CLK_EN (bit 11)
      ##############################################
      li   t0, SYSTEM_PERIP_CLK_EN0_REG
      lw   t1, 0(t0)
      li   t2, (1<<11)
      or   t1, t1, t2
      sw   t1, 0(t0)

      ##############################################
      # LEDC_CONF_REG
      # select clock source
      # 1: APB_CLK; 2: RC_FAST_CLK; 3: XTAL_CLK
      ##############################################
      li   t0, LEDC_CONF_REG
      lw   a0, 4(sp)
      lw   t1, 4(a0)
      andi t1, t1, 0b11
      sw   t1, 0(t0)

      ##############################################
      # LEDC_TIMER1_CONF_REG
      ##############################################
      li   t0, LEDC_TIMER1_CONF_REG
      # divisor
      lw   a0, 4(sp)
      lw   t1, 8(a0)
      li   t2, 0x3FFFF
      and  t1, t1, t2
      slli t1, t1, 4
      # resolution
      lw   a0, 4(sp)
      lw   t2, 12(a0)
      andi t2, t2, 0xF
      or   t1, t1, t2
      # set LEDC_TIMERx_PARA_UP (bit 25)
      li   t2, (1<<25)
      or   t1, t1, t2
      sw   t1, 0(t0)

      ##############################################
      # LEDC_CH1_HPOINT_REG
      # output to HIGH when the selected timer
      # for this channel has reached this value
      # (13 bits) max: 0x1FFF
      ##############################################
      li   t0, LEDC_CH1_HPOINT_REG
      li   t1, 0
      sw   t1, 0(t0)

      ##############################################
      # LEDC_CH1_DUTY_REG
      # output to LOW when the selected timer
      # for this channel has reached the Lpoint
      # (18 bits) max: 0x3FFFF
      ##############################################
      li   t0, LEDC_CH1_DUTY_REG
      lw   a0, 4(sp)
      lw   t1, 16(a0)
      li   t2, 0x3FFFF
      and  t1, t1, t2
      sw   t1, 0(t0)

      ##############################################
      # LEDC_CH1_CONF1_REG
      ##############################################
      li   t0, LEDC_CH1_CONF1_REG
      li   t1, (1<<31) | (1<<30) | (1<<20)| (1<<10)
      sw   t1, 0(t0)

      ##############################################
      # LEDC_CH1_CONF0_REG
      # update all settings               (bit 4)
      # enable signal output on channel 1 (bit 2)
      # select timer 1                 (bits 1-0)
      ##############################################
      li   t0, LEDC_CH1_CONF0_REG
      li   t1, (1<<4) | (1<<2) | 1
      sw   t1, 0(t0)

      ##############################################
      # restore registers
      ##############################################
      lw   ra, 0(sp)
      addi sp, sp, 32
      ret

# a0: channel, a1: duty, a0: return
pwm_duty_update:
      addi sp, sp, -16
      sw   ra, 0(sp)
      sw   a0, 4(sp)
      sw   a1, 8(sp)

      li   t0, 6
      bge  a0, t0, .LDUE
      blt  a0, zero, .LDUE

      li   t0, LEDC_CH0_DUTY_REG
      lw   t1, 4(sp)
      li   t2, 0x14
      mul  t1, t1, t2
      add  t0, t0, t1
      lw   t1, 8(sp)
      li   t2, 0x3FFFF
      and  t1, t1, t2
      sw   t1, 0(t0)

      li   t0, LEDC_CH0_CONF1_REG
      lw   t1, 4(sp)
      li   t2, 0x14
      mul  t1, t1, t2
      add  t0, t0, t1 
      li   t1, (1<<31) | (1<<30) | (1<<20)| (1<<10)
      sw   t1, 0(t0)

      li   t0, LEDC_CH0_CONF0_REG
      lw   t1, 4(sp)
      li   t2, 0x14
      mul  t1, t1, t2
      add  t0, t0, t1
      lw   t1, 0(t0)
      ori  t1, t1, (1<<4)
      sw   t1, 0(t0)

      li   a0, 0
      j    .LDUS

      .LDUE:
      li   a0, -1
      .LDUS:

      lw   ra, 0(sp)
      addi sp, sp, 16
      ret