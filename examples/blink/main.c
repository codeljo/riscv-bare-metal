//
// Blink LED Example
//

#include "bmv.h"

#define LED0 12

void setup() {
    gpio_output_func_select(LED0, 0x80);
    gpio_output_enable(LED0);
}

int main() {
    setup();
    while (1)
    {
        gpio_toggle(LED0);
        delay_ms(1000);
    }
}