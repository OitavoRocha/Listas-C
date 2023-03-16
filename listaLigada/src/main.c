#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
typedef int BOOL;

typedef struct _list {
    struct _node *head;
    int size;
}List; // SENTINEL

typedef struct _node {
    int code;
    struct _node *next;
}Node; // NODE

void PUSH( List * pList, Node * newNode); // PUSH
void POP( List * pList, int nIndex ); // POP FROM INDEX
Node* newNode( int code ); // CREATES A NEW NODE
List* START(); // INITIALIZES THE LIST
BOOL EMPTY( List * pList ); // CHECKS IF LIST`S EMPTY
void PRINT( Node ** head ); // PRINTS EACH NODE FROM THE LIST
void CLEAR( List * pList );

int main() {
    List *pL = START();

    PUSH( pL, newNode(1));
    PUSH( pL, newNode(2));
    PUSH( pL, newNode(3));
    PUSH( pL, newNode(4));
    PUSH( pL, newNode(5));
    PUSH( pL, newNode(6));
    
    PRINT( &pL->head );

    POP( pL, 1); // POP FIRST NUMBER -- IN THIS CASE '1'
    POP( pL, 2); // POP SECOND NUMBER -- IN THIS CASE '3'
    POP( pL, 3); // POP THIRD NUMBER -- IN THIS CASE '5'

    printf("\n+---+\n\n");
    PRINT( &pL->head );

    CLEAR( pL );

    return 0;
}

void PUSH( List* pList, Node * newNode ) {
    Node *pCurrent;

    if ( EMPTY( pList ) ) {
        pList->head = newNode;
        pList->size++;
        return;
    }

    pCurrent = pList->head;

    for ( int i=1 ; i < pList->size ; i++ ) {
        pCurrent = pCurrent->next;
    }

    pCurrent->next = newNode;
    pList->size++;

}

void POP(List *pList, int nIndex) {
    Node *pCurrent = pList->head;
    Node *pPrevious;

    // CHECKS IF LIST IS EMPTY
    if ( EMPTY( pList ) )
        return ;

    pList->size--; // SUBSTRACTS FROM LIST`S SIZE

    // FIRST NODE CASE
    if ( nIndex == 1 ) {
        pList->head = pList->head->next;
        free( pCurrent );
        return;
    }

    // LOOP TO THE ASKED POSITION
    for ( int i=0 ; i < nIndex - 1 && pCurrent != NULL ; i++ ) {
        pPrevious = pCurrent;
        pCurrent = pCurrent->next;
    }

    if (!pCurrent) return; // IF INDEX IS NOT IN THE LIST, IT RETURNS

    pPrevious->next = pCurrent->next;
    free( pCurrent );
}

Node *newNode( int code ) {
    Node * new;

    new = ( Node * )malloc( sizeof( Node ) );
    new->code = code;
    new->next = NULL;

    return new;
}

List* START() {
    List* pList = ( List * )malloc( sizeof( List ) ); 
    pList->size = 0;
    pList->head = NULL;

    return pList;
}

BOOL EMPTY( List *pList ) {
    if ( pList->head == NULL )
        return TRUE;

    return FALSE;
}

void PRINT( Node ** head ) {
    Node ** tracer = head;

    while ( *tracer ) {
        printf(" %d \n", (*tracer)->code);
        tracer = &(*tracer)->next;
    } 
}

void CLEAR( List *pList ) {
    Node * tracer = pList->head;

    while ( pList->head ) {
        pList->head = pList->head->next;
        free( tracer );
        tracer = pList->head;
    }

    free( pList );
}
