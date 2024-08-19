# ESP32-C3

<br>

# Table of Contents
[CPU](#esp32-c3)  
[Memory Map](#memory-map)  
[esptool.py](#esptoolpy)  
[gen_esp32part.py](#gen_esp32partpy)  
[Linker Script](#linker-script)  
[References](#references)   
<br>

# CPU
><br>ESP32-C3  
32-bit RISC-V single-core microprocessor  
RV32IMC ISA  
Clock frequency of up to 160 MHz  
<br>

<br>

# Memory Map

>Instruction Bus  

| Name          | Start       | End         | Size      |
| ------------- | ----------- | ----------- | --------- |
| ROM0          | 0x4000_0000 | 0x4003_FFFF | 256 kB    |
| ROM1          | 0x4004_0000 | 0x4005_FFFF | 128 kB    |
| SRAM0         | 0x4037_C000 | 0x4037_FFFF |  16 kB    |
| SRAM1         | 0x4038_0000 | 0x403D_FFFF | 384 kB    |
| RTCFAST       | 0x5000_0000 | 0x5000_1FFF |   8 kB    |
| UNIFORM_CACHE | 0x4200_0000 | 0x427F_FFFF |   8 MB    |

>Data Bus  

| Name          | Start       | End         | Size      |
| ------------- | ----------- | ----------- | --------- |
| ROM1          | 0x3FF0_0000 | 0x3FF1_FFFF | 128 kB    |
| SRAM1         | 0x3FC8_0000 | 0x3FCD_FFFF | 384 kB    |
| RTCFAST       | 0x5000_0000 | 0x5000_1FFF |   8 kB    |
| UNIFORM_CACHE | 0x3C00_0000 | 0x3C7F_FFFF |   8 MB (read only) |

> Peripherals (Data Bus)

| Name               | Base        |
| ------------------ | ----------- |
| UART0              | 0x6000_0000 |
| SPI1               | 0x6000_2000 |
| SPI0               | 0x6000_3000 |
| GPIO               | 0x6000_4000 |
| FE2                | 0x6000_5000 |
| FE                 | 0x6000_6000 |
| TIMER              | 0x6000_7000 |
| RTCCNTL            | 0x6000_8000 |
| EFUSE              | 0x6000_8800 |
| IO_MUX             | 0x6000_9000 |
| RTC_I2C            | 0x6000_E000 |
| UART1              | 0x6001_0000 |
| I2C_EXT            | 0x6001_3000 |
| UHCI0              | 0x6001_4000 |
| RMT                | 0x6001_6000 |
| LEDC               | 0x6001_9000 |
| NRX                | 0x6001_CC00 |
| BB                 | 0x6001_D000 |
| TIMERGROUP0        | 0x6001_F000 |
| TIMERGROUP1        | 0x6002_0000 |
| SYSTIMER           | 0x6002_3000 |
| SPI2               | 0x6002_4000 |
| SYSCON (APB)       | 0x6002_6000 |
| TWAI               | 0x6002_B000 |
| I2S0               | 0x6002_D000 |
| AES                | 0x6003_A000 |
| SHA                | 0x6003_B000 |
| RSA                | 0x6003_C000 |
| HMAC               | 0x6003_E000 |
| DIGITAL_SIGNATURE  | 0x6003_D000 |
| GDMA               | 0x6003_F000 |
| SARADC             | 0x6004_0000 |
| USB_SERIAL_JTAG    | 0x6004_3000 |
| SYSTEM_REGS        | 0x600C_0000 |
| SENSITIVE_REGS     | 0x600C_1000 |
| INTERRUPT_MATRIX   | 0x600C_2000 |
| CACHE (32k)        | 0x600C_4000 |
| EXT_MEM_ENC_DEC    | 0x600C_C000 |
| ASSIST_DEBUG       | 0x600C_E000 |
| WORLDC             | 0x600D_0000 |

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
python esptool.py -chip esp32c3 elf2image --flash_mode dio --flash_freq 80m --flash_size 4MB main.elf -o main.bin
```

**image_info**
```
python esptool.py image_info --version 2 main.bin
```

**load_ram**
```
python esptool.py --chip esp32c3 --port /dev/ttyACM0 --no-stub load_ram main.bin
```
<br>

**write_flash**
```
python esptool.py --chip esp32c3 --port /dev/ttyACM0 --no-stub write_flash 0x0 main.e2i
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
python esptool.py --chip esp32c3 elf2image --flash_mode dio --flash_freq 80m --flash_size 4MB bootloader.elf -o bootloader.bin
```
<br>

<br>

# References

**Datasheet**  
[https://www.espressif.com/sites/default/files/documentation/esp32-c3_datasheet_en.pdf](https://www.espressif.com/sites/default/files/documentation/esp32-c3_datasheet_en.pdf)  

**Technical Reference Manual**  
[https://www.espressif.com/sites/default/files/documentation/esp32-c3_technical_reference_manual_en.pdf](https://www.espressif.com/sites/default/files/documentation/esp32-c3_technical_reference_manual_en.pdf)  

**esptool**  
[https://github.com/espressif/esptool](https://github.com/espressif/esptool)  
[https://github.com/espressif/esptool/releases](https://github.com/espressif/esptool/releases)

**Arduino core for the ESP32**  
[https://github.com/espressif/arduino-esp32](https://github.com/espressif/arduino-esp32)  

**Misc**  
[https://en.wikipedia.org/wiki/ESP32#ESP32-C3](https://en.wikipedia.org/wiki/ESP32#ESP32-C3)  

<br>
