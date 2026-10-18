#include<p18f4580.h>

#define Led PORTCbits.RC3
void delay(int a);
void main()
{
	TRISCbits.RC3 = 0;
 //Interrupt
	ADCON1 = 0X0F;
	RCONbits.IPEN = 0;//interrupt disable
	INTCONbits.GIE = 1;//ENABLE ALL UNMASKED INTR
	INTCONbits.PEIE = 0; //DISABLE PERIPHERAL INT
	INTCON3bits.INT1IE = 1;//ENABLE INTR EXT 
	INTCON2bits.INTEDG1 = 0;//FALLING EDGE
	
	
	Led = 0;
while(1);
}

#pragma code Ext_Int1 = 0x08 					
#pragma interrupt Ext_Int1

void Ext_Int1()
{
Led = 1;
delay(100);
Led = 0;
delay(100);
INTCON3bits.INT1IF = 0;//CLEAR THE FLAG BIT
}

void delay(int a)
{
int i,j;
for(i=0;i<a;i++)
for(j=0;j<=a;j++);
}