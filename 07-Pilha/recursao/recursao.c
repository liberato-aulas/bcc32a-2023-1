#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>


void imprimirIterativo(int n){
    for (int i=n; i > 0; i--){
        printf("%d ", i);
    }
}

void imprimirRecursivo(int n){
    if (n == 0) return;
    
    imprimirRecursivo(n-1);
    printf("%d ", n);
}



int main(){
    
    // imprimir(10);
    imprimirRecursivo(10);

    return 0;
}