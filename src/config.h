//
// Created by daanp on 02/02/2024.
//

#ifndef MAGLEV_CONTROL_CONFIG_H
#define MAGLEV_CONTROL_CONFIG_H

// #define USE_MICRO_SECONDS
// in milliseconds, unless USE_MICRO_SECONDS is defined
#define POLARITY_SWITCH_INTERVAL 50000
//#define SET_CYCLE_COUNT
#define CYCLES 10
#define HBRIDGE_BIT_1 PORTD2
#define HBRIDGE_BIT_2 PORTD3
#define CTRL_BIT PORTD5
#define CTRL_PIN 5

#endif //MAGLEV_CONTROL_CONFIG_H
