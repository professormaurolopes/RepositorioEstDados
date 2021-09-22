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
int listavazia();
void primeiroNo(No *ptrNo);
void insereFim(No *ptrNo);
void imprimir();
int buscarporAluno(char nomebusca[60]);

//Ponteiros usados na manipulação da Lista Encadeada
No *inicio = NULL;
No *fim = NULL;

int main()
{
    //Declaração de uma variável aluno
    Aluno meualuno;
    char opcao, nomeLocalizar[60];
    No *novoNo;
    int resultado;

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
                printf("A criacao do No não foi possível\n");
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
            //Buscar por um Aluno
            if (listavazia()){
                printf("Lista Vazia. Busca nao pode ser realizada.\n");
            }
            else{
                fflush(stdin);
                printf("Informe o nome do Aluno a ser Localizado:");
                fgets(nomeLocalizar,60,stdin);
                resultado = buscarporAluno(nomeLocalizar);
                if (resultado){
                    printf("Nome informado, foi Localizado\n");
                }
                else{
                    printf("Nome informado, NAO foi Localizado\n");
                }
            }
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
    //A Lista já possui algum Nó da Lista
    fim->proximo = ptrNo;
    fim = ptrNo;
}

void imprimir(){
    No *percorre;

    //O ponteiro "inicio" é usado para navegarmos em nossa Lista
    percorre = inicio;
    while (percorre != NULL){
        printf("Matricula:%d\n",percorre->aluno.matricula);
        printf("Nome:%s",percorre->aluno.nome);
        percorre = percorre->proximo;
    }
}

int buscarporAluno(char nomebusca[60]){
    No *percorre;

    //O ponteiro "inicio" é usado para navegarmos em nossa Lista
    percorre = inicio;
    while (percorre != NULL){
        if (strncmp(percorre->aluno.nome,nomebusca,60) == 0){
            return 1;
        }
        percorre = percorre->proximo;
    }
    return 0;
}
