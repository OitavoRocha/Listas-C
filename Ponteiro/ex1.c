/*
Escreva um programa que declare um inteiro, um real e um char, e ponteiros para inteiro, real, e char. Associe as variaveis aos ponteiros (use &). Modifique os valores de cada variavel usando os ponteiros. Imprima os valores das variaveis antes e apos a modificacao. 
*/
#include<stdio.h>

int main() {
    int i, *pInt;
    float f, *pFloat;
    char c, *pChar;

    pInt = &i;
    pFloat = &f;
    pChar = &c;

    scanf("%d", &i);
    scanf("%f", &f);
    getchar();
    c = getchar();

    printf("ANTES ---> Inteiro: %d -- Real: %.2f -- Caracter: %c\n", i, f, c);
    *pInt = 6;
    *pFloat = 15.43;
    *pChar = 'C';
    printf("DEPOIS ---> Inteiro: %d -- Real: %.2f -- Caracter: %c\n", i, f, c);

    return 0;
}