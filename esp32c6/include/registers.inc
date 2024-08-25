######################################################
# ESP32-C6
######################################################

######################################################
# Configuration and Status Registers (CSRs)
# (TRM 37)
######################################################
# Machine Information CSRs
.equ mvendorid, 0xF11
.equ marchid,   0xF12
.equ mimpid,    0xF13
.equ mhartid,   0xF14
# Machine Trap Setup CSRs
.equ mstatus,   0x300
.equ misa,      0x301
.equ mideleg,   0x303
.equ mie,       0x304
.equ mtvec,     0x305
# Machine Trap Handling CSRs
.equ mscratch,  0x340
.equ mepc,      0x341
.equ mcause,    0x342
.equ mtval,     0x343
.equ mip,       0x344
# User Trap Setup CSRs
.equ ustatus,   0x000
.equ uie,       0x004
.equ utvec,     0x005 
# User Trap Handling CSRs
.equ uscratch,  0x040
.equ uepc,      0x041
.equ ucause,    0x042
.equ uip,       0x044
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
.equ cpu_gpio_oen, 0x803
.equ cpu_gpio_in,  0x804
.equ cpu_gpio_out, 0x805
######################################################

######################################################
# GPIO (GPIO)
# (TRM 255)
######################################################
.equ GPIO_BASE,             0x60091000
# Configuration Registers
.equ GPIO_OUT_REG,          0x60091004
.equ GPIO_OUT_W1TS_REG,     0x60091008
.equ GPIO_OUT_W1TC_REG,     0x6009100C
.equ GPIO_ENABLE_REG,       0x60091020
.equ GPIO_ENABLE_W1TS_REG,  0x60091024
.equ GPIO_ENABLE_W1TC_REG,  0x60091028
.equ GPIO_STRAP_REG,        0x60091038
.equ GPIO_IN_REG,           0x6009103C
# Interrupt Status Registers
.equ GPIO_STATUS_REG,       0x60091044
.equ GPIO_STATUS_W1TS_REG,  0x60091048
.equ GPIO_STATUS_W1TC_REG,  0x6009104C
.equ GPIO_PCPU_INT_REG,     0x6009105C
.equ GPIO_STATUS_NEXT_REG,  0x6009114C
# Pin Configuration Registers
.equ GPIO_PIN0_REG,         0x60091074
.equ GPIO_PIN1_REG,         0x60091078
.equ GPIO_PIN2_REG,         0x6009107C
.equ GPIO_PIN3_REG,         0x60091080
.equ GPIO_PIN4_REG,         0x60091084
.equ GPIO_PIN5_REG,         0x60091088
.equ GPIO_PIN6_REG,         0x6009108C
.equ GPIO_PIN7_REG,         0x60091090
.equ GPIO_PIN8_REG,         0x60091094
.equ GPIO_PIN9_REG,         0x60091098
.equ GPIO_PIN10_REG,        0x6009109C
.equ GPIO_PIN11_REG,        0x600910A0
.equ GPIO_PIN12_REG,        0x600910A4
.equ GPIO_PIN13_REG,        0x600910A8
.equ GPIO_PIN14_REG,        0x600910AC
.equ GPIO_PIN15_REG,        0x600910B0
.equ GPIO_PIN16_REG,        0x600910B4
.equ GPIO_PIN17_REG,        0x600910B8
.equ GPIO_PIN18_REG,        0x600910BC
.equ GPIO_PIN19_REG,        0x600910C0
.equ GPIO_PIN20_REG,        0x600910C4
.equ GPIO_PIN21_REG,        0x600910C8
.equ GPIO_PIN22_REG,        0x600910CC
.equ GPIO_PIN23_REG,        0x600910D0
.equ GPIO_PIN24_REG,        0x600910D4
.equ GPIO_PIN25_REG,        0x600910D8
.equ GPIO_PIN26_REG,        0x600910DC
.equ GPIO_PIN27_REG,        0x600910E0
.equ GPIO_PIN28_REG,        0x600910E4
.equ GPIO_PIN29_REG,        0x600910E8
.equ GPIO_PIN30_REG,        0x600910EC
# Input Function Configuration Registers
.equ GPIO_FUNC0_IN_SEL_CFG_REG,   0x60091154
.equ GPIO_FUNC1_IN_SEL_CFG_REG,   0x60091158
.equ GPIO_FUNC2_IN_SEL_CFG_REG,   0x6009115C
.equ GPIO_FUNC3_IN_SEL_CFG_REG,   0x60091160
.equ GPIO_FUNC4_IN_SEL_CFG_REG,   0x60091164
.equ GPIO_FUNC5_IN_SEL_CFG_REG,   0x60091168
.equ GPIO_FUNC6_IN_SEL_CFG_REG,   0x6009116C
.equ GPIO_FUNC7_IN_SEL_CFG_REG,   0x60091170
.equ GPIO_FUNC8_IN_SEL_CFG_REG,   0x60091174
.equ GPIO_FUNC9_IN_SEL_CFG_REG,   0x60091178
.equ GPIO_FUNC10_IN_SEL_CFG_REG,  0x6009117C
.equ GPIO_FUNC11_IN_SEL_CFG_REG,  0x60091180
.equ GPIO_FUNC12_IN_SEL_CFG_REG,  0x60091184
.equ GPIO_FUNC13_IN_SEL_CFG_REG,  0x60091188
.equ GPIO_FUNC14_IN_SEL_CFG_REG,  0x6009118C
.equ GPIO_FUNC15_IN_SEL_CFG_REG,  0x60091190
.equ GPIO_FUNC16_IN_SEL_CFG_REG,  0x60091194
.equ GPIO_FUNC17_IN_SEL_CFG_REG,  0x60091198
.equ GPIO_FUNC18_IN_SEL_CFG_REG,  0x6009119C
.equ GPIO_FUNC19_IN_SEL_CFG_REG,  0x600911A0
.equ GPIO_FUNC20_IN_SEL_CFG_REG,  0x600911A4
.equ GPIO_FUNC21_IN_SEL_CFG_REG,  0x600911A8
.equ GPIO_FUNC22_IN_SEL_CFG_REG,  0x600911AC
.equ GPIO_FUNC23_IN_SEL_CFG_REG,  0x600911B0
.equ GPIO_FUNC24_IN_SEL_CFG_REG,  0x600911B4
.equ GPIO_FUNC25_IN_SEL_CFG_REG,  0x600911B8
.equ GPIO_FUNC26_IN_SEL_CFG_REG,  0x600911BC
.equ GPIO_FUNC27_IN_SEL_CFG_REG,  0x600911C0
.equ GPIO_FUNC28_IN_SEL_CFG_REG,  0x600911C4
.equ GPIO_FUNC29_IN_SEL_CFG_REG,  0x600911C8
.equ GPIO_FUNC30_IN_SEL_CFG_REG,  0x600911CC
.equ GPIO_FUNC31_IN_SEL_CFG_REG,  0x600911D0
.equ GPIO_FUNC32_IN_SEL_CFG_REG,  0x600911D4
.equ GPIO_FUNC33_IN_SEL_CFG_REG,  0x600911D8
.equ GPIO_FUNC34_IN_SEL_CFG_REG,  0x600911DC
.equ GPIO_FUNC35_IN_SEL_CFG_REG,  0x600911E0
.equ GPIO_FUNC36_IN_SEL_CFG_REG,  0x600911E4
.equ GPIO_FUNC37_IN_SEL_CFG_REG,  0x600911E8
.equ GPIO_FUNC38_IN_SEL_CFG_REG,  0x600911EC
.equ GPIO_FUNC39_IN_SEL_CFG_REG,  0x600911F0
.equ GPIO_FUNC40_IN_SEL_CFG_REG,  0x600911F4
.equ GPIO_FUNC41_IN_SEL_CFG_REG,  0x600911F8
.equ GPIO_FUNC42_IN_SEL_CFG_REG,  0x600911FC
.equ GPIO_FUNC43_IN_SEL_CFG_REG,  0x60091200
.equ GPIO_FUNC44_IN_SEL_CFG_REG,  0x60091204
.equ GPIO_FUNC45_IN_SEL_CFG_REG,  0x60091208
.equ GPIO_FUNC46_IN_SEL_CFG_REG,  0x6009120C
.equ GPIO_FUNC47_IN_SEL_CFG_REG,  0x60091210
.equ GPIO_FUNC48_IN_SEL_CFG_REG,  0x60091214
.equ GPIO_FUNC49_IN_SEL_CFG_REG,  0x60091218
.equ GPIO_FUNC50_IN_SEL_CFG_REG,  0x6009121C
.equ GPIO_FUNC51_IN_SEL_CFG_REG,  0x60091220
.equ GPIO_FUNC52_IN_SEL_CFG_REG,  0x60091224
.equ GPIO_FUNC53_IN_SEL_CFG_REG,  0x60091228
.equ GPIO_FUNC54_IN_SEL_CFG_REG,  0x6009122C
.equ GPIO_FUNC55_IN_SEL_CFG_REG,  0x60091230
.equ GPIO_FUNC56_IN_SEL_CFG_REG,  0x60091234
.equ GPIO_FUNC57_IN_SEL_CFG_REG,  0x60091238
.equ GPIO_FUNC58_IN_SEL_CFG_REG,  0x6009123C
.equ GPIO_FUNC59_IN_SEL_CFG_REG,  0x60091240
.equ GPIO_FUNC60_IN_SEL_CFG_REG,  0x60091244
.equ GPIO_FUNC61_IN_SEL_CFG_REG,  0x60091248
.equ GPIO_FUNC62_IN_SEL_CFG_REG,  0x6009124C
.equ GPIO_FUNC63_IN_SEL_CFG_REG,  0x60091250
.equ GPIO_FUNC64_IN_SEL_CFG_REG,  0x60091254
.equ GPIO_FUNC65_IN_SEL_CFG_REG,  0x60091258
.equ GPIO_FUNC66_IN_SEL_CFG_REG,  0x6009125C
.equ GPIO_FUNC67_IN_SEL_CFG_REG,  0x60091260
.equ GPIO_FUNC68_IN_SEL_CFG_REG,  0x60091264
.equ GPIO_FUNC69_IN_SEL_CFG_REG,  0x60091268
.equ GPIO_FUNC70_IN_SEL_CFG_REG,  0x6009126C
.equ GPIO_FUNC71_IN_SEL_CFG_REG,  0x60091270
.equ GPIO_FUNC72_IN_SEL_CFG_REG,  0x60091274
.equ GPIO_FUNC73_IN_SEL_CFG_REG,  0x60091278
.equ GPIO_FUNC74_IN_SEL_CFG_REG,  0x6009127C
.equ GPIO_FUNC75_IN_SEL_CFG_REG,  0x60091280
.equ GPIO_FUNC76_IN_SEL_CFG_REG,  0x60091284
.equ GPIO_FUNC77_IN_SEL_CFG_REG,  0x60091288
.equ GPIO_FUNC78_IN_SEL_CFG_REG,  0x6009128C
.equ GPIO_FUNC79_IN_SEL_CFG_REG,  0x60091290
.equ GPIO_FUNC80_IN_SEL_CFG_REG,  0x60091294
.equ GPIO_FUNC81_IN_SEL_CFG_REG,  0x60091298
.equ GPIO_FUNC82_IN_SEL_CFG_REG,  0x6009129C
.equ GPIO_FUNC83_IN_SEL_CFG_REG,  0x600912A0
.equ GPIO_FUNC84_IN_SEL_CFG_REG,  0x600912A4
.equ GPIO_FUNC85_IN_SEL_CFG_REG,  0x600912A8
.equ GPIO_FUNC86_IN_SEL_CFG_REG,  0x600912AC
.equ GPIO_FUNC87_IN_SEL_CFG_REG,  0x600912B0
.equ GPIO_FUNC88_IN_SEL_CFG_REG,  0x600912B4
.equ GPIO_FUNC89_IN_SEL_CFG_REG,  0x600912B8
.equ GPIO_FUNC90_IN_SEL_CFG_REG,  0x600912BC
.equ GPIO_FUNC91_IN_SEL_CFG_REG,  0x600912C0
.equ GPIO_FUNC92_IN_SEL_CFG_REG,  0x600912C4
.equ GPIO_FUNC93_IN_SEL_CFG_REG,  0x600912C8
.equ GPIO_FUNC94_IN_SEL_CFG_REG,  0x600912CC
.equ GPIO_FUNC95_IN_SEL_CFG_REG,  0x600912D0
.equ GPIO_FUNC96_IN_SEL_CFG_REG,  0x600912D4
.equ GPIO_FUNC97_IN_SEL_CFG_REG,  0x600912D8
.equ GPIO_FUNC98_IN_SEL_CFG_REG,  0x600912DC
.equ GPIO_FUNC99_IN_SEL_CFG_REG,  0x600912E0
.equ GPIO_FUNC100_IN_SEL_CFG_REG, 0x600912E4
.equ GPIO_FUNC101_IN_SEL_CFG_REG, 0x600912E8
.equ GPIO_FUNC102_IN_SEL_CFG_REG, 0x600912EC
.equ GPIO_FUNC103_IN_SEL_CFG_REG, 0x600912F0
.equ GPIO_FUNC104_IN_SEL_CFG_REG, 0x600912F4
.equ GPIO_FUNC105_IN_SEL_CFG_REG, 0x600912F8
.equ GPIO_FUNC106_IN_SEL_CFG_REG, 0x600912FC
.equ GPIO_FUNC107_IN_SEL_CFG_REG, 0x60091300
.equ GPIO_FUNC108_IN_SEL_CFG_REG, 0x60091304
.equ GPIO_FUNC109_IN_SEL_CFG_REG, 0x60091308
.equ GPIO_FUNC110_IN_SEL_CFG_REG, 0x6009130C
.equ GPIO_FUNC111_IN_SEL_CFG_REG, 0x60091310
.equ GPIO_FUNC112_IN_SEL_CFG_REG, 0x60091314
.equ GPIO_FUNC113_IN_SEL_CFG_REG, 0x60091318
.equ GPIO_FUNC114_IN_SEL_CFG_REG, 0x6009131C
.equ GPIO_FUNC115_IN_SEL_CFG_REG, 0x60091320
.equ GPIO_FUNC116_IN_SEL_CFG_REG, 0x60091324
.equ GPIO_FUNC117_IN_SEL_CFG_REG, 0x60091328
.equ GPIO_FUNC118_IN_SEL_CFG_REG, 0x6009132C
.equ GPIO_FUNC119_IN_SEL_CFG_REG, 0x60091330
.equ GPIO_FUNC120_IN_SEL_CFG_REG, 0x60091334
.equ GPIO_FUNC121_IN_SEL_CFG_REG, 0x60091338
.equ GPIO_FUNC122_IN_SEL_CFG_REG, 0x6009133C
.equ GPIO_FUNC123_IN_SEL_CFG_REG, 0x60091340
.equ GPIO_FUNC124_IN_SEL_CFG_REG, 0x60091344
.equ GPIO_FUNC125_IN_SEL_CFG_REG, 0x60091348
.equ GPIO_FUNC126_IN_SEL_CFG_REG, 0x6009134C
.equ GPIO_FUNC127_IN_SEL_CFG_REG, 0x60091350
# Output Function Configuration Registers
.equ GPIO_FUNC0_OUT_SEL_CFG_REG,  0x60091554
.equ GPIO_FUNC1_OUT_SEL_CFG_REG,  0x60091558
.equ GPIO_FUNC2_OUT_SEL_CFG_REG,  0x6009155C
.equ GPIO_FUNC3_OUT_SEL_CFG_REG,  0x60091560
.equ GPIO_FUNC4_OUT_SEL_CFG_REG,  0x60091564
.equ GPIO_FUNC5_OUT_SEL_CFG_REG,  0x60091568
.equ GPIO_FUNC6_OUT_SEL_CFG_REG,  0x6009156C
.equ GPIO_FUNC7_OUT_SEL_CFG_REG,  0x60091570
.equ GPIO_FUNC8_OUT_SEL_CFG_REG,  0x60091574
.equ GPIO_FUNC9_OUT_SEL_CFG_REG,  0x60091578
.equ GPIO_FUNC10_OUT_SEL_CFG_REG, 0x6009157C
.equ GPIO_FUNC11_OUT_SEL_CFG_REG, 0x60091580
.equ GPIO_FUNC12_OUT_SEL_CFG_REG, 0x60091584
.equ GPIO_FUNC13_OUT_SEL_CFG_REG, 0x60091588
.equ GPIO_FUNC14_OUT_SEL_CFG_REG, 0x6009158C
.equ GPIO_FUNC15_OUT_SEL_CFG_REG, 0x60091590
.equ GPIO_FUNC16_OUT_SEL_CFG_REG, 0x60091594
.equ GPIO_FUNC17_OUT_SEL_CFG_REG, 0x60091598
.equ GPIO_FUNC18_OUT_SEL_CFG_REG, 0x6009159C
.equ GPIO_FUNC19_OUT_SEL_CFG_REG, 0x600915A0
.equ GPIO_FUNC20_OUT_SEL_CFG_REG, 0x600915A4
.equ GPIO_FUNC21_OUT_SEL_CFG_REG, 0x600915A8
.equ GPIO_FUNC22_OUT_SEL_CFG_REG, 0x600915AC
.equ GPIO_FUNC23_OUT_SEL_CFG_REG, 0x600915B0
.equ GPIO_FUNC24_OUT_SEL_CFG_REG, 0x600915B4
.equ GPIO_FUNC25_OUT_SEL_CFG_REG, 0x600915B8
.equ GPIO_FUNC26_OUT_SEL_CFG_REG, 0x600915BC
.equ GPIO_FUNC27_OUT_SEL_CFG_REG, 0x600915C0
.equ GPIO_FUNC28_OUT_SEL_CFG_REG, 0x600915C4
.equ GPIO_FUNC29_OUT_SEL_CFG_REG, 0x600915C8
.equ GPIO_FUNC30_OUT_SEL_CFG_REG, 0x600915CC
# Version Register
.equ GPIO_DATE_REG,               0x600916FC
# Clock Gate Register
.equ GPIO_CLOCK_GATE_REG,         0x6009162C
######################################################

