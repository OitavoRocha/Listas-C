/*
Faca um programa que leia um numero N e:
    • Crie dinamicamente e leia um vetor de inteiro de N posicoes;
    • Leia um numero inteiro X e conte e mostre os multiplos desse numero que existem no vetor.
*/
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    int *array;
    int x;
    int count=0;

    scanf("%d", &n);
    array = (int *)malloc(n*sizeof(int));
    for( int i=0 ; i<n ; i++ ) {
        scanf("%d", (array+i));
    }
    scanf("%d", &x);
    for( int i=0 ; i<n ; i++ ) {
        if ( (*(array+i))%x == 0 ) {
            count++;
        }
    }
    printf("Existem %d multiplos de X\n", count);

    return 0;
}
