/*
Escreva uma funcao que aceita como parametro um array de inteiros com N valores, e determina o maior elemento do array e o numero de vezes que este elemento ocorreu no array. Por exemplo, para um array com os seguintes elementos: 5, 2, 15, 3, 7, 15, 8, 6, 15, a funcao deve retorna para o programa que a chamou o valor 15 e o numero 3(indicando que o numero 15 ocorreu 3 vezes). A funcao deve ser do tipo void.
*/
#include <stdio.h>

void calculaMaior(int* array, int* counter, int* maior);

int main() {
    int a[9] = {5, 2, 15, 3, 7, 15, 8, 6, 15};
    int count = 0;
    int maior;

    calculaMaior(a, &count, &maior);
    printf("Dentro do array o maior numero eh %d e ele aparece %d vezes\n", maior, count);

    return 0;
}

void calculaMaior(int* array, int* counter, int* maior) {
    for ( int i=0 ; i<9 ; i++ ) {
        if ( i==0 ) {
            *maior = *(array+i);
        } else if ( *(array+i) > *maior ) {
            *maior = *(array+i);
        }
    }
    for ( int i=0 ; i<9 ; i++ ) {
        if ( *maior == *(array+i) ) {
            (*counter)++;
        }
    }
}