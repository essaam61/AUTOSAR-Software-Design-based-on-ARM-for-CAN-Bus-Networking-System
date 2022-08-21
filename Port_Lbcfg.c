/**********************************************/
/*Module Name: PORT Driver                      */
/*Author: Ahmed Essam / Nader Ahmed / Mahmoud Ayman */
/*Purpose: Initializes the ports and pins required to configure the DIO input switches.     */
/**********************************************/

#include <Port.h>

/***************************************************************/
/*Function Name : Port_Init                                                      */
/*Inputs                : ConfigPtr (Pointer to configuration set)   */
/*Outputs            : None                                                            */
/*Reentrancy       : Non-Reentrant                                            */
/*Synchronous    : Synch                                                           */
/*Description      : Initializes the Port Driver module.             */
/***************************************************************/
void Port_Init (const Port_ConfigType * ConfigPtr)
{
    switch(ConfigPtr->pinmode)
    {
    case(DIO):
    {
        /*  PORT A Configuration  */
        if (ConfigPtr->port == PortA)
        {
            SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);        /*  Enabling the GPIO Port A Peripheral   */
            while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOA)) {}      /*      Wait for the GPIO module to be ready    */
            HWREG(PortA + GPIO_O_LOCK) = GPIO_LOCK_KEY;   /*  Unlocking PORTA Pins for use   */
            HWREG(PortA + GPIO_O_CR) = GPIO_CR_NO;                /* Enable writing to PUR */
            if (ConfigPtr->pin_direction == PORT_PIN_IN)
            {
                GPIODirModeSet(PortA,ConfigPtr->pin, GPIO_DIR_MODE_IN);     /* Sets the direction of the specified pin */
                GPIOPadConfigSet(PortA, ConfigPtr->pin, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPU);    /* Pull Up Resistance on Push Buttons  */
            }
            else if (ConfigPtr->pin_direction == PORT_PIN_OUT)
            {
                GPIOPinWrite(PortA, ConfigPtr->pin, ConfigPtr->pin_level);
                GPIODirModeSet(PortA,ConfigPtr->pin, GPIO_DIR_MODE_OUT);     /* Sets the direction of the specified pin */
                GPIOPinTypeGPIOOutput(PortA, ConfigPtr->pin);
            }
        }


        /*  PORT B Configuration  */
        else if (ConfigPtr->port == PortB)
        {
            SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);        /*  Enabling the GPIO Port B Peripheral   */
            while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOB)) {}      /*      Wait for the GPIO module to be ready    */
            HWREG(PortB + GPIO_O_LOCK) = GPIO_LOCK_KEY;   /*  Unlocking PORTB Pins for use   */
            HWREG(PortB + GPIO_O_CR) = GPIO_CR_NO;                /* Enable writing to PUR */
            if (ConfigPtr->pin_direction == PORT_PIN_IN)
            {
                GPIODirModeSet(PortB,ConfigPtr->pin, GPIO_DIR_MODE_IN);     /* Sets the direction of the specified pin */
                GPIOPadConfigSet(PortB, ConfigPtr->pin, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPU);    /* Pull Up Resistance on Push Buttons  */
            }
            else if (ConfigPtr->pin_direction == PORT_PIN_OUT)
            {
                GPIOPinWrite(PortB, ConfigPtr->pin, ConfigPtr->pin_level);
                GPIODirModeSet(PortB,ConfigPtr->pin, GPIO_DIR_MODE_OUT);     /* Sets the direction of the specified pin */
                GPIOPinTypeGPIOOutput(PortB, ConfigPtr->pin);
            }
        }


        /*  PORT C Configuration  */
        else if (ConfigPtr->port == PortC)
        {
            SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOC);        /*  Enabling the GPIO Port C Peripheral   */
            while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOC)) {}      /*      Wait for the GPIO module to be ready    */
            HWREG(PortC + GPIO_O_LOCK) = GPIO_LOCK_KEY;   /*  Unlocking PORTC Pins for use   */
            HWREG(PortC + GPIO_O_CR) = GPIO_CR_NO;                /* Enable writing to PUR */
            if (ConfigPtr->pin_direction == PORT_PIN_IN)
            {
                GPIODirModeSet(PortC,ConfigPtr->pin, GPIO_DIR_MODE_IN);     /* Sets the direction of the specified pin */
                GPIOPadConfigSet(PortC, ConfigPtr->pin, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPU);    /* Pull Up Resistance on Push Buttons  */
            }
            else if (ConfigPtr->pin_direction == PORT_PIN_OUT)
            {
                GPIOPinWrite(PortC, ConfigPtr->pin, ConfigPtr->pin_level);
                GPIODirModeSet(PortC,ConfigPtr->pin, GPIO_DIR_MODE_OUT);     /* Sets the direction of the specified pin */
                GPIOPinTypeGPIOOutput(PortC, ConfigPtr->pin);
            }
        }


        /*  PORT D Configuration  */
        else if (ConfigPtr->port == PortD)
        {
            SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD);        /*  Enabling the GPIO Port D Peripheral   */
            while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOD)) {}      /*      Wait for the GPIO module to be ready    */
            HWREG(PortD + GPIO_O_LOCK) = GPIO_LOCK_KEY;   /*  Unlocking PORTD Pins for use   */
            HWREG(PortD + GPIO_O_CR) = GPIO_CR_NO;                /* Enable writing to PUR */
            if (ConfigPtr->pin_direction == PORT_PIN_IN)
            {
                GPIODirModeSet(PortD,ConfigPtr->pin, GPIO_DIR_MODE_IN);     /* Sets the direction of the specified pin */
                GPIOPadConfigSet(PortD, ConfigPtr->pin, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPU);    /* Pull Up Resistance on Push Buttons  */
            }
            else if (ConfigPtr->pin_direction == PORT_PIN_OUT)
            {
                GPIOPinWrite(PortD, ConfigPtr->pin, ConfigPtr->pin_level);
                GPIODirModeSet(PortD,ConfigPtr->pin, GPIO_DIR_MODE_OUT);     /* Sets the direction of the specified pin */
                GPIOPinTypeGPIOOutput(PortD, ConfigPtr->pin);
            }
        }


        /*  PORT E Configuration  */
        else if (ConfigPtr->port == PortE)
        {
            SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOE);        /*  Enabling the GPIO Port E Peripheral   */
            while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOE)) {}      /*      Wait for the GPIO module to be ready    */
            HWREG(PortE + GPIO_O_LOCK) = GPIO_LOCK_KEY;   /*  Unlocking PORTE Pins for use   */
            HWREG(PortE + GPIO_O_CR) = GPIO_CR_NO;                /* Enable writing to PUR */
            if (ConfigPtr->pin_direction == PORT_PIN_IN)
            {
                GPIODirModeSet(PortE,ConfigPtr->pin, GPIO_DIR_MODE_IN);     /* Sets the direction of the specified pin */
                GPIOPadConfigSet(PortE, ConfigPtr->pin, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPU);    /* Pull Up Resistance on Push Buttons  */
            }
            else if (ConfigPtr->pin_direction == PORT_PIN_OUT)
            {
                GPIOPinWrite(PortE, ConfigPtr->pin, ConfigPtr->pin_level);
                GPIODirModeSet(PortE,ConfigPtr->pin, GPIO_DIR_MODE_OUT);     /* Sets the direction of the specified pin */
                GPIOPinTypeGPIOOutput(PortE, ConfigPtr->pin);
            }
        }


        /*  PORT F Configuration  */
        else if (ConfigPtr->port == PortF)
        {
            SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);        /*  Enabling the GPIO Port B Peripheral   */
            while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOF)) {}      /*      Wait for the GPIO module to be ready    */
            HWREG(PortF + GPIO_O_LOCK) = GPIO_LOCK_KEY;   /*  Unlocking PORTF Pins for use   */
            HWREG(PortF + GPIO_O_CR) = GPIO_CR_NO;                /* Enable writing to PUR */
            if (ConfigPtr->pin_direction == PORT_PIN_IN)
            {
                GPIODirModeSet(PortF,ConfigPtr->pin, GPIO_DIR_MODE_IN);     /* Sets the direction of the specified pin */
                GPIOPadConfigSet(PortF, ConfigPtr->pin, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPU);    /* Pull Up Resistance on Push Buttons  */
            }
            else if (ConfigPtr->pin_direction == PORT_PIN_OUT)
            {
                GPIOPinWrite(PortF, ConfigPtr->pin, ConfigPtr->pin_level);
                GPIODirModeSet(PortF,ConfigPtr->pin, GPIO_DIR_MODE_OUT);     /* Sets the direction of the specified pin */
                GPIOPinTypeGPIOOutput(PortF, ConfigPtr->pin);
            }
        }

        break;
    }



    case(CAN):
    {
        /*  PORT B Configuration  */
        if (ConfigPtr->port == PortB)
        {
            /* CAN0 is used with RX and TX pins on port B4 and B5. */
            /* GPIO port B needs to be enabled so these pins can be used. */
            SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);        /*  Enabling the GPIO Port B Peripheral   */
            while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOB)) {}      /*      Wait for the GPIO module to be ready    */
            HWREG(PortB + GPIO_O_LOCK) = GPIO_LOCK_KEY;   /*  Unlocking PORTB Pins for use   */
            HWREG(PortB + GPIO_O_CR) = GPIO_CR_NO;                /* Enable writing to PUR */


            #if defined(TARGET_IS_TM4C129_RA0) ||                                         \
                defined(TARGET_IS_TM4C129_RA1) ||                                         \
                defined(TARGET_IS_TM4C129_RA2)
                uint32_t ui32SysClock;
            #endif

                /*
                 Set the clocking to run directly from the external crystal/oscillator.
                 TODO: The SYSCTL_XTAL_ value must be changed to match the value of the
                 crystal on your board.
                */
            #if defined(TARGET_IS_TM4C129_RA0) ||                                         \
                defined(TARGET_IS_TM4C129_RA1) ||                                         \
                defined(TARGET_IS_TM4C129_RA2)
                ui32SysClock = SysCtlClockFreqSet((SYSCTL_XTAL_25MHZ |
                                                   SYSCTL_OSC_MAIN |
                                                   SYSCTL_USE_OSC)
                                                   ClkFreq);
            #else
                SysCtlClockSet(SYSCTL_SYSDIV_1 | SYSCTL_USE_OSC | SYSCTL_OSC_MAIN |
                               SYSCTL_XTAL_16MHZ);
            #endif

            /*  The GPIO port and pins have been set up for CAN.  The CAN peripheral
             must be enabled.   */
            SysCtlPeripheralEnable(SYSCTL_PERIPH_CAN0);
            if (ConfigPtr->pin == Pin_4)
            {
                /* Configure the GPIO pin muxing to select CAN0 functions for these pins.
                   This step selects which alternate function is available for these pins.
                   This is necessary if your part supports GPIO pin function muxing */
                GPIOPinConfigure(GPIO_PB4_CAN0RX);
                /* Enable the alternate function on the GPIO pins.  The above step selects
                    which alternate function is available.  This step actually enables the
                    alternate function instead of GPIO for these pins.
                    TODO: change this to match the port/pin you are using */
                GPIOPinTypeCAN(PortB, Pin_4);
            }
            else if (ConfigPtr->pin == Pin_5)
            {
                GPIOPinConfigure(GPIO_PB5_CAN0TX);
                GPIOPinTypeCAN(PortB, Pin_5);
            }

            /* Initialize the CAN controller  */
            CANInit(CAN0_BASE);

            /*
             Set up the bit rate for the CAN bus.  This function sets up the CAN
             bus timing for a nominal configuration.  You can achieve more control
             over the CAN bus timing by using the function CANBitTimingSet() instead
             of this one, if needed.
             In this example, the CAN bus is set to 500 kHz.  In the function below,
             the call to SysCtlClockGet() or ui32SysClock is used to determine the
             clock rate that is used for clocking the CAN peripheral.  This can be
             replaced with a  fixed value if you know the value of the system clock,
             saving the extra function call.  For some parts, the CAN peripheral is
             clocked by a fixed 8 MHz regardless of the system clock in which case
             the call to SysCtlClockGet() or ui32SysClock should be replaced with
             8000000.  Consult the data sheet for more information about CAN
             peripheral clocking.
            */
        #if defined(TARGET_IS_TM4C129_RA0) ||                                         \
            defined(TARGET_IS_TM4C129_RA1) ||                                         \
            defined(TARGET_IS_TM4C129_RA2)
            CANBitRateSet(CAN0_BASE, ui32SysClock, BR);
        #else
            CANBitRateSet(CAN0_BASE, SysCtlClockGet(), BR);
        #endif

            CANEnable(CAN0_BASE);           /* Enable the CAN for operation.  */
        }



        /*  PORT E Configuration  */
        else if (ConfigPtr->port == PortE)
        {
            SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOE);        /*  Enabling the GPIO Port B Peripheral   */
            while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOE)) {}      /*      Wait for the GPIO module to be ready    */
            HWREG(PortE + GPIO_O_LOCK) = GPIO_LOCK_KEY;   /*  Unlocking PORTB Pins for use   */
            HWREG(PortE + GPIO_O_CR) = GPIO_CR_NO;                /* Enable writing to PUR */

            #if defined(TARGET_IS_TM4C129_RA0) ||                                         \
                defined(TARGET_IS_TM4C129_RA1) ||                                         \
                defined(TARGET_IS_TM4C129_RA2)
                uint32_t ui32SysClock;
            #endif

                /*
                 Set the clocking to run directly from the external crystal/oscillator.
                 TODO: The SYSCTL_XTAL_ value must be changed to match the value of the
                 crystal on your board.
                */
            #if defined(TARGET_IS_TM4C129_RA0) ||                                         \
                defined(TARGET_IS_TM4C129_RA1) ||                                         \
                defined(TARGET_IS_TM4C129_RA2)
                ui32SysClock = SysCtlClockFreqSet((SYSCTL_XTAL_25MHZ |
                                                   SYSCTL_OSC_MAIN |
                                                   SYSCTL_USE_OSC)
                                                   ClkFreq);
            #else
                SysCtlClockSet(SYSCTL_SYSDIV_1 | SYSCTL_USE_OSC | SYSCTL_OSC_MAIN |
                               SYSCTL_XTAL_16MHZ);
            #endif

            /*  The GPIO port and pins have been set up for CAN.  The CAN peripheral
             must be enabled.   */
            SysCtlPeripheralEnable(SYSCTL_PERIPH_CAN0);
            if (ConfigPtr->pin == Pin_4)
            {
                /* Configure the GPIO pin muxing to select CAN0 functions for these pins.
                   This step selects which alternate function is available for these pins.
                   This is necessary if your part supports GPIO pin function muxing */
                GPIOPinConfigure(GPIO_PE4_CAN0RX);
                /* Enable the alternate function on the GPIO pins.  The above step selects
                    which alternate function is available.  This step actually enables the
                    alternate function instead of GPIO for these pins.
                    TODO: change this to match the port/pin you are using */
                GPIOPinTypeCAN(PortE, Pin_4);
            }
            else if (ConfigPtr->pin == Pin_5)
            {
                GPIOPinConfigure(GPIO_PE5_CAN0TX);
                GPIOPinTypeCAN(PortE, Pin_5);
            }

            /* Initialize the CAN controller  */
            CANInit(CAN0_BASE);

            /*
             Set up the bit rate for the CAN bus.  This function sets up the CAN
             bus timing for a nominal configuration.  You can achieve more control
             over the CAN bus timing by using the function CANBitTimingSet() instead
             of this one, if needed.
             In this example, the CAN bus is set to 500 kHz.  In the function below,
             the call to SysCtlClockGet() or ui32SysClock is used to determine the
             clock rate that is used for clocking the CAN peripheral.  This can be
             replaced with a  fixed value if you know the value of the system clock,
             saving the extra function call.  For some parts, the CAN peripheral is
             clocked by a fixed 8 MHz regardless of the system clock in which case
             the call to SysCtlClockGet() or ui32SysClock should be replaced with
             8000000.  Consult the data sheet for more information about CAN
             peripheral clocking.
            */
            #if defined(TARGET_IS_TM4C129_RA0) ||                                         \
            defined(TARGET_IS_TM4C129_RA1) ||                                         \
            defined(TARGET_IS_TM4C129_RA2)
            CANBitRateSet(CAN0_BASE, ui32SysClock, BR);
            #else
            CANBitRateSet(CAN0_BASE, SysCtlClockGet(), BR);
            #endif

            CANEnable(CAN0_BASE);           /* Enable the CAN for operation.  */
        }



        /*  PORT A Configuration  */
        else if (ConfigPtr->port == PortA)
        {
            SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);        /*  Enabling the GPIO Port B Peripheral   */
            while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOA)) {}      /*      Wait for the GPIO module to be ready    */
            HWREG(PortA + GPIO_O_LOCK) = GPIO_LOCK_KEY;   /*  Unlocking PORTB Pins for use   */
            HWREG(PortA + GPIO_O_CR) = GPIO_CR_NO;                /* Enable writing to PUR */

            #if defined(TARGET_IS_TM4C129_RA0) ||                                         \
                defined(TARGET_IS_TM4C129_RA1) ||                                         \
                defined(TARGET_IS_TM4C129_RA2)
                uint32_t ui32SysClock;
            #endif

                /*
                 Set the clocking to run directly from the external crystal/oscillator.
                 TODO: The SYSCTL_XTAL_ value must be changed to match the value of the
                 crystal on your board.
                */
            #if defined(TARGET_IS_TM4C129_RA0) ||                                         \
                defined(TARGET_IS_TM4C129_RA1) ||                                         \
                defined(TARGET_IS_TM4C129_RA2)
                ui32SysClock = SysCtlClockFreqSet((SYSCTL_XTAL_25MHZ |
                                                   SYSCTL_OSC_MAIN |
                                                   SYSCTL_USE_OSC)
                                                   ClkFreq);
            #else
                SysCtlClockSet(SYSCTL_SYSDIV_1 | SYSCTL_USE_OSC | SYSCTL_OSC_MAIN |
                               SYSCTL_XTAL_16MHZ);
            #endif

            /*  The GPIO port and pins have been set up for CAN.  The CAN peripheral
             must be enabled.   */
            SysCtlPeripheralEnable(SYSCTL_PERIPH_CAN1);
            if (ConfigPtr->pin == Pin_0)
            {
                /* Configure the GPIO pin muxing to select CAN0 functions for these pins.
                   This step selects which alternate function is available for these pins.
                   This is necessary if your part supports GPIO pin function muxing */
                GPIOPinConfigure(GPIO_PA0_CAN1RX);
                /* Enable the alternate function on the GPIO pins.  The above step selects
                    which alternate function is available.  This step actually enables the
                    alternate function instead of GPIO for these pins.
                    TODO: change this to match the port/pin you are using */
                GPIOPinTypeCAN(PortA, Pin_0);
            }
            else if (ConfigPtr->pin == Pin_1)
            {
                GPIOPinConfigure(GPIO_PA1_CAN1TX);
                GPIOPinTypeCAN(PortA, Pin_1);
            }

            /* Initialize the CAN controller  */
            CANInit(CAN1_BASE);

            /*
             Set up the bit rate for the CAN bus.  This function sets up the CAN
             bus timing for a nominal configuration.  You can achieve more control
             over the CAN bus timing by using the function CANBitTimingSet() instead
             of this one, if needed.
             In this example, the CAN bus is set to 500 kHz.  In the function below,
             the call to SysCtlClockGet() or ui32SysClock is used to determine the
             clock rate that is used for clocking the CAN peripheral.  This can be
             replaced with a  fixed value if you know the value of the system clock,
             saving the extra function call.  For some parts, the CAN peripheral is
             clocked by a fixed 8 MHz regardless of the system clock in which case
             the call to SysCtlClockGet() or ui32SysClock should be replaced with
             8000000.  Consult the data sheet for more information about CAN
             peripheral clocking.
            */
            #if defined(TARGET_IS_TM4C129_RA0) ||                                         \
            defined(TARGET_IS_TM4C129_RA1) ||                                         \
            defined(TARGET_IS_TM4C129_RA2)
            CANBitRateSet(CAN1_BASE, ui32SysClock, BR);
            #else
            CANBitRateSet(CAN1_BASE, SysCtlClockGet(), BR);
            #endif

            CANEnable(CAN1_BASE);           /* Enable the CAN for operation.  */
        }

        break;
    }
    default: {}
    }



}


