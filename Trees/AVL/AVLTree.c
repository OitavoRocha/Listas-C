#include <stdio.h>
#include <stdlib.h>

// boolean type definition
#define TRUE 1
#define FALSE 0
typedef int BOOL;

struct _node {
    int data;
    int h;
    struct _node * letf;
    struct _node * right;
};

typedef struct _node * AVLTree;
typedef struct _node Node;

// functions declaration
AVLTree * create();
void clear( AVLTree *root );
int insertNode( AVLTree *root , int value );
int removeNode( AVLTree *root, int value );
BOOL isEmpty( AVLTree *root );
int height( AVLTree *root );
int quantity( AVLTree *root );
BOOL isIn( AVLTree *root, int value );
void preOrder( AVLTree *root );
void inOrder( AVLTree *root );
void postOrder( AVLTree *root );

int main() {
    
    return 0;
}

AVLTree * create() {
    AVLTree * root = ( AVLTree * )malloc( sizeof( AVLTree ) );

    if ( root != NULL )
        *root = NULL;

    return root;
}

void preOrder( AVLTree * root ) {
    if ( root == NULL )
        return;

    printf("%d ", (*root)->data);
    preOrder( &(*root)->letf );
    preOrder( &(*root)->right );
}

void inOrder( AVLTree * root ) {
    if ( root == NULL )
        return;

    preOrder( &(*root)->letf );
    printf("%d ", (*root)->data);
    preOrder( &(*root)->right );
}

void postOrder( AVLTree * root ) {
    if ( root == NULL )
        return;

    preOrder( &(*root)->letf );
    preOrder( &(*root)->right );
    printf("%d ", (*root)->data);
}
