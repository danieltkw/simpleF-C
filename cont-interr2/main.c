#include "msp430g2553.h"

#pragma vector=TIMER0_A1_VECTOR
__interrupt void timer()
{
    if(TACTL & TAIFG) // identifica se é interrupcao do TIMER A0 (TAIFG)
    {
        TACTL &= ~TAIFG;  // reseta indicador de interrupcao do TIMER A0
        P1OUT &= ~BIT0; // apaga o led
    }
    if(TACCTL2 & CCIFG) // identifica se é interrupcao do CCR2
    {
        TACCTL2 &= ~CCIFG;  // reseta indicador de interrupcao do CCR2 do TIMER A0
        P1OUT |= BIT0;  // acende o led
    }
}

void main( void )
{
  // Stop watchdog timer to prevent time out reset
    WDTCTL = WDTPW + WDTHOLD;
    
    P1DIR |= BIT0 + BIT6;      // define P1.0 como saida

    TACCR0 = 62500;     // define o valor do TIMER para 0,5s (0,2 + 0,3)
    TACCR2 = 25000;     // define o calor de CCR2 para uma interrupcao em 0,2s
    TACTL |= TASSEL_2   // seleciona SMCLK como clock
           + ID_3       // divide clock por 8
           + MC_1       // seleciona modo UP
           + TAIE;      // habilita interrupcao do TIMER A0
    TACCTL2 |= CCIE;    // habilita interrupcao do CCR2

    TACTL &= ~TAIFG;    // reseta indicador de interrupcao do TIMER A0
      
    __enable_interrupt();       // habilita as interrupcoes
    
    while(1);           // loop infinito
}

// faça um programa que mantenha o led ligado por 300ms e apagado desligado por 200ms