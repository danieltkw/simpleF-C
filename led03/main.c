
#include "msp430g2553.h"

int main( void )
{
 
  
  // Stop watchdog timer to prevent time out reset
  WDTCTL = WDTPW + WDTHOLD;
  
  P1DIR |= BIT0+BIT6;   // coloca 1 no bit0 e bit6
  P1SEL &= ~BIT0;       // coloca 0 no bit0
  P1SEL2 &= ~BIT0;      // coloca 0 no bit0
  P1REN |= BIT3;        // coloca 1 no bit3
  P1OUT |= BIT3;        // coloca 1 no bit3
  
  while(1){
  if (P1IN & BIT3)
     P1OUT &= BIT0;      // seta P1.0
  else
     P1OUT |= BIT0;
  }
  

  // return 0;
}
