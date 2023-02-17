/*
Elaborar um programa que leia dois valores inteiros (A e B). Em seguida faca uma funcao que retorne a soma do dobro dos dois numeros lidos. A funcao devera armazenar o dobro de A na propria variavel A e o dobro de B na propria variavel B. 
*/
#include<stdio.h>

int calculaDobro(int* a, int* b);

int main() {
    int a;
    int b;
    int dobro;

    scanf("%d%d", &a, &b);
    dobro = calculaDobro(&a, &b);
    printf("Dobro: %d\n", dobro);

    return 0;
}

int calculaDobro(int* a, int* b) {
    *a = (*a) * 2;
    *b = (*b) * 2;

    return (*a) + (*b);
}