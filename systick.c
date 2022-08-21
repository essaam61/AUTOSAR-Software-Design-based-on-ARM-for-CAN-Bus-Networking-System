/**********************************************/
/*Module Name: SysTick Driver                    */
/*Author: Mahmoud Ayman / Nader Ahmed   */
/*Purpose: Initializes the SysTick timer and provides a specific periodicity to hold LEDs' status.  */
/**********************************************/

#include "systick.h"

/***************************************************************/
/*Function Name : Systick_Init                                                 */
/*Inputs                : None                                                          */
/*Outputs             : None                                                          */
/*Reentrancy        : Non-Reentrant                                          */
/*Synchronous     : Synch                                                          */
/*Description       : Initializes the SysTick Driver.                     */
 /***************************************************************/
void Systick_Init (void)
{
    SysTickDisable();       /*  Disable SysTick. */
    SysTickPeriodSet(SysCtlClockGet());        /*  Sets the period of the SysTick counter. */
    SysTickIntEnable();         /*  Enable the SysTick Interrupt.   */
    SysTickIntRegister(SysTickIntHandler);  /*  Registers an interrupt handler for the SysTick interrupt    */
}

bool tflag=false;
/***************************************************************/
/*Function Name : SystickIntHandler                                      */
/*Inputs                : None                                                          */
/*Outputs             : None                                                         */
/*Reentrancy        : Reentrant                                                  */
/*Synchronous     : Synch                                                         */
/*Description       : Sets the ECU state back to waiting and disables the systick timer.  */
 /***************************************************************/
void SysTickIntHandler(void)
{
    tflag=true;
    Systick_EndCount();

}


/***************************************************************/
/*Function Name : Systick_StartCount                                    */
/*Inputs                : None                                                          */
/*Outputs             : None                                                          */
/*Reentrancy        : Reentrant                                                   */
/*Synchronous     : Synch                                                          */
/*Description       : Enables the systick timer counter to start counting.   */
 /***************************************************************/
void Systick_StartCount (void)
{
    SysTickEnable();            /*  Enable SysTick Timer */
}


/***************************************************************/
/*Function Name : Systick_EndCount                                      */
/*Inputs                : None                                                          */
/*Outputs             : None                                                          */
/*Reentrancy        : Reentrant                                                   */
/*Synchronous     : Synch                                                          */
/*Description       : Disables the systick timer from counting and reloads it. */
 /***************************************************************/
void Systick_EndCount (void)
{
    SysTickDisable();       /*  Disable SysTick Timer */
    NVIC_ST_CURRENT_R = 0;  /*  Reload SysTick Counter  */
}

