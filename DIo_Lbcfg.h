/**********************************************/
/*Module Name: DIO Driver                         */
/*Author: Mostafa Khaled / Ahmed Essam  */
/*Purpose: Initializes the ports and pins required to configure the DIO output LEDs.      */
/**********************************************/

#ifndef DIO_LBCFG_H_
#define DIO_LBCFG_H_

#include <Port_Lbcfg.h>
#include <stdbool.h>
#include <stdint.h>
#include <Typedefs.h>
#include "inc/hw_memmap.h"
#include "driverlib/gpio.h"
#include "driverlib/interrupt.h"
#include "driverlib/pin_map.h"
#include "driverlib/sysctl.h"
#include "driverlib/rom_map.h"
#include "inc/hw_types.h"
#include "inc/hw_gpio.h"


#define GPIO_Port GPIO_PORTF_BASE
#define Channel_0 GPIO_PIN_1    /* Pin 1 represents Red LED on Port F */
#define Channel_1 GPIO_PIN_2    /* Pin 2 represents Blue LED on Port F */
#define Channel_2 GPIO_PIN_3    /* Pin 3 represents Green LED on Port F */

#define STD_HIGH 0x01
#define STD_LOW 0x00


#endif /* DIO_LBCFG_H_ */
