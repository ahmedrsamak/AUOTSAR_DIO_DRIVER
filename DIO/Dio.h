/*
 * DIO.h
 *
 * Created: 7/23/2018 6:49:29 PM
 *  Author: ahmed
 */ 

#ifndef DIO_H_
#define DIO_H_ 
#define STD_LOW  0
#define STD_HIGH 1
#include "common.h"
#include "Dio_Cfg.h"
#include "Std_Types.h"
#include "error.h"

typedef u16 Dio_ChannelType;
typedef u16 Dio_PortType;
typedef u8 Dio_LevelType; // STD_LOW or STD_HIGH
typedef u8 Dio_PortLevelType;


typedef struct 
{
 u32 mask;
 u8 offset;
 Dio_PortType port;
}Dio_ChannelGroupType;

#if 0
typedef struct
{
	//This structure contains all configurable parameters of the DIO driver. A pointer to this structure is passed to the DIO driver initialization function for configuration.
	// MCU register config that defined in config.h
}Dio_ConfigType;
#endif
typedef struct
{
u8 pin_num;
u8 base_addres;
}channel;

Dio_LevelType Dio_ReadChannel(const channel * RW_channel); //struct > pin num , base address >> user input
void Dio_WriteChannel(const channel * RW_channel, Dio_LevelType Level);
Dio_LevelType Dio_ReadPort(Dio_PortType PortId);
void Dio_WritePort(Dio_PortType PortId, Dio_PortLevelType Level);
Dio_PortLevelType Dio_ReadChannelGroup(const Dio_ChannelGroupType * ChannelGroupIdPtr);
void Dio_WriteChannelGroup(const Dio_ChannelGroupType *ChannelGroupIdPtr, Dio_PortLevelType Level);
//void Dio_Init(const Dio_ConfigType *ConfigPtr);
Dio_LevelType Dio_FlipChannel(const channel * RW_channel); //returns STD_HIGH or STD_LOW
void Dio_GetVersionInfo(Std_VersionInfoType *VersionInfoPtr);
u8 error_ret();

#endif /* DIO_H_ */
