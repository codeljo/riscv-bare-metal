######################################################
# ESP32-C2
######################################################

######################################################
# Configuration and Status Registers (CSRs)
# (TRM 20)
######################################################
# Machine Information CSRs
.equ mvendorid, 0xF11
.equ marchid,   0xF12
.equ mimpid,    0xF13
.equ mhartid,   0xF14
# Machine Trap Setup CSRs
.equ mstatus,   0x300
.equ misa,      0x301
.equ mtvec,     0x305
# Machine Trap Handling CSRs
.equ mscratch,  0x340
.equ mepc,      0x341
.equ mcause,    0x342
.equ mtval,     0x343
# Physical Memory Protection (PMP) CSRs
.equ pmpcfg0,   0x3A0
.equ pmpcfg1,   0x3A1
.equ pmpcfg2,   0x3A2
.equ pmpcfg3,   0x3A3
.equ pmpaddr0,  0x3B0
.equ pmpaddr1,  0x3B1
.equ pmpaddr2,  0x3B2
.equ pmpaddr3,  0x3B3
.equ pmpaddr4,  0x3B4
.equ pmpaddr5,  0x3B5
.equ pmpaddr6,  0x3B6
.equ pmpaddr7,  0x3B7
.equ pmpaddr8,  0x3B8
.equ pmpaddr9,  0x3B9
.equ pmpaddr10, 0x3BA
.equ pmpaddr11, 0x3BB
.equ pmpaddr12, 0x3BC
.equ pmpaddr13, 0x3BD
.equ pmpaddr14, 0x3BE
.equ pmpaddr15, 0x3BF
# Trigger Module CSRs (shared with Debug Mode)
.equ tselect,   0x7A0
.equ tdata1,    0x7A1
.equ tdata2,    0x7A2
.equ tcontrol,  0x7A5
# Debug Mode CSRs
.equ dcsr,      0x7B0
.equ dpc,       0x7B1
.equ dscratch0, 0x7B2
.equ dscratch1, 0x7B3
# Performance Counter CSRs (Custom)
.equ mpcer,     0x7E0
.equ mpcmr,     0x7E1
.equ mpccr,     0x7E2
# GPIO Access CSRs (Custom)
# .equ cpu_gpio_oen, 0x803
# .equ cpu_gpio_oen, 0x804
# .equ cpu_gpio_oen, 0x805
######################################################

######################################################
# GDMA Controller (GDMA)
# (TRM 57)
######################################################
.equ GDMA_BASE,                           0x6003F000
# Interrupt Registers
.equ GDMA_INT_RAW_CH0_REG,                0x6003F000
.equ GDMA_INT_ST_CH0_REG,                 0x6003F004
.equ GDMA_INT_ENA_CH0_REG,                0x6003F008
.equ GDMA_INT_CLR_CH0_REG,                0x6003F00C
# Configuration Registers
.equ GDMA_MISC_CONF_REG,                  0x6003F044
.equ GDMA_IN_CONF0_CH0_REG,               0x6003F070
.equ GDMA_IN_CONF1_CH0_REG,               0x6003F074
.equ GDMA_IN_POP_CH0_REG,                 0x6003F07C
.equ GDMA_IN_LINK_CH0_REG,                0x6003F080
.equ GDMA_OUT_CONF0_CH0_REG,              0x6003F0D0
.equ GDMA_OUT_CONF1_CH0_REG,              0x6003F0D4
.equ GDMA_OUT_PUSH_CH0_REG,               0x6003F0DC
.equ GDMA_OUT_LINK_CH0_REG,               0x6003F0E0
# Status Registers
.equ GDMA_INFIFO_STATUS_CH0_REG,          0x6003F078
.equ GDMA_IN_STATE_CH0_REG,               0x6003F084
.equ GDMA_IN_SUC_EOF_DES_ADDR_CH0_REG,    0x6003F088
.equ GDMA_IN_ERR_EOF_DES_ADDR_CH0_REG,    0x6003F08C
.equ GDMA_IN_DSCR_CH0_REG,                0x6003F090
.equ GDMA_IN_DSCR_BF0_CH0_REG,            0x6003F094
.equ GDMA_IN_DSCR_BF1_CH0_REG,            0x6003F098
.equ GDMA_OUTFIFO_STATUS_CH0_REG,         0x6003F0D8
.equ GDMA_OUT_STATE_CH0_REG,              0x6003F0E4
.equ GDMA_OUT_EOF_DES_ADDR_CH0_REG,       0x6003F0E8
.equ GDMA_OUT_EOF_BFR_DES_ADDR_CH0_REG,   0x6003F0EC
.equ GDMA_OUT_DSCR_CH0_REG,               0x6003F0F0
.equ GDMA_OUT_DSCR_BF0_CH0_REG,           0x6003F0F4
.equ GDMA_OUT_DSCR_BF1_CH0_REG,           0x6003F0F8
# Priority Registers
.equ GDMA_IN_PRI_CH0_REG,                 0x6003F09C
.equ GDMA_OUT_PRI_CH0_REG,                0x6003F0FC
# Peripheral Select Registers
.equ GDMA_IN_PERI_SEL_CH0_REG,            0x6003F0A0
.equ GDMA_OUT_PERI_SEL_CH0_REG,           0x6003F100
# Version Register
.equ GDMA_DATE_REG,                       0x6003F048
######################################################

