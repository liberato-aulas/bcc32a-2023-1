//  Escreva um programa que inverte uma string. Faça um algoritmo que não use espaço adicional.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

void removeQuebraLinha(char *texto){
    int tamanho = strlen(texto);
    if(texto[tamanho-1] == '\n'){
        texto[tamanho-1] = '\0';
    }
}

void inverteTexto(char *texto){
    int tamanho = strlen(texto);
    
    int i = 0;
    int j = tamanho-1;

    while (i<j){
        char aux = texto[i];
        texto[i] = texto[j];
        texto[j] = aux;
        i++;
        j--;
    }
        
}

int main(){
    
    char texto[200];
    // ENTRADA
    fgets(texto, 200, stdin);
    removeQuebraLinha(texto);

    // PROCESSAMENTO
    inverteTexto(texto);

    // SAIDA
    printf("%s\n", texto);


    return 0;
}