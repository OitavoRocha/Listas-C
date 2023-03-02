#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int numero;
    int div;
    int resto;
    int tamanho = 1;
    char* str;
    char* palindrome;
    char buffer;

    printf("Informe um numero: ");
    scanf("%d", &numero);

    if ( numero>10 ) {
        resto = numero;
        div = resto/10;
        tamanho++;
        while ( div>9 ) {
            resto = resto%10;
            div = div/10;
            tamanho++;
        }
    }

    str = (char *)malloc((1+tamanho)*sizeof(char));
    palindrome = (char *)malloc((1+tamanho)*sizeof(char));
    sprintf(str, "%d", numero);

    for ( int i=0 ; i<tamanho ; i++ ) {
        palindrome[tamanho-1-i] = str[i];
    }
    palindrome[tamanho]= '\0';

    if ( !strcmp(str, palindrome) ) {
        printf("Eh palindromo\n");
    } else {
        printf("Nao eh palindromo\n");
    }

    return 0;
}
