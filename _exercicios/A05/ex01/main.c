#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

char getConceito_v1(float nota){
    char conceito = 'R';
    if (nota >= 9.0){
        conceito = 'A';
    } else if (nota >= 7.0){
        conceito = 'B';
    } else if (nota >= 6.0){
        conceito = 'C';
    }
    return conceito;
}

void getConceito_v2(float nota, char* saida){
    char conceito = getConceito_v1(nota);
    *saida = conceito;
}

int main(){
    
    char conceito;

    conceito = getConceito_v1(9.0);
    printf("%c\n", conceito);
    conceito = getConceito_v1(8.0);
    printf("%c\n", conceito);
    conceito = getConceito_v1(6.0);
    printf("%c\n", conceito);
    conceito = getConceito_v1(5.9);
    printf("%c\n", conceito);

    getConceito_v2(9.0, &conceito);
    printf("%c\n", conceito);
    getConceito_v2(8.0, &conceito);
    printf("%c\n", conceito);
    getConceito_v2(6.0, &conceito);
    printf("%c\n", conceito);
    getConceito_v2(5.9, &conceito);
    printf("%c\n", conceito);
    
    return 0;
}