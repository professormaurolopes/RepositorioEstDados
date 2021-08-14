#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM_ENDERECO 60
#define TAM_MAX 5

//itemHistorico � um tipo de dado criado pelo desenvolvedor
//As structs d�o essa liberdade ao desenvolvedor
typedef struct{
    char url[TAM_ENDERECO];
}itemHistorico;

//listadeHistoricos representa a nossa Lista Sequencial
itemHistorico listadeHistoricos[TAM_MAX];
//As fun��es criadas para manipular a Lista Sequencial
void inserirnaLista(itemHistorico item, int *indice);
void listarLista(int indice);
int buscarnaLista(itemHistorico item, int indice);


int main()
{
    char opcao;
    int indice = 0,encontrou=0;
    itemHistorico item;

    do{
        system("cls");
        printf("1 - INSERIR / 2 - LISTAR / 3 - BUSCAR / 4 - SAIR\n");
        printf("Escolha uma opcao:");
        scanf("%c",&opcao);
        switch(opcao){
            case '1':
                printf("Insercao na Lista\n");
                //Verificar o limite da Lista
                //indice ir� nos ajudar a identificar quando a Lista Sequencial estiver cheia
                if (indice == TAM_MAX){
                    printf("Limite do Historico alcancado!!!!\n");
                }
                else {
                    printf("Informe o endereco:");
                    scanf("%s",item.url);
                    //Vamos inserir este "item" na posi��o indicado por "indice"
                    //Na primeira inser��o "indice" ser� igual a 0
                    //Depois disso o valor da vari�vel ser modificado dentro da fun��o de inser��o
                    inserirnaLista(item, &indice);
                }
                system("pause");
                break;
            case '2':
                printf("Listagem da Lista\n");
                //Na listagem o "indice" nos ajuda a imprimir somente at� aonde a Lista Sequencial tem dados
                //Isso evita que imprimamos espa�os da Lista Sequencial que n�o est�o sendo usados
                listarLista(indice);
                system("pause");
                break;
            case '3':
                printf("Buscar na Lista\n");
                printf("Informe o endereco a ser localizado:");
                scanf("%s",item.url);
                //Na fun��o de Busca iremos tentar localizar um "item" dentro da nossa Lista Sequencial
                //de itens de Historico
                //Caso o "item" seja encontrado na Lista Sequencial retornamos "1", caso contr�rio "0"
                //Tanto "1" como "0" s�o valores inteiros
                encontrou = buscarnaLista(item,indice);
                if(encontrou == 1){
                    printf("O endereco [%s] foi localizado.\n",item.url);
                }
                else {
                    printf("O endereco [%s] NAO foi localizado.\n",item.url);
                }
                system("pause");
                break;
            case '4':
                printf("Saindo....");
                break;
        }
    }while(opcao != '4');
    return 0;
}

void inserirnaLista(itemHistorico item, int *indice){
    listadeHistoricos[*indice] = item;
    *indice = *indice + 1;
}

void listarLista(int indice){
    for(int i=0;i<indice;i++){
        printf("Item do Historico:%s\n",listadeHistoricos[i]);
    }
}

int buscarnaLista(itemHistorico item, int indice){
    int encontrou = 0;

    for(int i=0;i<indice;i++){
        //A fun��o strncmp ser� recebe tr�s argumentos
        //1� - um vetor de caracteres
        //2� - um vetor de caracteres
        //3� - a quantidade de caracteres a serem verificados
        //A fun��o retorna 0 se os dois vetores de caracteres forem iguais
        if (strncmp(listadeHistoricos[i].url,item.url,TAM_ENDERECO) == 0){
            encontrou = 1;
            break;
        }
    }
    return (encontrou);

}

