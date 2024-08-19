//
// USB CDC Serial Example
//

#include "bmv.h"

#define LED0 12
#define DELAY 0xFF

void setup() {
    gpio_output_func_select(LED0, 0x80);
    gpio_output_enable(LED0);
}

int main() {
    
    setup();
    
    while (1) {

        delay(DELAY);
        
        // toggle LED0 on data received, echo back any received data
        if (usb_cdc_is_read_ready()) {
            char c = usb_cdc_read();
            usb_cdc_write(c);
            if (c == '\r') {
                usb_cdc_write('\n');
            }
            gpio_toggle(LED0);
            usb_cdc_write_flush();
        }

    }

}