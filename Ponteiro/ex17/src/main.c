/*
Escreva uma funcao que dado um numero real passado como parametro, retorne a parte inteira e a parte fracionaria deste numero. Escreva um programa que chama esta funcao
*/
#include <stdio.h>

void frac(float num, int* inteiro, float* frac);

int main() {
    int inteiro;
    float fracao;
    float real = 25.67;

    frac(real, &inteiro, &fracao);
    printf("O numero real %.2f tem parte inteira igual a %d e parte real igual a %.2f\n", real, inteiro, fracao);

    return 0;
}

void frac(float num, int* inteiro, float* frac) {
    *inteiro = (int)num;
    *frac = num - (float)*inteiro;
}