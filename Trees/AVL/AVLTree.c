#include <stdio.h>
#include <stdlib.h>

// boolean type definition
#define TRUE 1
#define FALSE 0
typedef int BOOL;

struct _node {
    int data;
    int h;
    struct _node * left;
    struct _node * right;
};

typedef struct _node * AVLTree;
typedef struct _node Node;

// functions declaration
AVLTree * create();
void clear( AVLTree *root );
Node * newNode( int value );
void insertNode( AVLTree *root , Node * new );
int removeNode( AVLTree *root, int value );
BOOL isEmpty( AVLTree *root );
BOOL isIn( AVLTree *root, int value );
int FB( AVLTree * root );
int height( AVLTree *root );
int quantity( AVLTree *root );
void leftRotate( AVLTree * root );
void rightRotate( AVLTree * root );
void preOrder( AVLTree *root );
void inOrder( AVLTree *root );
void postOrder( AVLTree *root );

int main() {
    AVLTree * root = create();

    insertNode( root, newNode( 40 ) );
    insertNode( root, newNode( 4 ) );

    preOrder( root );
    
    return 0;
}

AVLTree * create() {
    AVLTree * root = ( AVLTree * )malloc( sizeof( AVLTree ) );

    if ( root != NULL )
        *root = NULL;

    return root;
}

Node *newNode( int value ) {
    Node * new = ( Node * )malloc( sizeof( Node *) );

    new->data = value;
    new->h = 0;
    new->left = NULL;
    new->right = NULL;

    return new;
}

void insertNode( AVLTree * root, Node * new ) {
    if ( *root == NULL ) {
        *root = new;
        return;
    }

    if ( new->data < (*root)->data ) 
        insertNode( &(*root)->left, new );
    else 
        insertNode( &(*root)->right, new );

    (*root)->data = height( &(*root) );
}

void preOrder( AVLTree * root ) {
    if ( *root == NULL )
        return;

    printf("%d ", (*root)->data);
    preOrder( &(*root)->left );
    preOrder( &(*root)->right );
}

void inOrder( AVLTree * root ) {
    if ( *root == NULL )
        return;

    inOrder( &(*root)->left );
    printf("%d ", (*root)->data);
    inOrder( &(*root)->right );
}

void postOrder( AVLTree * root ) {
    if ( *root == NULL )
        return;

    postOrder( &(*root)->left );
    postOrder( &(*root)->right );
    printf("%d ", (*root)->data);
}

BOOL isEmpty( AVLTree * root ) {
    if ( root == NULL ) 
        return TRUE;
    
    return FALSE;
}

int FB( AVLTree * root ) {
    if ( root == NULL )
        return 0;
    
    return (*root)->left->h - (*root)->right->h;
}

int height(AVLTree *root)
{
    int iLeft, iRight;

    if ( root == NULL )
        return 0;

    iLeft = height( &(*root)->left );
    iRight = height( &(*root)->right );

    if ( iLeft > iRight )
        return iLeft + 1;
    else
        return iRight + 1;
}

void leftRotate( AVLTree * root ) {
    AVLTree aux;

    aux = (*root)->right;
    (*root)->right = aux->left;
    aux->left = (*root);
    (*root) = aux;
}

void rightRotate( AVLTree * root ) {
    AVLTree aux;

    aux = (*root)->left;
    (*root)->left = aux->right;
    aux->right = (*root);
    (*root) = aux;
}
