#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int matricula;
    char nome[60];
}Aluno;

int main()
{
    Aluno meualuno;

    printf("Informe a matricula do Aluno:");
    scanf("%d",&meualuno.matricula);
    fflush(stdin);
    printf("Informe o nome do Aluno:");
    fgets(meualuno.nome,60,stdin);
    printf("Matricula:%d\nNome:%s",meualuno.matricula,meualuno.nome);
    return 0;
}
