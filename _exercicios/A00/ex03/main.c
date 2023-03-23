#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>


bool isVogal(char c){
    char vogais[] = "aeiouAEIOU";
    int tam = strlen(vogais);
    for (int i=0; i < tam; i++){
        if(c == vogais[i]) return true;
    }
    return false;
}
int contaVogais(char* texto){
        
    int cont = 0;
    int tam = strlen(texto);
    for (int i=0; i < tam; i++){
        if(isVogal(texto[i])){
            cont++;
        }
    }
    return cont;

}

int main(){
    
    char texto[102];
    fgets(texto, 100, stdin);

    int qtdeVogais = contaVogais(texto);

    printf("Vogais: %d\n", qtdeVogais);

    return 0;
}