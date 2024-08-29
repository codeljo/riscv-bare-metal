//
// PWM LED Example
//

#include "bmv.h"

#define LED0 12
#define LED1 13

void setup() {
    // 80000000 ÷ (0b1111111111 × 2¹⁶) = 1.19 Hz, duty range: 0 - 2¹⁸−1 = 0x3FFFF, 50%(0x1FFFF) 100%(0x3FFFF)
    #ifdef ESP32C3
    pwm_config_t pwm_config_0 = { .pin=LED0, .clock=PWM_CLOCK_APB, .divisor=PWM_DIVISOR_MAX, .resolution=PWM_RESOLUTION_MAX, .duty=0x1FFFF };
    pwm_channel_0_init(&pwm_config_0);
    #endif

    #ifdef ESP32C6
    pwm_config_t pwm_config_0 = { .pin=LED0, .clock=PWM_CLOCK_XTAL, .divisor=0x3F00, .resolution=PWM_RESOLUTION_MAX, .duty=0x7FFFFF };
    pwm_channel_0_init(&pwm_config_0);
    #endif

    #ifdef ESP32H2
    pwm_config_t pwm_config_0 = { .pin=LED0, .clock=PWM_CLOCK_XTAL, .divisor=0x1F00, .resolution=PWM_RESOLUTION_MAX, .duty=0x7FFFFF };
    pwm_channel_0_init(&pwm_config_0);
    #endif
}

int main() {
    setup();
    while (1)
    {
        delay_ms(500);
    }
}