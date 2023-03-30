#include <stdio.h>
#include<string.h>
#define TAM 50


void leValoresVetor(int* v, int tam){
    for(int i=0; i<tam; i++){
        scanf("%d",&v[i]);
    }
}

void imprimeVetor(int* v, int tam){
    printf("[");
    for (int i=0; i < tam; i++){
        printf("%d", v[i]);
        if(i < tam-1) printf(",");
    }
    printf("]");
    printf("\n");
}

int copiaSubVetor(int* destino, int* origem, int inicio, int fim){
    int qtde = fim - inicio;
    memcpy(destino, origem+inicio, qtde*sizeof(int) );
    return qtde;
}

void dobraValor(int* v, int tam){
    for (int i=0; i < tam; i++){
        v[i] *= 2;
    }
}

int somaValores(int* v, int tam){
    int soma = 0;
    for (int i=0; i < tam; i++){
        soma += v[i];
    }
    return soma;
}

int main(){
    int n;
    int vetor[TAM];
    int copia[TAM];
    scanf("%d",&n);

    leValoresVetor(vetor, n);


    // Função para imprimir o vetor
    imprimeVetor(vetor, n);

    // Função para copiar parte de um vetor. Por exemplo, copiar do vetor A o intervalo das posições 2 e 5 para o vetor B
    int tam = copiaSubVetor(copia, vetor, 2, 5);
    imprimeVetor(copia, tam);

    // Função para dobrar o valor dos elementos do vetor
    dobraValor(vetor, n);
    imprimeVetor(vetor, n);

    // Função para devolver a soma de todos os elementos contidos no vetor.
    int soma = somaValores(vetor, n);
    printf("Soma: %d\n", soma);
    
}