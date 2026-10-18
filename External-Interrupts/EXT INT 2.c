#include<p18f4580.h>
#define Led PORTCbits.RC0
void main()
{
	TRISCbits.RC0 = 0;

	ADCON1 = 0X0F;
	RCONbits.IPEN = 0; //
	INTCONbits.GIE = 1; //ENABLE INTERRUPT
	INTCONbits.PEIE = 0;//DISABLE PERIPHERAL INTERRUPTS
	INTCON3bits.INT2IE = 1;//ENABLE INT2 PIN IN INTCON 3 REGISTER
	INTCON2bits.INTEDG2 = 0;//FALLING EDGE
	Led = 0;
while(1);
}
#pragma code Ext_Int2 = 0x08
#pragma interrupt Ext_Int2
void Ext_Int2()
{
Led = ~Led;//Led Toggle
INTCON3bits.INT2IF = 0;//CLEAR FLAG 
}
