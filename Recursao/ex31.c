/*
Uma palavra de Fibonacci e definida por

f(n) = b se n = 0
f(n) = a se n = 1
f(n) = f(n-1)+f(n-2) se n > 1

Aqui o sımbolo “+” denota a concatenacao de duas strings. Esta sequencia inicia com as seguintes palavras:
b, a, ab, aba, abaab, abaababa, abaababaabaab, ...
Faca uma funcao recursiva que receba um numero N e retorne a N-esima palavra de Fibonacci.
*/
#include<stdio.h>
#include<string.h>

char passo(int n);

int main() {
    int n;
    char *string;

    scanf("%d", &n);
    string = passo(n);
    printf("%s", string);

    return 0;
}

char passo(int n) {
    //ISSO AQUI TA CERTO? APARENTEMENTE NAO
    if ( n==1 ) {
        return 'b';
    } else if ( n==0 ) {
        return 'a';
    } else {
        return strcat(passo(n-1), passo(n-2));
    }
}