######################################################
# GPIO (GPIO)
# (TRM 128)
######################################################
.equ GPIO_BASE,             0x60004000
# Configuration Registers
.equ GPIO_OUT_REG,          0x60004004    # (reset: 0x00) (output value of GPIO0 - 30 output in simple GPIO output mode)
.equ GPIO_OUT_W1TS_REG,     0x60004008
.equ GPIO_OUT_W1TC_REG,     0x6000400C
.equ GPIO_ENABLE_REG,       0x60004020    # (reset: 0x00) (configures whether or not to enable the output of GPIO0 - GPIO30)
.equ GPIO_ENABLE_W1TS_REG,  0x60004024
.equ GPIO_ENABLE_W1TC_REG,  0x60004028
.equ GPIO_STRAP_REG,        0x60004038
.equ GPIO_IN_REG,           0x6000403C    # (reset: 0x00) (input value of GPIO0 - GPIO30)
.equ GPIO_STATUS_REG,       0x60004044      
.equ GPIO_STATUS_W1TS_REG,  0x60004048
.equ GPIO_STATUS_W1TC_REG,  0x6000404C
.equ GPIO_PCPU_INT_REG,     0x6000405C
.equ GPIO_STATUS_NEXT_REG,  0x6000414C
# Pin Configuration Registers
.equ GPIO_PIN0_REG,         0x60004074
.equ GPIO_PIN1_REG,         0x60004078
.equ GPIO_PIN2_REG,         0x6000407C
.equ GPIO_PIN3_REG,         0x60004080
.equ GPIO_PIN4_REG,         0x60004084
.equ GPIO_PIN5_REG,         0x60004088
.equ GPIO_PIN6_REG,         0x6000408C
.equ GPIO_PIN7_REG,         0x60004090
.equ GPIO_PIN8_REG,         0x60004094
.equ GPIO_PIN9_REG,         0x60004098
.equ GPIO_PIN10_REG,        0x6000409C
.equ GPIO_PIN11_REG,        0x600040A0
.equ GPIO_PIN12_REG,        0x600040A4
.equ GPIO_PIN13_REG,        0x600040A8
.equ GPIO_PIN14_REG,        0x600040AC
.equ GPIO_PIN15_REG,        0x600040B0
.equ GPIO_PIN16_REG,        0x600040B4
.equ GPIO_PIN17_REG,        0x600040B8
.equ GPIO_PIN18_REG,        0x600040BC
.equ GPIO_PIN19_REG,        0x600040C0
.equ GPIO_PIN20_REG,        0x600040C4
# Input Function Configuration Registers
.equ GPIO_FUNC0_IN_SEL_CFG_REG,   0x60004154
.equ GPIO_FUNC1_IN_SEL_CFG_REG,   0x60004158
.equ GPIO_FUNC2_IN_SEL_CFG_REG,   0x6000415C
.equ GPIO_FUNC3_IN_SEL_CFG_REG,   0x60004160
.equ GPIO_FUNC4_IN_SEL_CFG_REG,   0x60004164
.equ GPIO_FUNC5_IN_SEL_CFG_REG,   0x60004168
.equ GPIO_FUNC6_IN_SEL_CFG_REG,   0x6000416C
.equ GPIO_FUNC7_IN_SEL_CFG_REG,   0x60004170
.equ GPIO_FUNC8_IN_SEL_CFG_REG,   0x60004174
.equ GPIO_FUNC9_IN_SEL_CFG_REG,   0x60004178
.equ GPIO_FUNC10_IN_SEL_CFG_REG,  0x6000417C
.equ GPIO_FUNC11_IN_SEL_CFG_REG,  0x60004180
.equ GPIO_FUNC12_IN_SEL_CFG_REG,  0x60004184
.equ GPIO_FUNC13_IN_SEL_CFG_REG,  0x60004188
.equ GPIO_FUNC14_IN_SEL_CFG_REG,  0x6000418C
.equ GPIO_FUNC15_IN_SEL_CFG_REG,  0x60004190
.equ GPIO_FUNC16_IN_SEL_CFG_REG,  0x60004194
.equ GPIO_FUNC17_IN_SEL_CFG_REG,  0x60004198
.equ GPIO_FUNC18_IN_SEL_CFG_REG,  0x6000419C
.equ GPIO_FUNC19_IN_SEL_CFG_REG,  0x600041A0
.equ GPIO_FUNC20_IN_SEL_CFG_REG,  0x600041A4
.equ GPIO_FUNC21_IN_SEL_CFG_REG,  0x600041A8
.equ GPIO_FUNC22_IN_SEL_CFG_REG,  0x600041AC
.equ GPIO_FUNC23_IN_SEL_CFG_REG,  0x600041B0
.equ GPIO_FUNC24_IN_SEL_CFG_REG,  0x600041B4
.equ GPIO_FUNC25_IN_SEL_CFG_REG,  0x600041B8
.equ GPIO_FUNC26_IN_SEL_CFG_REG,  0x600041BC
.equ GPIO_FUNC27_IN_SEL_CFG_REG,  0x600041C0
.equ GPIO_FUNC28_IN_SEL_CFG_REG,  0x600041C4
.equ GPIO_FUNC29_IN_SEL_CFG_REG,  0x600041C8
.equ GPIO_FUNC30_IN_SEL_CFG_REG,  0x600041CC
.equ GPIO_FUNC31_IN_SEL_CFG_REG,  0x600041D0
.equ GPIO_FUNC32_IN_SEL_CFG_REG,  0x600041D4
.equ GPIO_FUNC33_IN_SEL_CFG_REG,  0x600041D8
.equ GPIO_FUNC34_IN_SEL_CFG_REG,  0x600041DC
.equ GPIO_FUNC35_IN_SEL_CFG_REG,  0x600041E0
.equ GPIO_FUNC36_IN_SEL_CFG_REG,  0x600041E4
.equ GPIO_FUNC37_IN_SEL_CFG_REG,  0x600041E8
.equ GPIO_FUNC38_IN_SEL_CFG_REG,  0x600041EC
.equ GPIO_FUNC39_IN_SEL_CFG_REG,  0x600041F0
.equ GPIO_FUNC40_IN_SEL_CFG_REG,  0x600041F4
.equ GPIO_FUNC41_IN_SEL_CFG_REG,  0x600041F8
.equ GPIO_FUNC42_IN_SEL_CFG_REG,  0x600041FC
.equ GPIO_FUNC43_IN_SEL_CFG_REG,  0x60004200
.equ GPIO_FUNC44_IN_SEL_CFG_REG,  0x60004204
.equ GPIO_FUNC45_IN_SEL_CFG_REG,  0x60004208
.equ GPIO_FUNC46_IN_SEL_CFG_REG,  0x6000420C
.equ GPIO_FUNC47_IN_SEL_CFG_REG,  0x60004210
.equ GPIO_FUNC48_IN_SEL_CFG_REG,  0x60004214
.equ GPIO_FUNC49_IN_SEL_CFG_REG,  0x60004218
.equ GPIO_FUNC50_IN_SEL_CFG_REG,  0x6000421C
.equ GPIO_FUNC51_IN_SEL_CFG_REG,  0x60004220
.equ GPIO_FUNC52_IN_SEL_CFG_REG,  0x60004224
.equ GPIO_FUNC53_IN_SEL_CFG_REG,  0x60004228
.equ GPIO_FUNC54_IN_SEL_CFG_REG,  0x6000422C
.equ GPIO_FUNC55_IN_SEL_CFG_REG,  0x60004230
.equ GPIO_FUNC56_IN_SEL_CFG_REG,  0x60004234
.equ GPIO_FUNC57_IN_SEL_CFG_REG,  0x60004238
.equ GPIO_FUNC58_IN_SEL_CFG_REG,  0x6000423C
.equ GPIO_FUNC59_IN_SEL_CFG_REG,  0x60004240
.equ GPIO_FUNC60_IN_SEL_CFG_REG,  0x60004244
.equ GPIO_FUNC61_IN_SEL_CFG_REG,  0x60004248
.equ GPIO_FUNC62_IN_SEL_CFG_REG,  0x6000424C
.equ GPIO_FUNC63_IN_SEL_CFG_REG,  0x60004250
.equ GPIO_FUNC64_IN_SEL_CFG_REG,  0x60004254
.equ GPIO_FUNC65_IN_SEL_CFG_REG,  0x60004258
.equ GPIO_FUNC66_IN_SEL_CFG_REG,  0x6000425C
.equ GPIO_FUNC67_IN_SEL_CFG_REG,  0x60004260
.equ GPIO_FUNC68_IN_SEL_CFG_REG,  0x60004264
.equ GPIO_FUNC69_IN_SEL_CFG_REG,  0x60004268
.equ GPIO_FUNC70_IN_SEL_CFG_REG,  0x6000426C
.equ GPIO_FUNC71_IN_SEL_CFG_REG,  0x60004270
.equ GPIO_FUNC72_IN_SEL_CFG_REG,  0x60004274
.equ GPIO_FUNC73_IN_SEL_CFG_REG,  0x60004278
.equ GPIO_FUNC74_IN_SEL_CFG_REG,  0x6000427C
.equ GPIO_FUNC75_IN_SEL_CFG_REG,  0x60004280
.equ GPIO_FUNC76_IN_SEL_CFG_REG,  0x60004284
.equ GPIO_FUNC77_IN_SEL_CFG_REG,  0x60004288
.equ GPIO_FUNC78_IN_SEL_CFG_REG,  0x6000428C
.equ GPIO_FUNC79_IN_SEL_CFG_REG,  0x60004290
.equ GPIO_FUNC80_IN_SEL_CFG_REG,  0x60004294
.equ GPIO_FUNC81_IN_SEL_CFG_REG,  0x60004298
.equ GPIO_FUNC82_IN_SEL_CFG_REG,  0x6000429C
.equ GPIO_FUNC83_IN_SEL_CFG_REG,  0x600042A0
.equ GPIO_FUNC84_IN_SEL_CFG_REG,  0x600042A4
.equ GPIO_FUNC85_IN_SEL_CFG_REG,  0x600042A8
.equ GPIO_FUNC86_IN_SEL_CFG_REG,  0x600042AC
.equ GPIO_FUNC87_IN_SEL_CFG_REG,  0x600042B0
.equ GPIO_FUNC88_IN_SEL_CFG_REG,  0x600042B4
.equ GPIO_FUNC89_IN_SEL_CFG_REG,  0x600042B8
.equ GPIO_FUNC90_IN_SEL_CFG_REG,  0x600042BC
.equ GPIO_FUNC91_IN_SEL_CFG_REG,  0x600042C0
.equ GPIO_FUNC92_IN_SEL_CFG_REG,  0x600042C4
.equ GPIO_FUNC93_IN_SEL_CFG_REG,  0x600042C8
.equ GPIO_FUNC94_IN_SEL_CFG_REG,  0x600042CC
.equ GPIO_FUNC95_IN_SEL_CFG_REG,  0x600042D0
.equ GPIO_FUNC96_IN_SEL_CFG_REG,  0x600042D4
.equ GPIO_FUNC97_IN_SEL_CFG_REG,  0x600042D8
.equ GPIO_FUNC98_IN_SEL_CFG_REG,  0x600042DC
.equ GPIO_FUNC99_IN_SEL_CFG_REG,  0x600042E0
.equ GPIO_FUNC100_IN_SEL_CFG_REG, 0x600042E4
.equ GPIO_FUNC101_IN_SEL_CFG_REG, 0x600042E8
.equ GPIO_FUNC102_IN_SEL_CFG_REG, 0x600042EC
.equ GPIO_FUNC103_IN_SEL_CFG_REG, 0x600042F0
.equ GPIO_FUNC104_IN_SEL_CFG_REG, 0x600042F4
.equ GPIO_FUNC105_IN_SEL_CFG_REG, 0x600042F8
.equ GPIO_FUNC106_IN_SEL_CFG_REG, 0x600042FC
.equ GPIO_FUNC107_IN_SEL_CFG_REG, 0x60004300
.equ GPIO_FUNC108_IN_SEL_CFG_REG, 0x60004304
.equ GPIO_FUNC109_IN_SEL_CFG_REG, 0x60004308
.equ GPIO_FUNC110_IN_SEL_CFG_REG, 0x6000430C
.equ GPIO_FUNC111_IN_SEL_CFG_REG, 0x60004310
.equ GPIO_FUNC112_IN_SEL_CFG_REG, 0x60004314
.equ GPIO_FUNC113_IN_SEL_CFG_REG, 0x60004318
.equ GPIO_FUNC114_IN_SEL_CFG_REG, 0x6000431C
.equ GPIO_FUNC115_IN_SEL_CFG_REG, 0x60004320
.equ GPIO_FUNC116_IN_SEL_CFG_REG, 0x60004324
.equ GPIO_FUNC117_IN_SEL_CFG_REG, 0x60004328
.equ GPIO_FUNC118_IN_SEL_CFG_REG, 0x6000432C
.equ GPIO_FUNC119_IN_SEL_CFG_REG, 0x60004330
.equ GPIO_FUNC120_IN_SEL_CFG_REG, 0x60004334
.equ GPIO_FUNC121_IN_SEL_CFG_REG, 0x60004338
.equ GPIO_FUNC122_IN_SEL_CFG_REG, 0x6000433C
.equ GPIO_FUNC123_IN_SEL_CFG_REG, 0x60004340
.equ GPIO_FUNC124_IN_SEL_CFG_REG, 0x60004344
.equ GPIO_FUNC125_IN_SEL_CFG_REG, 0x60004348
.equ GPIO_FUNC126_IN_SEL_CFG_REG, 0x6000434C
.equ GPIO_FUNC127_IN_SEL_CFG_REG, 0x60004350
# Output Function Configuration Registers
.equ GPIO_FUNC0_OUT_SEL_CFG_REG,  0x60004554
.equ GPIO_FUNC1_OUT_SEL_CFG_REG,  0x60004558
.equ GPIO_FUNC2_OUT_SEL_CFG_REG,  0x6000455C
.equ GPIO_FUNC3_OUT_SEL_CFG_REG,  0x60004560
.equ GPIO_FUNC4_OUT_SEL_CFG_REG,  0x60004564
.equ GPIO_FUNC5_OUT_SEL_CFG_REG,  0x60004568
.equ GPIO_FUNC6_OUT_SEL_CFG_REG,  0x6000456C
.equ GPIO_FUNC7_OUT_SEL_CFG_REG,  0x60004570
.equ GPIO_FUNC8_OUT_SEL_CFG_REG,  0x60004574
.equ GPIO_FUNC9_OUT_SEL_CFG_REG,  0x60004578
.equ GPIO_FUNC10_OUT_SEL_CFG_REG, 0x6000457C
.equ GPIO_FUNC11_OUT_SEL_CFG_REG, 0x60004580
.equ GPIO_FUNC12_OUT_SEL_CFG_REG, 0x60004584
.equ GPIO_FUNC13_OUT_SEL_CFG_REG, 0x60004588
.equ GPIO_FUNC14_OUT_SEL_CFG_REG, 0x6000458C
.equ GPIO_FUNC15_OUT_SEL_CFG_REG, 0x60004590
.equ GPIO_FUNC16_OUT_SEL_CFG_REG, 0x60004594
.equ GPIO_FUNC17_OUT_SEL_CFG_REG, 0x60004598
.equ GPIO_FUNC18_OUT_SEL_CFG_REG, 0x6000459C
.equ GPIO_FUNC19_OUT_SEL_CFG_REG, 0x600045A0
.equ GPIO_FUNC20_OUT_SEL_CFG_REG, 0x600045A4
# Version Register
.equ GPIO_DATE_REG,               0x600046FC
# Clock Gate Register
.equ GPIO_CLOCK_GATE_REG,         0x6000462C
######################################################

