#include <stdio.h>
#include <stdlib.h>

#include <stdarg.h>


// Tipo va_list
// Macros va_start, va_arg, va_end
int soma2(int n, ...){
    int soma = 0;
    va_list args;
    va_start(args, n);

    for (int i=0; i < n; i++){
        soma += va_arg(args, int);
    }

    va_end(args);
    return soma;
}

int soma1(int* v, int tam){
    int soma = 0;
    for (int i=0; i < tam; i++){
        soma += v[i];
    }
    return soma;
}


int main(){
    


    int vetor[5] = {10,20,30,40,50};
    int resultado = soma1(vetor, 5);
    printf("%d\n", resultado);


    resultado = soma2(2,4,6);
    printf("%d\n", resultado);

    resultado = soma2(4,1,1,1,1);
    printf("%d\n", resultado);

    return 0;
}