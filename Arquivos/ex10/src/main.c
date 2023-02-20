/*
Faca um programa que receba o nome de um arquivo de entrada e outro de saıda. O arquivo de entrada contem em cada linha o nome de uma cidade (ocupando 40 caracteres) e o seu numero de habitantes. O programa devera ler o arquivo de entrada e gerar um arquivo de saıda onde aparece o nome da cidade maisopulosa seguida pelo seu numero de habitantes.
*/
#include <stdio.h>
#include <stdlib.h>

int main() {
    char entrada[20];
    char saida[20];
    char cidade[30];
    int habitantes;
    int* h = &habitantes;
    int maior = 0;
    FILE *in, *out;

    printf("Informe o arquivo de entrada: ");
    scanf("%s", entrada);
    printf("E o de saida: ");
    scanf("%s", saida);

    in = fopen(entrada, "r");
    out = fopen(saida, "w");
    if ( in == NULL || out == NULL ) {
        printf("IMPOSSIVEL ABRIR O ARQUIVO\n");
        exit(1);
    }
    
    do {
        fscanf((in+30), "%d", h);
        if ( habitantes > maior ) {
            for ( int i=0 ; i<30 ; i++ ) {
                cidade[i] = fgetc(in);
            }
        }
        in += 2;
    } while ( fgetc(in) != EOF );
    
    for ( int i=0 ; i<30 ; i++ )  {
        fputc(cidade[i], out);
    }
    fprintf(out, "%d", maior);

    fclose(out);
    fclose(in);

    return 0;
}
