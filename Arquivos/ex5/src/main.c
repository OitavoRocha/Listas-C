/*
Faca um programa que receba do usuario um arquivo texto e um caracter. Mostre na tela quantas vezes aquele caractere ocorre dentro do arquivo.
*/
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *p;
    char c;
    char k;
    int counter = 0;

    p = fopen("arq.txt", "r");
    if ( p == NULL ) {
        printf("IMPOSSIVEL ABRIR O ARQUIVO\n");
        exit(1);
    }
    printf("Informe um caractere: ");
    scanf("%c", &k);
    c = fgetc(p);
    while ( c!=EOF ) {
        if ( c == k ){
            counter++;
        }
        c = fgetc(p);
    }
    
    fclose(p);
    printf("O caracter %c aparece %d vezes no arquivo", k, counter);

    return 0;
}
