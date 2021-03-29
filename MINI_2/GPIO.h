/*
 * GPIO.h
 *
 *  Created on: ١٧‏/٠٢‏/٢٠٢١
 *      Author: mm
 */

#ifndef GPIO_H_
#define GPIO_H_

#include "micro_config.h"
#include "std_types.h"
#include "common_macros.h"

extern unsigned char g_Interrupt_Flag ;

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/


/*
 * Description :
 * Function responsible for initialize the INT1 driver.
 */
void INT1_Init(void);

#endif /* GPIO_H_ */
