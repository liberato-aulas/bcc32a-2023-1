#include <stdio.h>
#include <stdlib.h>

int main(int qtdParametros, char const *vetor[]){

    // Imprime os parâmetros recebidos pelo console
    printf("PARAMETROS RECEBIDOS: \n");
    for (int i=0; i < qtdParametros; i++){
        printf("[%d]: %s\n",i, vetor[i]);
    }




    int a, b;
    
    // ENTRADA
    a = atoi(vetor[1]);
    b = atoi(vetor[2]);
    
    // PROCESSAMENTO
    int soma = a + b;

    // SAÍDA
    printf("%d\n", soma);

    return 0;
}
