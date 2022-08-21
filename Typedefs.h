/**********************************************/
/*Module Name: Type Definitions               */
/*Author:   Ahmed Essam, Mahmoud Ayman                     */
/*Purpose: Type definitions of data types.  */
/**********************************************/

#ifndef TYPEDEFS_H_
#define TYPEDEFS_H_

typedef unsigned char uint8;
typedef char int8;                                               /* same as signed char */
typedef unsigned int uint32;
typedef int int32;                                               /* same as signed int */

typedef short  int16t;                                        /* same as signed short */
typedef unsigned short uint16t;
typedef long   int32t;                                        /* same as signed long int */
typedef unsigned long  uint32t;
typedef long long  int64t;
typedef unsigned long long uint64t;

typedef float f32_t;
typedef double d64_t;
typedef long double d80_t;


/*  DIO Driver Type Definitions   */
typedef uint32 Dio_ChannelType;
typedef uint8 Dio_LevelType;


/*  PORT Driver Type Definitions   */
typedef uint32 Port_PinType;
typedef enum { PORT_PIN_IN, PORT_PIN_OUT } Port_PinDirectionType;
typedef struct PortConfig {
    uint32 pinmode;
    uint32 port;
    Port_PinType pin;
    Port_PinDirectionType pin_direction;
    uint8 pin_level;
  } Port_ConfigType;


#endif /* TYPEDEFS_H_ */
