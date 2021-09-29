#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char acaoexecutada[100];
}Acao;

typedef struct{
    Acao acao;
    struct No *proximo;
}No;

//Criacao do ponteiro topo
No *topo;

//Funcoes
No * criaNo(Acao acaoparametro);
int push(Acao acao);
int isEmpty();
Acao pop();


int main()
{
    char op;
    int resultado;
    Acao minhaacao;
    //Pilha Vazia
    topo = NULL;

    do{
        system("cls");
        printf("Escolha uma opção:\n");
        printf("1 - INSERIR ACAO || 2 - CTRL+Z || 3 - SAIR\n");
        op = getchar();
        switch(op){
            case '1':
                fflush(stdin);
                //Inserir Acao (Empilhar)
                printf("Informe a acao:\n");
                fgets(minhaacao.acaoexecutada,100,stdin);
                resultado = push(minhaacao);
                if (resultado == 1){
                    printf("Acao empilhada com sucesso.");
                }
                else{
                    printf("Nao foi possivel empilhar a acao.");
                }
                getche();
                break;
            case '2':
                //Remover Acao (Desempilhar)
                getche();
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

int push(Acao acao){
    No *ptrnovo;

    ptrnovo = criaNo(acao);
    if (ptrnovo == NULL){
        //A função criaNo não conseguiu alocar memória
        //Logo não poderemos empilhar uma ação
        return 0;
    }
    else{
        if(isEmpty()){
            //Empilhando quando a Pilha esta vazia
            topo = ptrnovo;
        }
        else{
            //Empilhando quando a Pilha não está vazia
            ptrnovo->proximo = topo;
            topo = ptrnovo;
        }
        return 1;
    }
}

Acao pop(){

}

int isEmpty(){
    if (topo == NULL){
        return 1;
    }
    else{
        return 0;
    }
}
