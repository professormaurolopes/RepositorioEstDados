#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char nomearquivo[60];
    int qtdpaginas;
}Arquivo;

typedef struct{
    Arquivo arquivo;
    struct No *proximo;
}No;

//Funcoes
No * criaNo(Arquivo arquivoparam);
int enqueue(Arquivo arq);
int isEmpty();
Arquivo dequeue();
void imprimirFila();

//Ponteiros que marcam o inicio e o final da Fila
No *inicio;
No *fim;

int main()
{
     char op;
     Arquivo meuarquivo;
     int retorno;

     //Indicacao de que a Fila esta vazia
     inicio = NULL;
     fim = NULL;

     do{
        system("cls");
        printf("Escolha uma opção:\n");
        printf("1 - ENVIAR PARA A IMPRESSORA || 2 - IMPRIMIR || 3 - LISTAR ARQUIVOS DA FILA || 4 - SAIR\n");
        op = getchar();
        switch(op){
            case '1':
                fflush(stdin);
                //Enviar Arquivo para Impressora (Enfileirar)
                printf("Informe o nome do Arquivo para Impressao:");
                fgets(meuarquivo.nomearquivo,60,stdin);
                printf("Informe a quantidade de paginas do Arquivo:");
                scanf("%d", &meuarquivo.qtdpaginas);
                retorno = enqueue(meuarquivo);
                if (retorno == 0){
                    printf("Nao foi possivel enviar arquivo para impressora\n");
                }
                else{
                    printf("Arquivo enviado com sucesso para impressora\n");
                }
                getche();
                break;
            case '2':
                //Remover Arquivo da Fila - Imprimir (Desenfileirar)
                if(isEmpty()){
                    printf("Nenhum arquivo para imprimir\n");
                }
                else{
                    meuarquivo = dequeue();
                    printf("Arquivo impresso:%s",meuarquivo.nomearquivo);
                    printf("Numero de Paginas:%d\n",meuarquivo.qtdpaginas);
                    printf("Arquivo removido da Fila de Impressao.\n");
                }
                getche();
                break;
            case '3':
                //Listar Fila de Impressão
                if (isEmpty()){
                    printf("A Fila de Impressao esta vazia!!!\n");
                }
                else{
                    printf("Fila de Impressao....\n");
                    imprimirFila();
                }
                getche();
                break;
            case '4':
                printf("saindo....");
                break;
        }
    }while(op != '4');
    return 0;
}

No * criaNo(Arquivo arquivoparam){
    No *novo;

    novo = (No *) malloc(sizeof(No));
    if (novo == NULL){
        printf("Falha na Alocacao!!!\n");
    }
    else{
        novo->arquivo = arquivoparam;
        novo->proximo = NULL;
    }

    return novo;
}

int enqueue(Arquivo arq){
    No *ptrnovo;

    ptrnovo = criaNo(arq);
    if (ptrnovo == NULL){
        return 0;
    }
    else {
        if (isEmpty()){
            inicio = ptrnovo;
            fim = ptrnovo;
        }
        else{
            fim->proximo = ptrnovo;
            fim = ptrnovo;
        }
        return 1;
    }
}

int isEmpty(){
    if ((inicio == NULL) && (fim == NULL)){
        return 1;
    }
    else{
        return 0;
    }
}

Arquivo dequeue(){
    Arquivo arqretorno;

    //Recuperando o conteudo
    arqretorno = inicio->arquivo;
    //Movimento dos ponteiros mudando o incio da Fila
    inicio = inicio->proximo;
    if (inicio == NULL){
        fim = NULL;
    }

    return arqretorno;
}

void imprimirFila(){
    No *percorrer;

    percorrer = inicio;
    while(percorrer != NULL){
        printf("Arquivo:%s",percorrer->arquivo.nomearquivo);
        printf("Quantidade de Paginas:%d\n",percorrer->arquivo.qtdpaginas);
        percorrer = percorrer->proximo;
    }
}