######################################################
# IO MUX (IO MUX)
# (TRM 257)
######################################################
# Configuration Registers
.equ IO_MUX_BASE,                 0x60090000
.equ IO_MUX_PIN_CTRL_REG,         0x60090000
.equ IO_MUX_GPIO0_REG,            0x60090004
.equ IO_MUX_GPIO1_REG,            0x60090008
.equ IO_MUX_GPIO2_REG,            0x6009000C
.equ IO_MUX_GPIO3_REG,            0x60090010
.equ IO_MUX_GPIO4_REG,            0x60090014
.equ IO_MUX_GPIO5_REG,            0x60090018
.equ IO_MUX_GPIO6_REG,            0x6009001C
.equ IO_MUX_GPIO7_REG,            0x60090020
.equ IO_MUX_GPIO8_REG,            0x60090024
.equ IO_MUX_GPIO9_REG,            0x60090028
.equ IO_MUX_GPIO10_REG,           0x6009002C
.equ IO_MUX_GPIO11_REG,           0x60090030
.equ IO_MUX_GPIO12_REG,           0x60090034
.equ IO_MUX_GPIO13_REG,           0x60090038
.equ IO_MUX_GPIO14_REG,           0x6009003C
.equ IO_MUX_GPIO15_REG,           0x60090040
.equ IO_MUX_GPIO16_REG,           0x60090044
.equ IO_MUX_GPIO17_REG,           0x60090048
.equ IO_MUX_GPIO18_REG,           0x6009004C
.equ IO_MUX_GPIO19_REG,           0x60090050
.equ IO_MUX_GPIO20_REG,           0x60090054
.equ IO_MUX_GPIO21_REG,           0x60090058
.equ IO_MUX_GPIO22_REG,           0x6009005C
.equ IO_MUX_GPIO23_REG,           0x60090060
.equ IO_MUX_GPIO24_REG,           0x60090064
.equ IO_MUX_GPIO25_REG,           0x60090068
.equ IO_MUX_GPIO26_REG,           0x6009006C
.equ IO_MUX_GPIO27_REG,           0x60090070
.equ IO_MUX_GPIO28_REG,           0x60090074
.equ IO_MUX_GPIO29_REG,           0x60090078
.equ IO_MUX_GPIO30_REG,           0x6009007C
# Version Register
.equ IO_MUX_DATE_REG,             0x600900FC
######################################################

