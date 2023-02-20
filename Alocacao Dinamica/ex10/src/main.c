/*
Faca um programa que pergunte ao usuario quantos valores ele deseja armazenar em um vetor de double, depois use a funcao MALLOC para reservar (alocar) o espaco de memoria de acordo com o especificado pelo usuario. Esse vetor deve ter um tamanho maior ou igual a 10 elementos. Use este vetor dinamico como um vetor comum, atribuindo aos 10 primeiros elementos do vetor valores aleatorios (usando a funcao rand) entre 0 e 100. Exiba na tela os valores armazenados nos 10 primeiros elementos do vetor.
*/
#include <stdio.h>
#include <stdlib.h>

int main() {
    double* array;
    int n;

    scanf("%d", &n);
    array = (double *)malloc(n*sizeof(double));
    for( int i=0 ; i<n ; i++ ) {
        *(array+i) = rand() % 100;
    }
    for( int i=0 ; i<10 ; i++ ) {
        printf("%.2f ", *(array+i));
    }

    return 0;
}
