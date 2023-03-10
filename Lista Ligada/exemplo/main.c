/*
INCOMPLETO
*/
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
typedef int bool;

typedef struct {
    int code;
    struct SNodo * pNext;
}SNodo;

typedef struct {
    SNodo * pFirst;
    unsigned int tamanho;
}SLista;

void PUSH ( SLista * pLista , SNodo * pNodo );
bool POP (  SLista * pLista , SNodo * pNodo , unsigned int nIndex );
bool EMPTY ( SLista * pLista );

int main() {
    SLista * lista;
    SNodo nodo[5] = { {1, NULL}, {2, NULL}, {3, NULL}, {4, NULL}, {5, NULL} };

    lista = ( SLista * )malloc( sizeof( SLista ) );
    lista->pFirst = NULL;
    lista->tamanho = 0;
    
    for ( int i = 0 ; i < 5 ; i++ ) {
        PUSH ( lista , &nodo[i] );
    }
    
    

    return 0;
}

void PUSH( SLista * pLista , SNodo *pNodo ) {
    pLista = ( SLista * )realloc( pLista, sizeof( * pLista ) + ( pLista->tamanho * sizeof( SNodo ) ) );

    if ( EMPTY( pLista ) ) {
        pLista->pFirst = pNodo;
        pLista->pFirst->pNext = NULL;
        pLista->tamanho++;
        return;
    }
    

}

bool POP( SLista *pLista , SNodo *pNodo , unsigned int nIndex ) {

    if ( EMPTY( pLista ) ){ return FALSE; }
    



    return TRUE;
}

bool EMPTY(SLista *pLista) {

    if ( pLista->pFirst == NULL ) { return TRUE; }

    return FALSE;
}