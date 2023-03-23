#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

int main(){
    
    int vetor[4] = {10,20,30,40};
    int* p = vetor;

    printf("&vetor: %lu\n", (long int)&vetor);
    printf("vetor : %lu\n", (long int)vetor);
    printf("p     : %lu\n", (long int)p);
    printf("&p    : %lu\n", (long int)&p);

    

    printf("\n");

    printf("vetor + 0: %lu\n", (long int) (vetor+0) );
    printf("vetor + 1: %lu\n", (long int) (vetor+1) );
    printf("vetor + 2: %lu\n", (long int) (vetor+2) );
    printf("vetor + 3: %lu\n", (long int) (vetor+3) );
    
    printf("\n");

    printf("&vetor[0]: %lu\n", (long int) (&vetor[0]) );
    printf("&vetor[1]: %lu\n", (long int) (&vetor[1]) );
    printf("&vetor[2]: %lu\n", (long int) (&vetor[2]) );
    printf("&vetor[3]: %lu\n", (long int) (&vetor[3]) );

    *p = 100;
    *(p+1) = 200;
    vetor[2] = 300;

    printf("\n");

    printf("vetor[0]: %d\n", vetor[0] );
    printf("vetor[1]: %d\n", vetor[1] );
    printf("vetor[2]: %d\n", vetor[2] );
    printf("vetor[3]: %d\n", vetor[3] );

    return 0;
}