/*
Escreva um programa que contenha duas variaveis inteiras. Leia essas variaveis do teclado. Em seguida, compare seus enderecos e exiba o conteudo do maior endereco.
*/
#include<stdio.h>

int main() {
    int n, m;

    scanf("%d %d", &n, &m);
    if( &m > &n ) {
        printf("%p\n", &n);
    } else {
        printf("%p\n", &m);
    }

    return 0;
}