######################################################
# IO MUX (IO MUX)
# (TRM 130)
######################################################
# Configuration Registers
.equ IO_MUX_BASE,                 0x60009000
.equ IO_MUX_PIN_CTRL_REG,         0x60009000
.equ IO_MUX_GPIO0_REG,            0x60009004
.equ IO_MUX_GPIO1_REG,            0x60009008
.equ IO_MUX_GPIO2_REG,            0x6000900C
.equ IO_MUX_GPIO3_REG,            0x60009010
.equ IO_MUX_GPIO4_REG,            0x60009014
.equ IO_MUX_GPIO5_REG,            0x60009018
.equ IO_MUX_GPIO6_REG,            0x6000901C
.equ IO_MUX_GPIO7_REG,            0x60009020
.equ IO_MUX_GPIO8_REG,            0x60009024
.equ IO_MUX_GPIO9_REG,            0x60009028
.equ IO_MUX_GPIO10_REG,           0x6000902C
.equ IO_MUX_GPIO11_REG,           0x60009030
.equ IO_MUX_GPIO12_REG,           0x60009034
.equ IO_MUX_GPIO13_REG,           0x60009038
.equ IO_MUX_GPIO14_REG,           0x6000903C
.equ IO_MUX_GPIO15_REG,           0x60009040
.equ IO_MUX_GPIO16_REG,           0x60009044
.equ IO_MUX_GPIO17_REG,           0x60009048
.equ IO_MUX_GPIO18_REG,           0x6000904C
.equ IO_MUX_GPIO19_REG,           0x60009050
.equ IO_MUX_GPIO20_REG,           0x60009054
# Version Register
.equ IO_MUX_DATE_REG,             0x600090FC
######################################################

