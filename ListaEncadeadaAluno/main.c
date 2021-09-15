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

//Funções
No * criaNo(Aluno aluno);

//Ponteiros usados na manipulação da Lista Encadeada
No *inicio = NULL;
No *fim = NULL;

int main()
{
    //Declaração de uma variável aluno
    Aluno meualuno;
    char opcao;
    No *resultado;

    do{
        system("cls");
        printf("Escolha uma opcao:\n");
        printf("1 - INSERIR UM ALUNO || 2 - SAIR\n");
        opcao = getchar();
        switch(opcao){
        case '1':
            //Insercao de um aluno
            printf("Informe a matricula do Aluno:");
            scanf("%d",&meualuno.matricula);
            fflush(stdin);
            printf("Informe o nome do Aluno:");
            fgets(meualuno.nome,60,stdin);
            resultado = criaNo(meualuno);
            if (resultado == NULL){
                printf("A criacao do No não foi possível");
            }
            else{
                printf("Deu certo a criacao do No");
            }
            system("pause");
            break;
        case '2':
            //Sair da aplicacao
            printf("saindo...");
            break;
        }
    }while(opcao != '2');

    return 0;
}

No * criaNo(Aluno aluno){
    No *novo;

    //Alocar memória para um Nó
    novo = (No *) malloc(sizeof(No));
    //Testar se a alocação funcionou
    if (novo == NULL){
        //Caso a alocação não funcione devo informar ao usuário
        //A alocacao não foi possível
        return NULL;
    }
    else{
        //Caso a alocação funcione eu devo fazer duas ações:
        //incluir o aluno na parte dado
        //fazer o proximo apontar para nulo
        novo->aluno = aluno;
        novo->proximo = NULL;
        if (inicio == NULL){
            inicio = novo;
            fim = novo;
        }
        else{
            fim->proximo = novo;
            fim = novo;
        }
        return novo;
    }
}
