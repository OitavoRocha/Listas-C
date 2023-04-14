// problem from leetcode -> https://leetcode.com/problems/symmetric-tree/
// resolution taken from NeetCodeIoO on youtube -> https://www.youtube.com/watch?v=Mao9uzxwvmc
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
typedef int BOOL;

struct _node {
    int data;
    struct _node * pLeft;
    struct _node * pRight;
};
typedef struct _node * Node;

Node create( int value );
BOOL isSymmetric( Node root );
BOOL DFS( Node left, Node right );

int main() {
    Node root = create( 1 );

    root->pLeft = create( 2 );
    root->pLeft->pLeft = create( 3 );
    root->pLeft->pRight = create( 4 );

    root->pRight = create( 2 );
    root->pRight->pLeft = create( 3 );
    root->pRight->pRight = create( 4 );

    if( isSymmetric( root ) )
        printf("\nSymmetric Tree\n");
    else
        printf("\nAssymetric Tree\n");

    return 0;
}

Node create( int value ) {
    Node newNode = (Node)malloc( sizeof( struct _node ) );

    newNode->data = value;
    newNode->pLeft = NULL;
    newNode->pRight = NULL;

    return newNode;
}

BOOL isSymmetric( Node root ) {
    if ( DFS( root->pLeft, root->pRight ) )
        return TRUE;
    
    return FALSE;
}

BOOL DFS( Node left, Node right ) {
    if ( left == NULL  && right == NULL ) 
        return TRUE;

    if ( left == NULL || right == NULL ) 
        return FALSE;

    if ( left->data == right->data && DFS( left->pLeft, right->pRight ) && DFS( left->pRight, right->pLeft ) )
        return TRUE;
    
    return FALSE;
}