######################################################
# Interrupt Matrix (INTERRUPT)
# (TRM 157)
######################################################
.equ INTERRUPT_BASE,                                0x600C2000
# Interrupt Source Mapping Registers
.equ INTERRUPT_CORE0_GPIO_INTERRUPT_PRO_MAP_REG,    0x600C2034
.equ INTERRUPT_CORE0_SPI_INTR_1_MAP_REG,            0x600C2040
.equ INTERRUPT_CORE0_UART_INTR_MAP_REG,             0x600C2044
.equ INTERRUPT_CORE0_UART1_INTR_MAP_REG,            0x600C2048
.equ INTERRUPT_CORE0_LEDC_INT_MAP_REG,              0x600C204C
.equ INTERRUPT_CORE0_EFUSE_INT_MAP_REG,             0x600C2050
.equ INTERRUPT_CORE0_RTC_CORE_INTR_MAP_REG,         0x600C2054
.equ INTERRUPT_CORE0_I2C_EXT0_INTR_MAP_REG,         0x600C2058
.equ INTERRUPT_CORE0_TG_T0_INT_MAP_REG,             0x600C205C
.equ INTERRUPT_CORE0_TG_WDT_INT_MAP_REG,            0x600C2060
.equ INTERRUPT_CORE0_SYSTIMER_TARGET0_INT_MAP_REG,  0x600C2068
.equ INTERRUPT_CORE0_SYSTIMER_TARGET1_INT_MAP_REG,  0x600C206C
.equ INTERRUPT_CORE0_SYSTIMER_TARGET2_INT_MAP_REG,  0x600C2070
.equ INTERRUPT_CORE0_APB_ADC_INT_MAP_REG,           0x600C2080
.equ INTERRUPT_CORE0_DMA_CH0_INT_MAP_REG,           0x600C2084
.equ INTERRUPT_CORE0_SHA_INT_MAP_REG,               0x600C2088
.equ INTERRUPT_CORE0_ECC_INT_MAP_REG,               0x600C208C
.equ INTERRUPT_CORE0_CPU_INTR_FROM_CPU_0_MAP_REG,   0x600C2090
.equ INTERRUPT_CORE0_CPU_INTR_FROM_CPU_1_MAP_REG,   0x600C2094
.equ INTERRUPT_CORE0_CPU_INTR_FROM_CPU_2_MAP_REG,   0x600C2098
.equ INTERRUPT_CORE0_CPU_INTR_FROM_CPU_3_MAP_REG,   0x600C209C
.equ INTERRUPT_CORE0_ASSIST_DEBUG_INTR_MAP_REG,     0x600C20A0
.equ INTERRUPT_CORE0_SIZE_INTR_MAP_REG,             0x600C2070
# Interrupt Source Status Registers
.equ INTERRUPT_CORE0_INTR_STATUS_0_REG,             0x600C20AC
.equ INTERRUPT_CORE0_INTR_STATUS_1_REG,             0x600C20B0
# Clock Register
.equ INTERRUPT_CORE0_CLOCK_GATE_REG,                0x600C20B4
# CPU Interrupt Registers
.equ INTERRUPT_CORE0_CPU_INT_ENABLE_REG,            0x600C20B8
.equ INTERRUPT_CORE0_CPU_INT_TYPE_REG,              0x600C20BC
.equ INTERRUPT_CORE0_CPU_INT_CLEAR_REG,             0x600C20C0
.equ INTERRUPT_CORE0_CPU_INT_EIP_STATUS_REG,        0x600C20C4
.equ INTERRUPT_CORE0_CPU_INT_PRI_1_REG,             0x600C20CC
.equ INTERRUPT_CORE0_CPU_INT_PRI_2_REG,             0x600C20D0
.equ INTERRUPT_CORE0_CPU_INT_PRI_3_REG,             0x600C20D4
.equ INTERRUPT_CORE0_CPU_INT_PRI_4_REG,             0x600C20D8
.equ INTERRUPT_CORE0_CPU_INT_PRI_5_REG,             0x600C20DC
.equ INTERRUPT_CORE0_CPU_INT_PRI_6_REG,             0x600C20E0
.equ INTERRUPT_CORE0_CPU_INT_PRI_7_REG,             0x600C20E4
.equ INTERRUPT_CORE0_CPU_INT_PRI_8_REG,             0x600C20E8
.equ INTERRUPT_CORE0_CPU_INT_PRI_9_REG,             0x600C20EC
.equ INTERRUPT_CORE0_CPU_INT_PRI_10_REG,            0x600C20F0
.equ INTERRUPT_CORE0_CPU_INT_PRI_11_REG,            0x600C20F4
.equ INTERRUPT_CORE0_CPU_INT_PRI_12_REG,            0x600C20F8
.equ INTERRUPT_CORE0_CPU_INT_PRI_13_REG,            0x600C20FC
.equ INTERRUPT_CORE0_CPU_INT_PRI_14_REG,            0x600C2100
.equ INTERRUPT_CORE0_CPU_INT_PRI_15_REG,            0x600C2104
.equ INTERRUPT_CORE0_CPU_INT_PRI_16_REG,            0x600C2108
.equ INTERRUPT_CORE0_CPU_INT_PRI_17_REG,            0x600C210C
.equ INTERRUPT_CORE0_CPU_INT_PRI_18_REG,            0x600C2110
.equ INTERRUPT_CORE0_CPU_INT_PRI_19_REG,            0x600C2114
.equ INTERRUPT_CORE0_CPU_INT_PRI_20_REG,            0x600C2118
.equ INTERRUPT_CORE0_CPU_INT_PRI_21_REG,            0x600C211C
.equ INTERRUPT_CORE0_CPU_INT_PRI_22_REG,            0x600C2120
.equ INTERRUPT_CORE0_CPU_INT_PRI_23_REG,            0x600C2124
.equ INTERRUPT_CORE0_CPU_INT_PRI_24_REG,            0x600C2128
.equ INTERRUPT_CORE0_CPU_INT_PRI_25_REG,            0x600C212C
.equ INTERRUPT_CORE0_CPU_INT_PRI_26_REG,            0x600C2130
.equ INTERRUPT_CORE0_CPU_INT_PRI_27_REG,            0x600C2134
.equ INTERRUPT_CORE0_CPU_INT_PRI_28_REG,            0x600C2138
.equ INTERRUPT_CORE0_CPU_INT_PRI_29_REG,            0x600C213C
.equ INTERRUPT_CORE0_CPU_INT_PRI_30_REG,            0x600C2140
.equ INTERRUPT_CORE0_CPU_INT_PRI_31_REG,            0x600C2144
.equ INTERRUPT_CORE0_CPU_INT_THRESH_REG,            0x600C2148
# Version Register
.equ INTERRUPT_CORE0_INTERRUPT_DATE_REG,            0x600C27FC
######################################################

