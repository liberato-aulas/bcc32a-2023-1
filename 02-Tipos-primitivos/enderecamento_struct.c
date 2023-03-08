#include <stdio.h>



// typedef int inteiro;

// struct aluno {
//     int ra;
//     char nome[10];
//     float coeficiente;
// };
// typedef struct aluno Aluno;

typedef struct aluno {
    int ra;
    char nome[8];
    float coeficiente;
} Aluno;





int main(){

    
    struct aluno a1;
    Aluno a2;

    printf("%u\n", &a1);
    printf("%u\n", &a1.ra);
    printf("%u\n", &a1.nome);
    printf("%u\n", &a1.coeficiente);
   

}