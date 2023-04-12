/*
https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
tem q terminar isso aq ainda
*/
#include <stdio.h>
#include <stdlib.h>

struct _node {
    int data;
    struct _node * pLeft;
    struct _node * pRight;
};
typedef struct _node * Node;

Node create( int value );
Node insertNode( Node root, int value );
Node removeNode( Node root, int value );
void predecessor( Node root, Node * r );
int height( Node root );
void zigZagPrint( Node root );

void preOrder( Node root ) {
    if ( root == NULL ) return;

    printf("%d ", root->data);
    preOrder( root->pLeft );
    preOrder( root->pRight );
}


int main() {
    Node root = create( 40 );
    
    root = insertNode( root, 4 );
    root = insertNode( root, 34 );
    root = insertNode( root, 45 );
    root = insertNode( root, 48 );

    printf("\n");
    preOrder( root );
    printf("\n");


    return 0;
}

Node create( int value ) {
    Node newNode = (Node)malloc( sizeof( struct _node ) );

    newNode->data = value;
    newNode->pLeft = NULL;
    newNode->pRight = NULL;

    return newNode;
}

Node insertNode( Node root, int value ) {
    if ( root == NULL ) {
        root = create( value );
        return root;
    }

    if ( value < root->data )
        root->pLeft = insertNode( root->pLeft, value );
    else
        root->pRight = insertNode( root->pRight, value );
    
    return root;
}

Node removeNode( Node root, int value ) {
    Node aux;

    if ( root == NULL ) {
        printf("Not found\n");
        return root;
    }


    if ( root->data < value ) {
        root->pLeft = removeNode( root->pLeft, value );
        return root;
    } else {
        root->pRight = removeNode( root->pRight, value );
        return root;
    }

    if ( root->pRight == NULL ) {
        aux = root;
        root = root->pLeft;
        free( aux );
        return root;
    }

    if ( root->pLeft == NULL ) {
        aux = root;
        root = root->pRight;
        free( aux );
        return root;
    }

    predecessor( root, &root->pLeft );
    return root;
}

void predecessor(Node root, Node * r ) {
    Node aux;

    if ( (*r)->pRight != NULL ) {
        predecessor( root, &(*r)->pRight );
        return;
    }

    // changes the root data to that of the found node ( most right on left subtree )
    root->data = (*r)->data;
    aux = *r;
    *r = (*r)->pLeft;
    free( aux );
}

void zigZagPrint( Node root ) {
    Node aux;
    int h = height( root );
    
    for( int i = 0 ; i < h ; i++ ) {
        ;
    }
}
