#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char acaoexecutada[100];
}Acao;

typedef struct{
    Acao acao;
    struct No *proximo;
}No;

int main()
{
    char opcao;

    do{
        system("cls");
        printf("Escolha uma opção:\n");
        printf("1 - INSERIR ACAO || 2 - CTRL+Z || 3 - SAIR\n");
        op = getchar();
        switch(op){
            case '1':
                //Inserir Acao (Empilhar)
                break;
            case '2':
                //Remover Acao (Desempilhar)
                break;
            case '3':
                printf("saindo....");
                break;
        }
    }while(op != '3');
    return 0;
}


No * criaNo(Acao acaoparametro){
    No *novo;

    novo = (No *) malloc(sizeof(No));
    if (novo == NULL){
        printf("A Alocacao não funcionou!!!");
    }
    else{
        novo->acao = acaoparametro;
        novo->proximo = NULL;
    }
    return novo;
}

void push(Acao acao){

}

Acao pop(){

}
