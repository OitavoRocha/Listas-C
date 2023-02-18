/*
Crie um programa que contenha uma matriz de float contendo 3 linhas e 3 colunas.
Imprima o endereco de cada posicao dessa matriz.
*/
#include <stdio.h>

int main() {
    float matrix[3][3];
    int n=0;

    for( int i=0 ; i<3 ; i++ ) {
        for( int j=0 ; j<3 ; j++ ) {
            printf("%p ", matrix + n);
            n++;
        }
        printf("\n");
    }

    return 0;
}
