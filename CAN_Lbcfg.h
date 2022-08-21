/**********************************************/
/*Module Name: CAN Driver                        */
/*Author: Mahmoud Ayman / Nader Ahmed  */
/*Purpose: Initializes and configures the required sets of the CAN module.  */
/**********************************************/

#ifndef CAN_LBCFG_H_
#define CAN_LBCFG_H_

#include <Port.h>
#include "can.h"
#include "Dio_Lbcfg.h"
#include <stdbool.h>
#include <stdint.h>
#include <Typedefs.h>
#include "inc/hw_can.h"
#include "inc/hw_ints.h"
#include "inc/hw_memmap.h"
#include "driverlib/can.h"
#include "driverlib/gpio.h"
#include "driverlib/interrupt.h"
#include "driverlib/pin_map.h"
#include "driverlib/sysctl.h"
#include "inc/hw_types.h"
#include "inc/hw_gpio.h"


#define Msg1TX_Object 1
#define Msg2TX_Object 2
#define Msg3TX_Object 3

#define MsgIDMask 0
#define Msg1_ID 0x1001
#define Msg2_ID 0x2001
#define Msg3_ID 0x3001


#define CAN_GPIOPort PortB
#define GPIO_RXPin Pin_4
#define GPIO_TXPin Pin_5

#define CANChannel CAN0_BASE
#define CANChannel_Interrupt INT_CAN0


#endif
