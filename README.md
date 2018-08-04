# AUOTSAR_DIO_DRIVER
DIO MCAL  DRIVER for AVR MCU 
# Example for main code
```C
/*
 * DIO.c
 *
 * Created: 7/23/2018 6:17:51 PM
 * Author : ahmed
 */ 

#include <avr/io.h>
#include "Dio.h"
channel myobj; // write channel struct
Dio_ChannelGroupType myobj2; // read channel group structs

u8 x;
int main(void)
{
	myobj.base_addres=PORT_B;
	myobj.pin_num=3;
	
	myobj2.mask=0x06;
	myobj2.offset=1;
	myobj2.port=PORT_B;
	
   DDRA=0x00; // PORTA IS INPUT
   DDRB=0xFF; // PORTB IS OUTPUT
 //PORTB=0b01010101;
  // Dio_WriteChannel(DIO_CHANNEL_B_0,STD_HIGH);
    while (1) 
    {
		x=Dio_ReadChannel(&myobj); // X = STATE OF CHANNEL 3 IN PORTA
		Dio_WriteChannel(&myobj,STD_HIGH); // WRITE HIGH TO CHANNEL 3 IN PORTB 
		Dio_WriteChannel(&myobj,STD_LOW); // WRITE 0 TO CHANNEL 3 IN PORT B
		x=Dio_ReadPort(PORT_A); // X = THE REG VALUE OF PORT A
		Dio_WritePort(PORT_B,STD_HIGH); // WRITE HIGH TO ALL CHANNELS IN PORTB
		Dio_WritePort(PORT_B,STD_LOW); // WRITE LOW TO ALL CHANNELS IN PORTB
		x=Dio_ReadChannelGroup(&myobj2); // READ CHANNEL 2 AND CHANNEL 3 IN PORTA
		Dio_WriteChannelGroup(&myobj2,STD_HIGH); // WRITE HIGH TO CHANNEL 2 AND CHANNEL 3 IN PORTB
		Dio_WriteChannelGroup(&myobj2,STD_LOW); // WRITE LOW TO CHANNEL 2 AND CHANNEL 3 IN PORTB
		x=Dio_FlipChannel(&myobj); // INVERT CHANNEL 3 IN PORTB AND RETURN ITS NEW VALUE
		x=error_ret(); // CHECK ERROR FUNCTION AND RETURN ERROR CODE MAPPED IN ERROR.H FILE
    }
}
```

