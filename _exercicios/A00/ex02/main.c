// Escreva um programa que verifique se duas strings são iguais. Não é permitido a utilização de funções prontas.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

bool ehIgual(char* texto1, char* texto2){
    int i = 0;
    while(texto1[i] != '\0' && texto2[i] != '\0'){
        if(texto1[i] != texto2[i]){
            return false;
        }
        i++;
    }
    return true;
}

int main(){

    char texto1[100], texto2[100];
    fgets(texto1, 100, stdin);
    fgets(texto2, 100, stdin);

    printf("%s\n", ehIgual(texto1, texto2) ? "São iguais" : "Não são iguais");
    



    return 0;
}