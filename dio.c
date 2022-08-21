/**********************************************/
/*Module Name: DIO_Switches Driver         */
/*Author: Mahmoud Ayman / Nader Ahmed  */
/*Purpose: Read the input switches' state.   */
/**********************************************/

#include "dio.h"

/***************************************************************/
/*Function Name : DioChannel_Init                                     */
/*Inputs               : None                                                     */
/*Outputs            : None                                                     */
/*Reentrancy        : Non-Reentrant                                      */
/*Synchronous     : Synch                                                    */
/*Description       : Initializes the DIO Driver module.           */
 /***************************************************************/
void DioChannel_Init (void)
{
    Port_ConfigType PORT_Switch2 = { DIO, GPIO_Port, Channel_0, PORT_PIN_IN};
    Port_ConfigType PORT_Switch1 = { DIO,GPIO_Port , Channel_1, PORT_PIN_IN};
    Port_Init(&PORT_Switch2);
    Port_Init(&PORT_Switch1);

    GPIOIntDisable(GPIO_Port, Channel_0 | Channel_1);        /* Disable interrupt for PF0, PF4 (in case it was enabled)  */
    GPIOIntClear(GPIO_Port, Channel_0 | Channel_1);      /* Clear pending interrupts for PF0, PF4   */
    GPIOIntTypeSet(GPIO_Port, Channel_0 | Channel_1, GPIO_FALLING_EDGE);
    GPIOIntEnable(GPIO_Port, Channel_0 | Channel_1);
    IntEnable(GPIOPort_Interrupt);

}

/***************************************************************/
/*Function Name : Dio_ReadChannel                                  */
/*Inputs               : ChannelId (ID of DIO channel)              */
/*Outputs            : None                                                    */
/*Return Value     : Dio_LevelType (STD_HIGH: The physical level of the corresponding Pin is STD_HIGH,
                                                    STD_LOW: The physical level of the corresponding Pin is STD_LOW)    */
/*Reentrancy        : Reentrant                                             */
/*Synchronous     : Synch                                                   */
/*Description       : Returns the value of the specified DIO channel.   */
 /***************************************************************/
Dio_LevelType Dio_ReadChannel ( Dio_ChannelType ChannelId )
{
    uint32 SW1_Status;
    uint32 SW2_Status;
    if (ChannelId == 0)
    {
        SW2_Status = GPIOPinRead(GPIO_Port,Channel_0);
         return SW2_Status;
    }
    else if (ChannelId == 1)
    {
        SW1_Status = GPIOPinRead(GPIO_Port,Channel_1);
        return SW1_Status;
    }

    return SW1_Status | SW2_Status;
}

