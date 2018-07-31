/*
 * Std_Types.h
 *
 * Created: 7/23/2018 6:52:00 PM
 *  Author: ahmed
 */ 

#include "common.h"
#include "platform_types.h"

#ifndef STD_TYPES_H_
#define STD_TYPES_H_
typedef struct // fill with right info
{
  u16 vendorID;
  u16 moduleID;
  u8  sw_major_version;
  u8  sw_minor_version;
  u8  sw_patch_version;
 
}Std_VersionInfoType;






#endif /* STD_TYPES_H_ */