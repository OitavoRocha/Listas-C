/*
https://leetcode.com/problems/same-tree/

dando problema no momento o qual eu dou free nos vetores usados
*/
#include <stdio.h>
#include <stdlib.h>

struct _node
{
    int data;
    struct _node * pLeft;
    struct _node * pRight;
};

typedef struct _node * Node;

Node create( int value ) {
    Node newNode = ( Node )malloc( sizeof(struct _node) );

    newNode->data = value;
    newNode->pLeft = NULL;
    newNode->pRight = NULL;

    return newNode;
}

int count( Node root ) {
    if ( root == NULL )
        return 0;
    
    return 1 + count( root->pLeft ) + count( root->pRight );
}

void preOrder( Node root, int * vector ) {
    if ( root == NULL )
        return;

    (*vector) = root->data;
    preOrder( root->pLeft, vector + sizeof( int ) );
    preOrder( root->pRight, vector + sizeof( int ) + (count( root->pLeft ) * sizeof( int )) );
}

// 1 - same || 0 - not
int isSame( Node p, Node q ) {
    int * a;
    int * b;
    int size = count( p );

    // if trees have different quantity of nodes
    if ( size != count( q ) )
        return 0;

    a = (int *)malloc( sizeof( int ) * size );
    b = (int *)malloc( sizeof( int ) * size );

    preOrder( p, a );
    preOrder( q, b );

    for( int i = 0 ; i < size ; i++ ) 
        if ( *(a + (sizeof( int ) * i) ) != *(b + (sizeof( int ) * i) ) ) 
            return 0;

    //free( a );
    //free( b );
    return 1;
}

int main() {
    Node p = create( 1 );
    Node q = create( 1 );

    p->pLeft = create( 2 );
    p->pRight = create( 3 );

    q->pLeft = create( 2 );
    q->pRight = create( 3 );
    q->pLeft->pRight = create( 5 );

    if ( isSame( p, q ) )
        printf("\nArvores Iguais\n");
    else
        printf("\nArvores Diferentes\n");

    return 0;
}
