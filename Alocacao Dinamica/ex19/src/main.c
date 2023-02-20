/*
Faca um programa para associar nomes as linhas de uma matriz de caracteres. O usuario ira informar o numero maximo de nomes que poderao ser armazenados. Cada nome podera ter ate 30 caracteres com o ’\0’. O usuario podera usar 5 opcoes diferentes para manipular a matriz:
(a) Gravar um nome em uma linha da matriz;
(b) Apagar o nome contido em uma linha da matriz;
(c) Informar um nome, procurar a linha onde ele se encontra e substituir por outro nome;
(d) Informar um nome, procurar a linha onde ele se encontra e apagar;
(e) Pedir para recuperar o nome contido em uma linha da matriz;
*/
#include <stdio.h>
#include <stdlib.h>

void gravarNome(char **matrix);
void apagarNome();
void trocarNome();
void apagarPorPosicao();
void pegarNome();

int main() {
    char** matriz;
    int n;
    int qtd=0;
    int c;

    scanf("%d", &n);
    for( int i=0 ; i<n ; i++ ) {
        matriz[i] = (char *)malloc(30*sizeof(char));
    }

    do {
        printf("+------------------+\n");
        printf(" 1.Gravar um nome\n 2.Apagar por nome\n 3.Trocar nome\n 4.Apagar por posicao\n 5.Verificar nome por posicao\n");
        scanf("%d", &c);
        switch (c) {
        case 1:
            gravarNome(&matriz[qtd]);
            break;
        case 2:

            break;
        case 3:
            
            break;
        case 4:
            
            break;
        case 5:
            
            break;
        }

    } while ( c>0 && c<6);
    



    return 0;
}


void gravarNome(char** matrix) {
    printf("Informe o nome: ");
    scanf("%s", *matrix);
}