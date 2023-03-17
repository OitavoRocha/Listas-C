#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
typedef int BOOL;

typedef struct _stack {
    struct _node * top;
}Stack;

typedef struct _node {
    int code;
    struct _node * next;
}Node;

Stack * START();
void PUSH( Stack * pStack, Node * newElement );
Node * POP( Stack * pStack );
void PRINT( Stack * pStack );
Node * NEW( int code );
void CLEAR( Stack * pStack );
BOOL EMPTY( Stack * pStack );

int main() {
    Stack * pS = START();
    Node * pPopped;

    PUSH( pS, NEW(1));
    PUSH( pS, NEW(2));
    PUSH( pS, NEW(3));
    PUSH( pS, NEW(4));
    PUSH( pS, NEW(5));
    PUSH( pS, NEW(6));

    PRINT( pS );

    pPopped = POP( pS );
    free( pPopped );
    pPopped = POP( pS );
    free( pPopped );

    printf("\n+----+\n\n");
    PRINT( pS );    

    CLEAR( pS );

    return 0;
}

Stack * START() {
    Stack * pStack = ( Stack * )malloc( sizeof( Stack ) );

    pStack->top = NULL;
    return pStack;
}

void PUSH( Stack * pStack, Node * newElement ) {
    newElement->next = pStack->top;
    pStack->top = newElement;
}

Node *POP( Stack * pStack ) {
    Node * pNode;

    if ( EMPTY( pStack ) ) {
        printf("Lista vazia/n");
        return NULL;
    }

    pNode = pStack->top;
    pStack->top = pNode->next;

    return pNode;
}

void PRINT( Stack * pStack ) {
    Stack * pTemporary = START();
    Node * pNode;

    while ( pStack->top ) {
        pNode = POP( pStack );
        PUSH( pTemporary, pNode );
        printf(" %d \n", pNode->code);
    }

    while ( pTemporary->top ) {
        pNode = POP( pTemporary );
        PUSH( pStack, pNode );
    }

    free( pTemporary );
}

Node * NEW( int code ) {
    Node * pNode = ( Node * )malloc( sizeof( Node ));

    pNode->code = code;
    pNode->next = NULL;

    return pNode;
}

void CLEAR( Stack * pStack ) {
    Node * pNode;

    while ( pStack->top ) {
        pNode = POP( pStack );
        free( pNode );
    }

    free( pStack );
}

BOOL EMPTY( Stack * pStack ) {
    if ( pStack->top == NULL )
        return TRUE;
    
    return FALSE;
}