######################################################
# System Timer (SYSTIMER)
# (TRM 488)
######################################################
.equ SYSTIMER_BASE,                0x6000A000
# Clock Control Register
.equ SYSTIMER_CONF_REG,            0x6000A000
# UNIT0 Control and Configuration Registers
.equ SYSTIMER_UNIT0_OP_REG,        0x6000A004
.equ SYSTIMER_UNIT0_LOAD_HI_REG,   0x6000A00C
.equ SYSTIMER_UNIT0_LOAD_LO_REG,   0x6000A010
.equ SYSTIMER_UNIT0_VALUE_HI_REG,  0x6000A040
.equ SYSTIMER_UNIT0_VALUE_LO_REG,  0x6000A044
.equ SYSTIMER_UNIT0_LOAD_REG,      0x6000A05C
# UNIT1 Control and Configuration Registers
.equ SYSTIMER_UNIT1_OP_REG,        0x6000A008
.equ SYSTIMER_UNIT1_LOAD_HI_REG,   0x6000A014
.equ SYSTIMER_UNIT1_LOAD_LO_REG,   0x6000A018
.equ SYSTIMER_UNIT1_VALUE_HI_REG,  0x6000A048
.equ SYSTIMER_UNIT1_VALUE_LO_REG,  0x6000A04C
.equ SYSTIMER_UNIT1_LOAD_REG,      0x6000A060
# Comparator0 Control and Configuration Registers
.equ SYSTIMER_TARGET0_HI_REG,      0x6000A01C
.equ SYSTIMER_TARGET0_LO_REG,      0x6000A020
.equ SYSTIMER_TARGET0_CONF_REG,    0x6000A034
.equ SYSTIMER_COMP0_LOAD_REG,      0x6000A050
# Comparator1 Control and Configuration Registers
.equ SYSTIMER_TARGET1_HI_REG,      0x6000A024
.equ SYSTIMER_TARGET1_LO_REG,      0x6000A028
.equ SYSTIMER_TARGET1_CONF_REG,    0x6000A038
.equ SYSTIMER_COMP1_LOAD_REG,      0x6000A054
# Comparator2 Control and Configuration Registers
.equ SYSTIMER_TARGET2_HI_REG,      0x6000A02C
.equ SYSTIMER_TARGET2_LO_REG,      0x6000A030
.equ SYSTIMER_TARGET2_CONF_REG,    0x6000A03C
.equ SYSTIMER_COMP2_LOAD_REG,      0x6000A058
# Interrupt Registers
.equ SYSTIMER_INT_ENA_REG,         0x6000A064
.equ SYSTIMER_INT_RAW_REG,         0x6000A068
.equ SYSTIMER_INT_CLR_REG,         0x6000A06C
.equ SYSTIMER_INT_ST_REG,          0x6000A070
# COMP0 Status Registers
.equ SYSTIMER_REAL_TARGET0_LO_REG, 0x6000A074
.equ SYSTIMER_REAL_TARGET0_HI_REG, 0x6000A078
# COMP1 Status Registers
.equ SYSTIMER_REAL_TARGET1_LO_REG, 0x6000A07C
.equ SYSTIMER_REAL_TARGET1_HI_REG, 0x6000A080
# COMP2 Status Registers
.equ SYSTIMER_REAL_TARGET2_LO_REG, 0x6000A084
.equ SYSTIMER_REAL_TARGET2_HI_REG, 0x6000A088
# Version Registers
.equ SYSTIMER_DATE_REG,            0x6000A0FC
######################################################

