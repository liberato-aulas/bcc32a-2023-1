// Escreva um programa que verifique se duas strings são iguais. Não é permitido a utilização de funções prontas.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

void removeEspacos(char* texto){
    int i = 0;
    // remove espaco no inicio
    for(i = 0; texto[i] == ' '; i++);
    memcpy(texto, texto+i, strlen(texto) - i);
    
    // remove espaco no final
    for(i = strlen(texto)-1; texto[i] == ' '; i--);
    texto[i+1] = '\0';

    // remove espacos no meio
    for(i = 0; texto[i] != '\0'; i++){

        if (texto[i] == ' ' && texto[i+1] == ' '){
            int j = i+1;
            while(texto[j] == ' '){
                j++;
            }
            memcpy(texto+i+1, texto+j, strlen(texto) - j + 1);            
        }
    }
}

void removeQuebraLinha(char *texto){
    int tamanho = strlen(texto);
    if(texto[tamanho-1] == '\n'){
        texto[tamanho-1] = '\0';
    }
}

int main(){
    
    char texto[100];
    fgets(texto, 100, stdin);
    removeQuebraLinha(texto);

    printf("[%s]\n", texto);
    removeEspacos(texto);
    printf("[%s]\n", texto);

    

    return 0;
}