
#ifndef TIMER_H_
#define TIMER_H_

#include "std_types.h"
#include "micro_config.h"
#include "common_macros.h"
/*******************************************************************************
 *                      Preprocessor Macros                                    *
 *******************************************************************************/
#define Full_duty_cycle 256
#define Half_duty_cycle 128
#define stop_motor      0


/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
void PWM_init(void);


#endif /* TIMER_H_ */
