/**********************************************/
/*Module Name: Main Program                 */
/*Author: Ahmed Essam                            */
/*Purpose: Initializes the ECU drivers, its state and output LED.   */
/*********************************************/

#include "can.h"
#include "dio.h"
#include "timer.h"
#include "systick.h"
#include "statemachine.h"

int main(void)
{
    DioChannel_Init();
    CAN_Init();
    Systick_Init();
    App_SM_Init();
    GPT_Init();

    while (1)
    {

    }

}

/***************************************************************/
/*Function Name : TimerIntHandler                                        */
/*Inputs                : None                                                          */
/*Outputs             : None                                                         */
/*Reentrancy        : Reentrant                                                  */
/*Synchronous     : Synch                                                        */
/*Description       : Calls the ECU state machine periodically each 10ms. */
 /***************************************************************/
void TimerIntHandler(void)
{
    App_SM();

    /*  Clear the timer interrupt flag.    */
    TimerIntClear(TIMERChannel, TIMERIntFlag);

}
