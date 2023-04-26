#ifndef TAD_ESTOQUE_H
#define TAD_ESTOQUE_H
// A sequência de declarações será compilada apenas se o nome da macro não estiver definido. 
// A diretiva de compilação #endif define o fim de uma sequência de declarações para todas as diretivas de compilação condicional.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

/***********************************************
* DEFINIÇÃO
************************************************/

/*** DADOS ****/
typedef struct produto Produto;

typedef struct estoque Estoque;

/*** OPERAÇÕES ****/
Produto* produto_criar(int codigo, char* descricao, float preco);
void produto_destruir(Produto** endereco);
void produto_imprimir(Produto* p);

Estoque* estoque_novo(char* nome, int tam);
void estoque_destruir(Estoque** endereco);
int estoque_importar(char* nomeArquivo);
void estoque_imprimir(Estoque* e);


#endif