######################################################
# Low-power Management Registers
# (TRM 175)
######################################################
.equ LOW_POWER_MANAGEMENT_BASE,      0x60008000
# Control / Configuration Registers
.equ RTC_CNTL_OPTIONS0_REG,          0x60008000
.equ RTC_CNTL_SLP_TIMER0_REG,        0x60008004
.equ RTC_CNTL_SLP_TIMER1_REG,        0x60008008
.equ RTC_CNTL_TIME_UPDATE_REG,       0x6000800C
.equ RTC_CNTL_TIME_LOW0_REG,         0x60008010
.equ RTC_CNTL_TIME_HIGH0_REG,        0x60008014
.equ RTC_CNTL_STATE0_REG,            0x60008018
.equ RTC_CNTL_TIMER1_REG,            0x6000801C
.equ RTC_CNTL_TIMER2_REG,            0x60008020
.equ RTC_CNTL_ANA_CONF_REG,          0x6000802C
.equ RTC_CNTL_WAKEUP_STATE_REG,      0x60008034
.equ RTC_CNTL_STORE0_REG,            0x60008048
.equ RTC_CNTL_STORE1_REG,            0x6000804C
.equ RTC_CNTL_STORE2_REG,            0x60008050
.equ RTC_CNTL_STORE3_REG,            0x60008054
.equ RTC_CNTL_EXT_WAKEUP_CONF_REG,   0x6000805C
.equ RTC_CNTL_SLP_REJECT_CONF_REG,   0x60008060
.equ RTC_CNTL_CLK_CONF_REG,          0x60008068
.equ RTC_CNTL_REG,                   0x60008074
.equ RTC_CNTL_PWC_REG,               0x60008078
.equ RTC_CNTL_DIG_PWC_REG,           0x6000807C
.equ RTC_CNTL_DIG_ISO_REG,           0x60008080
.equ RTC_CNTL_WDTCONFIG0_REG,        0x60008084
.equ RTC_CNTL_WDTCONFIG1_REG,        0x60008088
.equ RTC_CNTL_WDTCONFIG2_REG,        0x6000808C
.equ RTC_CNTL_WDTCONFIG3_REG,        0x60008090
.equ RTC_CNTL_WDTCONFIG4_REG,        0x60008094
.equ RTC_CNTL_WDTFEED_REG,           0x60008098
.equ RTC_CNTL_WDTWPROTECT_REG,       0x6000809C
.equ RTC_CNTL_SWD_CONF_REG,          0x600080A0
.equ RTC_CNTL_SWD_WPROTECT_REG,      0x600080A4
.equ RTC_CNTL_SW_CPU_STALL_REG,      0x600080A8
.equ RTC_CNTL_STORE4_REG,            0x600080AC
.equ RTC_CNTL_STORE5_REG,            0x600080B0
.equ RTC_CNTL_STORE6_REG,            0x600080B4
.equ RTC_CNTL_STORE7_REG,            0x600080B8
.equ RTC_CNTL_PAD_HOLD_REG,          0x600080C4
.equ RTC_CNTL_DIG_PAD_HOLD_REG,      0x600080C8
.equ RTC_CNTL_BROWN_OUT_REG,         0x600080CC
.equ RTC_CNTL_TIME_LOW1_REG,         0x600080D0
.equ RTC_CNTL_TIME_HIGH1_REG,        0x600080D4
.equ RTC_CNTL_USB_CONF_REG,          0x600080D8
.equ RTC_CNTL_SLP_REJECT_CAUSE_REG,  0x600080DC
.equ RTC_CNTL_OPTION1_REG,           0x600080E0
.equ RTC_CNTL_SLP_WAKEUP_CAUSE_REG,  0x600080E4
.equ RTC_CNTL_GPIO_WAKEUP_REG,       0x600080FC
.equ RTC_CNTL_SENSOR_CTRL_REG,       0x60008108
.equ RTC_CNTL_FIB_SEL_REG,           0x600080F8
# Status Registers
.equ RTC_CNTL_RESET_STATE_REG,       0x60008030
.equ RTC_CNTL_LOW_POWER_ST_REG,      0x600080BC
# Interrupt Registers
.equ RTC_CNTL_INT_ENA_RTC_REG,       0x60008038
.equ RTC_CNTL_INT_RAW_RTC_REG,       0x6000803C
.equ RTC_CNTL_INT_ST_RTC_REG,        0x60008040
.equ RTC_CNTL_INT_CLR_RTC_REG,       0x60008044
.equ RTC_CNTL_INT_ENA_RTC_W1TS_REG,  0x600080EC
.equ RTC_CNTL_INT_ENA_RTC_W1TC_REG,  0x600080F0
######################################################

######################################################
# System Timer (SYSTIMER)
# (TRM 213)
######################################################
.equ SYSTIMER_BASE,               0x60023000
# Clock Control Register
.equ SYSTIMER_CONF_REG,           0x60023000
# UNIT0 Control and Configuration Registers
.equ SYSTIMER_UNIT0_OP_REG,       0x60023004
.equ SYSTIMER_UNIT0_LOAD_HI_REG,  0x6002300C
.equ SYSTIMER_UNIT0_LOAD_LO_REG,  0x60023010
.equ SYSTIMER_UNIT0_VALUE_HI_REG, 0x60023040
.equ SYSTIMER_UNIT0_VALUE_LO_REG, 0x60023044
.equ SYSTIMER_UNIT0_LOAD_REG,     0x6002305C
# UNIT1 Control and Configuration Registers
.equ SYSTIMER_UNIT1_OP_REG,       0x60023008
.equ SYSTIMER_UNIT1_LOAD_HI_REG,  0x60023014
.equ SYSTIMER_UNIT1_LOAD_LO_REG,  0x60023018
.equ SYSTIMER_UNIT1_VALUE_HI_REG, 0x60023048
.equ SYSTIMER_UNIT1_VALUE_LO_REG, 0x6002304C
.equ SYSTIMER_UNIT1_LOAD_REG,     0x60023060
# Comparator0 Control and Configuration Registers
.equ SYSTIMER_TARGET0_HI_REG,     0x6002301C
.equ SYSTIMER_TARGET0_LO_REG,     0x60023020
.equ SYSTIMER_TARGET0_CONF_REG,   0x60023034
.equ SYSTIMER_COMP0_LOAD_REG,     0x60023050
# Comparator1 Control and Configuration Registers
.equ SYSTIMER_TARGET1_HI_REG,     0x60023024
.equ SYSTIMER_TARGET1_LO_REG,     0x60023028
.equ SYSTIMER_TARGET1_CONF_REG,   0x60023038
.equ SYSTIMER_COMP1_LOAD_REG,     0x60023054
# Comparator2 Control and Configuration Registers
.equ SYSTIMER_TARGET2_HI_REG,     0x6002302C
.equ SYSTIMER_TARGET2_LO_REG,     0x60023030
.equ SYSTIMER_TARGET2_CONF_REG,   0x6002303C
.equ SYSTIMER_COMP2_LOAD_REG,     0x60023058
# Interrupt Registers
.equ SYSTIMER_INT_ENA_REG,        0x60023064
.equ SYSTIMER_INT_RAW_REG,        0x60023068
.equ SYSTIMER_INT_CLR_REG,        0x6002306C
.equ SYSTIMER_INT_ST_REG,         0x60023070
# Version Registers
.equ SYSTIMER_DATE_REG,           0x600230FC
######################################################

######################################################
# Timer Group (TIMG)
# (TRM 233) (timer group 0)
# (note: inserted a 0 to the register names)
######################################################
.equ TIMG0_BASE,             0x6001F000
# T0 control and configuration registers
.equ TIMG0_T0CONFIG_REG,     0x6001F000
.equ TIMG0_T0LO_REG,         0x6001F004
.equ TIMG0_T0HI_REG,         0x6001F008
.equ TIMG0_T0UPDATE_REG,     0x6001F00C
.equ TIMG0_T0ALARMLO_REG,    0x6001F010
.equ TIMG0_T0ALARMHI_REG,    0x6001F014
.equ TIMG0_T0LOADLO_REG,     0x6001F018
.equ TIMG0_T0LOADHI_REG,     0x6001F01C
.equ TIMG0_T0LOAD_REG,       0x6001F020
# WDT control and configuration registers
.equ TIMG0_WDTCONFIG0_REG,   0x6001F048
.equ TIMG0_WDTCONFIG1_REG,   0x6001F04C
.equ TIMG0_WDTCONFIG2_REG,   0x6001F050
.equ TIMG0_WDTCONFIG3_REG,   0x6001F054
.equ TIMG0_WDTCONFIG4_REG,   0x6001F058
.equ TIMG0_WDTCONFIG5_REG,   0x6001F05C
.equ TIMG0_WDTFEED_REG,      0x6001F060
.equ TIMG0_WDTWPROTECT_REG,  0x6001F064
# RTC frequency calculation control and configuration registers
.equ TIMG0_RTCCALICFG_REG,   0x6001F068
.equ TIMG0_RTCCALICFG1_REG,  0x6001F06C
.equ TIMG0_RTCCALICFG2_REG,  0x6001F080
# Interrupt registers
.equ TIMG0_INT_ENA_TIMERS_REG, 0x6001F070
.equ TIMG0_INT_RAW_TIMERS_REG, 0x6001F074
.equ TIMG0_INT_ST_TIMERS_REG,  0x6001F078
.equ TIMG0_INT_CLR_TIMERS_REG, 0x6001F07C
# Version register
.equ TIMG0_NTIMERS_DATE_REG,   0x6001F0F8
# Clock configuration registers
.equ TIMG0_REGCLK_REG,         0x6001F0FC
######################################################

