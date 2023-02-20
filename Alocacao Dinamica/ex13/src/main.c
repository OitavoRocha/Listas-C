/*
Escreva um programa que aloque dinamicamente uma matriz (de inteiros) de dimensoes definidas pelo usuario e a leia. Em seguida, implemente uma funcao que receba um valor, retorne 1 caso o valor esteja na matriz ou retorne 0 caso nao esteja na matriz. 
*/
#include <stdio.h>
#include <stdlib.h>

int verifyValue(int* matrix, int rows, int columns, int n) {
    for( int i=0 ; i<(rows*columns) ; i++ ) {
        if ( *(matrix+i) == n ) {
            return 1;
        }
    }
    return 0;
}

int main() {
    int r, c;
    int *matrix;
    int n;
    int flag;

    scanf("%d%d", &r, &c);
    matrix = (int *)malloc(r*c*sizeof(int));

    for( int i=0 ; i<(r*c) ; i++ ) {
        scanf("%d", (matrix+i));
    }
    printf("Value to be found: ");
    scanf("%d", &n);
    flag = verifyValue(matrix, r, c, n);
    if ( flag==0 ) {
        printf("VALUE NOT FOUND\n");        
    } else {
        printf("FOUND THE VALUE\n");
    }

    return 0;
}
