#include "pilha.h"

/**************************************
* DADOS
**************************************/
typedef struct no{
	TipoElemento dado;
	struct no    *prox;
}No;

struct pilha{
	No *topo;
	int qtdeElementos;
};



/**************************************
* FUNÇÕES AUXILIARES
**************************************/




/**************************************
* IMPLEMENTAÇÃO
**************************************/