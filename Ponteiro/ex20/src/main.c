/*
Implemente uma funcao que receba como parametro um array de numeros reais de tamanho N e retorne quantos numeros negativos a nesse array.
*/
#include <stdio.h>

int negativos(float *vet, int N);

int main() {
    int totalNegativos;
    int n = 5;
    float array[5] = {1.1, -7.0, 4.2, 0.0, -5.4};

    /*for( int i=0 ; i<n ; i++ ) {
        scanf("%f", &array[i]);
    }*/

    totalNegativos = negativos(array, n);
    printf("Total de numeros negativos no array: %d\n", totalNegativos);

    return 0;
}

int negativos(float *vet, int N) {
    int counter = 0;

    for( int i=0 ; i<N ; i++ ) {
        if ( *(vet+i) < 0 ) {
            counter++;
        }
    }
    return counter;
}