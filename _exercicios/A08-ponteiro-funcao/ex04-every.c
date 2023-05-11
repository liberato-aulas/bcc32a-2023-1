#include <stdio.h>

// Função every
int every(int *array, int n, int (*condition)(int)) {
    for (int i = 0; i < n; i++) {
        if (!condition(array[i])) { // verifica se algum elemento não satisfaz a condição
            return 0; // retorna falso se algum elemento não satisfaz a condição
        }
    }
    return 1; // retorna verdadeiro se todos os elementos satisfazem a condição
}

// Exemplo de uso
int e_positivo(int x) {
    return x > 0; // condição para verificar se todos os números são positivos
}

int main() {
    int v1[10] = {1, 2, 3, 4, 5, -6, 7, 8, 9, 10};
    int v2[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    

    int result = every(v1, 10, e_positivo); // verifica se todos os números são positivos

    if (result) {
        printf("Todos os números são positivos.\n");
    } else {
        printf("Alguns dos números são negativos.\n");
    }

    result = every(v2, 10, e_positivo); // verifica se todos os números são positivos
    if (result) {
        printf("Todos os números são positivos.\n");
    } else {
        printf("Alguns dos números são negativos.\n");
    }

    return 0;
}