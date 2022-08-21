/**********************************************/
/*Module Name: CAN Driver                        */
/*Author: Mahmoud Ayman / Nader Ahmed  */
/*Purpose: Sends messages over CAN bus and reads the CAN interrupt status. */
/**********************************************/

#include "can.h"

tCANMsgObject sCANMessage1;
uint8 Sw1Data[8];

tCANMsgObject sCANMessage2;
uint8 Sw2Data[8];

tCANMsgObject sCANMessage3;
uint8 BothSwData[8];

/***************************************************************/
/*Function Name : CAN_Init                                                */
/*Inputs               : None                                                     */
/*Outputs            : None                                                     */
/*Reentrancy        : Non-Reentrant                                      */
/*Synchronous     : Synch                                                    */
/*Description       : Initializes the CAN Driver module.          */
 /***************************************************************/
void CAN_Init(void)
{
    Port_ConfigType PORT_CANRX = { CAN, CAN_GPIOPort, GPIO_RXPin };
    Port_ConfigType PORT_CANTX = { CAN, CAN_GPIOPort, GPIO_TXPin };
    Port_Init(&PORT_CANRX);
    Port_Init(&PORT_CANTX);

    /*
     Enable interrupts on the CAN peripheral.  This example uses static
     allocation of interrupt handlers which means the name of the handler
     is in the vector table of startup code.  If you want to use dynamic
     allocation of the vector table, then you must also call CANIntRegister()
     here.
    */
    CANIntRegister(CANChannel, CANIntHandler);     /*  Register an interrupt handler for the CAN controller.   */

    CANIntEnable(CANChannel, CAN_INT_MASTER | CAN_INT_ERROR | CAN_INT_STATUS);

    /*  Enable the CAN interrupt on the processor (NVIC).  */
    IntEnable(CANChannel_Interrupt);


    /*
     Initialize the message object that will be used for sending CAN
     messages.  The message will be 4 bytes that will contain an incrementing
     value.  Initially it will be set to 0.
    */

    /*
     Initialize message object 1 to be able to send CAN message 1.  This
     message object is not shared so it only needs to be initialized one
     time, and can be used for repeatedly sending the same message ID.
    */
    /*  MSG OBJECT 1    */
    sCANMessage1.ui32MsgID = Msg1_ID;
    sCANMessage1.ui32MsgIDMask = MsgIDMask;
    sCANMessage1.ui32Flags = MSG_OBJ_TX_INT_ENABLE;
    sCANMessage1.ui32MsgLen = sizeof(Sw1Data);
    sCANMessage1.pui8MsgData = Sw1Data;
    /*
     Initialize message object 2 to be able to send CAN message 2.  This
     message object is not shared so it only needs to be initialized one
     time, and can be used for repeatedly sending the same message ID.
    */
    /*  MSG OBJECT 2    */
    sCANMessage2.ui32MsgID = Msg2_ID;
    sCANMessage2.ui32MsgIDMask = MsgIDMask;
    sCANMessage2.ui32Flags = MSG_OBJ_TX_INT_ENABLE;
    sCANMessage2.ui32MsgLen = sizeof(Sw2Data);
    sCANMessage2.pui8MsgData = Sw2Data;
    /*
     Initialize message object 2 to be able to send CAN message 3.  This
     message object is not shared so it only needs to be initialized one
     time, and can be used for repeatedly sending the same message ID.
    */
    /*  MSG OBJECT 3    */
    sCANMessage3.ui32MsgID = Msg3_ID;
    sCANMessage3.ui32MsgIDMask = MsgIDMask;
    sCANMessage3.ui32Flags = MSG_OBJ_TX_INT_ENABLE;
    sCANMessage3.ui32MsgLen = sizeof(BothSwData);
    sCANMessage3.pui8MsgData = BothSwData;

}


/***************************************************************/
/*Function Name : CAN_Write                                             */
/*Inputs               : Switch1_Status (Value of DIO Channel 0), Switch2_Status (Value of DIO Channel 1)   */
/*Outputs            : None                                                     */
/*Reentrancy        : Reentrant                                              */
/*Synchronous     : Synch                                                    */
/*Description       : Passes a CAN message to CanDrv for transmission depending on input switches' state. */
 /***************************************************************/
