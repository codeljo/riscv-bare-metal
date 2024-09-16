//
// RGB - WS2812 Example
//

#include "bmv.h"

#define RGB0 8
#define LED_COUNT 125

void setup() {
    gpio_output_func_select(RGB0, 0x80);
    gpio_output_enable(RGB0);
    gpio_write(RGB0, 0);

    #ifdef ESP32C2
    clock_set_cpu_freq(40);
    #endif
}

int main() {
    setup();
    while (1) {

        for (int i=0; i<=LED_COUNT; i++) {
            ws2812_write(RGB0, 0x00220000);
            ws2812_write(RGB0, 0x22000000);
            ws2812_write(RGB0, 0x00002200);
        }
        delay_ms(2000);

        for (int i=0; i <= LED_COUNT; i++) {
            for (int j=0; j < LED_COUNT; j++) {
                ws2812_write(RGB0, i == j ? 0x00AA0000 : 0);
            }
            delay_ms(20);
        }

        for (int i=LED_COUNT; i >= 0; i--) {
            for (int j=0; j < LED_COUNT; j++) {
                ws2812_write(RGB0, i == j ? 0xAA000000 : 0);
            }
            delay_ms(20);
        }

        for (int i=0; i <= LED_COUNT; i++) {
            for (int j=0; j < LED_COUNT; j++) {
                ws2812_write(RGB0, i == j ? 0x0000AA00 : 0);
            }
            delay_ms(20);
        }

    }
}