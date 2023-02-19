/*
Escreva uma funcao que receba um array de inteiros V e os enderecos de duas variaveis inteiras, min e max, e armazene nessas variaveis o valor mınimo e maximo do array. Escreva tambem uma funcao main que use essa funcao.
*/
#include <stdio.h>

void findLimits(int* array, int* min, int* max);

int main() {
    int ar[10] = {1, 23, 4, -56, 52, 44, 120, 0, 13, -75};
    int min;
    int max;

    findLimits(ar, &min, &max);
    printf("Min: %d\nMax: %d\n", min, max);

    return 0;
}

void findLimits(int* array, int* min, int* max) {
    int size = (int)sizeof(array)/sizeof(array[0]);
    printf("%d\n", sizeof(array[0]));

    for( int i=0 ; i<(int)size ; i++ ) {
        if ( i==0 ) {
            *min = *(array+i);
            *max = *min;
        } else {
            if ( *min > *(array+i) ) {
                *min = *(array+i);
            }
            if ( *max < *(array+i) ) {
                *max = *(array+i);
            }
        }
    }
}