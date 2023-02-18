/*
Faca um programa que leia tres valores inteiros e chame uma funcao que receba estes 3 valores de entrada e retorne eles ordenados, ou seja, o menor valor na primeira variavel, o segundo menor valor na variavel do meio, e o maior valor na ultima variavel. A funcao deve retornar o valor 1 se os tres valores forem iguais e 0 se existirem valores diferentes. Exibir os valores ordenados na tela.
*/
#include <stdio.h>

int ordenaInt(int* a, int* b, int* c) {
    int buffer;

    if ( *a == *b && *a == *c && *b == *c ) {
        return 1;
    } else {
        if ( *a > *b && *a > *c ) {
            if ( *b < *c ) {
                buffer = *c;
                *c = *b;
                *b = buffer;
                return 0;
            }
        } else if ( *b > *a && *b > *c ) {
            buffer = *a;
            *a = *b;
            *b = buffer;
            if ( *b < *c ) {
                buffer = *c;
                *c = *b;
                *b = buffer;
                return 0;
            }
        } else {
            buffer = *a;
            *a = *c;
            *c = buffer;
            if ( *b < *c ) {
                buffer = *c;
                *c = *b;
                *b = buffer;
                return 0;
            }
        }
        return 0;
    }
}

int main() {
    int a=1, b=2, c=3;
    int flag;

    scanf("%d%d%d", &a, &b, &c);
    
    if ( (flag = ordenaInt(&a, &b, &c)) == 0 ) {
        printf("%d %d %d\n", a, b, c);
    } else {
        printf("Valores iguais\n");
    }

    return 0;
}
