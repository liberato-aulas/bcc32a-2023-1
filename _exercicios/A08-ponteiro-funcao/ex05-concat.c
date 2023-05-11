#include <stdio.h>
#include <stdlib.h>

// Função concat
int* concat(int *array1, int n1, int *array2, int n2, int* endNovoTamanho) {
    int *result = (int*) malloc((n1 + n2) * sizeof(int)); // aloca memória para o array resultante
    if (result == NULL) { // verifica se a alocação de memória falhou
        printf("Erro ao alocar memória.\n");
        return NULL;
    }

    int i, j;

    // copia os elementos do primeiro array para o resultado
    for (i = 0; i < n1; i++) {
        result[i] = array1[i];
    }

    // copia os elementos do segundo array para o resultado
    for (j = 0; j < n2; j++) {
        result[i++] = array2[j];
    }
    *endNovoTamanho = n1 + n2;
    return result;
}

void imprimeVetor(int* v, int tam){
    printf("[");
    for (int i = 0; i < tam; i++){
        printf("%d", v[i]);
        if(i < tam-1) printf(",");
    }
    printf("]\n");
}

int main() {
    int vetor1[5] = {1, 2, 3, 4, 5};
    int vetor2[5] = {6, 7, 8, 9, 10};
    int tamanho;

    int *result = concat(vetor1, 5, vetor2, 5, &tamanho); // concatena os dois arrays


    imprimeVetor(result, tamanho); // imprime o array resultante

    free(result); // libera a memória alocada

    return 0;
}