#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>


int soma(int a, int b){
    return a+b;
}
int subtracao(int a, int b){
    return a-b;
}
int multiplicacao(int a, int b){
    return a*b;
}
int divisao(int a, int b){
    return a/b;
}

int operacaoMatematica1(int a, int b, char operador){
    int resultado = 0;
    if(operador == '+'){
        resultado = a + b;
    } else if (operador == '-'){
        resultado = a - b;
    } else if (operador == '*'){
        resultado = a * b;
    } else if (operador == '/'){
        resultado = a / b;
    } else{
        resultado = -9999999;
    }
    return resultado;
}



int operacaoMatematica2(int a, int b, int (*operacao)(int, int)){
    int resultado = 0;
    resultado = operacao(a,b);
    return resultado;
}


int main(){

    int resultado;

    resultado = soma(10,20);
    printf("soma: %d\n", resultado);
    
    resultado = operacaoMatematica1(10, 20, '*');
    printf("resultado: %d\n", resultado);

    resultado = operacaoMatematica2(10, 20, soma);
    printf("resultado: %d\n", resultado);
    resultado = operacaoMatematica2(10, 20, subtracao);
    printf("resultado: %d\n", resultado);



    return 0;
}