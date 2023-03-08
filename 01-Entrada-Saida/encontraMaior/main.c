#include <stdio.h>
#include <limits.h>



int main(){
    int qtde,n;
    int maior = INT_MIN;


    // ENTRADA / PROCESSAMENTO
    scanf("%d", &qtde);   

    for (int i=0; i < qtde; i++){
        scanf("%d", &n);
        if (n > maior) maior = n;
    }


    //SAIDA
    printf("%d\n", maior);

}