/*
Crie um programa que contenha um array contendo 5 elementos inteiros. Leia esse array
do teclado e imprima o endereco das posicoes contendo valores pares.
*/
#include <stdio.h>

int main() {
    int a[5];

    for ( int i=0 ; i<5 ; i++ ) {
        scanf("%d", (a+i));
    }
    for ( int i=0 ; i<5 ; i++ ) {
        if ( *(a+i)%2==0 ) {
            printf("%d ", *(a+i));
        }
    }

    return 0;
}
