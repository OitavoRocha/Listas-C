/*
Faca um programa que leia dois numeros N e M e: 
• Crie e leia uma matriz de inteiros N x M;
• Localize os tres maiores numeros de uma matriz e mostre a linha e a coluna onde estao.
*/
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;
    int** matrix;
    int maiores[3];

    scanf("%d%d", &n, &m);
    for( int i=0 ; i<n ; i++ ) {
        matrix[i] = (int *)malloc(m*sizeof(int));
    }
    for( int i=0 ; i<n ; i++ ) {
        for( int j=0 ; j<m ; j++ ) {
            scanf("%d", (matrix[i]+j));
        }
    }

    for ( int i=0 ; i<n ; i++ ) {
        for ( int j=0 ; j<m ; j++ ) {
            
        }
    }

    return 0;
}
