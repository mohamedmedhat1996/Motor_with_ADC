

#ifndef MY_KEYPAD_H_
#define MY_KEYPAD_H_

#include "std_types.h"
#include "micro_config.h"
#include "common_macros.h"

/* Keypad configurations for number of rows and columns */
#define N_col 4
#define N_row 4

/* Keypad Port Configurations */
#define KEYPAD_PORT_OUT PORTA
#define KEYPAD_PORT_IN  PINA
#define KEYPAD_PORT_DIR DDRA


uint8 Keypad_getPressedKey();

#endif /* MY_KEYPAD_H_ */
