/*
Faca um programa no qual o usuario informa o nome do arquivo e uma palavra, e retorne o numero de vezes que aquela palavra aparece no arquivo.
*/
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *p;
    char c;
    char k;
    char entrada[20];
    int counter = 0;

    printf("Informe o nome do arquivo: ");
    scanf("%s", entrada);
    getchar();

    p = fopen(entrada, "r");
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
