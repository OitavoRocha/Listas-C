/*
Faca um programa que receba do usuario um arquivo texto e mostre na tela quantas letras sao vogais e quantas sao consoantes.
*/
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *p;
    char c;
    int vogais = 0;
    int consoante = 0;

    p = fopen("arq.txt", "r");
    if ( p == NULL ) {
        printf("IMPOSSIVEL ABRIR O ARQUIVO\n");
        exit(1);
    }
    c = fgetc(p);
    while ( c!=EOF ) {
        switch (c) {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
        case 'A':
        case 'E':
        case 'I':
        case 'O':
        case 'U':
            vogais++;
            break;
        default:
            if ((c>=65 && c<=90)||(c>=97 && c<=122)) {
                consoante++;
            }
        }
        c = fgetc(p);
    }
    
    fclose(p);
    printf("Existem %d vogais e %d consoantes no arquivo\n", vogais, consoante);

    return 0;
}
