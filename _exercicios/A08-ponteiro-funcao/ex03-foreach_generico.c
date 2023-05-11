
#include <stdio.h>

typedef struct{
    int codigo;
    char nome[40];
    float preco;
} Produto;

// Função forEach
void forEach(void *array, int n, int tamDado, void (*func)(void*)) {
    for (int i = 0; i < n; i++) {
        func(array + (i*tamDado)); // executa a função para cada elemento do array
    }
}

void imprime_int(void* endereco) {
    int elemento = *(int*)endereco;
    printf("[%d]", elemento); 
}
void imprime_char(void* endereco) {
    int elemento = *(char*)endereco;
    printf("[%c]", elemento); 
}

void imprime_Produto(void* endereco) {
    Produto elemento = *(Produto*)endereco;

    printf("[%d, %s, %.2f]", elemento.codigo, elemento.nome, elemento.preco); 
}



int main() {
    
    int vet_int[10] = {1,2,3,4,5,6,7,8,9,10};

    char vet_char[5] = {'a','e','i','o','u'};

    Produto vet_prod[3] = {{1, "Mouse", 89.90},{2, "Teclado", 155.5}, {3, "Monitor", 500.00}};

    forEach(vet_int, 10, sizeof(int), imprime_int);
    printf("\n");
    forEach(vet_char, 5, sizeof(char), imprime_char);
    printf("\n");
    forEach(vet_prod, 3, sizeof(Produto), imprime_Produto);


    return 0;
}