#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<time.h>
#include "tad_timer.h"


long int* criaVetorOrdenado(long int n){
    long int * vetor = (long int*) calloc(n, sizeof(long int));
    for (long int i=0; i < n; i++){
        vetor[i] = i;
    }
    return vetor;
}

void preencheOrdenado(long int* v, int tam){
    for (long int i=0; i < tam; i++){
        v[i] = i;
    }

}

long int* criaVetorAleatorio(long int n){
    long int * vetor = (long int*) calloc(n, sizeof(long int));
    // srand(time(NULL));
    for (long int i=0; i < n; i++){
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

long int buscaSequencial(long int* v, long int tam, int elemento){
    long int i;
    for (i=0; i < tam; i++){
        if (elemento == v[i]) return i;
    }
    
    return -1;
}

long int buscaBinaria(long int* v, long int tam, int elemento){
    long int inicio = 0;
    long int fim = tam-1;
    long int meio;

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
    
    long int n = 2 * 1000*1000*1000;
    // long int vetor[n];
    long int *vetor = (long int*) calloc(n, sizeof(long int));
    Timer* t = timer_criar();
    timer_start(t);

    printf("Preenchendo vetor\n");
    preencheOrdenado(vetor, n);


    // long int* vOrdenado = criaVetorOrdenado(n);
    // long int* vAleatorio = criaVetorAleatorio(n);

    timer_stop(t);
    printf("Tempo: %.2f\n", timer_resultado(t));
    timer_reset(t);
    
    long int num = n-1;

    printf("Iniciando busca\n");
    timer_start(t);

    // printf("Busca: %ld\n", buscaSequencial(vetor, n, num));
    printf("Busca: %ld\n", buscaBinaria(vetor, n, num));
    // printf("Busca: %ld\n", buscaBinaria(vOrdenado, n, num));

    // int interacoes = 1000*1000*1000;
    // for (int i=0; i<interacoes; i++) {
    //     soma += i;
    //     divisao /= 2;
    // }

    timer_stop(t);
    printf("Tempo: %.2f\n", timer_resultado(t));
    timer_desalocar(&t);


    

    return 0;
}