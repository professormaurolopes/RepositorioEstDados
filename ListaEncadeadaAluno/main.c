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

//Fun��es
No * criaNo(Aluno aluno);

//Ponteiros usados na manipula��o da Lista Encadeada
No *inicio = NULL;
No *fim = NULL;

int main()
{
    //Declara��o de uma vari�vel aluno
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
                printf("A criacao do No n�o foi poss�vel");
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

    //Alocar mem�ria para um N�
    novo = (No *) malloc(sizeof(No));
    //Testar se a aloca��o funcionou
    if (novo == NULL){
        //Caso a aloca��o n�o funcione devo informar ao usu�rio
        //A alocacao n�o foi poss�vel
        return NULL;
    }
    else{
        //Caso a aloca��o funcione eu devo fazer duas a��es:
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
