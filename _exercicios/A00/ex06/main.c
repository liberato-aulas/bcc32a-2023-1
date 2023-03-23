#include <stdio.h>
int main()
{
    int h_inicial, h_final, m_inicial, m_final;
    int dif;
    scanf("%d %d %d %d", &h_inicial, &m_inicial, &h_final, &m_final);
    

    dif = ( ( h_final * 60 ) + m_final) - ( ( h_inicial * 60 ) + m_inicial );
    // Se a diferença for menor ou igual a zero, significa que o jogo durou 24 horas
    if(dif <= 0 ) dif += 24*60;

    printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n", dif/60, dif%60);
    return 0;
}