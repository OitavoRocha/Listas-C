/*
Faca uma funcao recursiva que receba um numero inteiro positivo N e retorne o super-fatorial desse numero. O superfatorial de um numero N e definida pelo produto dos N primeiros fatoriais de N. Assim, o superfatorial de 4 eh: sf(4) = 1! ∗ 2! ∗ 3! ∗ 4! = 288
*/
#include<stdio.h>

int fatorial(int n);
int superFatorial(int n);

int main() {
    int n;

    scanf("%d", &n);
    printf("%d! = %d\n", n, fatorial(n));
    printf("sf(%d) = %d\n", n, superFatorial(n));

    return 0;
}

int fatorial(int n) {
    if ( n==1 || n==0 ) {
        return 1;
    } else {
        return n*fatorial(n-1);
    }
}

int superFatorial(int n) {
    if ( n==1 || n==0 ) {
        return 1;
    } else {
        return fatorial(n) * superFatorial(n-1);
    }
}