/**********************************************/
/*Module Name: SysTick Driver                    */
/*Author: Mostafa Khaled                             */
/*Purpose: Initializes the SysTick timer        */
/**********************************************/

#include "systick.h"

/***************************************************************/
/*Function Name : Systick_Init                                             */
/*Inputs                : None                                                    */
/*Outputs             : None                                                    */
/*Reentrancy        : Non-Reentrant                                      */
/*Synchronous     : Synch                                                    */
/*Description       : Initializes the SysTick Driver.                   */
 /***************************************************************/
void Systick_Init (void)
{
    SysTickDisable();       /*  Disable SysTick. */
    SysTickPeriodSet(SysCtlClockGet()/2);        /*  Sets the period of the SysTick counter. */
    SysTickIntEnable();         /*  Enable the SysTick Interrupt.   */
    SysTickEnable();            /*  Enable SysTick. */

}

