/**********************************************/
/*Module Name: DIO_LEDs Driver                */
/*Author: Mostafa Khaled / Ahmed Essam  */
/*Purpose: Blink the output LEDs.                */
/**********************************************/


#ifndef DIO_H_
#define DIO_H_

#include "Dio_Lbcfg.h"

extern void DioChannel_Init (void);
extern void Dio_WriteChannel ( Dio_ChannelType ChannelId, Dio_LevelType Level );

#endif
