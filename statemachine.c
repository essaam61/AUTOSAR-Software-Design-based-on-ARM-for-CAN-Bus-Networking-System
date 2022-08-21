/**********************************************/
/*Module Name: State Machine Software Component  */
/*Author: Ahmed Essam / Ahmed Hatem    */
/*Purpose: Controls ECU state depending on received CAN message.    */
/**********************************************/

#include <statemachine.h>

static uint8 state;
static uint8 colorstate;
/***************************************************************/
/*Function Name  : App_SM_Init                                              */
/*Inputs                : None                                                          */
/*Outputs             : None                                                          */
/*Reentrancy        : Non-Reentrant                                          */
/*Synchronous     : Synch                                                         */
/*Description       : Initializes the ECU and color states.        */
/***************************************************************/
void App_SM_Init (void)
{
    /*  Set the leds initially to red   */
    Dio_WriteChannel(Red, STD_HIGH);    /*  Turn on LED 1 (RED) */
    colorstate = RED_LED;   /*  Declare color state variable   */
    state=waiting;      /*  Declare state variable   */
}


/***************************************************************/
/*Function Name : App_SM                                                     */
/*Inputs                : None                                                          */
/*Outputs             : None                                                          */
/*Reentrancy        : Reentrant                                                   */
/*Synchronous     : Synch                                                         */
/*Description       : Defines the states of ECU and how it operates.    */
/***************************************************************/
void App_SM (void)
{
            switch (state) {
              case(waiting): {
                  CAN_Read();
                  if( SW1State == SW_HIGH || BothSWState == SW_HIGH )
                      state = definition;

                break;
              }
              case(definition): {
                  if( SW1State == SW_HIGH )
                      state = checking;
                  else if (BothSWState == SW_HIGH){
                      state = red_execution;
                      BothSWState = SW_LOW;
                  }

                break;
              }
              case(checking): {

                  switch (colorstate)
                  {
                      case (RED_LED):   {
                          state=green_execution;
                      break;
                      }
                      case (GREEN_LED):   {
                          state=blue_execution;
                      break;
                      }
                      case (BLUE_LED):   {
                          state=red_execution;
                      break;
                      }
                      default: {}
                  }

                break;
              }
              case(red_execution): {
                  Dio_WriteChannel(Blue, STD_LOW);
                  Dio_WriteChannel(Green, STD_LOW);
                  Dio_WriteChannel(Red, STD_HIGH);   /*  Turn on LED 1 (RED) */
                  colorstate = RED_LED;
                  Systick_StartCount();            /*  Enable SysTick Timer  */
                  state = blocked;
                break;
              }
              case(green_execution): {
                  Dio_WriteChannel(Red, STD_LOW);
                  Dio_WriteChannel(Blue, STD_LOW);
                  Dio_WriteChannel(Green, STD_HIGH);   /*  Turn on LED 3 (Green)   */
                  colorstate = GREEN_LED;
                  Systick_StartCount();           /*  Enable SysTick Timer */
                  state = blocked;
                break;
              }
              case(blue_execution): {
                  Dio_WriteChannel(Red, STD_LOW);
                  Dio_WriteChannel(Green, STD_LOW);
                  Dio_WriteChannel(Blue, STD_HIGH);    /* Turn on LED 2 (Blue)   */
                  colorstate = BLUE_LED;
                  Systick_StartCount();           /*  Enable SysTick Timer */
                  state = blocked;
                break;
              }
              case(blocked): {
                  /*    ECU goes in blocked state until a 1000ms timeout is reached then returns to waiting state    */
                  if(tflag)
                  {
                      state = waiting;
                      tflag=false;
                  }
                  break;
              }
            default: {}
            }

}

