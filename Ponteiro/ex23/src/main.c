/*
Escreva uma funcao que retorna o maior valor de um array de tamanho N. Escreva um programa que leia N valores inteiros, imprima o array com k elementos por linha, e o maior elemento. O valor de k tambem deve ser fornecido pelo usuario. 
*/
#include <stdio.h>
#include <stdlib.h>

void achaMaior(int* maior, int* pointer, int N) {
    for ( int i=0 ; i<N ; i++ ) {
        if ( i==0 ) {
            *maior = *(pointer+i);
        } else if ( *(pointer+i) > *maior ) {
            *maior = *(pointer+i);
        }
    }
}

int main() {
    int *array;
    int n;
    int k;
    int maior;

    printf("Informe o N: ");
    scanf("%d", &n);
    printf("Informe os valores do vetor: ");
    array = (int *)malloc(n * sizeof(int));
    for ( int i=0 ; i<n ; i++ ) {
        scanf("%d", (array+i));
    }
    achaMaior(&maior, array, n);
    
    printf("Informe o k: ");
    scanf("%d", &k);
    printf("Maior: %d\n", maior);
    for( int i=0 ; i<n ; i++ ) {
        for ( int j=0 ; j<k ; j++ ) {
            printf("%d ", *(array+i));
            i++;
            if ( n==i ) j=k;
        }
        i--;
        printf("\n");
    }

    return 0;
}
