/*
Crie um programa que:
(a) Aloque dinamicamente um array de 5 numeros inteiros,
(b) Peca para o usuario digitar os 5 numeros no espaco alocado,
(c) Mostre na tela os 5 numeros,
(d) Libere a memoria alocada. 
*/
#include <stdio.h>
#include <stdlib.h>

int main() {
    int* array;

    array = (int*)malloc(5*sizeof(int));
    for( int i=0 ; i<5 ; i++ ) {
        scanf("%d", (array+i));
    }
    for( int i=0 ; i<5 ; i++ ) {
        printf("%d ", *(array+i));
    }
    printf("\n");

    free(array);

    return 0;
}
