#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

// int fatorial(int n){
//     int fatorial = 1;
//     for (int i=n; i >= 1; i--){
//         fatorial = fatorial * i;
//     }
//     return fatorial;
// }

int fatorial(int n){
    if (n == 1) return 1;

    return n * fatorial(n-1);
}


int main(){
    printf("%d\n", fatorial(6));
    
    return 0;
}