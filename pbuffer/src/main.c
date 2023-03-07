/*
Faça uma agenda capaz de incluir, apagar, buscar e listar quantas pessoas o usuário desejar, porém, toda a informação incluída na agenda deve ficar num único lugar chamado: “void *pBuffer”.
• Não pergunte para o usuário quantas pessoas ele vai incluir. Não pode alocar espaço para mais pessoas do que o necessário.
• Cada pessoa tem nome[10], idade e telefone.
• O trabalho que vale nota será uma continuação deste.
*/

/*
PROBLEMAS:
    nao mantem os dados conforme adiciono pessoas, mantendo soh o primeiro e o ultimo
    nao procura por nome pessoas apos a segunda
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANHO_NOME 10
#define TAMANHO_REGISTRO (int)(sizeof(char)*TAMANHO_NOME)+sizeof(int)+sizeof(int)

int menu();

int main() {
    void *pBuffer;
    int opcao;
    int idade;
    int telefone;
    char nome[10];
    int count=0;
    int pos;

    pBuffer = calloc(1, sizeof(int));

    opcao = menu();
    while (1) {
        switch (opcao)
        {
        case 1: //LE PESSOA POR PESSOA
            getchar();
            printf("Informe os dados da pessoa %d:\n", *(int*)pBuffer + 1);
            printf("-Nome: ");
            scanf("%[^\n]s", nome);
            printf("-Idade: ");
            scanf("%d", &idade);
            printf("-Telefone: ");
            scanf("%d", &telefone);
            *(int *)pBuffer += 1;
            pBuffer = realloc(pBuffer, sizeof(int)+((TAMANHO_REGISTRO)*(*(int *)pBuffer)));
            if ( *(int*)pBuffer == 1 ) {
                strcpy((char *)(pBuffer + sizeof(int)), nome);
                *(int *)(pBuffer+sizeof(int)+(sizeof(char)*TAMANHO_NOME)) = idade;
                *(int *)(pBuffer+(2*sizeof(int))+(sizeof(char)*TAMANHO_NOME)) = telefone;
            } else {
                strcpy((char *)(pBuffer + sizeof(int) + ((*(int*)pBuffer - 1)*TAMANHO_REGISTRO)), nome);
                *(int *)(pBuffer+sizeof(int)+(sizeof(char)*TAMANHO_NOME)+((*(int*)pBuffer - 1)*TAMANHO_REGISTRO)) = idade;
                *(int *)(pBuffer+(2*sizeof(int))+(sizeof(char)*TAMANHO_NOME)+((*(int*)pBuffer - 1)*TAMANHO_REGISTRO)) = telefone;
            break;
            }
            
        case 2:
            //apaga(&pBuffer);
            break;
        case 3: // IMPRIME OS DADOS DE TODAS AS PESSOAS
            for( int i=0 ; i<*(int *)pBuffer ; i++ ) {
                printf("+---Dado da Pessoa %d---+\n", i+1);
                if ( i == 0 ) {
                    printf("Nome: %s\nIdade: %d\nTelefone: %d\n", (char*)(pBuffer+sizeof(int)), *(int*)(pBuffer+sizeof(int)+TAMANHO_NOME), *(int*)(pBuffer+(2*sizeof(int))+TAMANHO_NOME));
                } else {
                    printf("Nome: %s\nIdade: %d\nTelefone: %d\n", (char*)(pBuffer+sizeof(int)+(i*TAMANHO_REGISTRO)), *(int*)(pBuffer+sizeof(int)+(i*TAMANHO_REGISTRO)+TAMANHO_NOME), *(int*)(pBuffer+(2*sizeof(int))+(int)(i*TAMANHO_REGISTRO)+TAMANHO_NOME));
                }
            }
            break;
        case 4: // IMPRIME OS DADOS DE UMA PESSOA BUSCADA PELO NOME
            getchar();
            count = 0;
            printf("Informe a pessoa que voce quer buscar: ");
            scanf("%[^\n]s", nome);
            for( int i=0 ; i<*(int *)pBuffer ; i++ ) {
                if( strcmp(nome, (char*)(pBuffer+sizeof(int)+i*(TAMANHO_REGISTRO)))==0 ) {
                    printf("+---Dados de %s---+\n", nome);
                    if ( i == 0 ) {
                        printf("Idade: %d\nTelefone: %d\n", *(int*)(pBuffer+sizeof(int)+TAMANHO_NOME), *(int*)(pBuffer+(2*sizeof(int))+TAMANHO_NOME));
                    } else {
                        printf("Idade: %d\nTelefone: %d\n", *(int*)(pBuffer+sizeof(int)+(i*TAMANHO_REGISTRO)+TAMANHO_NOME), *(int*)(pBuffer+(2*sizeof(int))+(int)(i*TAMANHO_REGISTRO)+TAMANHO_NOME));
                    }
                    count++;
                } 
            }
            if ( count==0 ) {
                printf("PESSOA NAO ENCONTRADA\n");
            }
            break;
        case 5:
            printf("Informe a pessoa que voce quer buscar: ");
            scanf("%d", &pos);
            if ( pos > *(int *)pBuffer ) {
                printf("PESSOA INEXISTENTE\n");
            } else {
                printf("Dados da pessoa %d\n", pos);
                if ( pos==1 ) {
                    printf("Nome: %s\nIdade: %d\nTelefone: %d\n", (char *)(pBuffer+sizeof(int)), *(int*)(pBuffer+sizeof(int)+TAMANHO_NOME), *(int*)(pBuffer+(2*sizeof(int))+TAMANHO_NOME));
                } else {
                    printf("Nome: %s\nIdade: %d\nTelefone: %d\n", (char *)(pBuffer+sizeof(int)+((pos-1)*TAMANHO_REGISTRO)), *(int*)(pBuffer+sizeof(int)+((pos-1)*TAMANHO_REGISTRO)+TAMANHO_NOME), *(int*)(pBuffer+(2*sizeof(int))+((pos-1)*TAMANHO_REGISTRO)+TAMANHO_NOME));
                }
            }
            break;
        case 6:
            exit(1);
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
    printf(" 5. Buscar por posicao\n");
    printf(" 6. Sair\n");
    scanf("%d", &c);

    return c;
}