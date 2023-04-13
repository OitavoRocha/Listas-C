/*
https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
tem q terminar isso aq ainda
*/
#include <stdio.h>
#include <stdlib.h>

#define LeftRight 0
#define RightLeft 1

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
int count( Node root );
int changeDirection( int flag );
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

    printf(" height: %d", height( root ));
    printf("\n");
    zigZagPrint( root );
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

    if ( value < root->data ) {
        root->pLeft = insertNode( root->pLeft, value );
    } else {
        root->pRight = insertNode( root->pRight, value );
    }

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

int height( Node root ) {
    if ( root == NULL ) 
        return 0;

    int hR, hL;

    hR = height( root->pRight );
    hL = height( root->pLeft );

    if ( hR > hL )
        return hR + 1;

    return hL + 1; 
}

int count( Node root ) {
    if( root == NULL )
        return 0;

    return 1 + count( root->pLeft ) + count( root->pRight );
}

int changeDirection( int flag ) {
    return !flag;
}

void zigZagPrint( Node root ) {
    Node aux = root;
    int * vector = (int *)malloc( count( root ) * sizeof( int ) );
    int size = count( root );
    int flag = LeftRight;

    if ( size == 0 ) {
        return;
    }
    
    for( int i = 0 ; i < size ; i++ ) {
        if ( LeftRight ) 
            vector[i] = aux->data;
        else
            vector[i] = aux->data;
    }
    
}
