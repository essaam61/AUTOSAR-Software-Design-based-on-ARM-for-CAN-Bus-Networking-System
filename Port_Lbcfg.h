/**********************************************/
/*Module Name: PORT Driver                      */
/*Author: Ahmed Essam / Nader Ahmed / Mahmoud Ayman */
/*Purpose: Initializes the ports and pins required to configure the DIO input switches.     */
/**********************************************/

#ifndef PORT_LBCFG_H_
#define PORT_LBCFG_H_

#include <stdbool.h>
#include <stdint.h>
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

#define DIO 0
#define CAN 1

#define GPIO_CR_NO 0x1F
#define PortA GPIO_PORTA_BASE
#define PortB GPIO_PORTB_BASE
#define PortC GPIO_PORTC_BASE
#define PortD GPIO_PORTD_BASE
#define PortE GPIO_PORTE_BASE
#define PortF GPIO_PORTF_BASE

#define Pin_0 GPIO_PIN_0
#define Pin_1 GPIO_PIN_1
#define Pin_2 GPIO_PIN_2
#define Pin_3 GPIO_PIN_3
#define Pin_4 GPIO_PIN_4
#define Pin_5 GPIO_PIN_5
#define Pin_6 GPIO_PIN_6
#define Pin_7 GPIO_PIN_7

#define ClkFreq 25000000
#define BR 500000


#endif /* PORT_LBCFG_H_ */
