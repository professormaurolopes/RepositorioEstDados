# Repositório da Disciplina de Estrutura de Dados
Este repositório foi criado para compartilhamento dos códigos-fontes criados para a disciplina de Estrutura de Dados (Curso Técnico em Informática).
Temos vários projetos aqui, você encontrará projetos desenvolvidos pelo Professor durante as aulas e projetos desenvolvidos para reforçar alguns conceitos mais complexos e que precisam de reforço.

# Projetos

## PilhadeAcoes

Neste projeto desenvolvido em nossa aula sobre a implementação de uma Pilha Encadeada a partir do dia 24/09/2021, iremos demonstrar os elementos que fazem parte da construção de uma pilha encadeada. Conceitos como: o ponteiro topo, a criação do Nó, a "dança dos ponteiros", tudo isso será apresentado de forma que o aluno possa compreender na prática os elementos teóricos apresentados nos slides. O objetivo é criar uma aplicação que permita: empilhar ações que são realizadas em uma ferramenta de desenhos, executar a operação CTRL+Z, e desta forma desempilhar as últimas ações. Aqui iremos trabalhar: 
- O conceito de Nó (DADO + PONTEIRO PARA O PRÓXIMO NÓ).
- A criação da parte DADO
- A criação da parte PONTEIRO PARA O PRÓXIMO NÓ
- Criar o ponteiro topo e explanar sua utilização
- Alocação Dinâmica de um Nó através da criação da função criaNo()
- Implementação da função push() para o empilhamento de ações
- Implementação da função isEmpty()
- Implementação da função pop() para permitir a ação do CTRL+Z 


## ListaEncadeadaAlunos

Neste projeto desenvolvido em nossa aula sobre a implementação de uma Lista Encadeada a partir do dia 25/08/2021, iremos demonstrar os elementos que fazem parte da construção de uma lista encadeada. O objetivo é criar uma aplicação que permita: cadastrar alunos, listar os alunos cadastrados e realizar a busca através do nome do aluno para descobrir se o mesmo se encontra na lista cadastrada. Aqui iremos trabalhar: 
- O conceito de Nó (DADO + PONTEIRO PARA O PRÓXIMO NÓ).
- A criação da parte DADO
- A criação da parte PONTEIRO PARA O PRÓXIMO NÓ
- Alocação Dinâmica de um Nó
- Encadeamento de um Nó a outro Nó
- Listagem dos Alunos armazenados na Lista Encadeada
- Busca por um Aluno na Lista Encadeada 

## ListaSequencialProfessores

Neste projeto desenvolvido em nossa aula extra do dia 14/08/2021, implementamos uma lista sequencial que permitiu aos alunos rever as ações básicas de um Lista:
- Inserção
- Listagem
- Busca
- Remoção** (Não trabalhamos a remoção aqui, pois ela será vista na implementação da lista encadeada)

No projeto trabalhamos com uma struct Professor e realizamos a ação de **inserir um professor na lista**, **listar os professores da lista** e **buscar um professor na lista pelo nome**.

## ListaVetor

Neste projeto desenvolvido em nossas aulas do dia 11/08/2021 e 13/08/2021, implementamos uma lista sequencial que permitiu aos alunos entender as ações básicas de um Lista:
- Inserção
- Listagem
- Busca
- Remoção** (Não trabalhamos a remoção aqui, pois ela será vista na implementação da lista encadeada)

No projeto criamos a funcionalidade do **Histórico de um navegador**, em que tínhamos que incluir **urls** na lista de **históricos de navegação**. Desta forma, trabalhamos com uma struct que representava uma url e realizamos a ação de **inserir uma url no histórico de navegação**, **listar as urls do histórico de navegação** e **pesquisar se uma url estava no histórico de navegação**.
