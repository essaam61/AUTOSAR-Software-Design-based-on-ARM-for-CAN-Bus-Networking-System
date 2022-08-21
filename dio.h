/**********************************************/
/*Module Name: DIO_Switches Driver         */
/*Author: Mahmoud Ayman / Nader Ahmed  */
/*Purpose: Read the input switches' state.   */
/**********************************************/

#ifndef DIO_H_
#define DIO_H_

#include <Typedefs.h>
#include "Dio_Lbcfg.h"

extern void DioChannel_Init (void);
extern Dio_LevelType Dio_ReadChannel ( Dio_ChannelType ChannelId );

#endif
