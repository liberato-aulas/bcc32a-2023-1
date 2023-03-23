#include<stdio.h>
#include<string.h>
#include<stdbool.h>


void removeQuebraLinha(char* texto){
    int tam = strlen(texto);
    if(texto[tam-1] == '\n') texto[tam-1] = '\0';
}

void imprimePalavraOculta(char* linha){
    char palavraOculta[51];
    int tam = strlen(linha);
    bool isPrimeiraLetra = true;
    int pos = 0;

    for (int i=0; i < tam; i++){
        if(linha[i] != ' '){
            if (isPrimeiraLetra){                
                palavraOculta[pos++] = linha[i];
                isPrimeiraLetra = false;
            }
        } else {
            isPrimeiraLetra = true;

        }
    }
    palavraOculta[pos] = '\0';
    puts(palavraOculta);
}


int main(){
    int n;
    char texto[51];
    
    scanf("%d", &n);
    getchar(); // limpa o \n que fica no buffer

    for (int i=0; i < n; i++){
        fgets(texto, 51, stdin);
        removeQuebraLinha(texto);
        imprimePalavraOculta(texto);        
    }

    return 0;
}

 