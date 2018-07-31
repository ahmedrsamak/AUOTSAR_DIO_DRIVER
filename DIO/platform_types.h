/*
 * platform_types.h
 *
 * Created: 7/24/2018 5:58:12 PM
 *  Author: ahmed
 */ 


#ifndef PLATFORM_TYPES_H_
#define PLATFORM_TYPES_H_
// NOTE THAT DDR I WE DON'T USE IN DIO DRIVER, DEL AFTER FINSHISH DRIVER
//#define PIN_A 0x39

typedef enum
{
 INVALID_MIN_INDEX=0x2F,
 READ_PORT_D = 0X30,
 DDR_D,
 WRITE_PORT_D,
 READ_PORT_C,
 DDR_C,
 WRITE_PORT_C,
 READ_PORT_B,
 DDR_B,
 WRITE_PORT_B,
 READ_PORT_A,
 DDR_A,
 WRITE_PORT_A,
 INVALID_MAX_INDEX,
}port_base;






#endif /* PLATFORM_TYPES_H_ */