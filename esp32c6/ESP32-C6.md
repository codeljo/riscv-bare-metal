# ESP32-C6

<br>

# Table of Contents
[CPU](#esp32-c6)  
[Memory Map](#memory-map)  
[esptool.py](#esptoolpy)  
[gen_esp32part.py](#gen_esp32partpy)  
[Linker Script](#linker-script)  
[References](#references)   
<br>

# CPU
><br>ESP32-C6  
32-bit RISC-V single-core microprocessor  
RV32IMAC ISA  
Clock frequency of up to 160 MHz  
<br>

<br>

# Memory Map

>Instruction Bus  

| Name          | Start       | End         | Size      |
| ------------- | ----------- | ----------- | --------- |
| ROM0          | 0x4000_0000 | 0x4004_FFFF | 320 kB    |
| HPRAM         | 0x4080_0000 | 0x4087_FFFF | 512 kB    |
| LPRAM         | 0x5000_0000 | 0x5000_3FFF |  16 kB    |
| UNIFORM_CACHE | 0x4200_0000 | 0x42FF_FFFF |  16 MB    |

>Data Bus  

| Name          | Start       | End         | Size      |
| ------------- | ----------- | ----------- | --------- |
| ROM0          | 0x4000_0000 | 0x4004_FFFF | 320 kB    |
| HPRAM         | 0x4080_0000 | 0x4087_FFFF | 512 kB    |
| LPRAM         | 0x5000_0000 | 0x5000_3FFF |  16 kB    |
| UNIFORM_CACHE | 0x4200_0000 | 0x42FF_FFFF |  16 MB    |

> Peripherals (Data Bus)

| Name                          | Base        |
| ----------------------------- | ----------- |
| UART0                         | 0x6000_0000 |
| UART1                         | 0x6000_1000 |
| SPI0                          | 0x6000_2000 |
| SPI1                          | 0x6000_3000 |
| I2C_EXT                       | 0x6000_4000 |
| UHCI0                         | 0x6000_5000 |
| RMT                           | 0x6000_6000 |
| LEDC                          | 0x6000_7000 |
| TIMERGROUP0                   | 0x6000_8000 |
| TIMERGROUP1                   | 0x6000_9000 |
| SYSTIMER                      | 0x6000_A000 |
| TWAI0                         | 0x6000_B000 |
| I2S                           | 0x6000_C000 |
| TWAI1                         | 0x6000_D000 |
| APB_SARADC                    | 0x6000_E000 |
| USB_SERIAL_JTAG               | 0x6000_F000 |
| INTERRUPT_MATRIX              | 0x6001_0000 |
| PCNT                          | 0x6001_2000 |
| SOC_ETM                       | 0x6001_3000 |
| PWM                           | 0x6001_4000 |
| PARALEL_IO                    | 0x6001_5000 |
| SDIO_HINF                     | 0x6001_6000 |
| SDIO_SLC                      | 0x6001_7000 |
| SDIO_SLCHOST                  | 0x6001_8000 |
| GDMA                          | 0x6008_0000 |
| GP-SPI2                       | 0x6008_1000 |
| AES                           | 0x6008_8000 |
| SHA                           | 0x6008_9000 |
| RSA                           | 0x6008_A000 |
| ECC                           | 0x6008_B000 |
| DIGITAL_SIGNATURE             | 0x6008_C000 |
| HMAC                          | 0x6008_D000 |
| IO_MUX                        | 0x6009_0000 |
| GPIO (matrix)                 | 0x6009_1000 |
| GPIO_EXT                      | 0x6009_1F00 |
| MEM_MONITOR                   | 0x6009_2000 |
| HP_SYSTEM                     | 0x6009_5000 |
| PCR (power clock reset)       | 0x6009_6000 |
| TEE (trusted execution)       | 0x6009_8000 |
| HP_APM                        | 0x6009_9000 |
| LP_APM0                       | 0x6009_9800 |
| PWDET_CONF                    | 0x600A_8010 |
| I2C_ANA_MST                   | 0x600A_F800 |
| PMU                           | 0x600B_0000 |
| LP_CLKRST                     | 0x600B_0400 |
| EFUSE                         | 0x600B_0800 |
| LP_TIMER                      | 0x600B_0C00 |
| LP_AON                        | 0x600B_1000 |
| LP_UART                       | 0x600B_1400 |
| LP_I2C                        | 0x600B_1800 |
| LP_WDT                        | 0x600B_1C00 |
| LP_IO_MUX                     | 0x600B_2000 |
| LP_I2C_ANA_MST                | 0x600B_2400 |
| LP_PERI                       | 0x600B_2800 |
| LP_ANA_PERI                   | 0x600B_2C00 |
| LP_TEE                        | 0x600B_3400 |
| LP_APM                        | 0x600B_3800 |
| OPT_DEBUG                     | 0x600B_3C00 |
| TRACE (Risc-V trace encoder)  | 0x600C_0000 |
| ASIST_DEBUG (CPU_BUS_MONITOR) | 0x600C_2000 |
| INTPRI (Interrupt priority)   | 0x600C_5000 |
| EXT_MEM                       | 0x600C_8000 |
|                               | 0x600C_FFFF |

<br>

# esptool.py

**chip_id**
```
python esptool.py --port /dev/ttyACM0 chip_id
```

**read_mem**
```
python esptool.py --port /dev/ttyACM0 read_mem 0x40381000
```

**elf2image**
```
python esptool.py -chip esp32c6 elf2image --flash_mode qio --flash_freq 80m --flash_size 4MB main.elf -o main.bin
```

**image_info**
```
python esptool.py image_info --version 2 main.bin
```

**load_ram**
```
python esptool.py --chip esp32c6 --port /dev/ttyACM0 --no-stub load_ram main.bin
```
<br>

**write_flash**
```
python esptool.py --chip esp32c6 --port /dev/ttyACM0 --no-stub write_flash 0x0 main.e2i
```
<br>

# gen_esp32part.py
**partitions**
```
python gen_esp32part.py -q partitions.csv partitions.bin
```
<br>

# objdump, readelf
```
llvm-objdump --all-headers main.elf

readelf -a main.elf
```
<br>

# Create bootloader from .elf with elf2image
```
python esptool.py --chip esp32c6 elf2image --flash_mode qio --flash_freq 80m --flash_size 4MB bootloader.elf -o bootloader.bin
```
<br>

<br>

# References

**Datasheet**  
[https://www.espressif.com/sites/default/files/documentation/esp32-c6_datasheet_en.pdf](https://www.espressif.com/sites/default/files/documentation/esp32-c6_datasheet_en.pdf)  

**Technical Reference Manual**  
[https://www.espressif.com/sites/default/files/documentation/esp32-c6_technical_reference_manual_en.pdf](https://www.espressif.com/sites/default/files/documentation/esp32-c6_technical_reference_manual_en.pdf)  

**esptool**  
[https://github.com/espressif/esptool](https://github.com/espressif/esptool)  
[https://github.com/espressif/esptool/releases](https://github.com/espressif/esptool/releases)

**Arduino core for the ESP32**  
[https://github.com/espressif/arduino-esp32](https://github.com/espressif/arduino-esp32)  

**Misc**  
[https://en.wikipedia.org/wiki/ESP32#ESP32-C6](https://en.wikipedia.org/wiki/ESP32#ESP32-C6)  

<br>
