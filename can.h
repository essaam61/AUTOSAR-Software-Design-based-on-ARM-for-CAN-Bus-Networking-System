/**********************************************/
/*Module Name: CAN Driver                        */
/*Author: Mahmoud Ayman / Nader Ahmed  */
/*Purpose: Sends messages over CAN bus and reads the CAN interrupt status. */
/**********************************************/

#ifndef CAN_H_
#define CAN_H_

#include "Typedefs.h"
#include "CAN_Lbcfg.h"

extern tCANMsgObject sCANMessage1;
extern uint8 Sw1Data[8];
extern tCANMsgObject sCANMessage2;
extern uint8 Sw2Data[8];
extern tCANMsgObject sCANMessage3;
extern uint8 BothSwData[8];

extern void CAN_Init(void);
extern void CAN_Write (uint32 Switch1_Status, uint32 Switch2_Status);
extern void CANIntHandler(void);

#endif /* CAN_H_ */
