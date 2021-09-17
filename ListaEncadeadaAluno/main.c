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
int listavazia();
void primeiroNo(No *ptrNo);
void insereFim(No *ptrNo);
void imprimir();

//Ponteiros usados na manipula��o da Lista Encadeada
No *inicio = NULL;
No *fim = NULL;

int main()
{
    //Declara��o de uma vari�vel aluno
    Aluno meualuno;
    char opcao;
    No *novoNo;

    do{
        system("cls");
        printf("Escolha uma opcao:\n");
        printf("1 - INSERIR UM ALUNO || 2 - IMPRIMIR || 3 - BUSCAR || 4 - SAIR\n");
        opcao = getchar();
        switch(opcao){
        case '1':
            //Insercao de um aluno
            printf("Informe a matricula do Aluno:");
            scanf("%d",&meualuno.matricula);
            fflush(stdin);
            printf("Informe o nome do Aluno:");
            fgets(meualuno.nome,60,stdin);
            novoNo = criaNo(meualuno);
            if (novoNo == NULL){
                printf("A criacao do No n�o foi poss�vel\n");
            }
            else{
                if (listavazia()){
                    primeiroNo(novoNo);
                }
                else{
                    insereFim(novoNo);
                }
                printf("Aluno incluido com sucesso na Lista.\n");
            }
            getche();
            break;
        case '2':
            if (listavazia()){
                printf("Lista Vazia, nada a imprimir...\n");
            }
            else{
                imprimir();
            }
            getche();
            break;
        case '3':
            //Sair da aplicacao
            printf("buscar...");
            getche();
            break;
        case '4':
            //Sair da aplicacao
            printf("saindo...");
            getche();
            break;
        }
    }while(opcao != '4');

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
        return novo;
    }
}

int listavazia(){
    //Verifica se a Lista esta Vazia
    if(inicio == NULL){
        return 1;
    }
    else {
        return 0;
    }
}

void primeiroNo(No *ptrNo){
    //Primeiro No da Lista
    inicio = ptrNo;
    fim = ptrNo;
}

void insereFim(No *ptrNo){
    //A Lista j� possui algum N� da Lista
    fim->proximo = ptrNo;
    fim = ptrNo;
}

void imprimir(){
    No *percorre;

    //O ponteiro "inicio" � usado para navegarmos em nossa Lista
    percorre = inicio;
    while (percorre != NULL){
        printf("Matricula:%d\n",percorre->aluno.matricula);
        printf("Nome:%s",percorre->aluno.nome);
        percorre = percorre->proximo;
    }
}
