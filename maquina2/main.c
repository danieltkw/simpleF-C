
#include "io430.h"



int sinal( void )
{
  // Stop watchdog timer to prevent time out reset
  WDTCTL = WDTPW + WDTHOLD;

  if(chave==1)
    return 0;
  else
    return 1;
}

void main()
{
  char estado='A';
  int saida=0,x;
  while(1)
  {
    x=sinal();
    switch(estado_
  case 'A':
       if (x==0)
       {
         estado='B';
         saida=1;
       }
       else
        {
          estado='A'
            saida=0;
        }
       break;
       
       case 'B'
         if (x==0)
         {
           estado='C';
           saida=2;
         }
       else
       {
         estado='A'
           saida=0;
       }
       break;
       
  case 'C':
        