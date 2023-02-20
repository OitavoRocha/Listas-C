/*
Construa um programa que leia o numero de linhas e de colunas de uma matriz de numeros reais, aloque espaco dinamicamente para esta e a inicialize com valores fornecidos pelo usuario. Ao final, o programa devera retornar a matriz na saıda padrao com layout apropriado.
*/
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;
    float* matrix;

    scanf("%d%d", &n, &m);
    matrix = (float *)calloc(n*m , sizeof(float));

    for (int i = 0 ; i < n*m ; i++){
        scanf("%f", (matrix+i));
    }

    for( int i=0 ; i<n*m ; i++ ) {
        for( int j=0 ; j<m ; j++ ) {
            printf("%.1f ", *(matrix+i+j));
        }
        i += (m-1);
        printf("\n");
    }

    return 0;
}