######################################################
# Timer Group (TIMG)
# (TRM 514) (timer group 0)
# (note: inserted a 0 to the register names)
######################################################
.equ TIMG0_BASE,               0x60008000
# T0 control and configuration registers
.equ TIMG0_T0CONFIG_REG,       0x60008000
.equ TIMG0_T0LO_REG,           0x60008004
.equ TIMG0_T0HI_REG,           0x60008008
.equ TIMG0_T0UPDATE_REG,       0x6000800C
.equ TIMG0_T0ALARMLO_REG,      0x60008010
.equ TIMG0_T0ALARMHI_REG,      0x60008014
.equ TIMG0_T0LOADLO_REG,       0x60008018
.equ TIMG0_T0LOADHI_REG,       0x6000801C
.equ TIMG0_T0LOAD_REG,         0x60008020
# WDT control and configuration registers
.equ TIMG0_WDTCONFIG0_REG,     0x60008048
.equ TIMG0_WDTCONFIG1_REG,     0x6000804C
.equ TIMG0_WDTCONFIG2_REG,     0x60008050
.equ TIMG0_WDTCONFIG3_REG,     0x60008054
.equ TIMG0_WDTCONFIG4_REG,     0x60008058
.equ TIMG0_WDTCONFIG5_REG,     0x6000805C
.equ TIMG0_WDTFEED_REG,        0x60008060
.equ TIMG0_WDTWPROTECT_REG,    0x60008064
# RTC frequency calculation control and configuration registers
.equ TIMG0_RTCCALICFG_REG,     0x60008068
.equ TIMG0_RTCCALICFG1_REG,    0x6000806C
.equ TIMG0_RTCCALICFG2_REG,    0x60008080
# Interrupt registers
.equ TIMG0_INT_ENA_TIMERS_REG, 0x60008070
.equ TIMG0_INT_RAW_TIMERS_REG, 0x60008074
.equ TIMG0_INT_ST_TIMERS_REG,  0x60008078
.equ TIMG0_INT_CLR_TIMERS_REG, 0x6000807C
# Version register
.equ TIMG0_NTIMERS_DATE_REG,   0x600080F8
# Clock configuration registers
.equ TIMG0_REGCLK_REG,         0x600080FC
######################################################

