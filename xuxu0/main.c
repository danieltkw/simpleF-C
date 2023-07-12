
#include "msp430g2553.h"


char estado='B';

#pragma vector=TIMER0_A1_VECTOR
__interrupt void timer()
{
  
    TACTL&=(~TAIFG);  // limpa flag
    
    switch(estado)
    {
    case 'A':
      {
        if((P1IN & BIT3)==0)
        {
          estado='B';
          P1OUT|=BIT0+BIT1;
          P1OUT&=~(BIT2+BIT4);
        }
        else
        {
          estado='H';
          P1OUT|=BIT0+BIT4;
          P1OUT&=~(BIT1+BIT2);
        }
   break;
      }
    case 'B':
      {
        if((P1IN & BIT3)==0)
        {
          estado='C';
          P1OUT|=BIT1;
          P1OUT&=~(BIT0+BIT2+BIT4);
        }
        else
        {
          estado='A';
          P1OUT|=BIT0;
          P1OUT&=~(BIT1+BIT2+BIT4);
        }
        break;
      }
    case 'C':
      {
        if((P1IN & BIT3)==0)
        {
          estado='D';
          P1OUT|=BIT1+BIT2;
          P1OUT&=~(BIT0+BIT4);
        }
        else
        {
          estado='B';
          P1OUT|=BIT0+BIT1;
          P1OUT&=~(BIT2+BIT4);
        }
        break;
      }
    case 'D':
      {
        if((P1IN & BIT3)==0)
        {
          estado='E';
          P1OUT|=BIT2;
          P1OUT&=~(BIT0+BIT1+BIT4);
        }
        else
        {
          estado='C';
          P1OUT|=BIT1+BIT2;
          P1OUT&=~(BIT0+BIT4);
        }
        break;
      }
    case 'E':
      {
        if((P1IN & BIT3)==0)
        {
          estado='F';
          P1OUT|=BIT2+BIT4;
          P1OUT&=~(BIT0+BIT1);
        }
        else
        {
          estado='D';
          P1OUT|=BIT2;
          P1OUT&=~(BIT0+BIT1+BIT4);
        }
        break;
      }
    case 'F':
      {
        if((P1IN & BIT3)==0)
        {
          estado='G';
          P1OUT|=BIT4;
          P1OUT&=~(BIT0+BIT1+BIT2);
        }
        else
        {
          estado='E';
          P1OUT|=BIT2;
          P1OUT&=~(BIT0+BIT1+BIT4);
        }
        break;
      }
    case 'G':
      {
        if((P1IN & BIT3)==0)
        {
          estado='H';
          P1OUT|=BIT0+BIT4;
          P1OUT&=~(BIT1+BIT2);
        }
        else
        {
          estado='F';
          P1OUT|=BIT2+BIT4;
          P1OUT&=~(BIT0+BIT1);
        }
        break;
      }
    case 'H':
      {
        if((P1IN & BIT3)==0)
        {
          estado='A';
          P1OUT|=BIT0;
          P1OUT&=~(BIT1+BIT2+BIT4);
        }
        else
        {
          estado='G';
          P1OUT|=BIT4;
          P1OUT&=~(BIT0+BIT1+BIT2);
        }
        break;
      }
    }                                   // switch opera ativando os bits (que sao os leds)                           
    
}




int main( void )
{
   
    // Stop watchdog timer to prevent time out reset
    WDTCTL = WDTPW + WDTHOLD;

   P1SEL &= 0x00;           // Define todo o P1 como GPIO
   
   
    P1DIR |= BIT0+BIT1+BIT2+BIT4;                // P1 sera saida menos P1.3
    P1REN |= BIT3;              // ativa o pull up ou down
    P1OUT |= BIT3;                // escolhe pull up
       
   TACTL |= TASSEL_2 
            + ID_3      
              + MC_1     
                + TAIE;       // SMCLK, clock /8 e UP (retirado do codigo do prof)
     TACTL &= ~TAIFG;     // reseta a interr
    TACCR0 = 3000;                     // contagem (retirado dos codigos fornecidos pelo prof)
        
    __enable_interrupt();// habilita as interrupções

    while(1){}  // laco infinito
}
