/*
Escreva um programa que contenha duas variaveis inteiras. Compare seus enderecos e exiba o maior endereco.
*/
#include<stdio.h>

int main() {
    int n, m;

    if( &m > &n ) {
        printf("%p\n", &n);
    } else {
        printf("%p\n", &m);
    }

    return 0;
}