######################################################
# System Registers (SYSREG)
# (TRM 254) (TODO: base address for 3 SYSCON registers)
######################################################
.equ SYSTEM_BASE,                        0x600C0000
# Peripheral Clock Control Registers
.equ SYSTEM_CPU_PERI_CLK_EN_REG,         0x600C0000
.equ SYSTEM_CPU_PERI_RST_EN_REG,         0x600C0004
.equ SYSTEM_PERIP_CLK_EN0_REG,           0x600C0010
.equ SYSTEM_PERIP_CLK_EN1_REG,           0x600C0014
.equ SYSTEM_PERIP_RST_EN0_REG,           0x600C0018
.equ SYSTEM_PERIP_RST_EN1_REG,           0x600C001C
.equ SYSTEM_GDMA_CTRL_REG,               0x600C003C
.equ SYSTEM_CACHE_CONTROL_REG,           0x600C0040
#  Clock Configuration Registers
.equ SYSTEM_CPU_PER_CONF_REG,            0x600C0008
.equ SYSTEM_SYSCLK_CONF_REG,             0x600C0058
# CPU Interrupt Control Registers
.equ SYSTEM_CPU_INTR_FROM_CPU_0_REG,     0x600C0028
.equ SYSTEM_CPU_INTR_FROM_CPU_1_REG,     0x600C002C
.equ SYSTEM_CPU_INTR_FROM_CPU_2_REG,     0x600C0030
.equ SYSTEM_CPU_INTR_FROM_CPU_3_REG,     0x600C0034
# System and Memory Control Registers
.equ SYSTEM_EXTERNAL_DEVICE_ENCRYPT_DECRYPT_CONTROL_REG, 0x600C0044
# Clock Gate Control Register
.equ SYSTEM_CLOCK_GATE_REG,              0x600C0054
# Date Register
.equ SYSTEM_DATE_REG,                    0x600C0FFc

# The addresses below are relative to the base address of apb control
# Is the base address SYSCON ?: 0x60026000
#.equ SYSCON_CLKGATE_FORCE_ON_REG,      0x00A4
#.equ SYSCON_MEM_POWER_DOWN_REG,        0x00A8
#.equ SYSCON_MEM_POWER_UP_REG,          0x00AC
######################################################

######################################################
# Debug Assistant (ASSIST_DEBUG)
# (TRM 266)
######################################################
.equ ASSIST_DEBUG_BASE,                          0x600CE000
# Monitor configuration registers
.equ ASSIST_DEBUG_CORE_0_SP_MONITOR_EN_REG,      0x600CE000
.equ ASSIST_DEBUG_CORE_0_SP_MIN_REG,             0x600CE010
.equ ASSIST_DEBUG_CORE_0_SP_MAX_REG,             0x600CE014
.equ ASSIST_DEBUG_CORE_0_SP_PC_REG,              0x600CE018
# Interrupt configuration registers
.equ ASSIST_DEBUG_CORE_0_INTR_RAW_REG,           0x600CE004
.equ ASSIST_DEBUG_CORE_0_INTR_ENA_REG,           0x600CE008
.equ ASSIST_DEBUG_CORE_0_INTR_CLR_REG,           0x600CE00C
# PC logging configuration register
.equ ASSIST_DEBUG_CORE_0_RCD_EN_REG,             0x600CE01C
# PC logging status registers
.equ ASSIST_DEBUG_CORE_0_RCD_PDEBUGPC_REG,       0x600CE020
.equ ASSIST_DEBUG_CORE_0_RCD_PDEBUGSP_REG,       0x600CE024
# CPU Status Registers
.equ ASSIST_DEBUG_CORE_0_LASTPC_BEFORE_EXCEPTION_REG, 0x600CE028
.equ ASSIST_DEBUG_CORE_0_DEBUG_MODE_REG,         0x600CE02C
# Clock gate register
.equ ASSIST_DEBUG_CLOCK_GATE_REG,                0x600CE030
# Version register
.equ ASSIST_DEBUG_DATE_REG,                      0x600CE1FC
######################################################

######################################################
# ECC Hardware Accelerator (ECC)
# (TRM 279)
######################################################
.equ ECC_BASE,                         0x6003E000
# Interrupt registers
.equ ECC_MULT_INT_RAW_REG,             0x6003E00C
.equ ECC_MULT_INT_ST_REG,              0x6003E010
.equ ECC_MULT_INT_ENA_REG,             0x6003E014
.equ ECC_MULT_INT_CLR_REG,             0x6003E018
# Configuration register
.equ ECC_MULT_CONF_REG,                0x6003E01C
# Version register
.equ ECC_MULT_DATE_REG,                0x6003E0FC
######################################################

######################################################
# SHA Accelerator (SHA)
# (TRM 287)
######################################################
.equ SHA_BASE,                 0x6003B000
# Control/Status registers
.equ SHA_CONTINUE_REG,         0x6003B014
.equ SHA_BUSY_REG,             0x6003B018
.equ SHA_DMA_START_REG,        0x6003B01C
.equ SHA_START_REG,            0x6003B010
.equ SHA_DMA_CONTINUE_REG,     0x6003B020
.equ SHA_INT_CLEAR_REG,        0x6003B024
.equ SHA_INT_ENA_REG,          0x6003B028
# Versoin Register
.equ SHA_DATE_REG,             0x6003B02C
# Configuration Registers
.equ SHA_MODE_REG,             0x6003B000
# Data Registers
.equ SHA_DMA_BLOCK_NUM_REG,    0x6003B00C
.equ SHA_H_0_REG,              0x6003B040
.equ SHA_H_1_REG,              0x6003B044
.equ SHA_H_2_REG,              0x6003B048
.equ SHA_H_3_REG,              0x6003B04C
.equ SHA_H_4_REG,              0x6003B050
.equ SHA_H_5_REG,              0x6003B054
.equ SHA_H_6_REG,              0x6003B058
.equ SHA_H_7_REG,              0x6003B05C
.equ SHA_M_0_REG,              0x6003B080
.equ SHA_M_1_REG,              0x6003B084
.equ SHA_M_2_REG,              0x6003B088
.equ SHA_M_3_REG,              0x6003B08C
.equ SHA_M_4_REG,              0x6003B090
.equ SHA_M_5_REG,              0x6003B094
.equ SHA_M_6_REG,              0x6003B098
.equ SHA_M_7_REG,              0x6003B09C
.equ SHA_M_8_REG,              0x6003B0A0
.equ SHA_M_9_REG,              0x6003B0A4
.equ SHA_M_10_REG,             0x6003B0A8
.equ SHA_M_11_REG,             0x6003B0AC
.equ SHA_M_12_REG,             0x6003B0B0
.equ SHA_M_13_REG,             0x6003B0B4
.equ SHA_M_14_REG,             0x6003B0B8
.equ SHA_M_15_REG,             0x6003B0BC
######################################################

