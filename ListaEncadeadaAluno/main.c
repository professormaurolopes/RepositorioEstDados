#include <stdio.h>
#include <stdlib.h>

//Tipo de dado criado por n�s
typedef struct{
    int matricula;
    char nome[60];
}Aluno;

//Tipo de Dado No
typedef struct{
    Aluno aluno;
    struct No *proximo;
}No;

int main()
{
    //Declara��o de uma vari�vel aluno
    Aluno meualuno;


    printf("Informe a matricula do Aluno:");
    scanf("%d",&meualuno.matricula);
    fflush(stdin);
    printf("Informe o nome do Aluno:");
    fgets(meualuno.nome,60,stdin);
    printf("Matricula:%d\nNome:%s",meualuno.matricula,meualuno.nome);
    return 0;
}
