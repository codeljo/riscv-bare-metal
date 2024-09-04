//
// UART Example
//
// note: If building for ESP32-C2 board with 26 MHz external crystal BMV_XTAL must be defined.
//       make -C examples/uart/ clean flash BMV_CHIP=esp32c2 BMV_PORT=/dev/ttyUSB0 BMV_XTAL=26
//

#include "bmv.h"

/* USE_USB_CDC 0 - if using the dev boards USB port labeled 'UART' */
/* USE_USB_CDC 1 - if using the dev boards USB port labeled 'USB'  */
#define USE_USB_CDC 0

void setup() {
}

int main() {
    setup();
    while (1) {

        rom_printf("%s\r\n", "Hello from RISC-V");
        delay_ms(1000);

#if USE_USB_CDC == 1
        /*
        if (usb_cdc_is_write_ready()) {
            usb_cdc_write('A');
            usb_cdc_write('\r');
            usb_cdc_write('\n');
            usb_cdc_write_flush();
        }
        */
        if (usb_cdc_is_read_ready()) {
            char rx = usb_cdc_read();
            rom_printf("usb_cdc_read: 0x%02X %u %c\r\n", (unsigned int)rx, (unsigned int)rx, rx);
        }
#else
        /*
        rom_uart_tx('B');
        rom_uart_tx('\r');
        rom_uart_tx('\n');
        */
        unsigned char rx = 0;
        if (rom_uart_rx(&rx) == 0) {
            rom_printf("rom_uart_rx: 0x%02X %u %c\r\n", (unsigned int)rx, (unsigned int)rx, rx);
        }
#endif

    }
}
