/*
Crie um programa que declare uma estrutura (registro) para o cadastro de alunos.
(a) Deverao ser armazenados, para cada aluno: matrıcula, sobrenome (apenas um) e ano de nascimento.
(b) Ao inıcio do programa, o usuario devera informar o numero de alunos que serao armazenados
(c) O programa devera alocar dinamicamente a quantidade necessaria de memoria para armazenar os registros dos alunos.
(d) O programa devera pedir ao usuario que entre com as informacoes dos alunos. 
(e) Ao final, mostrar os dados armazenados e liberar a memoria alocada.
*/
#include <stdio.h>
#include <stdlib.h>

struct registro {
    int matricula;
    char sobrenome[20];
    int ano;
};

typedef struct registro rg;

int main() {
    int n;
    rg *alunos;

    scanf("%d", &n);
    alunos = (rg *)malloc(n*sizeof(rg));
    for( int i=0 ; i<n ; i++ ) {
        printf("Informe os dados do aluno %d\n", i+1);
        printf("Matricula: ");
        scanf("%d", &(alunos+i)->matricula);
        printf("Sobrenome: ");
        scanf("%s", (alunos+i)->sobrenome);
        getchar();
        printf("Ano de Nascimento: ");
        scanf("%d", &(alunos+i)->ano);
    }
    for( int i=0 ; i<n ; i++ ) {
        printf("Informacoes do aluno %d\n", i+1);
        printf("Matricula: %d\n", (alunos+i)->matricula);
        printf("Sobrenome: %s\n", (alunos+i)->sobrenome);
        printf("Ano de Nascimento: %d\n", (alunos+i)->ano);
    }

    return 0;
}
