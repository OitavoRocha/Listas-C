/*
Crie uma funcao que receba dois parametros: um array e um valor do mesmo tipo do array. A funcao devera preencher os elementos de array com esse valor. Nao utilize ındices para percorrer o array, apenas aritmetica de ponteiros.
*/
#include <stdio.h>

void preencheArray(int* a, int v) {
    for ( int i=0 ; i<5 ; i++ ) {
        *(a+i) = v;
    }
}

int main() {
    int a[5];
    int valor = 13;

    preencheArray(a, valor);
    for( int i=0 ; i<5 ; i++ ) {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}
