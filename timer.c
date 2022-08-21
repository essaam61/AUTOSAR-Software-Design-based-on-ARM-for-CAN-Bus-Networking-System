/**********************************************/
/*Module Name: GPT Driver                         */
/*Author: Ahmed Hatem                               */
/*Purpose:  Configures a Timer as a 16-bit periodic counter with an interrupt every 10ms.  */
/**********************************************/

#include "timer.h"

/***************************************************************/
/*Function Name : GPT_Init                                                 */
/*Inputs               : None                                                     */
/*Outputs            : None                                                     */
/*Reentrancy        : Non-Reentrant                                      */
/*Synchronous     : Synch                                                    */
/*Description       : Initializes the GPT Driver.                       */
 /***************************************************************/
void GPT_Init (void)
{

     /* The Timer0 peripheral must be enabled for use.  */
     SysCtlPeripheralEnable(TIMERPeripheral);

     /* Configure Timer0B as a 16-bit periodic timer. */
     TimerConfigure(TIMERChannel, TIMERConfig);

     /* Set the Timer0B load value to 10ms.  */
     TimerLoadSet(TIMERChannel, SubTimer, SysCtlClockGet() / 100);


     /* Enable processor interrupts.  */
     IntMasterEnable();

     /*  Configure the Timer0B interrupt for timer timeout.   */
     TimerIntEnable(TIMERChannel, TIMERIntFlag);

     /* Enable the Timer0B interrupt on the processor (NVIC). */
     IntEnable(TIMERChannel_Interrupt);

     /* Register the handler to be called when a timer interrupt occurs.    */
     TimerIntRegister(TIMERChannel, SubTimer, TimerIntHandler);


     /* Enable Timer0B. */
     TimerEnable(TIMERChannel, SubTimer);

}
