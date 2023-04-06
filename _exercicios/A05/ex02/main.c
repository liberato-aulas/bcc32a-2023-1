#include <stdio.h>

int main(){

    int vet1[10];
    int vet2[5];

    int i;
    // Inicializa o vetor com o valor 1
    for (i = 0; i < 10; i++){
        vet1[i] = 1;
    }

    // Imprime o resultado da inicialização
    printf("[");
    for (i = 0; i < 10; i++){
        printf("%d", vet1[i]);
        if(i < 9) printf(",");
    }
    printf("]\n");
    
    // Multiplica todos os valores por -1
    for (i = 0; i < 10; i++){
        vet1[i] *= -1;
    }

    // Imprime o resultado da multiplicação
    printf("[");
    for (i = 0; i < 10; i++){
        printf("%d", vet1[i]);
        if(i < 9) printf(",");
    }
    printf("]\n");

    // Inicializa o vetor VET2 com o valor 20
    for (i = 0; i < 5; i++){
        vet2[i] = 20;
    } 

    // Imprime o resultado da inicialização
    printf("[");
    for (i = 0; i < 5; i++){
        printf("%d", vet2[i]);
        if(i < 4) printf(",");
    }
    printf("]\n");

    // Multiplica todos os valores por 2
    for (i = 0; i < 5; i++){
        vet2[i] *= 2;
    }

    // Imprime o resultado da inicialização
    printf("[");
    for (i = 0; i < 5; i++){
        printf("%d", vet2[i]);
        if(i < 4) printf(",");
    }
    printf("]\n");

}