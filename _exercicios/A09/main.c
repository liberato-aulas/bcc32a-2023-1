#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#include "tad_estoque.h"

void imprimeProduto(Produto* p){
    printf("Cod  : %d\n", p->codigo);
    printf("Desc : %s\n", p->descricao);
    printf("Preco: %.2f\n", p->preco);
    printf("\n");
}
void imprimeProdutoPreco(Produto* p){    
    printf("Preco: %.2f\n", p->preco);
    
}


int main(){

 
   Estoque* estoque = estoque_criar("loja 1", 4500);

   estoque_importar(estoque, "lista.txt");

//    estoque_imprimir(estoque, imprimeProdutoPreco);

   estoque_menoresQue(estoque, 10, imprimeProduto);



    


    return 0;
}