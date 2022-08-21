/**********************************************/
/*Module Name: Read-Transport Protocol Software Component   */
/*Author: Mostafa Khaled                             */
/*Purpose: Reads the switches' states and provides a periodic interrupt to send CAN messages.        */
/**********************************************/

#ifndef RTP_H_
#define RTP_H_

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



#define Switch2 0
#define Switch1 1

extern void App_RP_Init (void);
extern void App_RP(void);

#endif /* RTP_H_ */
