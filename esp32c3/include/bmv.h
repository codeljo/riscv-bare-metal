#pragma once

#define ESP32C3

/////////////////////////////////////////////////////
// clock
/////////////////////////////////////////////////////

/* set CPU clock frequency to 20, 80, or 160 MHz */
void clock_set_cpu_freq(int mhz);

/////////////////////////////////////////////////////
// gpio
/////////////////////////////////////////////////////

void gpio_input_enable(int pin);
int gpio_read(int pin);
void gpio_output_enable(int pin);
void gpio_output_func_select(int pin, int func);
void gpio_write(int pin, int val);
void gpio_toggle(int pin);

int random();

/////////////////////////////////////////////////////
// interrupts
/////////////////////////////////////////////////////

/* enable interrupts */
void interrupts_enable();
/* disable interrupts */
void interrupts_disable();

/////////////////////////////////////////////////////
// pwm
/////////////////////////////////////////////////////

#define PWM_DIVISOR_MAX    0x3FF00
#define PWM_RESOLUTION_MAX 0xE
#define PWM_DUTY_MAX       0x3FFFF
#define PWM_CLOCK_APB    1
#define PWM_CLOCK_RCFAST 2
#define PWM_CLOCK_XTAL   3

typedef struct
{
    int pin;
    int clock;
    int divisor;
    int resolution;
    int duty;
} pwm_config_t;

void pwm_channel_0_init(pwm_config_t * config);
void pwm_channel_1_init(pwm_config_t * config);
int pwm_duty_update(int channel, int duty);

/////////////////////////////////////////////////////
// systimer
/////////////////////////////////////////////////////

/* delay microseconds */
void delay_us(unsigned int);
/* delay milliseconds */
void delay_ms(unsigned int);

/////////////////////////////////////////////////////
// usb cdc serial
/////////////////////////////////////////////////////

char usb_cdc_read();
int usb_cdc_is_read_ready();
int usb_cdc_write(char val);
int usb_cdc_is_write_ready();
void usb_cdc_write_flush();

/////////////////////////////////////////////////////
// spi via software
/////////////////////////////////////////////////////

//void spi_sw_init(int cs, int sck, int mosi, int miso);
//void spi_sw_tx_byte(unsigned char val);
//unsigned char spi_sw_rx_byte();
//void spi_sw_pulse_cs();
//void spi_sw_pulse_clock();

/////////////////////////////////////////////////////
// rgb - ws2812
/////////////////////////////////////////////////////

void ws2812_write(int pin, unsigned int grbx);

/////////////////////////////////////////////////////
// wdt
/////////////////////////////////////////////////////

/* feed WDT */
void wdt_feed();
/* disable WDT */
void wdt_disable();
