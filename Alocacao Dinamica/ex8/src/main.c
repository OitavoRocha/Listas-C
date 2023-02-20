/*
Faca um programa para armazenar em memoria um vetor de dados contendo 1500 valores do tipo int, usando a funcao de alocacao dinamica de memoria CALLOC:
(a) Faca um loop e verifique se o vetor contem realmente os 1500 valores inicializados com zero (conte os 1500 zeros do vetor).
(b) Atribua para cada elemento do vetor o valor do seu ındice junto a este vetor.
(c) Exibir na tela os 10 primeiros e os 10 ultimos elementos do vetor.
*/
#include <stdio.h>
#include <stdlib.h>

#define NUMERO 1500

int main() {
    int *array;

    array = (int *)calloc(NUMERO, sizeof(int));
    for( int i=0 ; i<NUMERO ; i++ ) {
        if ( *(array+i)!=0 ){
            printf("ERRO!");
            exit(0);
        }
    }
    for( int i=0 ; i<NUMERO ; i++ ) {
        *(array+i) += i;
    }
    for( int i=0 ; i<NUMERO ; i++ ) {
        for( int j=0 ; j<10 ; j++ ) {
            printf("%d ", *(array+i+j));
        }
        i = NUMERO-10;
        printf("\n");
        for( int j=0 ; j<10 ; j++ ) {
            printf("%d ", *(array+i+j));
        }
        i=NUMERO;
    }

    return 0;
}
