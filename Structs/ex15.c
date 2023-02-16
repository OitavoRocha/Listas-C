/*
Faca um programa que leia um vetor com dados de 5 livros: tıtulo (maximo 30 letras), autor (maximo 15 letras) e ano. Procure um livro por tıtulo, perguntando ao usuario qual tıtulo deseja buscar. Mostre os dados de todos os livros encontrados
*/
#include<stdio.h>
#include<string.h>

#define MAX_TITULO 30
#define MAX_AUTOR 15
#define NUMERO_LIVROS 5

struct info {
    char titulo[MAX_TITULO];
    char autor[MAX_AUTOR];
    int ano;
}INFO[NUMERO_LIVROS];

void mostraDados(int n);

int main() {
    char busca[MAX_TITULO];
    int count=0;
    
    for (int i = 0; i < NUMERO_LIVROS; i++) {
        printf("Informe os dados do livro %d:\n--Titulo: ", i+1);
        scanf("%[^\n]s", INFO[i].titulo);
        getchar();
        printf("--Autor: ");
        scanf("%[^\n]s", INFO[i].autor);
        getchar();
        printf("--Ano de Lancamento: ");
        scanf("%d", &INFO[i].ano);
        getchar();
        printf("+---------------------------------------------------+\n");
    }

    printf("Qual livro gostaria de buscar?\n");
    scanf("%[^\n]s", busca);
    getchar();

    for (int i = 0; i < NUMERO_LIVROS; i++) {
        if ( strcmp(busca, INFO[i].titulo)==0 ) {
            mostraDados(i);
            count++;
        }
    }
    if ( count==0 ) {
        printf("NENHUM LIVRO ENCONTRADO\n");
    }
    
    return 0;
}

void mostraDados(int n) {
    printf("+------Livro Encontrado------+\n");
    printf("+ Nome: %s\n", INFO[n].titulo);
    printf("+ Autor: %s\n", INFO[n].autor);
    printf("+ Ano: %d\n", INFO[n].ano);
}