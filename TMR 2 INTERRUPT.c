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
	PIR1bits.TMR2IF = 0;	
	PIE1bits.TMR2IE = 1;// Enables the TMR1 overflow interrupt 


//TIMER INIT CONFIG
	T2CON = 0X0E;
	PR2 = 0X9C;
	
	
	T2CONbits.TMR2ON = 1;    // Start Timer1
	Led = 0;
while(1);
}

#pragma code TMR2_INT = 0x08
#pragma interrupt TMR2_INT

void TMR2_INT()
{
	PR2 = 0X9C;
	Led =~Led;

	PIR1bits.TMR2IF = 0;
}