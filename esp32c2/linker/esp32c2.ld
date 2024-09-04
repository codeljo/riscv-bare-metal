MEMORY {
    iram0   (rwx)   : ORIGIN = 0x4037C000, LENGTH = 16k
    iram1   (rwx)   : ORIGIN = 0x40380000, LENGTH = 128k
    dram1    (rw)   : ORIGIN = 0x3FCA0000 + LENGTH(iram1), LENGTH = 128k
    iucache   (x)   : ORIGIN = 0x42000000, LENGTH = 4M
    ducache   (r)   : ORIGIN = 0x3C000000, LENGTH = 4M
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

PROVIDE(rom_uart_tx = 0x4000005C);
PROVIDE(rom_uart_rx = 0x40000060);
PROVIDE(rom_printf  = 0x40000034);

/*

https://docs.espressif.com/projects/esp-idf/en/v5.3/esp32c2/api-guides/memory-types.html


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

*/