######################################################
# Timer Group (TIMG)
# (TRM 514) (timer group 1)
# (note: inserted a 1 to the register names)
######################################################
.equ TIMG1_BASE,               0x60009000
# T0 control and configuration registers
.equ TIMG1_T0CONFIG_REG,       0x60009000
.equ TIMG1_T0LO_REG,           0x60009004
.equ TIMG1_T0HI_REG,           0x60009008
.equ TIMG1_T0UPDATE_REG,       0x6000900C
.equ TIMG1_T0ALARMLO_REG,      0x60009010
.equ TIMG1_T0ALARMHI_REG,      0x60009014
.equ TIMG1_T0LOADLO_REG,       0x60009018
.equ TIMG1_T0LOADHI_REG,       0x6000901C
.equ TIMG1_T0LOAD_REG,         0x60009020
# WDT control and configuration registers
.equ TIMG1_WDTCONFIG0_REG,     0x60009048
.equ TIMG1_WDTCONFIG1_REG,     0x6000904C
.equ TIMG1_WDTCONFIG2_REG,     0x60009050
.equ TIMG1_WDTCONFIG3_REG,     0x60009054
.equ TIMG1_WDTCONFIG4_REG,     0x60009058
.equ TIMG1_WDTCONFIG5_REG,     0x6000905C
.equ TIMG1_WDTFEED_REG,        0x60009060
.equ TIMG1_WDTWPROTECT_REG,    0x60009064
# RTC frequency calculation control and configuration registers
.equ TIMG1_RTCCALICFG_REG,     0x60009068
.equ TIMG1_RTCCALICFG1_REG,    0x6000906C
.equ TIMG1_RTCCALICFG2_REG,    0x60009080
# Interrupt registers
.equ TIMG1_INT_ENA_TIMERS_REG, 0x60009070
.equ TIMG1_INT_RAW_TIMERS_REG, 0x60009074
.equ TIMG1_INT_ST_TIMERS_REG,  0x60009078
.equ TIMG1_INT_CLR_TIMERS_REG, 0x6000907C
# Version register
.equ TIMG1_NTIMERS_DATE_REG,   0x600090F8
# Clock configuration registers
.equ TIMG1_REGCLK_REG,         0x600090FC
######################################################

