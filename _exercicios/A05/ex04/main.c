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

int main(){

    int v1[5] = {1,2,3,4,5};
    int v2[10] = {10,20,30,40,50,60,70,80,90,100};
    imprimeVetor(v1, 5);
    imprimeVetor(v2, 10);
    return 0;
}