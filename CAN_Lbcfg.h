/**********************************************/
/*Module Name: CAN Driver                        */
/*Author: Ahmed Essam / Ahmed Hatem    */
/*Purpose: Initializes and configures the required sets of the CAN module.  */
/**********************************************/

#ifndef CAN_LBCFG_H_
#define CAN_LBCFG_H_

#include <Port.h>
#include <stdbool.h>
#include <stdint.h>
#include <Typedefs.h>
#include "inc/hw_can.h"
#include "inc/hw_memmap.h"
#include "driverlib/can.h"
#include "driverlib/gpio.h"
#include "driverlib/interrupt.h"
#include "driverlib/pin_map.h"
#include "driverlib/sysctl.h"
#include "inc/hw_types.h"
#include "inc/hw_gpio.h"
#include "tm4c123gh6pm.h"


#define MsgIDMask 0xfffff
#define Msg1_ID 0x2001
#define Msg2_ID 0x3001

#define Msg1RX_Object 1
#define Msg2RX_Object 2


#define CAN_GPIOPort PortB
#define GPIO_RXPin Pin_4
#define GPIO_TXPin Pin_5

#define CANChannel CAN0_BASE
#define CANChannel_Interrupt INT_CAN0


#define SW_HIGH 0x00
#define SW_LOW 0x01


#endif
