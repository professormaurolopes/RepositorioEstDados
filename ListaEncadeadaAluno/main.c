#include <stdio.h>
#include <stdlib.h>

//Tipo de dado criado por nós
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
    //Declaração de uma variável aluno
    Aluno meualuno;
    int valor;
    //Criar um ponteiro para o tipo de dado que eu quero armazenar
    No *novoNo;

    //Preciso Alocar Memória
    //Chamar malloc
    //Malloc retorna um void *
    novoNo = (No *) malloc(sizeof(No));
    if (novoNo == NULL){
        printf("Alocaco deu errado!!!");
    }
    else{
        printf("Alocacao deu certo!!!");
        novoNo->aluno
        novoNo->proximo
    }





    printf("Informe a matricula do Aluno:");
    scanf("%d",&meualuno.matricula);
    fflush(stdin);
    printf("Informe o nome do Aluno:");
    fgets(meualuno.nome,60,stdin);
    printf("Matricula:%d\nNome:%s",meualuno.matricula,meualuno.nome);

    return 0;
}
