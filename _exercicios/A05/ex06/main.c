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

void vetor_incrementa(int*v, int tam){
    for (int i=0; i < tam; i++){
        v[i] += 1;
    }
}

int main(){
    int v1[5] = {10,20,30,40,50};

    vetor_incrementa(v1, 5); // [11,21,31,41,51]
    imprimeVetor(v1, 5);

    return 0;
}