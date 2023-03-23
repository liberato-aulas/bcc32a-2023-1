#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int somaVetor(int* v, int n){
    int soma = 0;
    for (int i=0; i < n; i++){
        soma += v[i];
    }
    return soma;
}

int main(){
    int n;
    int vetor[100];

    // ENTRADA
    scanf("%d\n", &n);
    for (int i=0; i < n; i++){
        scanf("%d", vetor+i);
    }

    // PROCESSAMENTO
    int soma = somaVetor(vetor, n);


    // SAIDA
    printf("%d\n", soma);


    return 0;
}