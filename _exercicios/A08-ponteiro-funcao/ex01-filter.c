#include <stdio.h>
#include <stdlib.h>

void imprimeVetor(int* v, int tam){
    printf("[");
    for (int i = 0; i < tam; i++){
        printf("%d", v[i]);
        if(i < tam-1) printf(",");
    }
    printf("]\n");
}

// Função de filtro
int *filter(int *array, int n, int (*condition)(int), int* saidaTamanho) {
    int *novo = (int *) malloc(n * sizeof(int)); // aloca novo array
    int cont = 0;
    for (int i = 0; i < n; i++) {
        if (condition(array[i])) { // verifica se o elemento satisfaz a condição
            novo[cont++] = array[i]; // adiciona o elemento no novo array
        }
    }
    novo = (int *) realloc(novo, cont * sizeof(int)); // redimensiona o array para o tamanho correto

    *saidaTamanho = cont;
    return novo;
}

// Exemplo de uso
int e_par(int x) {
    return x % 2 == 0; // condição para filtrar números pares
}

int main() {
    int vetor[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};			
    int tamanho = -1;
    int *novo = filter(vetor, 10, e_par, &tamanho); // filtra apenas números pares

	if(novo == NULL){
        if (tamanho == -1)
            printf("Erro na criação do vetor\n");
        else
            printf("Vetor vazio\n");
    } else {
        imprimeVetor(novo, tamanho);
    }
    
    free(novo); // libera a memória alocada para o novo array
    return 0;
}