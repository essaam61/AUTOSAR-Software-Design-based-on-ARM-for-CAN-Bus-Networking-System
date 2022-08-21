/**********************************************/
/*Module Name: SysTick Driver                    */
/*Author: Mahmoud Ayman / Nader Ahmed   */
/*Purpose: Initializes the SysTick timer and provides a specific periodicity to hold LEDs' status.  */
/**********************************************/

#ifndef SYSTICK_H_
#define SYSTICK_H_

#include "dio.h"
#include "can.h"
#include <stdbool.h>
#include <stdint.h>
#include <Typedefs.h>
#include "inc/hw_memmap.h"
#include "driverlib/gpio.h"
#include "driverlib/interrupt.h"
#include "driverlib/pin_map.h"
#include "driverlib/sysctl.h"
#include "driverlib/systick.h"
#include "inc/hw_types.h"
#include "inc/hw_gpio.h"
#include "tm4c123gh6pm.h"
#include "driverlib/rom_map.h"

extern bool tflag;

extern void Systick_Init (void);
extern void SysTickIntHandler(void);
extern void Systick_StartCount (void);
extern void Systick_EndCount (void);

#endif /* SYSTICK_H_ */
