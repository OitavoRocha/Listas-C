/*
Crie um programa que contenha um array de inteiros contendo 5 elementos. Utilizando
apenas aritmetica de ponteiros, leia esse array do teclado e imprima o dobro de cada
valor lido.
*/
#include <stdio.h>

int main() {
    int a[5];

    for( int i=0 ; i<5 ; i++ ) {
        scanf("%d", (a+i));
    }
    for( int i=0 ; i<5 ; i++ ) {
        printf("%d ", 2*(*(a+i)));
    }

    return 0;
}
