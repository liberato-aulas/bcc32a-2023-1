#ifndef TAD_ESTOQUE_H
#define TAD_ESTOQUE_H
// A sequência de declarações será compilada apenas se o nome da macro não estiver definido. 
// A diretiva de compilação #endif define o fim de uma sequência de declarações para todas as diretivas de compilação condicional.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


/***********************************************
* DEFINIÇÃO
************************************************/

/*** DADOS ****/
typedef struct produto {
    int codigo;
    char descricao[100];
    float preco;
} Produto;

typedef struct estoque Estoque;

/*** OPERAÇÕES ****/
/********************************************************
* Cria e inicializa a struct Produto
*********************************************************/
Produto* produto_criar(int codigo, char* descricao, float preco);

/********************************************************
* Destrói a struct Produto criada 
*********************************************************/
void produto_destruir(Produto** endereco);



/********************************************************
* Cria e inicializa a struct Estoque
*********************************************************/
Estoque* estoque_criar(char* nome, int tam);

/********************************************************
* Destrói a struct Estoque criada
*********************************************************/
void estoque_destruir(Estoque** endereco);

/********************************************************
* Importa para a struct Estoque a lista de produtos do
* arquivo.
*********************************************************/
void estoque_importar(Estoque* e, char* nomeArquivo);

/********************************************************
* Imprime todos os produtos
* A função recebe o endereço da struct Estoque e o 
* ponteiro de uma função que será invocada para imprimir
* cada produto do estoque. 
*********************************************************/
void estoque_imprimir(Estoque* e, void (*funcao)(Produto*));

/********************************************************
* Imprime todos os produtos que possuem preços menores que 
* um determinado valor.
* A função recebe o endereço da struct Estoque, o preço base
* e o ponteiro da função que será invocada para imprimir os
* produtos
*********************************************************/
void estoque_menoresQue(Estoque* e, double precoBase, void (*funcao)(Produto*));


#endif

