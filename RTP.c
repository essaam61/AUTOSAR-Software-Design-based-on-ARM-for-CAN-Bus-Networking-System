/**********************************************/
/*Module Name: Read-Transport Protocol Software Component   */
/*Author: Mostafa Khaled                             */
/*Purpose: Reads the switches' states and provides a periodic interrupt to send CAN messages.        */
/**********************************************/

#include <RTP.h>


static volatile uint32 PB1;
static volatile uint32 PB2;
/***************************************************************/
/*Function Name  : App_RP_Init                                                       */
/*Inputs                : None                                                           */
/*Outputs             : None                                                          */
/*Reentrancy        : Non-Reentrant                                        */
/*Synchronous     : Synch                                                          */
/*Description       : Initializes the Read Protocol Component.  */
 /***************************************************************/
void App_RP_Init (void)
{
    PB1=STD_LOW;
    PB2=STD_LOW;
    GPIOIntRegister(GPIO_Port, App_RP);
}

/***************************************************************/
/*Function Name : App_RP                                                       */
/*Inputs                : None                                                           */
/*Outputs             : None                                                          */
/*Reentrancy        : Reentrant                                                   */
/*Synchronous     : Synch                                                          */
/*Description       : Assigns the returned switch read value into global variables.    */
 /***************************************************************/
void App_RP (void)
{

    PB1 = Dio_ReadChannel(Switch1);         /*  Read Button 1   */
    PB2 = Dio_ReadChannel(Switch2);         /*  Read Button 2   */

    // Clear the asserted interrupts.
    GPIOIntClear(GPIO_Port, Channel_0 | Channel_1);      // Clear pending interrupts for PF4
}

/***************************************************************/
/*Function Name : App_TP                                                       */
/*Inputs                : None                                                          */
/*Outputs             : None                                                          */
/*Reentrancy        : Reentrant                                                   */
/*Synchronous     : Synch                                                          */
/*Description       : Writes the switch value over CAN Bus each 500ms.  */
 /***************************************************************/
void App_TP(void)
{
    /* Send message over CAN according to switch pressed after each 500ms period   */
    CAN_Write(PB1,PB2);
    PB1 = STD_LOW;
    PB2 = STD_LOW;

}

