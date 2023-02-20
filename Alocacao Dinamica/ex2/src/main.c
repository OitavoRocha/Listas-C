/*
Faca um programa que leia do usuario o tamanho de um vetor a ser lido e faca a alocacao dinamica de memoria. Em seguida, leia do usuario seus valores e imprima o vetor lido
*/
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    int* array;

    scanf("%d", &n);
    array = (int *)malloc(n*sizeof(int));
    for( int i=0 ; i<n ; i++ ) {
        scanf("%d", (array+i));
    }
    for ( int i = 0; i < n; i++ ) {
        printf("%d ", *(array+i));
    }
    printf("\n");
    
    return 0;
}
