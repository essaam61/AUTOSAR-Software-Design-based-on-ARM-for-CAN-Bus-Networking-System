/**********************************************/
/*Module Name: PORT Driver                      */
/*Author: Ahmed Essam / Nader Ahmed / Mahmoud Ayman */
/*Purpose: Initializes the ports and pins required to configure the DIO input switches.     */
/**********************************************/

#ifndef PORT_H_
#define PORT_H_

#include "Typedefs.h"
#include <Port_Lbcfg.h>

extern void Port_Init (const Port_ConfigType * ConfigPtr);

#endif /* PORT_H_ */
