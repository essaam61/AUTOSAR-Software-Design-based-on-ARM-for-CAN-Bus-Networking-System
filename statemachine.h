/**********************************************/
/*Module Name: State Machine Software Component  */
/*Author: Ahmed Essam / Ahmed Hatem    */
/*Purpose: Controls ECU state depending on received CAN message.    */
/**********************************************/

#ifndef STATEMACHINE_H_
#define STATEMACHINE_H_

#include "SM_Lbcfg.h"

extern void App_SM_Init (void);
extern void App_SM (void);


#endif
