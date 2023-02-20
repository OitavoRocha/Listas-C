/*
Escreva um programa que:
(a) Crie/abra um arquivo texto de nome “arq.txt”
(b) Permita que o usuario grave diversos caracteres nesse arquivo, ate que o usuario entre com o caractere ‘0’
(c) Feche o arquivo
Agora, abra e leia o arquivo, caractere por caractere, e escreva na tela todos os caracteres armazenados.
*/
#include <stdio.h>
#include <stdlib.h>

void criaEscreve() {
    FILE *p;
    char c;

    p = fopen("arq.txt", "w");
    if ( p == NULL ) {
        printf("IMPOSSIVEL ABRIR O ARQUIVO\n");
        exit(1);
    }
    c = getchar();
    while( c!='0' ) {
        fputc(c, p);
        c = getchar();
    }

    fclose(p);
}

void leImprime() {
    FILE *p;
    char c;

    p = fopen("arq.txt", "r");
    if ( p == NULL ) {
        printf("IMPOSSIVEL ABRIR O ARQUIVO\n");
        exit(1);
    }
    c = fgetc(p);
    while( c != EOF ) {
        printf("%c", c);
        c = fgetc(p);
    }

    printf("\n");
    fclose(p);
}

int main() {

    criaEscreve();
    leImprime();

    return 0;
}
