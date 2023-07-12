// Daniel Tiepolo Kochinski
// Tarefa 02, Comp2

#include <stdio.h>
#include <stdlib.h>

#define v_size 20000
#define v_chave 1333

int sequencial(int *itens, int tam, int chave)
{

 int t;

    //printf(" \nitens em %d - chave em %d - e tam em %d\n ",itens, chave, tam); // linha para checar se os parametros foram passados corretamente

 for (t=0; t < tam; t++)
 	{
        //printf("\n%d iten",itens[t]);
 	    //printf("\n%d seq",t);

 	if (chave == itens[t])
 		{
        //printf("\n %d it\n",itens[t]); // linha para checar o valor de itens[t]
 		return t;
 		}
 	}
 	printf(" \nt wm %d \n ",t);
 return -1;
}

int binaria(int *itens, int tam, int chave)
{

 int baixo, alto, meio;

 baixo = 0;
 alto = tam - 1;

 while (baixo <= alto)
 	{

 	meio = (baixo+alto)/2;

 	if (chave < itens[meio])
 		{
 		alto = meio -1;
 		}
 		else
 			{
 			if (chave > itens[meio])
 				{
 				baixo = meio + 1;
 				}
 				else
 					{
 					return meio; // encontrado
 					printf("%d\n bin",meio);
 					}
 			}
 	}
 return -1;
}


void main(void)
{
    // tive que fazer na main tudo void para ele retornar o valor que desejo corretamente,
    // usando o codigo que o prof. forneceu. O tempo que demorei pra descobrir isto... kkkjjj
    int i=v_size, valor=0, chave=v_chave;

    int itens[v_size];

	for (valor=0; valor < v_size ; valor++)
	{
	itens[valor]=valor;
	}

	//sequencial( itens,  v_size,  chave);
	binaria( itens,  v_size,  chave);

}