######################################################
# PCR Registers (PCR) (Power Clock Reset)
# (TRM 305)
######################################################
.equ PCR_BASE,                              0x60096000
# Configuration Registers
.equ PCR_UART0_CONF_REG,                    0x60096000
.equ PCR_UART0_SCLK_CONF_REG,               0x60096004
.equ PCR_UART0_PD_CTRL_REG,                 0x60096008
.equ PCR_UART1_CONF_REG,                    0x6009600C
.equ PCR_UART1_SCLK_CONF_REG,               0x60096010
.equ PCR_UART1_PD_CTRL_REG,                 0x60096014
.equ PCR_I2C_CONF_REG,                      0x60096020
.equ PCR_I2C_SCLK_CONF_REG,                 0x60096024
.equ PCR_UHCI_CONF_REG,                     0x60096028
.equ PCR_RMT_CONF_REG,                      0x6009602C
.equ PCR_RMT_SCLK_CONF_REG,                 0x60096030
.equ PCR_LEDC_CONF_REG,                     0x60096034
.equ PCR_LEDC_SCLK_CONF_REG,                0x60096038
.equ PCR_TIMERGROUP0_CONF_REG,              0x6009603C
.equ PCR_TIMERGROUP0_TIMER_CLK_CONF_REG,    0x60096040
.equ PCR_TIMERGROUP0_WDT_CLK_CONF_REG,      0x60096044
.equ PCR_TIMERGROUP1_CONF_REG,              0x60096048
.equ PCR_TIMERGROUP1_TIMER_CLK_CONF_REG,    0x6009604C
.equ PCR_TIMERGROUP1_WDT_CLK_CONF_REG,      0x60096050
.equ PCR_SYSTIMER_CONF_REG,                 0x60096054
.equ PCR_SYSTIMER_FUNC_CLK_CONF_REG,        0x60096058
.equ PCR_TWAI0_CONF_REG,                    0x6009605C
.equ PCR_TWAI0_FUNC_CLK_CONF_REG,           0x60096060
.equ PCR_TWAI1_CONF_REG,                    0x60096064
.equ PCR_TWAI1_FUNC_CLK_CONF_REG,           0x60096068
.equ PCR_I2S_CONF_REG,                      0x6009606C
.equ PCR_I2S_TX_CLKM_CONF_REG,              0x60096070
.equ PCR_I2S_TX_CLKM_DIV_CONF_REG,          0x60096074
.equ PCR_I2S_RX_CLKM_CONF_REG,              0x60096078
.equ PCR_I2S_RX_CLKM_DIV_CONF_REG,          0x6009607C
.equ PCR_SARADC_CONF_REG,                   0x60096080
.equ PCR_SARADC_CLKM_CONF_REG,              0x60096084
.equ PCR_TSENS_CLK_CONF_REG,                0x60096088
.equ PCR_USB_SERIAL_JTAG_CONF_REG,          0x6009608C
.equ PCR_INTMTX_CONF_REG,                   0x60096090
.equ PCR_PCNT_CONF_REG,                     0x60096094
.equ PCR_ETM_CONF_REG,                      0x60096098
.equ PCR_PWM_CONF_REG,                      0x6009609C
.equ PCR_PWM_CLK_CONF_REG,                  0x600960A0
.equ PCR_PARL_IO_CONF_REG,                  0x600960A4
.equ PCR_PARL_CLK_RX_CONF_REG,              0x600960A8
.equ PCR_PARL_CLK_TX_CONF_REG,              0x600960AC
.equ PCR_SDIO_SLAVE_CONF_REG,               0x600960B0
.equ PCR_GDMA_CONF_REG,                     0x600960BC
.equ PCR_SPI2_CONF_REG,                     0x600960C0
.equ PCR_SPI2_CLKM_CONF_REG,                0x600960C4
.equ PCR_AES_CONF_REG,                      0x600960C8
.equ PCR_SHA_CONF_REG,                      0x600960CC
.equ PCR_RSA_CONF_REG,                      0x600960D0
.equ PCR_RSA_PD_CTRL_REG,                   0x600960D4
.equ PCR_ECC_CONF_REG,                      0x600960D8
.equ PCR_ECC_PD_CTRL_REG,                   0x600960DC
.equ PCR_DS_CONF_REG,                       0x600960E0
.equ PCR_HMAC_CONF_REG,                     0x600960E4
.equ PCR_IOMUX_CONF_REG,                    0x600960E8
.equ PCR_IOMUX_CLK_CONF_REG,                0x600960EC
.equ PCR_MEM_MONITOR_CONF_REG,              0x600960F0
.equ PCR_TRACE_CONF_REG,                    0x600960FC
.equ PCR_ASSIST_CONF_REG,                   0x60096100
.equ PCR_CACHE_CONF_REG,                    0x60096104
.equ PCR_MODEM_APB_CONF_REG,                0x60096108
.equ PCR_TIMEOUT_CONF_REG,                  0x6009610C
.equ PCR_SYSCLK_CONF_REG,                   0x60096110
.equ PCR_CPU_WAITI_CONF_REG,                0x60096114
.equ PCR_CPU_FREQ_CONF_REG,                 0x60096118
.equ PCR_AHB_FREQ_CONF_REG,                 0x6009611C
.equ PCR_APB_FREQ_CONF_REG,                 0x60096120
.equ PCR_PLL_DIV_CLK_EN_REG,                0x60096128
.equ PCR_CTRL_32K_CONF_REG,                 0x60096134
.equ PCR_SRAM_POWER_CONF_REG,               0x60096138
.equ PCR_RESET_EVENT_BYPASS_REG,            0x60096FF0
# Frequency Statistics Register
.equ PCR_SYSCLK_FREQ_QUERY_0_REG,           0x60096124
# Version Register
.equ PCR_DATE_REG,                          0x60096FFC
######################################################

