/**********************************************/
/*Module Name: CAN Driver                        */
/*Author: Ahmed Essam / Ahmed Hatem    */
/*Purpose: Reads messages over CAN bus and the CAN interrupt status. */
/**********************************************/

#ifndef CAN_H_
#define CAN_H_

#include "CAN_Lbcfg.h"

extern tCANMsgObject sCANMessageRX;
extern uint8 pui8MsgDataRX[8];
extern uint8 SW1State;
extern uint8 BothSWState;

extern volatile bool g_M1RXFlag;
extern volatile bool g_M2RXFlag;

extern void CAN_Init(void);
extern void CAN_Read (void);
extern void CANIntHandler(void);

#endif /* CAN_H_ */
