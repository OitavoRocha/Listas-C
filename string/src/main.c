#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* adicionaNome(char** str, int *tamanho, char* nome);
int menu();
void lista(char** str, int* tamanho);
char* removePorPosicao(char** str, int* tamanho);

int main() {
    char* str;
    char nome[10];
    int opcao;
    int tamanho = 0;

    str = (char*)malloc(sizeof(char));

    while (1) {
        opcao = menu();
        switch (opcao) {
        case 1:
            getchar();
            printf("Informe o nome a ser adicionado: ");
            scanf("%[^\n]s", nome);
            str = adicionaNome(&str, &tamanho, nome);
            break;
        case 2:
            str = removePorPosicao(&str, &tamanho);
            break;
        case 3:
            lista(&str, &tamanho);
            break;
        case 4:
            exit(1);
            break;
        }
    }

    return 0;
}

int menu() {
    int c;

    printf("+---Escolha uma Opcao---+\n 1.Adicionar Nome\n 2.Excluir nome\n 3.Listar\n 4.Sair\n");
    scanf("%d", &c);

    return c;
}

char* adicionaNome(char** str, int* tamanho, char* nome) {
    char* pointer;

    pointer = (char *)realloc(*str, (*tamanho*sizeof(char))+((strlen(nome)+1)*sizeof(char)));
    strcat(pointer, nome);
    strcat(pointer, "-");
    *tamanho += strlen(nome)+1;

    return pointer;
}

void lista(char** str, int* tamanho) {
    for ( int i=0 ; i<*tamanho ; i++ ) {
        if ( *((*str)+i) == '-' ) {
            printf("\n");
        } else {
            printf("%c", *((*str)+i));
        }
    }
}

char* removePorPosicao(char** str, int* tamanho) {
    char* pointer;
    int pos;
    int count=0;
    int flag=0;
    int tamRemovido=0;
    int j=0;
    
    printf("Informe a posicao a ser removida: ");
    scanf("%d", &pos);
    for ( int i=0 ; i<*tamanho ; i++ ) {
        if ( pos==0 ) {
            while ( *((*str)+i)!='-' ) {
                tamRemovido++;
                i++;
            }
            tamRemovido++;
            i = *tamanho;
        } else if ( *((*str)+i)=='-' ) {
            if ( flag==pos ) {
                i++;
                while ( *((*str)+i)!='-' ) {
                    tamRemovido++;
                    i++;
                }
                tamRemovido++;
                i = *tamanho;
            } else {
                count++;
            }
            flag++;
        } else {
            count++;
        }
    }

    if ( *tamanho - tamRemovido == 0 ) {
        pointer = (char *)malloc(sizeof(char));
        pointer = '0';
    } else {
        pointer = (char *)malloc(sizeof(char)*(*tamanho-tamRemovido-1));
        for ( int i = 0 ; i<*tamanho ; i++, j++ ) {
            if ( count==i ) {
                i += tamRemovido;
            }
            pointer[j] = *((*str)+i);
        }
    }
    
    return pointer;
}