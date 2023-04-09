#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct _node
{
    int data;
    struct _node * left;
    struct _node * right;
};

typedef struct _node Node;

Node * create( int value );
Node * insert( Node * root, int value );
Node * removeNode( Node * root, int value );
void predecessor( Node * root, Node ** r );
//void search( Node * root, int * value );


// methods to print the tree
void preOrder( Node * root ) {
    if ( root == NULL ) return;

    printf("%d ", root->data);
    preOrder( root->left );
    preOrder( root->right );
}

void inOrder( Node * root ) {
    if ( root == NULL ) return;

    inOrder( root->left );
    printf("%d ", root->data);
    inOrder( root->right );
}

void postOrder( Node * root ) {
    if ( root == NULL ) return;

    postOrder( root->left );
    postOrder( root->right );
    printf("%d ", root->data);
}

int main() {
    int r;
    srand(time(0));
    r = rand() % 100 + 1;

    Node * root = create( r );

    for ( int i = 0 ; i<10 ; i++ ) {
        r = rand() % 100 + 1;
        root = insert( root, r );
    }

    preOrder( root );
    printf("\n");

    root = removeNode( root, root->data );

    printf("\n");
    preOrder( root );
    printf("\n");

    root = removeNode( root, root->data );

    printf("\n");
    preOrder( root );
    printf("\n");
    return 0;
}

Node * create( int value ) {
    Node * newNode = (Node *)malloc( sizeof( Node ) );

    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

// insertion doesnt check if value is already in the tree
Node * insert( Node * root, int value ) {
    
    if ( root == NULL ) {
        root = create( value );
        return root;
    }

    if ( value < root->data ) {
        root->left = insert( root->left, value );
        return root;
    }

    root->right = insert( root->right, value );
    return root;
}

Node * removeNode( Node * root, int value ) {
    Node * aux;

    if ( root == NULL ) {
        printf("Registro nao encontrado\n");
        return root;
    }

    if ( value < root->data ) {
        root->left = removeNode( root->left, value );
        return root;
    }

    if ( value > root->data) {
        root->right = removeNode( root->right, value );
        return root;
    }

    /*
    // tests if node is a leaf -- no children
    if ( root->right == NULL && root->left == NULL ) {
        free( root );
        return NULL;
    }
*/

    // if node has only one child, in the left
    if ( root->right == NULL ) {
        aux = root;
        root = root->left;
        free( aux );
        return root;
    }

    if ( root->left != NULL ) {
        predecessor( root, &root->left );
        return root;
    }

    // root->left == NULL
    // if node has only one child, in the right
    aux = root;
    root = root->right;
    free( aux );
    return root;
}

// finds the most right node on the left subtree
void predecessor(Node * root, Node ** r ) {
    Node * aux;

    if ( (*r)->right != NULL ) {
        predecessor( root, &(*r)->right );
        return;
    }

    // changes the root data to that of the found node ( most right on left subtree )
    root->data = (*r)->data;
    aux = *r;
    *r = (*r)->left;
    free( aux );
}

/*
 -- function to find a specific node based on a key value (int)
void search( Node * root, int * value ) {
    if ( root == NULL ) {
        printf("Erro: Valor nao presente\n");
        return;
    }

    if ( *value < root->data ) {
        search( root->left, value );
        return;
    } else if ( *value > root->data )
        search( root->right, value );
    else
        *value = root->data;
}
*/