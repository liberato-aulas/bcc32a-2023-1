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

bool aluno_alteraNota(Aluno* a, int n,float nota);
bool turma_matricular(Turma* t, Aluno* a);
void turma_ajustarTamanho(Turma* t);
float turma_media(Turma* t);

bool aluno_alteraNota(Aluno* a, int n,float nota){
    if(n < a->tamVetor) return false;

    a->notas[n] = nota;
    return true;

}

bool turma_matricular(Turma* t, Aluno* a){

    //COPIA 
    Aluno* copia = (Aluno*) malloc(sizeof(Aluno));
    copia->notas = (float*) calloc(a->tamVetor, sizeof(float));


    copia->ra = a->ra;
    strcpy(copia->nome, a->nome);
    for (int i=0; i < a->tamVetor; i++){
        copia->notas[i] = a->notas[i];
    }
    copia->tamVetor = a->tamVetor;

    t->alunos[t->qtdeAlunos++] = copia;
    return true;
}


void turma_ajustarTamanho(Turma* t){
    
    // Criar o novo espaço reduzido
    Aluno** temp = (Aluno**) calloc(t->qtdeAlunos, sizeof(Aluno*));
    // Copiar os elementos do vetor
    for (int i=0; i < t->qtdeAlunos; i++){
        temp[i] = t->alunos[i];
    }
    // Desalocar o vetor antigo
    free(t->alunos);
    // Atualizar o ponteiro para o novo vetor
    t->alunos = temp;
    t->tamVetor = t->qtdeAlunos;

}

float turma_media(Turma* t){
    float somaMedias = 0;
    for (int i=0; i < t->qtdeAlunos; i++){
        
        float somaNotas = 0;
        float mediaAluno = 0;
        for (int j=0; j < t->alunos[i]->tamVetor; j++){
            somaNotas += t->alunos[i]->notas[j];
        }
        mediaAluno = somaNotas / t->alunos[i]->tamVetor;

        somaMedias += mediaAluno;
    }

    return somaMedias / t->qtdeAlunos;

}
/***********************************************
* Outra versão
************************************************/

float calculaMedia(Aluno* a){
    float somaNotas = 0;    
    for (int j=0; j < a->tamVetor; j++){
        somaNotas += a->notas[j];
    }
    return somaNotas / a->tamVetor;
}

float turma_media(Turma* t){
    float somaMedias = 0;
    for (int i=0; i < t->qtdeAlunos; i++){
        somaMedias += calculaMedia(t->alunos[i]);
    }

    return somaMedias / t->qtdeAlunos;

}

int main(){

a)
x->alunos[1].notas[0]
x->alunos[1]->notas[0]  // 7.5

b)
*(x->alunos).tamVetor
*(x->alunos)->tamVetor  // 4

c)
*(x->alunos)->notas[1]  // 7.9

d)
(*(x->alunos))->ra  // 1

e)
*(*(x->alunos + 1)).notas[0] // 7.5

f)
*( (*x).alunos + 1 ).notas[1]
(*( (*x).alunos + 1 ))->notas[1] // 8.5

g)
* ( * ( (*x).alunos + 1).notas)
* ( * ( (*x).alunos + 1)->notas) // 7.5

h)
*( (*x).alunos[0]->notas + 2) // 8.2



    return 0;
}