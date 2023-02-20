/*
Faca um programa que receba do usuario o tamanho de uma string e chame uma funcao para alocar dinamicamente essa string. Em seguida, o usuario devera informar o conteudo dessa string. O programa imprime a string sem suas vogais.
*/
#include <stdio.h>
#include <stdlib.h>

char* alocaString(int n) {
    return (char *)malloc(n*sizeof(char));
}

int main() {
    int n;
    char *string;

    scanf("%d", &n);
    string = alocaString(n);
    scanf("%s", string);
    getchar();
    for( int i=0 ; i<n ; i++ ) {
        if( *(string+i)=='a' || *(string+i)=='e' || *(string+i)=='i' || *(string+i)=='o' || *(string+i)=='u' ) {
        } else {
            printf("%c", *(string+i));
        }
    }
    printf("\n");

    return 0;
}
