#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>


int dobra(int n){
    return n*2;
}

int incrementa(int n){
    return n+1;
}

void map(int* v, int tam, int (*funcao)(int)){
    for (int i=0; i < tam; i++){
        v[i] = funcao(v[i]);
    }
}

void imprimeVetor(int* v, int tam){
    printf("[");
    for (int i=0; i < tam; i++){
        printf("%d", v[i]);
        if(i < tam-1) printf(",");
    }
    printf("]");
    printf("\n");
}

int main(){
    
    int v1[5] = {1,2,3,4,5};
    imprimeVetor(v1,5);

    // v1.map(dobra)
    map(v1, 5, incrementa);
    imprimeVetor(v1,5);
    



    return 0;
}