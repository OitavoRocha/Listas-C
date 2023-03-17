#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
typedef int BOOL;

typedef struct _heap {
    struct _node *first;
    struct _node *last;
}Heap;

typedef struct _node {
    int code;
    struct _node *next;
}Node;

Heap * START();
void PUSH( Heap * pHeap, Node * newElement );

Node * NEW( int code );
BOOL EMPTY( Heap * pHeap );

int main() {
    Heap * pH = START();

    PUSH( pH, NEW(2) );
    PUSH( pH, NEW(3) );
    PUSH( pH, NEW(1) );
    PUSH( pH, NEW(4) );
    
    return 0;
}

Heap *START() {
    Heap * pHeap = ( Heap * )malloc( sizeof( Heap ) );

    pHeap->first = NULL;
    pHeap->last = NULL;

    return pHeap;
}

void PUSH( Heap * pHeap, Node * newElement ){
    Node * pCurrent = pHeap->first;
    Node * pPrevious;

    if ( EMPTY( pHeap ) ) {
        pHeap->first = newElement;
        pHeap->last = newElement;
        return;
    }
    
    while( pCurrent && (pCurrent->code < newElement->code) ) {
        pPrevious = pCurrent;
        pCurrent = pCurrent->next;
    }
    
    if ( pCurrent == pHeap->first ) {
        pHeap->first = newElement;
        newElement->next = pCurrent;
    }

    if ( pCurrent==NULL ) {
        pHeap->last = newElement;
        pPrevious->next = newElement;
        return;
    }

    pPrevious->next = newElement;
    newElement->next = pCurrent;
    pCurrent = newElement;
}

Node * NEW( int code ) {
    Node * newNode = ( Node * )malloc( sizeof( Node ) );

    newNode->code = code;
    newNode->next = NULL;

    return newNode;
}

BOOL EMPTY(Heap *pHeap)
{
    if ( !pHeap->first )
        return TRUE;

    return FALSE;
}
