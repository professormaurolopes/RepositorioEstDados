#include <stdio.h>
#include <stdlib.h>
#define TAM_MAX 5

typedef struct{
    char nome[60];
    int idade;
    char matricula[8];
    char email[60];
}Professor;


Professor listadeProfessores[TAM_MAX];
void inserirnaLista(Professor item,int *indice);
void listardaLista(int indice);
int buscarnaLista(Professor item,int indice);

int main()
{
    char opcao;
    Professor item;
    int indice = 0,encontrou=0;

    do{
        system("cls");
        printf("***************** MENU *****************\n");
        printf("1 - INSERIR PROFESSOR NA LISTA\n");
        printf("2 - LISTAR PROFESSORES DA LISTA\n");
        printf("3 - BUSCAR PROFESSOR (POR NOME) NA LISTA\n");
        printf("4 - SAIR DA APLICACAO\n");
        printf("****************************************\n\n");
        printf("ESCOLHA UMA OPCAO:");
        scanf("%c",&opcao);
        fflush(stdin);
        switch(opcao){
            case '1':
                printf("ESCOLHEU INSERIR PROFESSOR\n");
                if(indice == TAM_MAX){
                    printf("Lista de Professores lotada!!!!\n");
                }
                else{
                    printf("Informe o nome:");
                    fgets(item.nome,60,stdin);
                    printf("Informe a idade:");
                    scanf("%d",&item.idade);
                    printf("Informe a matricula:");
                    scanf("%s",item.matricula);
                    printf("Informe o email:");
                    scanf("%s",item.email);
                    inserirnaLista(item,&indice);
                }
                system("pause");
                break;
            case '2':
                printf("ESCOLHEU LISTAR PROFESSORES\n");
                listardaLista(indice);
                system("pause");
                break;
            case '3':
                printf("ESCOLHEU BUSCAR PROFESSOR\n");
                printf("Informe o nome do Professor a pesquisar:");
                fgets(item.nome,60,stdin);
                encontrou = buscarnaLista(item,indice);
                if(encontrou == 1){
                    printf("Professor Localizado!!!\n");
                }
                else{
                    printf("Professor NAO Localizado!!!\n");
                }
                system("pause");
                break;
            case '4':
                printf("ESCOLHEU SAIR DA APLICACAO\n");
                system("pause");
                break;
        }
    }while(opcao != '4');

    return 0;
}

void inserirnaLista(Professor item,int *indice){
    listadeProfessores[*indice] = item;
    *indice = *indice + 1;
}

void listardaLista(int indice){
    for(int i=0;i<indice;i++){
        printf("*****************************************\n");
        printf("Nome do Professor:%s",listadeProfessores[i].nome);
        printf("Idade do Professor:%d\n",listadeProfessores[i].idade);
        printf("Matricula do Professor:%s\n",listadeProfessores[i].matricula);
        printf("E-mail do Professor:%s\n",listadeProfessores[i].email);
        printf("*****************************************\n");
    }
}

int buscarnaLista(Professor item,int indice){
    int encontrou = 0;
    for(int i=0;i<indice;i++){
        if(strncmp(item.nome,listadeProfessores[i].nome,60)==0){
            encontrou = 1;
            break;
        }
    }
    return encontrou;
}
