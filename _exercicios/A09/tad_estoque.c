#include  "tad_estoque.h"

/***********************************************
* IMPLEMENTACAO
************************************************/

struct produto {
    int codigo;
    char descricao[50];
    float preco;
};

struct estoque{
	char nome[50];
	Produto *produtos;
	int tamEstoque;
	int qtdProdutos;
};