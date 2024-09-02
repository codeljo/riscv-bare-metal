# ESP32-C2

<br>

# Table of Contents
[CPU](#esp32-c2)  
[Memory Map](#memory-map)  
[esptool.py](#esptoolpy)  
[gen_esp32part.py](#gen_esp32partpy)  
[Linker Script](#linker-script)  
[References](#references)   
<br>

# CPU
><br>ESP32-C2  
32-bit RISC-V single-core microprocessor  
RV32IMC ISA  
Clock frequency of up to 120 MHz  
<br>

<br>

# Memory Map

>Instruction Bus  

| Name          | Start       | End         | Size      |
| ------------- | ----------- | ----------- | --------- |
| ROM0          | 0x4000_0000 | 0x4003_FFFF | 256 kB    |
| ROM1          | 0x4004_0000 | 0x4008_FFFF | 320 kB    |
| SRAM0         | 0x4037_C000 | 0x4037_FFFF |  16 kB    |
| SRAM1         | 0x4038_0000 | 0x403B_FFFF | 256 kB    |
| UNIFORM_CACHE | 0x4200_0000 | 0x423F_FFFF |   4 MB    |

>Data Bus

| Name          | Start       | End         | Size      |
| ------------- | ----------- | ----------- | --------- |
| ROM1          | 0x3FF0_0000 | 0x3FF4_FFFF | 320 kB    |
| SRAM1         | 0x3FCA_0000 | 0x3FCD_FFFF | 256 kB    |
| UNIFORM_CACHE | 0x3C00_0000 | 0x3C3F_FFFF |   4 MB    |

> Peripherals (Instruction / Data Bus)

| Name                           | Base        |
| ------------------------------ | ----------- |
| UART0                          | 0x6000_0000 |
| SPI1                           | 0x6000_2000 |
| SPI0                           | 0x6000_3000 |
| GPI0                           | 0x6000_4000 |
| RTC_CNTL                       | 0x6000_8000 |
| IO_MUX                         | 0x6009_0000 |
| UART1                          | 0x6001_0000 |
| I2C                            | 0x6001_3000 |
| LEDC                           | 0x6001_9000 |
| TIMG0                          | 0x6001_F000 |
| SYSTIMER                       | 0x6002_3000 |
| SPI2                           | 0x6002_4000 |
| SYSCON                         | 0x6002_6000 |
| SHA                            | 0x6003_B000 |
| ECC                            | 0x6003_E000 |
| GDMA                           | 0x6003_F000 |
| ADC                            | 0x6004_0000 |
| SYSTEM                         | 0x600C_0000 |
| SENSITIVE                      | 0x600C_1000 |
| INTMTRX                        | 0x600C_2000 |
| Configure Cache                | 0x600C_4000 |
| ASSIST_DEBUG                   | 0x600C_E000 |

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
python esptool.py -chip esp32c2 elf2image --flash_mode dio --flash_freq 48m --flash_size 4MB main.elf -o main.bin
```

**image_info**
```
python esptool.py image_info --version 2 main.bin
```

**load_ram**
```
python esptool.py --chip esp32c2 --port /dev/ttyACM0 --no-stub load_ram main.bin
```
<br>

**write_flash**
```
python esptool.py --chip esp32c2 --port /dev/ttyACM0 --no-stub write_flash 0x0 main.e2i
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
python esptool.py --chip esp32c2 elf2image --flash_mode dio --flash_freq 48m --flash_size 4MB bootloader.elf -o bootloader.bin
```
<br>

<br>

# References

**Datasheet**  
[https://www.espressif.com/sites/default/files/documentation/esp8684_datasheet_en.pdf](https://www.espressif.com/sites/default/files/documentation/esp8684_datasheet_en.pdf)  

**Technical Reference Manual**  
[https://www.espressif.com/sites/default/files/documentation/esp8684_technical_reference_manual_en.pdf](https://www.espressif.com/sites/default/files/documentation/esp8684_technical_reference_manual_en.pdf)  

**esptool**  
[https://github.com/espressif/esptool](https://github.com/espressif/esptool)  
[https://github.com/espressif/esptool/releases](https://github.com/espressif/esptool/releases)

**Arduino core for the ESP32**  
[https://github.com/espressif/arduino-esp32](https://github.com/espressif/arduino-esp32)  

**Misc**  
[https://en.wikipedia.org/wiki/ESP32#ESP32-C2](https://en.wikipedia.org/wiki/ESP32#ESP32-C2)  

<br>
