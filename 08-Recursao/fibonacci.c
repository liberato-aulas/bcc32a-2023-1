#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

// int fibonacci(int n){
//     int a = 0;
//     int b = 1;
//     int fibo = 0;

//     for (int i=2; i <= n; i++){
//         fibo = a + b;
//          a = b;
//          b = fibo;   
//     }
//     return fibo;
// }

int fibonacci(int n){
    if (n <= 1) return n;

    return fibonacci(n-1) + fibonacci(n-2);
}


int main(){


    for (int i=1; i <= 10; i++){
        printf("fibonacci(%d) = %d\n", i, fibonacci(i));        
    }

    return 0;
}