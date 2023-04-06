#include <stdio.h>

void inicializaVetor(int* v, int tam, int valor){
    for (int i = 0; i < tam; i++){
        v[i] = valor;
    }
}

void imprimeVetor(int* v, int tam){
    printf("[");
    for (int i = 0; i < tam; i++){
        printf("%d", v[i]);
        if(i < tam-1) printf(",");
    }
    printf("]\n");
}

void multiplicaValores(int* v, int tam, int fator){
    for (int i = 0; i < tam; i++){
        v[i] *= fator;
    }
}

int main(){

    int vet1[10];
    int vet2[5];

    int i;
    // Inicializa o vetor com o valor 1
    inicializaVetor(vet1, 10, 1);
    

    // Imprime o resultado da inicialização
    imprimeVetor(vet1, 10);
    
    
    // Multiplica todos os valores por -1
    multiplicaValores(vet1, 10, -1);
    

    // Imprime o resultado da multiplicação
    imprimeVetor(vet1, 10);
    

    // Inicializa o vetor VET2 com o valor 20
    inicializaVetor(vet2, 5, 20);
     

    // Imprime o resultado da inicialização
    imprimeVetor(vet2, 5);
    

    // Multiplica todos os valores por 2
    multiplicaValores(vet2, 5, 2);

    // Imprime o resultado da inicialização
    imprimeVetor(vet2, 5);

}