######################################################
# Random Number Generator (RNG)
# (TRM 302)
######################################################
.equ RNG_DATA_REG, 0x600260B0
######################################################

######################################################
# UART Controller (UART)
# (TRM 321)
######################################################
.equ UART0_BASE,               0x60000000
.equ UART1_BASE,               0x60010000

# UART0
# FIFO Configuration
.equ UART0_FIFO_REG,           0x60000000
.equ UART0_MEM_CONF_REG,       0x60000060
# UART Interrupt Register
.equ UART0_INT_RAW_REG,        0x60000004
.equ UART0_INT_ST_REG,         0x60000008
.equ UART0_INT_ENA_REG,        0x6000000C
.equ UART0_INT_CLR_REG,        0x60000010
# Configuration Register
.equ UART0_CLKDIV_REG,         0x60000014
.equ UART0_RX_FILT_REG,        0x60000018
.equ UART0_CONF0_REG,          0x60000020
.equ UART0_CONF1_REG,          0x60000024
.equ UART0_FLOW_CONF_REG,      0x60000034
.equ UART0_SLEEP_CONF_REG,     0x60000038
.equ UART0_SWFC_CONF0_REG,     0x6000003C
.equ UART0_SWFC_CONF1_REG,     0x60000040
.equ UART0_TXBRK_CONF_REG,     0x60000044
.equ UART0_IDLE_CONF_REG,      0x60000048
.equ UART0_RS485_CONF_REG,     0x6000004C
.equ UART0_CLK_CONF_REG,       0x60000078
# Status Register
.equ UART0_STATUS_REG,         0x6000001C
.equ UART0_MEM_TX_STATUS_REG,  0x60000064
.equ UART0_MEM_RX_STATUS_REG,  0x60000068
.equ UART0_FSM_STATUS_REG,     0x6000006C
# Autobaud Register
.equ UART0_LOWPULSE_REG,       0x60000028
.equ UART0_HIGHPULSE_REG,      0x6000002C
.equ UART0_RXD_CNT_REG,        0x60000030
.equ UART0_POSPULSE_REG,       0x60000070
.equ UART0_NEGPULSE_REG,       0x60000074
# AT Escape Sequence Selection Configuration
.equ UART0_AT_CMD_PRECNT_REG,  0x60000050
.equ UART0_AT_CMD_POSTCNT_REG, 0x60000054
.equ UART0_AT_CMD_GAPTOUT_REG, 0x60000058
.equ UART0_AT_CMD_CHAR_REG,    0x6000005C
# Version Register
.equ UART0_DATE_REG,           0x6000007C
.equ UART0_ID_REG,             0x60000080

# UART1
# FIFO Configuration
.equ UART1_FIFO_REG,           0x60010000
.equ UART1_MEM_CONF_REG,       0x60010060
# UART Interrupt Register
.equ UART1_INT_RAW_REG,        0x60010004
.equ UART1_INT_ST_REG,         0x60010008
.equ UART1_INT_ENA_REG,        0x6001000C
.equ UART1_INT_CLR_REG,        0x60010010
# Configuration Register
.equ UART1_CLKDIV_REG,         0x60010014
.equ UART1_RX_FILT_REG,        0x60010018
.equ UART1_CONF0_REG,          0x60010020
.equ UART1_CONF1_REG,          0x60010024
.equ UART1_FLOW_CONF_REG,      0x60010034
.equ UART1_SLEEP_CONF_REG,     0x60010038
.equ UART1_SWFC_CONF0_REG,     0x6001003C
.equ UART1_SWFC_CONF1_REG,     0x60010040
.equ UART1_TXBRK_CONF_REG,     0x60010044
.equ UART1_IDLE_CONF_REG,      0x60010048
.equ UART1_RS485_CONF_REG,     0x6001004C
.equ UART1_CLK_CONF_REG,       0x60010078
# Status Register
.equ UART1_STATUS_REG,         0x6001001C
.equ UART1_MEM_TX_STATUS_REG,  0x60010064
.equ UART1_MEM_RX_STATUS_REG,  0x60010068
.equ UART1_FSM_STATUS_REG,     0x6001006C
# Autobaud Register
.equ UART1_LOWPULSE_REG,       0x60010028 
.equ UART1_HIGHPULSE_REG,      0x6001002C
.equ UART1_RXD_CNT_REG,        0x60010030
.equ UART1_POSPULSE_REG,       0x60010070
.equ UART1_NEGPULSE_REG,       0x60010074
# AT Escape Sequence Selection Configuration
.equ UART1_AT_CMD_PRECNT_REG,  0x60010050
.equ UART1_AT_CMD_POSTCNT_REG, 0x60010054
.equ UART1_AT_CMD_GAPTOUT_REG, 0x60010058
.equ UART1_AT_CMD_CHAR_REG,    0x6001005C
# Version Register
.equ UART1_DATE_REG,           0x6001007C
.equ UART1_ID_REG,             0x60010080
######################################################

######################################################
# SPI Controller (SPI)
# (TRM 382)
# (note: inserted a 2 to the register names)
######################################################
.equ SPI0_BASE,               0x60003000 # not usable?
.equ SPI1_BASE,               0x60002000 # not usable?
.equ SPI2_BASE,               0x60024000
# User-defined control registers
.equ SPI2_CMD_REG,            0x60024000
.equ SPI2_ADDR_REG,           0x60024004
.equ SPI2_USER_REG,           0x60024010
.equ SPI2_USER1_REG,          0x60024014
.equ SPI2_USER2_REG,          0x60024018
# Control and configuration registers
.equ SPI2_CTRL_REG,           0x60024008
.equ SPI2_MS_DLEN_REG,        0x6002401C
.equ SPI2_MISC_REG,           0x60024020
.equ SPI2_DMA_CONF_REG,       0x60024030
.equ SPI2_SLAVE_REG,          0x600240E0
.equ SPI2_SLAVE1_REG,         0x600240E4
# Clock control registers
.equ SPI2_CLOCK_REG,          0x6002400C
.equ SPI2_CLK_GATE_REG,       0x600240E8
# Timing registers
#.equ SPI2_DIN_MODE_REG,       0x60024024
#.equ SPI2_DIN_NUM_REG,        0x60024028
#.equ SPI2_DOUT_MODE_REG,      0x6002402C
# Interrupt registers
.equ SPI2_DMA_INT_ENA_REG,    0x60024034
.equ SPI2_DMA_INT_CLR_REG,    0x60024038
.equ SPI2_DMA_INT_RAW_REG,    0x6002403C
.equ SPI2_DMA_INT_ST_REG,     0x60024040
.equ SPI2_DMA_INT_SET_REG,    0x60024044
# CPU-controlled data buffer
.equ SPI2_W0_REG,             0x60024098
.equ SPI2_W1_REG,             0x6002409C
.equ SPI2_W2_REG,             0x600240A0
.equ SPI2_W3_REG,             0x600240A4
.equ SPI2_W4_REG,             0x600240A8
.equ SPI2_W5_REG,             0x600240AC
.equ SPI2_W6_REG,             0x600240B0
.equ SPI2_W7_REG,             0x600240B4
.equ SPI2_W8_REG,             0x600240B8
.equ SPI2_W9_REG,             0x600240BC
.equ SPI2_W10_REG,            0x600240C0
.equ SPI2_W11_REG,            0x600240C4
.equ SPI2_W12_REG,            0x600240C8
.equ SPI2_W13_REG,            0x600240CC
.equ SPI2_W14_REG,            0x600240D0
.equ SPI2_W15_REG,            0x600240D4
# Version register
.equ SPI2_DATE_REG,           0x600240F0
######################################################

