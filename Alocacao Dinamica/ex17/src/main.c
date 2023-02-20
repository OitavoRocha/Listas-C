/*
Faca um programa que leia numeros do teclado e os armazene em um vetor alocado dinamicamente. O usuario ira digitar uma sequencia de numeros, sem limite de quantidade. Os numeros serao digitados um a um e, sendo que caso ele deseje encerrar a entrada de dados, ele ira digitar o numero ZERO. Os dados devem ser armazenados na memoria deste modo
    • Inicie com um vetor de tamanho 10 alocado dinamicamente;
    • Apos, caso o vetor alocado esteja cheio, aloque um novo vetor do tamanho do vetor anterior adicionado espaco para mais 10 valores (tamanho N+10, onde N inicia com 10);
    • Copie os valores ja digitados da area inicial para esta area maior e libere a memoria da area inicial;
    • Repita este procedimento de expandir dinamicamente com mais 10 valores o vetor alocado cada vez que o mesmo estiver cheio. Assim o vetor ira ser expandido de 10 em 10 valores.
Ao final, exiba o vetor lido. Nao use a funcao REALLOC.
*/
#include <stdio.h>
#include <stdlib.h>

int main() {
    int* array1;
    int* array2;
    int tamanho=10;
    int t=0;
    int counter=0;
    int counter2 = 0;
    int valor;

    array1 = (int *)malloc(tamanho*sizeof(int));
    do{
        scanf("%d", &valor);
        if ( counter==10 ) {
            tamanho += counter;
            if ( counter2%2==0 ) {
                array2 = (int *)malloc(tamanho*sizeof(int));
                counter2++;
                for( int i=0 ; i<10 ; i++ ) {
                    *(array2+i) = *(array1+i);
                }
                free(array1);
            } else {
                array1 = (int *)malloc(tamanho*sizeof(int));
                counter2++;
                for( int i=0 ; i<10 ; i++ ) {
                    *(array1+i) = *(array2+i);
                }
                free(array2);
            }
            counter = 0;
        } else {
            if ( counter2%2==0 ) {
                *(array1+t) = valor;
            } else {
                *(array2+t) = valor;
            }
            t++;
        }
    } while ( valor != 0);
    
    if ( counter2%2==0 ) {
        for( int i=0 ; i<t ; i++ ) {
            printf("%d ", *(array1+i));
        }
    } else {
        for( int i=0 ; i<t ; i++ ) {
            printf("%d ", *(array2+i));
        }
    }
    printf("\n");

    return 0;
}
