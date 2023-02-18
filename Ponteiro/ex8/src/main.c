/*
Crie um programa que contenha um array de float contendo 10 elementos. Imprima o
endereco de cada posicao desse array. 
*/
#include <stdio.h>

int main() {
    float array[10];

    for ( int i=0 ; i<10 ; i++ ) {
        printf("%p\n", array + i);
    }

    return 0;
}