######################################################
# I2C Controller (I2C)
# (TRM 435)
######################################################
.equ I2C_BASE,                     0x60013000
# Timing Registers
.equ I2C_SCL_LOW_PERIOD_REG,       0x60013000
.equ I2C_SDA_HOLD_REG,             0x60013030
.equ I2C_SDA_SAMPLE_REG,           0x60013034
.equ I2C_SCL_HIGH_PERIOD_REG,      0x60013038
.equ I2C_SCL_START_HOLD_REG,       0x60013040
.equ I2C_SCL_RSTART_SETUP_REG,     0x60013044
.equ I2C_SCL_STOP_HOLD_REG,        0x60013048
.equ I2C_SCL_STOP_SETUP_REG,       0x6001304C
.equ I2C_SCL_ST_TIME_OUT_REG,      0x60013078
.equ I2C_SCL_MAIN_ST_TIME_OUT_REG, 0x6001307C
# Configuration Registers
.equ I2C_CTR_REG,                  0x60013004
.equ I2C_TO_REG,                   0x6001300C
.equ I2C_FIFO_CONF_REG,            0x60013018
.equ I2C_FILTER_CFG_REG,           0x60013050
.equ I2C_CLK_CONF_REG,             0x60013054
.equ I2C_SCL_SP_CONF_REG,          0x60013080
# Status Registers
.equ I2C_SR_REG,                   0x60013008
.equ I2C_FIFO_ST_REG,              0x60013014
.equ I2C_DATA_REG,                 0x6001301C
# Interrupt Registers
.equ I2C_INT_RAW_REG,              0x60013020
.equ I2C_INT_CLR_REG,              0x60013024
.equ I2C_INT_ENA_REG,              0x60013028
.equ I2C_INT_STATUS_REG,           0x6001302C
# Command Registers
.equ I2C_COMD0_REG,                0x60013058
.equ I2C_COMD1_REG,                0x6001305C
.equ I2C_COMD2_REG,                0x60013060
.equ I2C_COMD3_REG,                0x60013064
.equ I2C_COMD4_REG,                0x60013068
.equ I2C_COMD5_REG,                0x6001306C
.equ I2C_COMD6_REG,                0x60013070
.equ I2C_COMD7_REG,                0x60013074
# Address Registers
.equ I2C_TXFIFO_START_ADDR_REG,    0x60013100
.equ I2C_RXFIFO_START_ADDR_REG,    0x60013180
# Version Register
.equ I2C_DATE_REG,                 0x600130F8
######################################################

######################################################
# LED PWM Controller (LEDC)
# (TRM 463)
######################################################
.equ LEDC_BASE,                        0x60019000
# Configuration Register
.equ LEDC_CH0_CONF0_REG,               0x60019000
.equ LEDC_CH0_CONF1_REG,               0x6001900C
.equ LEDC_CH1_CONF0_REG,               0x60019014
.equ LEDC_CH1_CONF1_REG,               0x60019020
.equ LEDC_CH2_CONF0_REG,               0x60019028
.equ LEDC_CH2_CONF1_REG,               0x60019034
.equ LEDC_CH3_CONF0_REG,               0x6001903C
.equ LEDC_CH3_CONF1_REG,               0x60019048
.equ LEDC_CH4_CONF0_REG,               0x60019050
.equ LEDC_CH4_CONF1_REG,               0x6001905C
.equ LEDC_CH5_CONF0_REG,               0x60019064
.equ LEDC_CH5_CONF1_REG,               0x60019070
.equ LEDC_CONF_REG,                    0x600190D0
# Hpoint Register
.equ LEDC_CH0_HPOINT_REG,              0x60019004
.equ LEDC_CH1_HPOINT_REG,              0x60019018
.equ LEDC_CH2_HPOINT_REG,              0x6001902C
.equ LEDC_CH3_HPOINT_REG,              0x60019040
.equ LEDC_CH4_HPOINT_REG,              0x60019054
.equ LEDC_CH5_HPOINT_REG,              0x60019068
# Duty Cycle Register
.equ LEDC_CH0_DUTY_REG,                0x60019008
.equ LEDC_CH0_DUTY_R_REG,              0x60019010
.equ LEDC_CH1_DUTY_REG,                0x6001901C
.equ LEDC_CH1_DUTY_R_REG,              0x60019024
.equ LEDC_CH2_DUTY_REG,                0x60019030
.equ LEDC_CH2_DUTY_R_REG,              0x60019038
.equ LEDC_CH3_DUTY_REG,                0x60019044
.equ LEDC_CH3_DUTY_R_REG,              0x6001904C
.equ LEDC_CH4_DUTY_REG,                0x60019058
.equ LEDC_CH4_DUTY_R_REG,              0x60019060
.equ LEDC_CH5_DUTY_REG,                0x6001906C
.equ LEDC_CH5_DUTY_R_REG,              0x60019074
# Timer Register
.equ LEDC_TIMER0_CONF_REG,             0x600190A0
.equ LEDC_TIMER0_VALUE_REG,            0x600190A4
.equ LEDC_TIMER1_CONF_REG,             0x600190A8
.equ LEDC_TIMER1_VALUE_REG,            0x600190AC
.equ LEDC_TIMER2_CONF_REG,             0x600190B0
.equ LEDC_TIMER2_VALUE_REG,            0x600190B4
.equ LEDC_TIMER3_CONF_REG,             0x600190B8
.equ LEDC_TIMER3_VALUE_REG,            0x600190BC
# Interrupt Register
.equ LEDC_INT_RAW_REG,                 0x600190C0
.equ LEDC_INT_ST_REG,                  0x600190C4
.equ LEDC_INT_ENA_REG,                 0x600190C8
.equ LEDC_INT_CLR_REG,                 0x600190CC
# Version Register
.equ LEDC_DATE_REG,                    0x600190FC
######################################################

######################################################
# On-Chip Sensor and Analog Signal Processing
# (TRM 480)
######################################################
.equ ADC_BASE, 0x60040000
# Configuration Registers
.equ APB_SARADC_CTRL_REG,              0x60040000
.equ APB_SARADC_CTRL2_REG,             0x60040004
.equ APB_SARADC_FILTER_CTRL1_REG,      0x60040008
.equ APB_SARADC_SAR_PATT_TAB1_REG,     0x60040018
.equ APB_SARADC_SAR_PATT_TAB2_REG,     0x6004001C
.equ APB_SARADC_ONETIME_SAMPLE_REG,    0x60040020
.equ APB_SARADC_FILTER_CTRL0_REG,      0x60040028
.equ APB_SARADC_1_DATA_STATUS_REG,     0x6004002C
.equ APB_SARADC_THRES0_CTRL_REG,       0x60040034
.equ APB_SARADC_THRES1_CTRL_REG,       0x60040038
.equ APB_SARADC_THRES_CTRL_REG,        0x6004003C
.equ APB_SARADC_INT_ENA_REG,           0x60040040
.equ APB_SARADC_INT_RAW_REG,           0x60040044
.equ APB_SARADC_INT_ST_REG,            0x60040048
.equ APB_SARADC_INT_CLR_REG,           0x6004004C
.equ APB_SARADC_DMA_CONF_REG,          0x60040050
.equ APB_SARADC_APB_ADC_CLKM_CONF_REG, 0x60040054
.equ APB_SARADC_APB_TSENS_CTRL_REG,    0x60040058
.equ APB_SARADC_APB_TSENS_CTRL2_REG,   0x6004005C
# Version Register
.equ APB_SARADC_APB_CTRL_DATE_REG,     0x600403FC
######################################################