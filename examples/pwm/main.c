//
// PWM LED Example
//

#include "bmv.h"

#define LED0 12
#define LED1 13

void setup() {
    // 80000000 ÷ (0b1111111111 × 2¹⁶) = 1.19 Hz
    // duty range: 0 - 2¹⁸−1 = 0x3FFFF
    // 50%(0x1FFFF), 100%(0x3FFFF)
    pwm_config_t pwm_config_0 = { .pin=LED0, .clock=PWM_CLOCK_APB, .divisor=PWM_DIVISOR_MAX, .resolution=PWM_RESOLUTION_MAX, .duty=0x1FFFF };
    pwm_channel_0_init(&pwm_config_0);
}

int main() {
    setup();
    while (1)
    {
        delay_ms(500);
    }
}