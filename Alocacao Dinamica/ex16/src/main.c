/*
Faca um programa que leia dois numeros N e M:
• Crie e leia uma matriz N x M de inteiros;
• Crie e construa uma matriz transposta M x N de inteiros.
• Mostre as duas matrizes
*/
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;
    int** normal;
    int** transposta;

    scanf("%d%d", &n, &m);
    for( int i = 0 ; i<n ; i++ ) {
        normal[i] = (int *)malloc(m*sizeof(int));
    }
   
    for( int i = 0 ; i<m ; i++ ) {
        transposta[i] = (int *)malloc(n*sizeof(int));
    } 

    for( int i = 0 ; i<n ; i++ ) {
        for( int j=0 ; j<m ; j++ ) {
            scanf("%d", (normal[i]+j));
        }
    }

    for( int i = 0 ; i<n ; i++ ) {
        for( int j=0 ; j<m ; j++ ) {
            printf("%d ", *(normal[i]+j));
        }
        printf("\n");
    }
/*
    for( int i=0 ; i<m ; i++ ) {
        for( int j=0 ; j<n ; j++ ) {
            *(transposta[i]+j) = *(normal[j]+i);
        }
    }

    for( int i=0 ; i<m ; i++ ) {
        for( int j=0 ; j<n ; j++ ) {
            printf("%d ", *(transposta[i]+j));
        }
        printf("\n");
    }*/

    return 0;
}
