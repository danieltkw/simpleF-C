#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()

{
    char sel,cad;
    int media=0;
FILE*fp1;
struct aluno
{char Nome[30],presenca[5],nota1[5], nota2[5];} aluno;


{char sel,cad;
FILE*fp1;
struct disciplina
{char Nome[30], professor[10], codigo[5], carga[5];} disciplina;

{char sel,cad;
FILE*fp1;
struct aulas
{char data[8], conteudo[20];
int aulas[5];} aulas;

media=(aluno.nota1[5]+aluno.nota2[5])/2;


//---------------------------------------------------------------------------------------------------------------------------------------------------------

//MENU
printf("DISCIPLINAS:\n\n");
printf("Cadastrar disciplinas - tecle 1\n\n");
printf("Editar cadastros - tecle 2\n\n");
printf("Consultar cadastros - tecle 3\n\n");
printf("ALUNOS:\n\n");
printf("Cadastrar alunos - tecle 4\n\n");
printf("Editar cadastros - tecle 5\n\n");
printf("Consultar cadastros - tecle 6\n\n");
printf("AULAS DADAS:\n\n");
printf("Registrar aula - tecle 7\n\n");
printf("Editar registros - tecle 8\n\n");
printf("Consultar cadastros - tecle 9\n\n");
sel=getchar();
fflush(stdin);


//--------------------------------------------------------------------------------------------------------------------------------------------------------

if (sel=='1')//Cadastrar disciplinas
    {//Abrir o arquivo
    system("cls");//Limpa a tela
    fp1 =  fopen("disciplinas.txt","at");
    if(fp1==NULL)
        printf("Impossivel abrir o arquivo!\n");
    else
        {do
           {system("cls");//Limpa a tela
            memset(disciplina.Nome,'\0',30);//Limpa string
            memset(disciplina.codigo,'\0',5);//Limpa string
            memset(disciplina.professor,'\0',10);//Limpa string
            memset(disciplina.carga,'\0',5);//Limpa string
            printf ("Nome: ");
            gets(disciplina.Nome);
            printf  ("Codigo da disciplina: ");
            gets(disciplina.codigo);
            printf  ("nome do professor: ");
            gets(disciplina.professor);
            printf  ("Carga horaria semanal: ");
            gets(disciplina.carga);
            fwrite(disciplina.Nome,sizeof(disciplina.Nome),1,fp1);
            fwrite(disciplina.codigo,sizeof(disciplina.codigo),1,fp1);
            fwrite(disciplina.professor,sizeof(disciplina.professor),1,fp1);
            fwrite(disciplina.carga,sizeof(disciplina.carga),1,fp1);
            fwrite("\n",1,1,fp1);//Salta para a próxima linha
            fflush(stdin);
            printf("Inserir novo cadastro? (S/N)\n");
            cad=getchar();
            fflush(stdin);}
        while(cad=='s');

        if (cad=='n')
            fclose(fp1);}}



//--------------------------------------------------------------------------------------------------------------------------
else
    {if (sel=='2')//Editar cadastros
        {//Abrir o arquivo
        system("cls");//Limpa a tela
        fp1 =  fopen("disciplinas.txt","wt");
        if(fp1==NULL)
            printf("Impossivel abrir o arquivo!\n");
        else
            {do
               {system("cls");//Limpa a tela
                memset(disciplina.Nome,'\0',30);//Limpa string
                memset(disciplina.codigo,'\0',5);//Limpa string
                memset(disciplina.professor,'\0',10);//Limpa string
                memset(disciplina.carga,'\0',5);//Limpa string
                printf ("Nome da disciplina: ");
                gets(disciplina.Nome);
                printf  ("Codigo da disciplina: ");
                gets(disciplina.codigo);
                printf  ("Nome do professor: ");
                gets(disciplina.professor);
                printf  ("Carga horaria da disciplina: ");
                gets(disciplina.carga);
                fwrite(disciplina.Nome,sizeof(disciplina.Nome),1,fp1);
                fwrite(disciplina.codigo,sizeof(disciplina.codigo),1,fp1);
                fwrite(disciplina.professor,sizeof(disciplina.professor),1,fp1);
                fwrite(disciplina.carga,sizeof(disciplina.carga),1,fp1);
                fwrite("\n",1,1,fp1);//Salta para a próxima linha

                fflush(stdin);
                printf("Inserir novo cadastro? (S/N)\n");
                cad=getchar();
                fflush(stdin);}
            while(cad=='s');

            if (cad=='n')
                fclose(fp1);}}

//-------------------------------------------------------------------------------------------------------------------

    else
        {if (sel=='3')//Consultar disciplinas
            {//Abrir o arquivo
            system("cls");//Limpa a tela
            fp1 =  fopen("disciplinas.txt","rt");
            if(fp1==NULL)
            printf("Impossivel abrir o arquivo!\n");
            else
                {do
                    {system("cls");//Limpa a tela
                    int i;
                    char ch;
                    printf("\ndisciplina: ");
                    for(i=0; i<30; i++){
                        ch=fgetc(fp1);
                        putchar(ch);
                    }
                    printf("\ncodigo: ");
                    for(i=0; i<5; i++){
                        ch=fgetc(fp1);
                        putchar(ch);
                    }
                    printf("\nprofessor: ");
                    for(i=0; i<10; i++){
                        ch=fgetc(fp1);
                        putchar(ch);
                    }
                    printf("\ncarga: ");
                    for(i=0; i<5; i++){
                        ch=fgetc(fp1);
                        putchar(ch);
                    }
                    fflush(stdin);
                    printf("\nMostrar proximo cadastro? (S/N)\n");
                    cad=getchar();
                    fflush(stdin);}
                 while(cad=='s');

                 if (cad=='n')
                 fclose(fp1);}}}}


//----------------------------------------------------------------------------------------------------------------------------------
//alunos
if (sel=='4')//Cadastrar alunos
    {//Abrir o arquivo
    system("cls");//Limpa a tela
    fp1 =  fopen("alunos.txt","at");
    if(fp1==NULL)
        printf("Impossivel abrir o arquivo!\n");
    else
        {do
           {system("cls");//Limpa a tela
            memset(aluno.Nome,'\0',30);//Limpa string
            memset(aluno.nota1,'\0',5);//Limpa string
            memset(aluno.nota2,'\0',5);//Limpa string
            memset(aluno.presenca,'\0',5);//Limpa string
            printf ("Nome: ");
            gets(aluno.Nome);
            printf  ("Nota primeiro bimestre: ");
            gets(aluno.nota1);
            printf  ("Nota segundo bimestre: ");
            gets(aluno.nota2);
            printf  ("Numero de presencas: ");
            gets(aluno.presenca);
            fwrite(aluno.Nome,sizeof(aluno.Nome),1,fp1);
            fwrite(aluno.nota1,sizeof(aluno.nota1),1,fp1);
            fwrite(aluno.nota2,sizeof(aluno.nota2),1,fp1);
            fwrite(aluno.presenca,sizeof(aluno.presenca),1,fp1);
            fwrite("\n",1,1,fp1);//Salta para a próxima linha
            fflush(stdin);
            printf("Inserir novo cadastro? (S/N)\n");
            cad=getchar();
            fflush(stdin);}
        while(cad=='s');

        if (cad=='n')
            fclose(fp1);}}

//--------------------------------------------------------------------------------------------------------------------------
else
    {if (sel=='5')//Editar cadastros
        {//Abrir o arquivo
        system("cls");//Limpa a tela
        fp1 =  fopen("alunos.txt","wt");
        if(fp1==NULL)
            printf("Impossivel abrir o arquivo!\n");
        else
            {do
               {system("cls");//Limpa a tela
                memset(aluno.Nome,'\0',30);//Limpa string
                memset(aluno.nota1,'\0',5);//Limpa string
                memset(aluno.nota2,'\0',5);//Limpa string
                memset(aluno.presenca,'\0',5);//Limpa string
                printf ("Nome: ");
                gets(aluno.Nome);
                printf  ("Nota primeiro bimestre: ");
                gets(aluno.nota1);
                printf  ("Nota segundo bimestre: ");
                gets(aluno.nota2);
                printf  ("Numero de presenca: ");
                gets(aluno.presenca);
                fwrite(aluno.Nome,sizeof(aluno.Nome),1,fp1);
                fwrite(aluno.nota1,sizeof(aluno.nota1),1,fp1);
                fwrite(aluno.nota2,sizeof(aluno.nota2),1,fp1);
                fwrite(aluno.presenca,sizeof(aluno.presenca),1,fp1);
                fwrite("\n",1,1,fp1);//Salta para a próxima linha

                fflush(stdin);
                printf("Inserir novo cadastro? (S/N)\n");
                cad=getchar();
                fflush(stdin);}
            while(cad=='s');

            if (cad=='n')
                fclose(fp1);}}

//-------------------------------------------------------------------------------------------------------------------

    else
        {if (sel=='6')//Consultar alunos
            {//Abrir o arquivo
            system("cls");//Limpa a tela
            fp1 =  fopen("alunos.txt","rt");
            if(fp1==NULL)
            printf("Impossivel abrir o arquivo!\n");
            else
                {do
                    {system("cls");//Limpa a tela
                    int i;
                    char ch;
                    printf("\nAluno: ");
                    for(i=0; i<30; i++){
                        ch=fgetc(fp1);
                        putchar(ch);
                    }
                    printf("\nNota1: ");
                    for(i=0; i<5; i++){
                        ch=fgetc(fp1);
                        putchar(ch);
                    }
                    printf("\nNota2: ");
                    for(i=0; i<5; i++){
                        ch=fgetc(fp1);
                        putchar(ch);
                    }
                    printf("\nPresenca: ");
                    for(i=0; i<5; i++){
                        ch=fgetc(fp1);
                        putchar(ch);
                    }
                    if (media>6)
                        printf("\nAluno reprovado por nota\n");
                    if (aluno.presenca>aulas.aulas[5]/1,333)
                        printf("\nAluno reprovado por falta\n");


                    fflush(stdin);
                    printf("\nMostrar proximo cadastro? (S/N)\n");
                    cad=getchar();
                    fflush(stdin);}
                 while(cad=='s');

                 if (cad=='n')
                 fclose(fp1);}}}}


//-------------------------------------------------------------------------------------------------------------------------------
//AULAS
if (sel=='7')//Registrar aulas
    {//Abrir o arquivo
    system("cls");//Limpa a tela
    fp1 =  fopen("aulas.txt","at");
    if(fp1==NULL)
        printf("Impossivel abrir o arquivo!\n");
    else
        {do
           {system("cls");//Limpa a tela
            memset(aulas.data,'\0',8);//Limpa string
            memset(aulas.conteudo,'\0',20);//Limpa string
            memset(aulas.aulas,'\0',3);//Limpa string
            printf ("data: ");
            gets(aulas.data);
            printf  ("conteudo da aula: ");
            gets(aulas.conteudo);
            printf  ("numero faltas: ");
            gets(aulas.aulas);
            fwrite(aulas.data,sizeof(aulas.data),1,fp1);
            fwrite(aulas.conteudo,sizeof(aulas.conteudo),1,fp1);
            fwrite(aulas.aulas,sizeof(aulas.aulas),1,fp1);
            fwrite("\n",1,1,fp1);//Salta para a próxima linha
            fflush(stdin);
            printf("Inserir novo cadastro? (S/N)\n");
            cad=getchar();
            fflush(stdin);}
        while(cad=='s');

        if (cad=='n')
            fclose(fp1);}}

//--------------------------------------------------------------------------------------------------------------------------
else
    {if (sel=='8')//Editar registro
        {//Abrir o arquivo
        system("cls");//Limpa a tela
        fp1 =  fopen("aulas.txt","wt");
        if(fp1==NULL)
            printf("Impossivel abrir o arquivo!\n");
        else
            {do
               {system("cls");//Limpa a tela
                memset(aulas.data,'\0',8);//Limpa string
                memset(aulas.conteudo,'\0',20);//Limpa string
                memset(aulas.aulas,'\0',3);//Limpa string

                printf ("data da aulas: ");
                gets(aulas.data);
                printf  ("conteudo da aulas: ");
                gets(aulas.conteudo);
                printf  ("presenca faltas: ");
                gets(aulas.aulas);

                fwrite(aulas.data,sizeof(aulas.data),1,fp1);
                fwrite(aulas.conteudo,sizeof(aulas.conteudo),1,fp1);
                fwrite(aulas.aulas,sizeof(aulas.aulas),1,fp1);

                fwrite("\n",1,1,fp1);//Salta para a próxima linha

                fflush(stdin);
                printf("Inserir novo cadastro? (S/N)\n");
                cad=getchar();
                fflush(stdin);}
            while(cad=='s');

            if (cad=='n')
                fclose(fp1);}}

//-------------------------------------------------------------------------------------------------------------------

    else
        {if (sel=='9')//Consultar aulas
            {//Abrir o arquivo
            system("cls");//Limpa a tela
            fp1 =  fopen("aulas.txt","rt");
            if(fp1==NULL)
            printf("Impossivel abrir o arquivo!\n");
            else
                {do
                    {system("cls");//Limpa a tela
                    int i;
                    char ch;
                    printf("\naulas: ");
                    for(i=0; i<8; i++){
                        ch=fgetc(fp1);
                        putchar(ch);
                    }
                    printf("\nconteudo: ");
                    for(i=0; i<20; i++){
                        ch=fgetc(fp1);
                        putchar(ch);
                    }
                    printf("\nfaltas: ");
                    for(i=0; i<3; i++){
                        ch=fgetc(fp1);
                        putchar(ch);
                    }

                    fflush(stdin);
                    printf("\nMostrar proximo cadastro? (S/N)\n");
                    cad=getchar();
                    fflush(stdin);}
                 while(cad=='s');

                 if (cad=='n')
                 fclose(fp1);



                 }}}}}}}








