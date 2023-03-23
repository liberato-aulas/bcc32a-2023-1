#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

void removeQuebraLinha(char* texto){
    int tamanho = strlen(texto);
    if (texto[tamanho-1] == '\n'){
        texto[tamanho-1] = '\0';
    }
}


int main(){
    int n;
    
    char palavras[50][52];

    scanf("%d", &n);
    getchar();


    while(n != 0){
        int maior = 0;

        // Leitura das palavras e verificação da maior
        for (int i=0; i < n; i++){
            fgets(palavras[i], 51, stdin);
            removeQuebraLinha(palavras[i]);

            if (strlen(palavras[i]) > maior){
                maior = strlen(palavras[i]);
            }
        }

        // Deslocamento e preenchimento de espaços em branco no inicio da string
        for (int i=0; i < n; i++){
            
            int tamanho = strlen(palavras[i]);
            int diferenca = maior - tamanho;

            // Deslocamento
            for (int j=tamanho; j >=0; j--){
                palavras[i][j+diferenca] = palavras[i][j];                
            }
            // Ao invés do for pode-se usar o memcpy para efetuar o deslocamento
            // memcpy(palavras[i]+diferenca, palavras[i], strlen(palavras[i])+1);

            // Preenchimento de espaços
            for (int j=0; j < diferenca; j++){
                palavras[i][j] = ' ';
            }

            printf("%s\n", palavras[i]);
        }
        printf("\n");
        scanf("%d\n", &n);
    }

    return 0;
}