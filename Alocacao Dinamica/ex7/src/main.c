/*
Escreva um programa que leia primeiro os 6 numeros gerados pela loteria e depois os 6 numeros do seu bilhete. O programa entao compara quantos numeros o jogador acertou. Em seguida, ele aloca espaco para um vetor de tamanho igual a quantidade de numeros corretos e guarda os numeros corretos nesse vetor. Finalmente, o programa exibe os numeros sorteados e os seus numeros corretos.
*/
#include <stdio.h>
#include <stdlib.h>

int main() {
    int loteria[6] = {15, 27, 34, 40, 48, 59};
    int jogo[6];
    int* certos;
    int tamanho=0;

    printf("Informe seu jogo: ");
    for( int i=0 ; i<6 ; i++ ) {
        scanf("%d", &jogo[i]);
    }
    certos = (int*)malloc(6*sizeof(int));
    for( int i=0 ; i<6 ; i++ ) {
        for( int j=0 ; j<6 ; j++ ) {
            if ( loteria[i] == jogo[j] ) {
                *(certos+tamanho) = jogo[j];
                tamanho++;
            }
        }
    }
    certos = (int *)realloc(certos, tamanho*sizeof(int));
    printf("Numeros Sorteados: \n");
    for( int i=0 ; i<6 ; i++ ) {
        printf("%d ", loteria[i]);
    }
    printf("\nNumeros certos: \n");
    for( int i=0 ; i<tamanho ; i++ ) {
        printf("%d ", *(certos+i));
    }

    return 0;
}
