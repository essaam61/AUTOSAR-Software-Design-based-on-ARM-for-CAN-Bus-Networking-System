/**********************************************/
/*Module Name: Main Program                 */
/*Author: Ahmed Essam                            */
/*Purpose: Initializes the ECU drivers.          */
/*********************************************/

#include "CAN_Lbcfg.h"
#include "Dio_Lbcfg.h"
#include "RTP.h"
#include "systick.h"

int main(void)
{
    DioChannel_Init();
    CAN_Init();
    App_RP_Init();
    Systick_Init();

    while (1)
    {

    }

}
