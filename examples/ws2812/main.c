//
// RGB - WS2812 Example
//

#include "bmv.h"

#define RGB0 8

void setup() {
    gpio_output_func_select(RGB0, 0x80);
    gpio_output_enable(RGB0);
    gpio_write(RGB0, 0);
}

int main() {
    setup();
    while (1)
    {

        // cycle red, green, blue
        // WS2812  (GRB)     GGRRBBxx
        delay_ms(2000);
        ws2812_write(RGB0, 0x00FF0000);
        delay_ms(2000);
        ws2812_write(RGB0, 0xFF000000);
        delay_ms(2000);
        ws2812_write(RGB0, 0x0000FF00);
        delay_ms(2000);

        // fade in, fade out - blue
        ws2812_write(RGB0, 0);
        delay_ms(2000);
        for (unsigned int i = 0; i <= 0xFF00; i += 0x100)
        {
            ws2812_write(RGB0, i);
            delay_ms(8);
        }
        delay_ms(2000);
        for (unsigned int i = 0xFF00; ; i -= 0x100)
        {
            ws2812_write(RGB0, i);
            delay_ms(8);
            if (i == 0) { break; }
        }
        
    }
}