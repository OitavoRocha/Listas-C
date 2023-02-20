/*
Faca um programa que leia do usuario o tamanho de um vetor a ser lido e faca a alocacao dinamica de memoria. Em seguida, leia do usuario seus valores e   mostre quantos dos numeros sao pares e quantos sao ımpares.
*/
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    int *array;
    int par = 0;
    int impar = 0;

    scanf("%d", &n);
    array = (int *)malloc(sizeof(int));
    for( int i=0 ; i<n ; i++ ) {
        scanf("%d", (array+i));
        if ( *(array+i)%2 == 0 ) {
            par++;
        } else {
            impar++;
        }
    }
    printf("Pares: %d\nImpares: %d\n", par, impar);

    return 0;
}
