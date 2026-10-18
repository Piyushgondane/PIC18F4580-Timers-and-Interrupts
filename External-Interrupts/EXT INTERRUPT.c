#include<p18f4580.h>
#define Led PORTCbits.RC3

void main()
{
	TRISCbits.RC3 = 0;
 //Interrupt
	ADCON1 = 0X0F;
	RCONbits.IPEN = 0;
	INTCON = 0X90;
	INTCON2bits.INTEDG0 = 0;// FALLING EDGE
	
	Led = 0;
while(1);
}

#pragma code Ext_Int0 = 0x08 					
#pragma interrupt Ext_Int0

void Ext_Int0()
{
Led = ~Led; //Toggle Led
INTCONbits.INT0IF = 0;//CLEAR THE FLAG BIT
}
