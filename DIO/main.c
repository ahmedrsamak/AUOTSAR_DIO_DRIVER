/*
 * DIO.c
 *
 * Created: 7/23/2018 6:17:51 PM
 * Author : ahmed
 */ 

#include <avr/io.h>
#include "Dio.h"
channel myobj_w; // write channel struct
channel myobj_r; // read channel struct
Dio_ChannelGroupType myobj_r_g; // read channel group struct
Dio_ChannelGroupType myobj_w_g; // write channel group struct

u8 x;
int main(void)
{
	myobj_w.base_addres=WRITE_PORT_B;
	myobj_w.pin_num=3;
	
	myobj_r.base_addres=READ_PORT_A;
	myobj_r.pin_num=3;
	
	myobj_r_g.mask=0x06;
	myobj_r_g.offset=1;
	myobj_r_g.port=READ_PORT_A;
	
	myobj_w_g.mask=0x06;
	myobj_w_g.offset=1;
	myobj_w_g.port=WRITE_PORT_B;
	
   DDRA=0x00; // PORTA IS INPUT
   DDRB=0xFF; // PORTB IS OUTPUT
 //PORTB=0b01010101;
  // Dio_WriteChannel(DIO_CHANNEL_B_0,STD_HIGH);
    while (1) 
    {
		x=Dio_ReadChannel(&myobj_r); // X = STATE OF CHANNEL 3 IN PORTA
		Dio_WriteChannel(&myobj_w,STD_HIGH); // WRITE HIGH TO CHANNEL 3 IN PORTB 
		Dio_WriteChannel(&myobj_w,STD_LOW); // WRITE 0 TO CHANNEL 3 IN PORT B
		x=Dio_ReadPort(READ_PORT_A); // X = THE REG VALUE OF PORT A
		Dio_WritePort(WRITE_PORT_B,STD_HIGH); // WRITE HIGH TO ALL CHANNELS IN PORTB
		Dio_WritePort(WRITE_PORT_B,STD_LOW); // WRITE LOW TO ALL CHANNELS IN PORTB
		x=Dio_ReadChannelGroup(&myobj_r_g); // READ CHANNEL 2 AND CHANNEL 3 IN PORTA
		Dio_WriteChannelGroup(&myobj_w_g,STD_HIGH); // WRITE HIGH TO CHANNEL 2 AND CHANNEL 3 IN PORTB
		Dio_WriteChannelGroup(&myobj_w_g,STD_LOW); // WRITE LOW TO CHANNEL 2 AND CHANNEL 3 IN PORTB
		x=Dio_FlipChannel(&myobj_w); // INVERT CHANNEL 3 IN PORTB AND RETURN ITS NEW VALUE
		x=error_ret(); // CHECK ERROR FUNCTION AND RETURN ERROR CODE MAPPED IN ERROR.H FILE
    }
}

