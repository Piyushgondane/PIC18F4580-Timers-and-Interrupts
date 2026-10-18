#include<p18f4580.h>

#define Led PORTCbits.RC3
void delay(int a);
void main()
{
	TRISCbits.RC3 = 0;
	

 //INTERRUPT CONFIG
	RCONbits.IPEN = 0;//Disable PRORITY LEVEL
	INTCONbits.GIE = 1;//ENABLE ALL GLOBAL INTR
	INTCONbits.PEIE = 1; //ENABLE PERIPHERAL INT

// Timer1 interrupt flag and enable
	PIR2bits.TMR3IF = 0;	
	PIE2bits.TMR3IE = 1;// Enables the TMR1 overflow interrupt 


	//TIMER INIT CONFIG
	T3CON = 0XF0;
	TMR0H = 0XB6;
	TMR0L = 0XC1;
	
	T3CONbits.TMR3ON = 1;    // Start Timer1
	Led = 0;
while(1);
}

#pragma code TMR3 = 0x08
#pragma interrupt TMR3

void TMR3()
{
	TMR0H = 0XB6;
	TMR0L = 0XC1;
	Led =~Led;

	PIR2bits.TMR3IF = 0;
}