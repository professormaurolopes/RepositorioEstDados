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
    int valor;
    //Criar um ponteiro para o tipo de dado que eu quero armazenar
    No *novoNo;
    No *novoNo2;

    //Preciso Alocar Mem�ria
    //Chamar malloc
    //Malloc retorna um void *
    novoNo = (No *) malloc(sizeof(No));
    if (novoNo == NULL){
        printf("Alocaco deu errado!!!");
    }
    else{
        printf("Informe a matricula do Aluno:");
        scanf("%d",&meualuno.matricula);
        fflush(stdin);
        printf("Informe o nome do Aluno:");
        fgets(meualuno.nome,60,stdin);
        //printf("Matricula:%d\nNome:%s",meualuno.matricula,meualuno.nome);
        novoNo->aluno = meualuno;
        novoNo->proximo = NULL;
    }
    novoNo2 = (No *) malloc(sizeof(No));
    if (novoNo2 == NULL){
        printf("Nao deu certo a alocacao!!!");
    }
    else{
        printf("Informe a matricula do Aluno:");
        scanf("%d",&meualuno.matricula);
        fflush(stdin);
        printf("Informe o nome do Aluno:");
        fgets(meualuno.nome,60,stdin);
        //printf("Matricula:%d\nNome:%s",meualuno.matricula,meualuno.nome);
        novoNo2->aluno = meualuno;
        novoNo2->proximo = NULL;
        novoNo->proximo = novoNo2;
    }







    return 0;
}
