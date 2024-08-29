MEMORY {
    lpram  (rwx) : ORIGIN = 0x50000000, LENGTH = 4k
    hpram  (rwx) : ORIGIN = 0x40800000, LENGTH = 160k
    dram    (rw) : ORIGIN = 0x40800000 + LENGTH(hpram), LENGTH = 160k
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


/*

https://docs.espressif.com/projects/esp-idf/en/v5.3/esp32h2/api-guides/memory-types.html

>Instruction / Data Bus  

| Name          | Start       | End         | Size      |
| ------------- | ----------- | ----------- | --------- |
| ROM0          | 0x4000_0000 | 0x4001_FFFF | 128 kB    |
| HPRAM         | 0x4080_0000 | 0x4084_FFFF | 320 kB    |
| LPRAM         | 0x5000_0000 | 0x5000_0FFF |   4 kB    |
| UNIFORM_CACHE | 0x4200_0000 | 0x42FF_FFFF |  16 MB    |

*/