#include  "tad_estoque.h"

/***********************************************
* IMPLEMENTACAO
************************************************/



struct estoque{
	char nome[50];
	Produto **produtos;
	int tamEstoque;
	int qtdProdutos;
};



// Remove espaços em branco do início e do final da string
void trim(char *str){
    int posIni = 0, j, k = 0;
    int posFim = strlen(str)-1;
 
    // Encontra espaços no início
    while (str[posIni] == ' ' || str[posIni] == '\t' || str[posIni] == '\n'){
        posIni++;
    }

    // Encontra espaços no final
    while (str[posFim] == ' ' || str[posFim] == '\t' || str[posFim] == '\n'){
        posFim--;
    }
 
    // Faz o deslocamento para a esquerda
    for (j = posIni; j <= posFim; j++){
        str[k] = str[j];
        k++;
    }

    str[k] = '\0'; 
}


/********************************************************
* Cria e inicializa a struct Produto
*********************************************************/
Produto* produto_criar(int codigo, char* descricao, float preco){

    

    Produto* novo = (Produto*) calloc(1, sizeof(Produto));
    novo->codigo = codigo;
    strcpy(novo->descricao, descricao);
    novo->preco = preco;
    return novo;
}

/********************************************************
* Destrói a struct Produto criada 
*********************************************************/
void produto_destruir(Produto** endereco){
    free(*endereco);
    *endereco = NULL;
}


/********************************************************
* Cria e inicializa a struct Estoque
*********************************************************/
Estoque* estoque_criar(char* nome, int tam){
    Estoque* novo = (Estoque*) calloc(1, sizeof(Estoque));
    strcpy(novo->nome, nome);
    novo->produtos = (Produto**) calloc(tam, sizeof(Produto*));
    novo->tamEstoque = tam;
    novo->qtdProdutos = 0;
    return novo;
}

/********************************************************
* Destrói a struct Estoque criada
*********************************************************/
void estoque_destruir(Estoque** endereco){
    Estoque* e = *endereco;
    for (int i=0; i < e->qtdProdutos; i++){
        free(e->produtos[i]);
    }
    free(e);
    *endereco = NULL;
}

/********************************************************
* Importa para a struct Estoque a lista de produtos do
* arquivo.
*********************************************************/
void estoque_importar(Estoque* e, char* nomeArquivo){
    

    FILE* arquivo = fopen(nomeArquivo,"r");
    char linha[501];
    int tam;
    char* token;
    char temp[200];
    int codigo;
    char descricao[100];
    float preco;
    Produto* p;


    int cont = 0;

    

    while (fgets(linha, 500, arquivo) != NULL){
        

        tam = strlen(linha);
        // Tira o \n do final
        if (linha[tam-1] == '\n') linha[tam-1] = '\0';

        // Código
        token = strtok(linha, "|");
        strcpy(temp, token);
        trim(temp);
        sscanf(temp, "%d", &codigo);

        // Descricao
        token = strtok(NULL, "|");
        strcpy(temp, token);
        trim(temp);
        strcpy(descricao, temp);
        
        // Preço
        token = strtok(NULL, "|");
        strcpy(temp, token);
        trim(temp);
        sscanf(temp, "U$ %f", &preco);

        p = malloc(sizeof(Produto));
        p->codigo = codigo;
        strcpy(p->descricao, descricao);

        p = produto_criar(codigo, descricao, preco);
        e->produtos[e->qtdProdutos++] = p;
    }

}

/********************************************************
* Imprime todos os produtos
* A função recebe o endereço da struct Estoque e o 
* ponteiro de uma função que será invocada para imprimir
* cada produto do estoque. 
*********************************************************/
void estoque_imprimir(Estoque* e, void (*funcao)(Produto*)){
    for (int i=0; i < e->qtdProdutos; i++){
        funcao(e->produtos[i]);
    }
}

/********************************************************
* Imprime todos os produtos que possuem preços menores que 
* um determinado valor.
* A função recebe o endereço da struct Estoque, o preço base
* e o ponteiro da função que será invocada para imprimir os
* produtos
*********************************************************/
void estoque_menoresQue(Estoque* e, double precoBase, void (*funcao)(Produto*)){
    for (int i=0; i < e->qtdProdutos; i++){
        if (e->produtos[i]->preco <= precoBase){
            funcao(e->produtos[i]);
        }
    }
}