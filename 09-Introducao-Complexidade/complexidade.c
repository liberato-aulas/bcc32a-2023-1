#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<time.h>
#include "tad_timer.h"


typedef unsigned long int Inteiro;

Inteiro* criaVetorOrdenado(Inteiro n){
    Inteiro * vetor = (Inteiro*) calloc(n, sizeof(Inteiro));
    for (Inteiro i=0; i < n; i++){
        vetor[i] = i;
    }
    return vetor;
}



Inteiro* criaVetorAleatorio(Inteiro n){
    Inteiro * vetor = (Inteiro*) calloc(n, sizeof(Inteiro));
    srand(time(NULL));
    for (Inteiro i=0; i < n; i++){
        vetor[i] = rand() % (8 * n);
    }
    return vetor;
}

void imprimeVetor(long int* v, long int tam){
    printf("[");
    for (long int i=0; i < tam; i++){
        printf("%ld", v[i]);
        if (i < tam-1) printf(",");
    }
    printf("]");
    printf("\n");
}

long int buscaSequencial(Inteiro* v, Inteiro tam, int elemento){
    Inteiro i;
    for (i=0; i < tam; i++){
        if (elemento == v[i]) return i;
    }
    
    return -1;
}

Inteiro buscaBinaria(Inteiro* v, Inteiro tam, int elemento){
    Inteiro inicio = 0;
    Inteiro fim = tam-1;
    Inteiro meio;

    while (inicio <= fim){
        meio = inicio + ( (fim - inicio) / 2 );
        if (elemento == v[meio]){
            return meio;
        } else if (elemento < v[meio]){
            fim = meio - 1;
        } else {
            inicio = meio + 1;
        }
    }

    return -1;
}



int main(){
    
    Inteiro n = 10;
    Inteiro* v = criaVetorAleatorio(n);

    imprimeVetor(v, n);


    

    return 0;
}