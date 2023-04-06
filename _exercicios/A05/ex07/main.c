#include<stdio.h>
#include<stdlib.h>

void imprimeVetor(int* v, int tam){
    printf("[");
    for (int i = 0; i < tam; i++){
        printf("%d", v[i]);
        if(i < tam-1) printf(",");
    }
    printf("]\n");
}

int vetor_dobraTamanho(int** endVetor, int tam){
    int* vetorOriginal = *endVetor;
    // 1. Alocar um novo vetor com o dobro do tamanho do vetor recebido por parâmetro. 
    int* novo = (int*) calloc(tam*2, sizeof(int));

    // 2. Copiar os valores para o vetor novo
    int i;
    for (i=0; i < tam; i++){
        novo[i] = vetorOriginal[i];
    }
    // 3. Preencher com `0` as novas posições
    for (int j=i; j < tam*2; j++){
        novo[j] = 0;
    }
    // 4. Desalocar o vetor antigo
    free(vetorOriginal);
    // 5. Atualizar a referência do vetor recebido por parâmetro  
    *endVetor = novo;

    return tam*2;
}

int main(){
    int* vet = (int*) calloc(5, sizeof(int));
    vet[0] = 10;
    vet[1] = 20;
    vet[2] = 30;
    vet[3] = 40;
    vet[4] = 50;

    imprimeVetor(vet, 5);
    int novoTamanho = vetor_dobraTamanho(&vet, 5);
    imprimeVetor(vet, 10);

    return 0;
}