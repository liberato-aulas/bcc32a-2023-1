
#include <stdio.h>

// Função forEach
void forEach(int *array, int n, void (*func)(int)) {
    for (int i = 0; i < n; i++) {
        func(array[i]); // executa a função para cada elemento do array
    }
}

// Exemplo de uso
void print_int(int x) {
    printf("[%d]", x); // imprime o valor do inteiro
}

int main() {
    int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    printf("\n");
    

    forEach(array, 10, print_int); // imprime cada elemento do array

    return 0;
}