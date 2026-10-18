#include<p18f4580.h>
#define Led PORTCbits.RC3
void delay(int a);
void main()
{
	TRISCbits.RC3 = 0;
 
	RCONbits.IPEN = 0;//interrupt disable
	INTCONbits.GIE = 1;//ENABLE ALL UNMASKED INTR
	INTCONbits.PEIE = 1; //ENABLE PERIPHERAL INT
	INTCONbits.TMR0IE = 1;//


	//TIMER INIT CONFIG
	T0CON = 0X87;
	TMR0H = 0XFE;
	TMR0L = 0X78;
	Led = 0;
    while(1);
}

#pragma code TMR0 = 0x08
#pragma interrupt TMR0
void TMR0()
{
	TMR0H = 0XFE;
	TMR0L = 0X78;
	Led =~Led;
	INTCONbits.TMR0IF = 0;
}
