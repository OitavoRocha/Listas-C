/*
Faca um programa que leia quatro numeros a, b, c e d, que serao as dimensOes de duas matrizes, e:
    • Crie e leia uma matriz, dadas as dimensoes dela; 
    • Crie e construa uma matriz que seja o produto de duas matrizes. Na sua funcao main(), imprima as duas matrizes e o produto entre elas, se existir.
*/
#include <stdio.h>
#include <stdlib.h>

int main() {
    int a, b, c, d;
    int** matriz1;
    int** matriz2;
    int** resultado;

    printf("Informe A, B, C e D: ");
    scanf("%d%d%d%d", &a, &b, &c, &d);

//  ALOCA MEMORIA PRAS MATRIZES
    matriz1 = (int **)malloc(sizeof(int *) * a);
    matriz2 = (int **)malloc(sizeof(int *) * c);

//  ALOCA MEMORIA PARA CADA LINHA DA MATRIZ
    for( int i=0 ; i<a ; i++ ) {
        matriz1[i] = (int *)malloc(sizeof(int) * b);
    }
    for( int i=0 ; i<c ; i++ ) {
        matriz2[i] = (int *)malloc(sizeof(int) * d);
    }
    
//  LE AS MATRIZES
    printf("Informe os valores da primeira matriz: ");
    for( int i=0 ; i<a ; i++ ) {
        for( int j=0 ; j<b ; j++ ) {
            scanf("%d", &matriz1[i][j]);
        }
    }
    printf("Informe os valores da segunda matriz: ");
    for( int i=0 ; i<c ; i++ ) {
        for( int j=0 ; j<d ; j++ ) {
            scanf("%d", &matriz2[i][j]);
        }
    }

//  VERIFICA SE EXISTE MATRIZ PRODUTO
    if ( b!=c ) {
        printf("IMPOSSIVEL CALCULAR O PRODUTO\n");
        exit(1);
    }

//  ALOCA ESPACO PARA A MATRIZ RESULTADO
    resultado = (int **)malloc(sizeof(int *) * a);
    for ( int i=0 ; i<a ; i++ ) {
        resultado[i] = (int *)calloc(d, sizeof(int));
    }

//  CALCULA O PRODUTO DAS MATRIZES
    for ( int i=0 ; i<a ; i++ ) {
        for ( int j=0 ; j<d ; j++ ) {
            for ( int t=0 ; t<b ; t++ ) {
                resultado[i][j] += matriz1[i][t] * matriz2[t][j];
            } 
        }
    }

//  IMPRIME A MATRIZ RESULTADO
    printf("A matriz resultante sera: \n");
    for ( int i=0 ; i<a ; i++ ) {
        for ( int j=0 ; j<d ; j++ ) {
            printf("%d ", resultado[i][j]);
        }
        printf("\n");
    }

//  LIBERA A MEMORIA ALOCADA PARA AS MATRIZES
    for ( int i=0 ; i<a ; i++ ) {
        free(matriz1[i]);
        free(matriz2[i]);
        free(resultado[i]);
    }
    free(matriz1);
    free(matriz2);
    free(resultado);

    return 0;
}