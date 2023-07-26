#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "pico/binary_info.h"

const uint PIN_TILT = 15;
const uint PIN_LED_RED = 12;
const uint PIN_LED_YELLOW = 13;

int main() {
	bi_decl(bi_program_description("This is a program to light LEDs depending on tilt sensor"));
	
	stdio_init_all();
	
	gpio_init(PIN_TILT);
	gpio_set_dir(PIN_TILT, GPIO_IN);
	
	gpio_init(PIN_LED_RED);
	gpio_set_dir(PIN_LED_RED, GPIO_OUT);
	
	gpio_init(PIN_LED_YELLOW);
	gpio_set_dir(PIN_LED_YELLOW, GPIO_OUT);
	
	while(1) {
		if (gpio_get(PIN_TILT)) {
			gpio_put(PIN_LED_YELLOW, 0);
			gpio_put(PIN_LED_RED, 1);
		} else {
			gpio_put(PIN_LED_RED, 0);
			gpio_put(PIN_LED_YELLOW, 1);
		}
		
		sleep_ms(5);
	}
}

