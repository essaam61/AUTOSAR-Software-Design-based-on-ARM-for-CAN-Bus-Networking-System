/**********************************************/
/*Module Name: GPT Driver                         */
/*Author: Ahmed Hatem                               */
/*Purpose:  Configures a Timer as a 16-bit periodic counter with an interrupt every 10ms.  */
/**********************************************/

#ifndef TIMER_H_
#define TIMER_H_

#include "Timer_Lbcfg.h"

extern void GPT_Init (void);
extern void TimerIntHandler(void);


#endif /* TIMER_H_ */
