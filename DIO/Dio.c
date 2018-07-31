/*
 * DIO.c
 *
 * Created: 7/23/2018 6:49:07 PM
 *  Author: ahmed
 */ 
#include "Dio.h"
static u8 ret;
static u8 check_error;
Dio_LevelType Dio_ReadChannel(const channel * RW_channel) //struct > pin num , base address >> user input
{
 if ((RW_channel->base_addres) > INVALID_MIN_INDEX && (RW_channel->base_addres) < INVALID_MAX_INDEX)
 {
  ret=((*(volatile port_base*)(RW_channel->base_addres)) & (1<<(RW_channel->pin_num)))>>(RW_channel->pin_num);
 }
 else check_error=READ_CHANNEL;
 return ret;
}

void Dio_WriteChannel(const channel * RW_channel, Dio_LevelType Level)
{
  if ((RW_channel->base_addres) > INVALID_MIN_INDEX && (RW_channel->base_addres) < INVALID_MAX_INDEX && Level <= STD_HIGH)
  {
	  if (Level == STD_HIGH)
	  {
		(*(volatile port_base*)(RW_channel->base_addres)) |= (1<<(RW_channel->pin_num));  
	  }
	  else
	  {
        (*(volatile port_base*)(RW_channel->base_addres)) &=~ (1<<(RW_channel->pin_num));
	  }
  }
  else check_error=WRITE_CHANNEL; 
}

Dio_LevelType Dio_ReadPort(Dio_PortType PortId)
{
   if (PortId<INVALID_MAX_INDEX && PortId > INVALID_MIN_INDEX)
   {
	ret=(*(volatile port_base*)(PortId));  
   }
   else check_error=READ_PORT ;
return ret;
}



void Dio_WritePort(Dio_PortType PortId, Dio_PortLevelType Level)
{
   if ((PortId<INVALID_MAX_INDEX && PortId > INVALID_MIN_INDEX) && Level <=STD_HIGH)
   {
	   if (Level==STD_HIGH)
	   {
		   (*(volatile port_base*)(PortId))=0xFF;
	   }
	   else (*(volatile port_base*)(PortId))=0x00;
   }
   else check_error=WRITE_PORT;
}

Dio_PortLevelType Dio_ReadChannelGroup(const Dio_ChannelGroupType * ChannelGroupIdPtr) // why he put that struct const !!?
{
	if ((ChannelGroupIdPtr->port<INVALID_MAX_INDEX) && (ChannelGroupIdPtr->port>INVALID_MIN_INDEX))
	{
		ret=((*(volatile port_base*)(ChannelGroupIdPtr->port)) & ((ChannelGroupIdPtr->mask) << (ChannelGroupIdPtr->offset))) >> (ChannelGroupIdPtr->offset);
	}
	else check_error=READ_CHANNEL_GROUP;

return ret;
}

void Dio_WriteChannelGroup(const Dio_ChannelGroupType *ChannelGroupIdPtr, Dio_PortLevelType Level)
{
	if (Level <= STD_HIGH && (ChannelGroupIdPtr->port<INVALID_MAX_INDEX) && (ChannelGroupIdPtr->port>INVALID_MIN_INDEX))
	{
		if (Level==STD_HIGH)
		{
			(*(volatile port_base*)(ChannelGroupIdPtr->port)) |= ((ChannelGroupIdPtr->mask)<<ChannelGroupIdPtr->offset);
		}
		else
		{
			(*(volatile port_base*)(ChannelGroupIdPtr->port)) &=~((ChannelGroupIdPtr->mask)<<ChannelGroupIdPtr->offset);
		}
	}
	else check_error=WRITE_CHANNEL_GROUP;  
}

Dio_LevelType Dio_FlipChannel(const channel * RW_channel)
{
  if ((RW_channel->base_addres) > INVALID_MIN_INDEX && (RW_channel->base_addres) < INVALID_MAX_INDEX)
  {
	 ret=((*(volatile port_base*)(RW_channel->base_addres)) & (1<<(RW_channel->pin_num)))>>(RW_channel->pin_num);
	  	  if (ret == STD_LOW)
	  	  {
		  	  (*(volatile port_base*)(RW_channel->base_addres)) |= (1<<(RW_channel->pin_num));
			ret=STD_HIGH;
	  	  }
	  	  else if (ret==STD_HIGH)
	  	  {
		  	  (*(volatile port_base*)(RW_channel->base_addres)) &=~ (1<<(RW_channel->pin_num));
				ret=STD_LOW;
	  	  }	
	
  }
else check_error=FLIP_CHANNEL;

  return ret;
}
  u8 error_ret()
  {
	  return check_error;
  }                
