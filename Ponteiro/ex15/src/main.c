/*
Crie uma funcao que receba como parametro um array e o imprima. Nao utilize ındices
para percorrer o array, apenas aritmetica de ponteiros.
*/
#include <stdio.h>

void imprimeArray(int* a) {
    for( int i=0 ; i<10 ; i++ ) {
        printf("%d ", *(a+i));
    }
    printf("\n");
}

int main(int argc, char const *argv[]) {
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    imprimeArray(a);

    return 0;
}
