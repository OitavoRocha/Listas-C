#include <stdio.h>
#include <stdlib.h>

#define RED 1
#define BLACK 0

struct _node {
    int data;
    int color;
    struct _node * left;
    struct _node * right;
    struct _node * parent;              
};
typedef struct _node Node;

Node * create( int value );
Node * insert( Node * n );
void insert_case2( Node * n );
void insert_case3( Node * n );
void insert_case4( Node * n );
void insert_case5( Node * n );
Node * grandparent( Node * n );
Node * uncle( Node * n);


int main() {
    Node * root = insert( create( 8 ));

    return 0;
}

Node * create( int value ) {
    Node * newNode = (Node *)malloc( sizeof(Node) );

    newNode->data = value;
    newNode->color = RED;
    newNode->left = NULL;
    newNode->right = NULL; 
    newNode->parent = NULL;    
    
    return newNode;
}

Node * insert( Node * n ) {
    // if newNode is the tree`s root
    if ( n->parent == NULL ) {
        n->color = BLACK;
        return n;
    }

    insert_case2( n );
}

void insert_case2( Node * n ) {
    if ( n->parent->color == BLACK )
        return;
    else
        insert_case3( n );
}

void insert_case3( Node * n ) {
    Node * u = uncle( n );
    Node * g;

    if ( (u!=NULL) && (u->color == RED) ) {
        n->parent->color = BLACK;
        u->color = BLACK;
        g = grandparent( n );
        g->color = RED;
        insert( g );
    } else 
        insert_case4( n );
}

void insert_case4( Node * n ) {
    Node * g = grandparent( n );

    if ( (n == n->parent->right))
}

Node * grandparent( Node * n ) {
    if ( ( n != NULL ) && ( n->parent != NULL ) )
        return n->parent->parent;
    else
        return NULL;
}

Node *uncle( Node * n ) {
    Node * g = grandparent( n );
    if ( g == NULL ) 
        return NULL; // no grandparent means no uncle
    
    if ( n->parent == g->left )
        return g->right;
    else
        return g->left;
}