######################################################
# Low-power Clock/Reset (LP_CLKRST)
# (TRM 307)
######################################################
.equ LP_CLKRST_BASE,                        0x600B0400
# Configuration Registers
.equ LP_CLKRST_LP_CLK_CONF_REG,             0x600B0400
.equ LP_CLKRST_LP_CLK_PO_EN_REG,            0x600B0404
.equ LP_CLKRST_LP_CLK_EN_REG,               0x600B0408
.equ LP_CLKRST_LP_RST_EN_REG,               0x600B040C
.equ LP_CLKRST_RESET_CAUSE_REG,             0x600B0410
.equ LP_CLKRST_CPU_RESET_REG,               0x600B0414
.equ LP_CLKRST_FOSC_CNTL_REG,               0x600B0418
.equ LP_CLKRST_RC32K_CNTL_REG,              0x600B041C
.equ LP_CLKRST_CLK_TO_HP_REG,               0x600B0420
.equ LP_CLKRST_LPMEM_FORCE_REG,             0x600B0424
.equ LP_CLKRST_LPPERI_REG,                  0x600B0428
.equ LP_CLKRST_XTAL32K_REG,                 0x600B042C
.equ LP_CLKRST_DATE_REG,                    0x600B07FC
######################################################

######################################################
# USB Serial/JTAG Controller (USB_SERIAL_JTAG)
# (TRM 1010)
######################################################
.equ USB_SERIAL_JTAG_BASE,                  0x6000F000
# Configuration Registers
.equ USB_SERIAL_JTAG_EP1_REG,               0x6000F000
.equ USB_SERIAL_JTAG_EP1_CONF_REG,          0x6000F004
.equ USB_SERIAL_JTAG_CONF0_REG,             0x6000F018
.equ USB_SERIAL_JTAG_TEST_REG,              0x6000F01C
.equ USB_SERIAL_JTAG_MISC_CONF_REG,         0x6000F044
.equ USB_SERIAL_JTAG_MEM_CONF_REG,          0x6000F048
.equ USB_SERIAL_JTAG_CHIP_RST_REG,          0x6000F04C
.equ USB_SERIAL_JTAG_GET_LINE_CODE_W0_REG,  0x6000F058
.equ USB_SERIAL_JTAG_GET_LINE_CODE_W1_REG,  0x6000F05C
.equ USB_SERIAL_JTAG_CONFIG_UPDATE_REG,     0x6000F060
.equ USB_SERIAL_JTAG_SER_AFIFO_CONFIG_REG,  0x6000F064
# Interrupt Registers
.equ USB_SERIAL_JTAG_INT_RAW_REG,           0x6000F008
.equ USB_SERIAL_JTAG_INT_ST_REG,            0x6000F00C
.equ USB_SERIAL_JTAG_INT_ENA_REG,           0x6000F010
.equ USB_SERIAL_JTAG_INT_CLR_REG,           0x6000F014
# Status Registers
.equ USB_SERIAL_JTAG_JFIFO_ST_REG,          0x6000F020
.equ USB_SERIAL_JTAG_FRAM_NUM_REG,          0x6000F024
.equ USB_SERIAL_JTAG_IN_EP0_ST_REG,         0x6000F028
.equ USB_SERIAL_JTAG_IN_EP1_ST_REG,         0x6000F02C
.equ USB_SERIAL_JTAG_IN_EP2_ST_REG,         0x6000F030
.equ USB_SERIAL_JTAG_IN_EP3_ST_REG,         0x6000F034
.equ USB_SERIAL_JTAG_OUT_EP0_ST_REG,        0x6000F038
.equ USB_SERIAL_JTAG_OUT_EP1_ST_REG,        0x6000F03C
.equ USB_SERIAL_JTAG_OUT_EP2_ST_REG,        0x6000F040
.equ USB_SERIAL_JTAG_SET_LINE_CODE_W0_REG,  0x6000F050
.equ USB_SERIAL_JTAG_SET_LINE_CODE_W1_REG,  0x6000F054
.equ USB_SERIAL_JTAG_BUS_RESET_ST_REG,      0x6000F068
# Version Registers
.equ USB_SERIAL_JTAG_DATE_REG,              0x6000F080
######################################################

