/*
Faça uma agenda capaz de incluir, apagar, buscar e listar quantas pessoas o usuário desejar, porém, toda a informação incluída na agenda deve ficar num único lugar chamado: “void *pBuffer”.
• Não pergunte para o usuário quantas pessoas ele vai incluir. Não pode alocar espaço para mais pessoas do que o necessário.
• Cada pessoa tem nome[10], idade e telefone.
• O trabalho que vale nota será uma continuação deste.
ERRO!
    depois de muito tempo testando, tive um erro de segmentation na linha 159

TO DO
    tem q implementar a função apagar, já fiz o esqueleto dela, acredito que a melhor opção seja utilizar ponteiro pra ponteiro
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true 1
#define false 0
typedef int bool;

#define SIZE ( sizeof ( char ) * 10 + sizeof ( int ) * 2 )
#define NAME_SIZE ( sizeof ( char ) * 10 ) 
#define INTEGER_SIZE (sizeof ( int ))

int menu();
void adiciona( void * ini );
//void apaga( void ** pBuffer, int * tamanho );
void imprimeContato( void * ini );
void lista( void * ini, int * tam );
void buscaPorPosicao( void * ini, int * tam );
void buscaNome( void * ini, int * tam );
bool empty( int * tam );

int main() {
    void *pBuffer;
    void *ini;
    int *tamanho;

    pBuffer = malloc( INTEGER_SIZE + 1 );
    tamanho = ( int * ) pBuffer;
    *tamanho = 0;

    while ( 1 ) {
        ini = ( pBuffer + INTEGER_SIZE );
        switch ( menu() ) {
        case 1:
            (*tamanho)++;
            pBuffer = realloc( pBuffer, SIZE * ( *tamanho ) + INTEGER_SIZE );
            tamanho = ( int * ) pBuffer;
            ini = ( pBuffer + INTEGER_SIZE );
            printf( "Informe os dados da pessoa %d:\n", *tamanho );
            adiciona( ( ini +  SIZE * ( ( * tamanho ) - 1 ) ) );
            break;
        case 2:
            //apaga( &pBuffer, tamanho );
            break;
        case 3:
            lista( ini, tamanho );
            break;
        case 4:
            buscaPorPosicao( ini, tamanho );
            break;
        case 5:
            buscaNome( ini, tamanho);
            break;
        case 6:
            /*
            FOI S
            printf( "Tamanho: %d\n" , *( int * )pBuffer );
            for ( int i = 0 ; i < * tamanho ; i++ ) {
                pBuffer = pBuffer + INTEGER_SIZE;
                printf( " %s\n" ,  ( char * )pBuffer );
                pBuffer = pBuffer + NAME_SIZE;
                printf( " %d\n" ,  *( int * )pBuffer );
                pBuffer = pBuffer + INTEGER_SIZE;
                printf( " %d\n" ,  *( int * )pBuffer );
            }
            */
            free( pBuffer );
            exit(1);
        }
    }

    return 0;
}

int menu() {
    int c;

    printf( "Informe uma opcao\n" );
    printf( " 1.Adicionar pessoa\n" );
    printf( " 2.Apaga Contato\n" );
    printf( " 3.Listar\n" );
    printf( " 4.Busca por Posicao\n" );
    printf( " 5.Busca por Nome\n" );
    printf( " 6.Sair\n" );
    scanf( "%d", &c );

    return c;
}

void adiciona( void * ini ) {

    getchar();
    printf( "-Nome: " );
    scanf( "%9[^\n]s", ( char * ) ini );
    ini = ini + NAME_SIZE;
    printf( "-Idade: ");
    scanf( "%d", ( int * ) ini );
    ini = ini + INTEGER_SIZE;
    printf( "-Telefone: " );
    scanf( "%d", ( int * ) ini );

}
/*
void apaga( void ** pBuffer, int * tamanho ) {


}
*/
void imprimeContato( void * ini) {

    printf( " Nome: %s\n", ( char * ) ini );
    ini = ini + NAME_SIZE;
    printf( " Idade: %d\n", * ( int * ) ini );
    ini = ini + INTEGER_SIZE;
    printf( " Telefone: %d\n", * ( int * ) ini );

}

void lista( void * ini, int * tam ) {

    if ( !empty( tam ) ) {
        printf( "Agenda vazia\n" );
        return;
    }

    for ( int i = 0 ; i < * tam ; i++ ){
        printf( "Dados da pessoa %d:\n", i+1 );
        imprimeContato( ini );
        ini = ini + SIZE;
    }
}

void buscaPorPosicao( void * ini, int * tam ) {
    int pos;

    if ( !empty( tam ) ) {
        printf( "Agenda vazia\n" );
        return;
    }

    printf( "Informe a posicao que deseja buscar: " );
    scanf( "%d", &pos );
    while ( !( pos <= *tam && pos > 0 ) ) {
        printf( "Posicao invalida, informe outra: " );
        scanf( "%d", &pos );
    }

    imprimeContato( ini + ( SIZE * ( pos - 1 ) ) );

}

void buscaNome( void * ini, int * tam ) {
    char nome[10];

    if ( !empty( tam ) ) {
        printf( "Agenda vazia\n" );
        return;
    }

    getchar();
    printf( "Informe o nome a ser procurado: " );
    scanf( "%9[^\n]s", nome );
    
    for ( int i = 0 ; i < * tam ; i++ , ini = ini + SIZE ) {
        if ( strcmp( ( char * )ini, nome ) == 0 ) {
            imprimeContato( ini );
            return;
        }
    }

    printf( "Nome nao encontrado!\n" );

}

bool empty( int * tam ) {
    if ( *tam == 0 ) {
        return false;
    } else {
        return true;
    }
}