void CAN_Write (uint32 Switch1_Status, uint32 Switch2_Status)
{
    if (Switch1_Status == STD_HIGH && Switch2_Status == STD_HIGH) {
        BothSwData[0] = Switch1_Status | Switch2_Status;
        CANMessageSet(CANChannel, Msg3TX_Object, &sCANMessage3, MSG_OBJ_TYPE_TX);             /* from ECU1 to both ECUs */
    }
    else if (Switch2_Status == STD_HIGH) {
        Sw2Data[0] = Switch2_Status;
        CANMessageSet(CANChannel, Msg2TX_Object, &sCANMessage2, MSG_OBJ_TYPE_TX);             /* from ECU1 to ECU3 */
    }
    else if (Switch1_Status == STD_HIGH) {
        Sw1Data[0] = Switch1_Status;
        CANMessageSet(CANChannel, Msg1TX_Object, &sCANMessage1, MSG_OBJ_TYPE_TX);             /* from ECU1 to ECU2 */
    }
    else {
            Sw1Data[0] = STD_LOW;
            CANMessageSet(CANChannel, Msg1TX_Object, &sCANMessage1, MSG_OBJ_TYPE_TX);             /* from ECU1 to ECU2 */
            Sw2Data[0] = STD_LOW;
            CANMessageSet(CANChannel, Msg2TX_Object, &sCANMessage2, MSG_OBJ_TYPE_TX);             /* from ECU1 to ECU3 */
            BothSwData[0] =STD_LOW;
            CANMessageSet(CANChannel, Msg3TX_Object, &sCANMessage3, MSG_OBJ_TYPE_TX);             /* from ECU1 to both ECUs */
    }
}



/******************************************************************************
 A flag to indicate that some transmission error occurred.
******************************************************************************/
volatile bool g_bErrFlag=0;

/***************************************************************/
/*Function Name : CANIntHandler                                   */
/*Inputs               : None                                                     */
/*Outputs            : None                                                     */
/*Reentrancy        : Reentrant                                              */
/*Synchronous     : Synch                                                    */
/*Description       : Reads the CAN interrupt controller status. */
 /***************************************************************/
void CANIntHandler(void)
{
    uint32 ui32Status;

    /*  Read the CAN interrupt status to find the cause of the interrupt */
    ui32Status = CANIntStatus(CANChannel, CAN_INT_STS_CAUSE);

    /*  If the cause is a controller status interrupt, then get the status */
    if(ui32Status == CAN_INT_INTID_STATUS)
    {
        /*
         Read the controller status.  This will return a field of status
         error bits that can indicate various errors.  Error processing
         is not done in this example for simplicity.  Refer to the
         API documentation for details about the error status bits.
         The act of reading this status will clear the interrupt.  If the
         CAN peripheral is not connected to a CAN bus with other CAN devices
         present, then errors will occur and will be indicated in the
         controller status.
        */
        ui32Status = CANStatusGet(CANChannel, CAN_STS_CONTROL);

        /*  Set a flag to indicate some errors may have occurred.   */
        g_bErrFlag = 1;
    }

    else if(ui32Status == Msg1TX_Object )
    {
        /*
         Getting to this point means that the TX interrupt occurred on
         message object TXOBJECT, and the message reception is complete.
         Clear the message object interrupt.
        */
        CANIntClear(CANChannel, Msg1TX_Object);

        /*
         Since a message was transmitted, clear any error flags.
         This is done because before the message is transmitted it triggers
         a Status Interrupt for TX complete. by clearing the flag here we
         prevent unnecessary error handling from happeneing
        */
        g_bErrFlag  = 0;
    }
    else if(ui32Status == Msg2TX_Object)
    {
        /*
         Getting to this point means that the TX interrupt occurred on
         message object TXOBJECT, and the message reception is complete.
         Clear the message object interrupt.
        */
        CANIntClear(CANChannel, Msg2TX_Object);

        /*
         Since a message was transmitted, clear any error flags.
         This is done because before the message is transmitted it triggers
         a Status Interrupt for TX complete. by clearing the flag here we
         prevent unnecessary error handling from happeneing
        */
        g_bErrFlag  = 0;
    }
    else if(ui32Status == Msg3TX_Object)
    {
        /*
         Getting to this point means that the TX interrupt occurred on
         message object TXOBJECT, and the message reception is complete.
         Clear the message object interrupt.
        */
        CANIntClear(CANChannel, Msg3TX_Object);

        /*
         Since a message was transmitted, clear any error flags.
         This is done because before the message is transmitted it triggers
         a Status Interrupt for TX complete. by clearing the flag here we
         prevent unnecessary error handling from happening
        */
        g_bErrFlag  = 0;
    }

    /*
     Otherwise, something unexpected caused the interrupt.  This should
     never happen.
    */
    else
    {
        /*
         Spurious interrupt handling can go here.
        */
    }
}



