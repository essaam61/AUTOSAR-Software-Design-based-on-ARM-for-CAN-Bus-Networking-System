/**********************************************/
/*Module Name: State Machine Software Component  */
/*Author: Ahmed Essam / Ahmed Hatem    */
/*Purpose: Initializes and configures the required sets of the state machine module.  */
/**********************************************/

#ifndef SM_LBCFG_H_
#define SM_LBCFG_H_

#include "Typedefs.h"
#include "CAN_Lbcfg.h"
#include "Dio_Lbcfg.h"
#include "can.h"
#include "dio.h"
#include "systick.h"

/*   Define ECU states   */
# define waiting 0
# define definition 1
# define checking 2
# define red_execution 3
# define green_execution 4
# define blue_execution 5
# define blocked 6


/*  Define color states  */
# define RED_LED 8
# define GREEN_LED 9
# define BLUE_LED 10


/* Define LED colors */
# define Red 0
# define Green 2
# define Blue 1

#endif /* SM_LBCFG_H_ */
