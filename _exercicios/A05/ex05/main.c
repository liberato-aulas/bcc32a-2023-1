#include<stdio.h>
#include<stdlib.h>

int* criaVetor_v1(int tam, int valor){
    int* novo = (int*) calloc(tam, sizeof(int));
    for (int i=0; i < tam; i++){
        novo[i] = valor;
    }
    return novo;
}

void criaVetor_v2(int tam, int valor, int** saida){
    int* novo = criaVetor_v1(tam, valor);
    *saida = novo;
}

void imprimeVetor(int* v, int tam){
    printf("[");
    for (int i = 0; i < tam; i++){
        printf("%d", v[i]);
        if(i < tam-1) printf(",");
    }
    printf("]\n");
}

int main(){
    int* v1;
    int* v2;

    v1 = criaVetor_v1(10, -5);
    imprimeVetor(v1, 10);

    criaVetor_v2(20, -1, &v2);
    imprimeVetor(v2, 20);
    
    return 0;
}