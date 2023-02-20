/*
Faca um programa que leia uma quantidade qualquer de numeros armazenando-os na memoria e pare a leitura quando o usuario entrar um numero negativo. Em seguida, imprima o vetor lido. Use a funcao REALLOC.
*/
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *array;
    int valor;
    int counter = 0;

    array = (int *)malloc(sizeof(int));
    scanf("%d", &valor);
    *(array) = valor;
    while ( valor>=0 ) {
        counter++;
        array = realloc(array, (counter + 1)*sizeof(int));
        scanf("%d", &valor);
        *(array+counter) = valor;
    }
    for( int i=0 ; i<counter ; i++ ) {
        printf("%d ", *(array+i));
    }
    printf("\n");    

    return 0;
}
