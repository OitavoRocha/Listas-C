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
Node * NEW( int code );
BOOL EMPTY( Stack * pStack );

int main() {
    Stack * pS = START();

    return 0;
}

Stack * START() {
    Stack * pStack = ( Stack * )malloc( sizeof( Stack ) );

    pStack->top = NULL;
}

void PUSH( Stack * pStack, Node * newElement ) {
    newElement->next = pStack->top;
    pStack->top = newElement;
}

Node * NEW( int code ) {
    Node * pNode = ( Node * )malloc( sizeof( Node ));

    pNode->code = code;
    pNode->next = NULL;

    return pNode;
}

BOOL EMPTY( Stack * pStack ) {
    if ( pStack->top == NULL )
        return TRUE;
    
    return FALSE;
}