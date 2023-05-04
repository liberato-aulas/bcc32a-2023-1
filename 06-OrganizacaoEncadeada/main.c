#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct no{
    int dado;
    struct no* prox;
} No;

No* criaListaExemplo(){
    No* e1 = (No*) malloc(sizeof(No));
    No* e2 = (No*) malloc(sizeof(No));
    No* e3 = (No*) malloc(sizeof(No));

    e1->dado = 1;
    e2->dado = 2;
    e3->dado = 3;

    e1->prox = e2;
    e2->prox = e3;
    e3->prox = NULL;

    return e1;
}

void imprimeEncadeamento(No* no){

    printf("[");
    while( no != NULL ){
        printf("%d", no->dado);
        if (no->prox != NULL) printf(",");
        no = no->prox; 
    }
    printf("]\n");
    

}

void insereNoFim(No* no, int elemento){
    while(no->prox != NULL) no = no->prox;

    No* novo = (No*) malloc(sizeof(No));
    novo->dado = elemento;
    novo->prox = NULL;

    no->prox = novo;
}

int main(){
    No* primeiro = criaListaExemplo();
    imprimeEncadeamento(primeiro); // [1,2,3]
    insereNoFim(primeiro, 4);
    imprimeEncadeamento(primeiro); // [1,2,3,4]
    
    return 0;
}