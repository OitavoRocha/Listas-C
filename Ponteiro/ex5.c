/*
Faca um programa que leia dois valores inteiros e chame uma funcao que receba estes 2 valores de entrada e retorne o maior valor na primeira variavel e o menor valor na segunda variavel. Escreva o conteudo das 2 variaveis na tela. 
*/
#include<stdio.h>

void sort(int* a, int* b);

int main() {
    int a, b;

    scanf("%d%d", &a, &b);
    sort(&a, &b);
    printf("%d e %d\n", a, b);

    return 0;
}

void sort(int* a, int* b) {
    int buffer = *a;

    if ( *a < *b ) {
        *a = *b;
        *b = buffer;
   }
}