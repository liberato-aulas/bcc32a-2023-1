#include "lista.h"


/**************************************
* DADOS
**************************************/
typedef struct no{
	TipoElemento dado;
	struct no    *ant;
	struct no    *prox;
}No;

struct lista{
	No *inicio;
	No *fim;
	int qtde;
};


/**************************************
* FUNÇÕES AUXILIARES
**************************************/



/**************************************
* IMPLEMENTAÇÃO
**************************************/