######################################################
# LED PWM Controller (LEDC)
# (TRM 1134)
######################################################
.equ LEDC_BASE,                        0x60007000
# Configuration Register
.equ LEDC_CH0_CONF0_REG,               0x60007000
.equ LEDC_CH0_CONF1_REG,               0x6000700C
.equ LEDC_CH1_CONF0_REG,               0x60007014
.equ LEDC_CH1_CONF1_REG,               0x60007020
.equ LEDC_CH2_CONF0_REG,               0x60007028
.equ LEDC_CH2_CONF1_REG,               0x60007034
.equ LEDC_CH3_CONF0_REG,               0x6000703C
.equ LEDC_CH3_CONF1_REG,               0x60007048
.equ LEDC_CH4_CONF0_REG,               0x60007050
.equ LEDC_CH4_CONF1_REG,               0x6000705C
.equ LEDC_CH5_CONF0_REG,               0x60007064
.equ LEDC_CH5_CONF1_REG,               0x60007070
.equ LEDC_EVT_TASK_EN0_REG,            0x600071A0
.equ LEDC_EVT_TASK_EN1_REG,            0x600071A4
.equ LEDC_EVT_TASK_EN2_REG,            0x600071A8
.equ LEDC_TIMER0_CMP_REG,              0x600071B0
.equ LEDC_TIMER1_CMP_REG,              0x600071B4
.equ LEDC_TIMER2_CMP_REG,              0x600071B8
.equ LEDC_TIMER3_CMP_REG,              0x600071BC
.equ LEDC_TIMER0_CNT_CAP_REG,          0x600071C0
.equ LEDC_TIMER1_CNT_CAP_REG,          0x600071C4
.equ LEDC_TIMER2_CNT_CAP_REG,          0x600071C8
.equ LEDC_TIMER3_CNT_CAP_REG,          0x600071CC
.equ LEDC_CONF_REG,                    0x600071F0
# Hpoint Register
.equ LEDC_CH0_HPOINT_REG,              0x60007004
.equ LEDC_CH1_HPOINT_REG,              0x60007018
.equ LEDC_CH2_HPOINT_REG,              0x6000702C
.equ LEDC_CH3_HPOINT_REG,              0x60007040
.equ LEDC_CH4_HPOINT_REG,              0x60007054
.equ LEDC_CH5_HPOINT_REG,              0x60007068
# Duty Cycle Register
.equ LEDC_CH0_DUTY_REG,                0x60007008
.equ LEDC_CH0_DUTY_R_REG,              0x60007010
.equ LEDC_CH1_DUTY_REG,                0x6000701C
.equ LEDC_CH1_DUTY_R_REG,              0x60007024
.equ LEDC_CH2_DUTY_REG,                0x60007030
.equ LEDC_CH2_DUTY_R_REG,              0x60007038
.equ LEDC_CH3_DUTY_REG,                0x60007044
.equ LEDC_CH3_DUTY_R_REG,              0x6000704C
.equ LEDC_CH4_DUTY_REG,                0x60007058
.equ LEDC_CH4_DUTY_R_REG,              0x60007060
.equ LEDC_CH5_DUTY_REG,                0x6000706C
.equ LEDC_CH5_DUTY_R_REG,              0x60007074
# Timer Register
.equ LEDC_TIMER0_CONF_REG,             0x600070A0
.equ LEDC_TIMER0_VALUE_REG,            0x600070A4
.equ LEDC_TIMER1_CONF_REG,             0x600070A8
.equ LEDC_TIMER1_VALUE_REG,            0x600070AC
.equ LEDC_TIMER2_CONF_REG,             0x600070B0
.equ LEDC_TIMER2_VALUE_REG,            0x600070B4
.equ LEDC_TIMER3_CONF_REG,             0x600070B8
.equ LEDC_TIMER3_VALUE_REG,            0x600070BC
# Interrupt Register
.equ LEDC_INT_RAW_REG,                 0x600070C0
.equ LEDC_INT_ST_REG,                  0x600070C4
.equ LEDC_INT_ENA_REG,                 0x600070C8
.equ LEDC_INT_CLR_REG,                 0x600070CC
# Gamma RAM Register

# Gamma Configuration Register
.equ LEDC_CH0_GAMMA_CONF_REG,          0x60007180
.equ LEDC_CH1_GAMMA_CONF_REG,          0x60007184
.equ LEDC_CH2_GAMMA_CONF_REG,          0x60007188
.equ LEDC_CH3_GAMMA_CONF_REG,          0x6000718C
.equ LEDC_CH4_GAMMA_CONF_REG,          0x60007190
.equ LEDC_CH5_GAMMA_CONF_REG,          0x60007194
# Version Register
.equ LEDC_DATE_REG,                    0x600071FC
######################################################

######################################################
# Watchdog Timers (WDT)
# (TRM 535)
######################################################
# Configuration Registers
.equ LP_WDT_BASE,                           0x600B1C00
.equ LP_WDT_RWDT_CONFIG0_REG,               0x600B1C00
.equ LP_WDT_RWDT_CONFIG1_REG,               0x600B1C04
.equ LP_WDT_RWDT_CONFIG2_REG,               0x600B1C08
.equ LP_WDT_RWDT_CONFIG3_REG,               0x600B1C0C
.equ LP_WDT_RWDT_CONFIG4_REG,               0x600B1C10
.equ LP_WDT_RWDT_FEED_REG,                  0x600B1C14
.equ LP_WDT_RWDT_WPROTECT_REG,              0x600B1C18
.equ LP_WDT_SWD_CONFIG_REG,                 0x600B1C1C
.equ LP_WDT_SWD_WPROTECT_REG,               0x600B1C20
.equ LP_WDT_INT_RAW_REG,                    0x600B1C24
.equ LP_WDT_INT_ST_REG,                     0x600B1C28
.equ LP_WDT_INT_ENA_REG,                    0x600B1C2C
.equ LP_WDT_INT_CLR_REG,                    0x600B1C30
.equ LP_WDT_DATE_REG,                       0x600B1FFC
######################################################

######################################################
# Random Number Generator (RNG)
# (TRM 705)
######################################################
.equ LPPERI_RNG_DATA_REG, 0x600B2808
######################################################