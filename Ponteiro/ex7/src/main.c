/*
Crie um programa que contenha uma funcao que permita passar por parametro dois numeros inteiros A e B. A funcao devera calcular a soma entre estes dois numeros e armazenar o resultado na variavel A. Esta funcao nao devera possuir retorno, mas devera modificar o valor do primeiro parametro. Imprima os valores de A e B na funcao principal
*/
#include <stdio.h>

void soma(int *a, int b) {
    *a = *a + b;
}

int main() {
    int a = 7;
    int b = 5;

    soma(&a, b);
    printf("%d\n", a);

    return 0;
}
