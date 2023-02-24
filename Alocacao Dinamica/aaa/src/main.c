/*
Faça uma agenda capaz de incluir, apagar, buscar e listar quantas pessoas o usuário desejar, porém, toda a informação incluída na agenda deve ficar num único lugar chamado: “void *pBuffer”.
• Não pergunte para o usuário quantas pessoas ele vai incluir. Não pode alocar espaço para mais pessoas do que o necessário.
• Cada pessoa tem nome[10], idade e telefone.
• O trabalho que vale nota será uma continuação deste.
*/
#include <stdio.h>
#include <stdlib.h>

#define TAMANHO_NOME 10
#define TAMANHO_REGISTRO (sizeof(char)*TAMANHO_NOME)+sizeof(int)+sizeof(int)

int menu();

int main() {
    void *pBuffer;
    int opcao;
    int idade;
    int telefone;
    char nome[10];

    pBuffer = calloc(1, sizeof(int));

    opcao = menu();
    while (1) {
        switch (opcao)
        {
        case 1:
            getchar();
            printf("Informe os dados da pessoa %d:\n", *(int*)pBuffer);
            printf("-Nome: ");
            scanf("%[^\n]s", nome);
            printf("-Idade: ");
            scanf("%d", &idade);
            printf("-Telefone: ");

            scanf("%d", &telefone);
            *(int *)pBuffer += 1;
            printf("%d", *(int *)pBuffer);
            pBuffer = (void*)realloc(pBuffer, 1+((TAMANHO_REGISTRO)*(*(int *)pBuffer)));
            printf("%d", *(int *)pBuffer);
            for( int i=0 ; i<TAMANHO_NOME ; i++ ) {
                *(char *)(sizeof(int) + pBuffer + i) = nome[i];
            }
            *(int *)(pBuffer+sizeof(int)+(sizeof(char)*TAMANHO_NOME)) = idade;
            *(int *)(pBuffer+sizeof(int)+(sizeof(char)*TAMANHO_NOME)+sizeof(int)) = telefone;
            break;
        case 2:
            //apaga(&pBuffer);
            break;
        case 3:
            for( int i=0 ; i<*(int *)pBuffer ; i++ ) {
                printf("Pessoa %d: \n", i+1);
                //ERRO DE SEGMENTAÇÃO AQUI v
                printf("Nome: %s\n", *(char*)(pBuffer+1+(i*TAMANHO_REGISTRO)));
                printf("Idade: %d\n"), *(int*)(pBuffer+1+(i*TAMANHO_REGISTRO)+(sizeof(char)*TAMANHO_NOME));
                printf("Telefone: %d\n", *(int*)(pBuffer+1+(i*TAMANHO_REGISTRO)+(sizeof(char)*TAMANHO_NOME)+sizeof(int)));
            }
            break;
        case 4:
            //busca();
            break;
        case 5:
            exit(1);
            break;
        default:
            break;
        }
        opcao = menu();
    }
    

    return 0;
}

int menu() {
    int c;

    printf("+---Informe sua Escolha---+\n");
    printf(" 1. Incluir Pessoa\n");
    printf(" 2. Apagar Pessoa\n");
    printf(" 3. Listar\n");
    printf(" 4. Buscar por nome\n");
    printf(" 5. Sair\n");
    scanf("%d", &c);

    return c;
}