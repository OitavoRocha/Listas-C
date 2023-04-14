/*
https://leetcode.com/problems/recover-binary-search-tree/
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

void recoverTree( Node root );
Node findLeft( Node root, Node problematic, int value );
Node findRight( Node root, Node problematic, int value );

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

void preOrder( Node root ) {
    if ( root == NULL )
        return;

    printf("%d ", root->data);
    preOrder( root->pLeft );
    preOrder( root->pRight );
}

int main() {
/*
        10
       /   \
     5      17 
    / \     /  
   6   8   15   
*/
    Node root = create( 10 );

    root->pLeft = create( 5 );
    root->pLeft->pRight = create( 8 );
    root->pLeft->pLeft = create( 6 );
    root->pRight = create( 17 );
    root->pRight->pLeft = create( 15 );

    printf("\n");
    preOrder( root );
    printf("\n");

    recoverTree( root );

    printf("\n");
    preOrder( root );
    printf("\n");

    return 0;
}

Node findLeft( Node root, Node problematic , int value ) {
    Node aux;

    if ( root == NULL ) 
        return NULL;

    if ( root->data > value ) 
        return root;
    
    if ( root->data <= value ) {
        aux = findLeft( root->pLeft, problematic, value );
        if ( aux == NULL )
            aux = findLeft( root->pRight, problematic, value );
    }

    return aux;
}

Node findRight( Node root, Node problematic , int value ) {
    Node aux;

    if ( root == NULL )
        return NULL;
    

    if ( root->data < value ) 
        return root;
    

    if ( root->data >= value ) {
        aux = findRight( root->pLeft, problematic, value );
        if ( aux == NULL )
            aux = findRight( root->pRight, problematic, value );
    }

    return aux;
}

void recoverTree( Node root ) {
    Node problematicNode = ( Node )malloc( sizeof(struct _node) );
    int aux;

    if ( root == NULL )
        return;
    
    problematicNode = findLeft( root->pLeft, problematicNode, root->data );
    
    if ( problematicNode == NULL )
        problematicNode = findRight( root->pRight, problematicNode, root->data );

    if( problematicNode == NULL ) {
        recoverTree( root->pLeft );
        recoverTree( root->pRight );
        return;
    }

    aux = root->data;
    root->data = problematicNode->data;
    problematicNode->data = aux;
}