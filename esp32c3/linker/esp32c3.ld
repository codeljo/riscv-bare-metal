MEMORY {
    iram0   (rwx)   : ORIGIN = 0X4037c000, LENGTH = 16k
    iram1   (rwx)   : ORIGIN = 0x40380000, LENGTH = 256k
    dram1    (rw)   : ORIGIN = 0x3fc80000 + LENGTH(iram1), LENGTH = 128k
    iucache   (x)   : ORIGIN = 0x42000000, LENGTH = 8M
    ducache   (r)   : ORIGIN = 0x3C000000, LENGTH = 8M
}

ENTRY(_start)

SECTIONS {

    .text : {
        _text_start = .;
        *(.text.init)
        *(.text)
        *(.text*)
    } > iram1
    . = ALIGN(4);

    _text_end = .;
    _text_size = _text_end - _text_start;

    .data : {
        . = ALIGN(16);
        _data_start = .;
        *(.data)
        *(.data*)
        *(.sdata)
        *(.sdata*)
        *(.rodata)
        *(.rodata*)
        . = ALIGN(16);
        _data_end = .;
    } > dram1

    _data_size = _data_end - _data_start;
    _data_loadaddr = LOADADDR(.data);

    .bss : {
        . = ALIGN(16);
        _bss_start = .;
        *(.bss)
        *(.bss*)
        *(.sbss)
        *(.sbss*)
        . = ALIGN(16);
        _bss_end = .;
    } > dram1

    _bss_size = _bss_end - _bss_start;

}

PROVIDE(rom_uart_tx = 0x4000006C);
PROVIDE(rom_uart_rx = 0x40000070);
PROVIDE(rom_printf  = 0x40000040);

/*

https://docs.espressif.com/projects/esp-idf/en/stable/esp32c3/api-guides/memory-types.html

Instruction Bus  

| Name          | Start       | End         | Size      |
| ------------- | ----------- | ----------- | --------- |
| ROM0          | 0x4000_0000 | 0x4003_FFFF | 256 kB    |
| ROM1          | 0x4004_0000 | 0x4005_FFFF | 128 kB    |
| SRAM0         | 0x4037_C000 | 0x4037_FFFF |  16 kB    |
| SRAM1         | 0x4038_0000 | 0x403D_FFFF | 384 kB    |
| RTCFAST       | 0x5000_0000 | 0x5000_1FFF |   8 kB    |
| UNIFORM_CACHE | 0x4200_0000 | 0x427F_FFFF |   8 MB    |

Data Bus  

| Name          | Start       | End         | Size               |
| ------------- | ----------- | ----------- | ------------------ |
| ROM1          | 0x3FF0_0000 | 0x3FF1_FFFF | 128 kB             |
| SRAM1         | 0x3FC8_0000 | 0x3FCD_FFFF | 384 kB             |
| RTCFAST       | 0x5000_0000 | 0x5000_1FFF |   8 kB             |
| UNIFORM_CACHE | 0x3C00_0000 | 0x3C7F_FFFF |   8 MB (read only) |

*/