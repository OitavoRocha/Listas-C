/*
Faca um programa que leia 2 valores inteiros e chame uma funcao que receba estas 2 variaveis e troque o seu conteudo, ou seja, esta funcao e chamada passando duas variaveis A e B por exemplo e, apos a execucao da funcao, A contera o valor de B e B tera o valor de A.
*/
#include<stdio.h>

void trocaValores(int* a, int* b);

int main() {
    int a, b;

    scanf("%d%d", &a, &b);
    printf("%d e %d\n", a, b);
    trocaValores(&a, &b);
    printf("%d e %d\n", a, b);

    return 0;
}

void trocaValores(int* a, int* b) {
    int buffer;

    buffer = *a;
    *a = *b; 
    *b = buffer;
}