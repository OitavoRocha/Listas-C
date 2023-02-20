/*
Faca um programa que receba do usuario um arquivo texto e mostre na tela quantas linhas esse arquivo possui.
*/
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *p;
    char c;
    int counter=0;

    p = fopen("arq.txt", "r");
    if ( p == NULL ) {
        printf("IMPOSSIVEL ABRIR O ARQUIVO\n");
        exit(1);
    }
    c = fgetc(p);
    while( c != EOF ) {
        if ( c == '\n' ) {
            counter++;
        }
        c = fgetc(p);
    }

    counter++;
    fclose(p);
    printf("O arquivo possui %d linhas\n", counter);

    return 0;
}
