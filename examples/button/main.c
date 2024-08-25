//
// Button Example
// GPIO9 is the 'BOOT' button on C3, C6 boards
//

#include "bmv.h"

#define LED0 12
#define BUTTON0 9

void setup() {
    gpio_output_func_select(LED0, 0x80);
    gpio_output_enable(LED0);
    gpio_input_enable(BUTTON0);
}

int main() {
    setup();
    while (1)
    {
        // toggle led if button(active low) is pressed
        if (!gpio_read(BUTTON0)) {
            gpio_toggle(LED0);
        }
        delay_ms(250);
    }
}