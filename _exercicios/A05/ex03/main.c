#include<stdio.h>
#include<stdlib.h>


int getInverso_v1(int n){
    int parteInteira, resto, inverso=0;

    
    while (n > 0){
        resto = n % 10;
        parteInteira = n / 10;

        inverso = inverso * 10 + resto;
        n = parteInteira;
    }
    return inverso;
}

void getInverso_v2(int n, int* saida){
    int inverso = getInverso_v1(n);
    *saida = inverso;
}
int main(){

    int inverso;

    inverso = getInverso_v1(254);
    printf("%d\n", inverso);
    inverso = getInverso_v1(123456);
    printf("%d\n", inverso);

    getInverso_v2(254, &inverso);
    printf("%d\n", inverso);
    getInverso_v2(123456, &inverso);
    printf("%d\n", inverso);


    return 0;
}