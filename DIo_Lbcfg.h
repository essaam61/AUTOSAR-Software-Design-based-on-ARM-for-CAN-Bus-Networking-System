/**********************************************/
/*Module Name: DIO Driver                         */
/*Author: Mahmoud Ayman / Nader Ahmed  */
/*Purpose: Initializes the ports and pins required to configure the DIO input switches.     */
/**********************************************/

#ifndef DIO_LBCFG_H_
#define DIO_LBCFG_H_

#include <stdbool.h>
#include <stdint.h>
#include <Typedefs.h>
#include <Port.h>
#include "inc/hw_memmap.h"
#include "driverlib/gpio.h"
#include "driverlib/interrupt.h"
#include "inc/hw_ints.h"
#include "driverlib/pin_map.h"
#include "driverlib/sysctl.h"
#include "driverlib/rom_map.h"
#include "inc/hw_types.h"
#include "inc/hw_gpio.h"


#define GPIO_Port PortF
#define Channel_0 Pin_0   /* Pin 0 represents SW2 on Port F */
#define Channel_1 Pin_4    /* Pin 4 represents SW1 on Port F */
#define GPIOPort_Interrupt INT_GPIOF

#define STD_HIGH 0x00
#define STD_LOW 0x01


#endif /* DIO_LBCFG_H_ */
