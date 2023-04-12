#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

bool vet_toString(int* v, int tam, char* saida){
    *saida = '\0';
    strcat(saida, "[");
    for (int i=0; i < tam; i++){
        char elemento[20];
        sprintf(elemento, "%d", v[i]); // converte int para char[]
        strcat(saida, elemento);
        if(i < tam-1) strcat(saida, ",");
    }
    strcat(saida, "]");
    return true;
}


int main(){
    int v[5] = {1,2,3,4,50};

    char str[400];
    
    
    vet_toString(v, 5, str);
    printf("%s\n", str);


    return 0;
}