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
	PIR1bits.TMR1IF = 0;	
	PIE1bits.TMR1IE = 1;// Enables the TMR1 overflow interrupt 


	//TIMER INIT CONFIG
	T1CON = 0XF0;
	TMR0H = 0XB6;
	TMR0L = 0XC1;
	
	T1CONbits.TMR1ON = 1;    // Start Timer1
	Led = 0;
while(1);
}

#pragma code TMR1 = 0x08
#pragma interrupt TMR1

void TMR1()
{
	TMR0H = 0XB6;
	TMR0L = 0XC1;
	Led =~Led;

	PIR1bits.TMR1IF = 0;
}