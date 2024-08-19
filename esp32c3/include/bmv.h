#pragma once

// clock
void clock_set_cpu_freq();
void delay(int val);

// gpio
void gpio_input_enable(int pin);
int gpio_read(int pin);
void gpio_output_enable(int pin);
void gpio_output_func_select(int pin, int func);
void gpio_write(int pin, int val);
void gpio_toggle(int pin);

int random();

// interrupts
void interrupts_enable();
void interrupts_disable();

// usb cdc
char usb_cdc_read();
void usb_cdc_write(char val);
void usb_cdc_write_flush();

// wdt
void wdt_feed();
void wdt_disable();
