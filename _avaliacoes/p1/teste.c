#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

typedef struct aluno {
    int ra;
    char nome[8];
    float *notas;
    int tamVetor;
} Aluno;

typedef struct turma {
    char codigo[8];
    Aluno **alunos;
    int qtdeAlunos;
    int tamVetor;
} Turma;



void teste_exercicio02(Turma* x){
    // printf("%.1f\n", x->alunos[1].notas[0]);
    printf("%.1f\n", x->alunos[1]->notas[0]);
    
    // printf("%d\n", (*(x->alunos)).tamVetor);
    printf("%d\n", (*(x->alunos))->tamVetor);

    printf("%.1f\n", (*(x->alunos))->notas[1]);
    printf("%d\n", (*(x->alunos))->ra);
    printf("%.1f\n", (*(*(x->alunos + 1))).notas[0]);

    // printf("%.1f\n", (*((*x).alunos + 1)).notas[1]);
    printf("%.1f\n", (*((*x).alunos + 1))->notas[1]);
    
    // printf("%.1f\n", *(*((*x).alunos + 1).notas));
    printf("%.1f\n", (*(*((*x).alunos + 1))->notas));

    printf("%.1f\n", *((*x).alunos[0]->notas + 2));


// a) x->alunos[1].notas[0]
// b) *(x->alunos).tamVetor
// c) *(x->alunos)->notas[1]
// d) (*(x->alunos))->ra
// e) *(*(x->alunos + 1)).notas[0]
// f) *((*x).alunos + 1).notas[1]
// g) *(*((*x).alunos + 1).notas)
// h) *((*x).alunos[0]->notas + 2)


}

int main(){
    
    Turma* x = (Turma*) malloc(sizeof(Turma));
    strcpy(x->codigo, "IC2A");
    x->alunos = (Aluno**) calloc(5, sizeof(Aluno*));
    x->tamVetor = 5;
    x->qtdeAlunos = 2;

    Aluno* a1 = (Aluno*) malloc(sizeof(Aluno));
    a1->ra = 1;
    strcpy(a1->nome, "Joao");
    a1->notas = (float*)calloc(4, sizeof(float));
    a1->tamVetor = 4;
    a1->notas[0] = 8.5;
    a1->notas[1] = 7.9;
    a1->notas[2] = 8.2;
    a1->notas[3] = 9.5;
    
    Aluno* a2 = (Aluno*) malloc(sizeof(Aluno));
    a2->ra = 2;
    strcpy(a2->nome, "Maria");
    a2->notas = (float*)calloc(2, sizeof(float));
    a2->tamVetor = 2;
    a2->notas[0] = 7.5;
    a2->notas[1] = 8.5;

    x->alunos[0] = a1;
    x->alunos[1] = a2;

    teste_exercicio02(x);

    return 0;
}