#include <avr/io.h>
#include <util/delay.h>
#include "config.h"

void switchPolarity(double delay) {
    PORTD &= ~(1 << HBRIDGE_BIT_2);
    PORTD |= (1 << HBRIDGE_BIT_1);
#ifdef USE_MICRO_SECONDS
    _delay_us(POLARITY_SWITCH_INTERVAL);
#else
    _delay_ms(delay);
#endif
    PORTD &= ~(1 << HBRIDGE_BIT_1);
    PORTD |= (1 << HBRIDGE_BIT_2);
#ifdef USE_MICRO_SECONDS
    _delay_us(POLARITY_SWITCH_INTERVAL);
#else
    _delay_ms(delay);
#endif
}

int main(void) {
    // setup pins as output
    DDRD |= (1 << HBRIDGE_BIT_1);
    DDRD |= (1 << HBRIDGE_BIT_2);

#ifdef SET_CYCLE_COUNT
    for (int i = 0; i < CYCLES; i ++)
        switchPolarity(POLARITY_SWITCH_INTERVAL);
#else
    while (1)
        switchPolarity(POLARITY_SWITCH_INTERVAL);
#endif

    // cleanup pin registers
    DDRD ^= DDRD;
    PORTD ^= PORTD;

    return 0;
}