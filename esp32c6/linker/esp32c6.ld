MEMORY {
    lpram  (rwx) : ORIGIN = 0x50000000, LENGTH = 16k
    hpram  (rwx) : ORIGIN = 0x40800000, LENGTH = 256k
    dram    (rw) : ORIGIN = 0x40800000 + LENGTH(hpram), LENGTH = 256k
    cache   (rx) : ORIGIN = 0x42000000, LENGTH = 16M
}

ENTRY(_start)

SECTIONS {

    .text : {
        _text_start = .;
        *(.text.init)
        *(.text)
        *(.text*)
    } > hpram
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
    } > dram

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
    } > dram

    _bss_size = _bss_end - _bss_start;

}

PROVIDE(rom_uart_tx = 0x4000005C);
PROVIDE(rom_uart_rx = 0x40000060);
PROVIDE(rom_printf  = 0x40000028);

/*

https://docs.espressif.com/projects/esp-idf/en/stable/esp32c6/api-guides/memory-types.html

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

*/