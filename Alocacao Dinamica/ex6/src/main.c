/*
Faca um programa que simule a memoria de um computador: o usuario ira especificar o tamanho da memoria, ou seja, quantos bytes serao alocados do tipo inteiro. Para tanto, a memoria solicitada deve ser um valor multiplo do tamanho do tipo inteiro. Em seguida, o usuario tera 2 opcoes: inserir um valor em uma determinada posicao ou consultar o valor contido em uma determinada posicao. A memoria deve iniciar com todos os dados zerados
*/
#include <stdio.h>
#include <stdlib.h>

int* iniciaMemoria(int n);
void adicionarDado(int* pointer, int posicao);
int consultaPosicao(int* pointer, int posicao);
void menu(int* opcao);

int main() {
    int* array;
    int n;
    int opcao;
    int pos;

    printf("Informe o Tamanho da Memoria\n");
    scanf("%d", &n);
    array = iniciaMemoria(n);
    menu(&opcao);

    while(1) {
        if ( opcao == 1) {
            scanf("%d", &pos);
            adicionarDado(array, pos);
        } else if ( opcao==2 ) {
            scanf("%d", &pos);
            printf("Na posicao esta o dado: %d\n", consultaPosicao(array, pos));
        } else {
            exit(1);
        }
        menu(&opcao);
    }

    return 0;
}

int* iniciaMemoria(int n) {
    int *array = (int *)malloc(sizeof(int)*n);

    for( int i=0 ; i<n ; i++ ) {
        *(array+i) = 0;
    }

    return array;
}

void adicionarDado(int* pointer, int posicao) {
    scanf("%d", (pointer+posicao));
}

int consultaPosicao(int* pointer, int posicao) {
    return *(pointer+posicao);
}

void menu(int* opcao) {
    do {
        printf("+---------------+\n");
        printf("1.Adicionar valor\n");
        printf("2.Verificar Posicao\n");
        printf("3.Sair\n");
        scanf("%d", opcao);
    } while ( *opcao<1 || *opcao>3 );
}