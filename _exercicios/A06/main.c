#include <stdio.h>
#include "tad_timer.h"

int main(){
		/**
     * Medir o tempo de execução de um trecho de código que realiza
     * 1.000.000.000 de somas e divisões  
     */
    long int soma = 0;
    double divisao = 1;
        
    Timer* t1 = timer_criar();

    timer_start(t1);    
    //-----------------------------------------------
    int interacoes = 1000*1000*1000;
    for (int i=0; i<interacoes; i++) {
        soma += i;
        divisao /= 2;
    }
    //-----------------------------------------------
    timer_stop(t1);

    printf("Tempo decorrido: %.2f\n", timer_resultado(t1));
    timer_desalocar(&t1);    
}