/**********************************************/
/*Module Name: SysTick Driver                    */
/*Author: Mostafa Khaled                             */
/*Purpose: Initializes the SysTick timer and provides a periodic interrupt to send CAN messages.  */
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
#include "driverlib/uart.h"
#include "inc/hw_types.h"
#include "inc/hw_gpio.h"
#include "inc/hw_ints.h"
#include "driverlib/rom_map.h"

extern void Systick_Init (void);

#endif /* SYSTICK_H_ */
