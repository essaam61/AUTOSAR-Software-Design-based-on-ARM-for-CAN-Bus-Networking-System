/**********************************************/
/*Module Name: GPT Driver                         */
/*Author: Ahmed Hatem                               */
/*Purpose:  Configures a Timer as a 16-bit periodic counter with an interrupt every 10ms.  */
/**********************************************/


#ifndef TIMER_LBCFG_H_
#define TIMER_LBCFG_H_

#include <stdbool.h>
#include <stdint.h>
#include <Typedefs.h>
#include "tm4c123gh6pm.h"
#include "inc/hw_memmap.h"
#include "driverlib/gpio.h"
#include "driverlib/interrupt.h"
#include "driverlib/pin_map.h"
#include "driverlib/sysctl.h"
#include "driverlib/timer.h"
#include "inc/hw_types.h"
#include "driverlib/rom_map.h"

#define TIMERPeripheral SYSCTL_PERIPH_TIMER0
#define TIMERChannel TIMER0_BASE
#define TIMERConfig TIMER_CFG_SPLIT_PAIR | TIMER_CFG_B_PERIODIC
#define SubTimer TIMER_B
#define TIMERIntFlag TIMER_TIMB_TIMEOUT
#define TIMERChannel_Interrupt INT_TIMER0B


#endif /* TIMER_LBCFG_H_ */
