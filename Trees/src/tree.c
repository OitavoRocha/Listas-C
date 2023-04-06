//  Cria uma arvore com inserção manual na função main
// code from: https://www.scaler.com/topics/binary-tree-in-c/
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node * left;
    struct node * right;
};

typedef struct node Node;

// cria um novo nodo
Node * create( int data ) {
    Node * newNode = ( Node * )malloc( sizeof( Node ) );

    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

// insere a esquerda
Node * insertLeft( Node * root, int value ) {
    root->left = create( value );
    return root->left;
}

// insere a direita
Node * insertRight( Node * root, int value ) {
    root->right = create( value );
    return root->right;
}

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
    Node * root = create( 40 ); // cria a raiz da arvore

    insertLeft( root, 4 );
    insertRight( root->left, 34 );
    insertLeft( root->left->right, 14 );
    insertLeft( root->left->right->left, 13 );
    insertRight( root->left->right->left, 15 );

    insertRight( root, 45 );
    insertRight( root->right, 55 );
    insertLeft( root->right->right, 48 );
    insertLeft( root->right->right->left, 47 );
    insertRight( root->right->right->left, 49 );

    printf("Pre Ordem: ");
    preOrder( root );

    printf("\nCentral: ");
    inOrder( root );

    printf("\nPos Ordem: ");
    postOrder( root );

    return 0;
}

// funcao para a busca de um valor na arvore para implementacao de insercao automatica (futura)
/*
Node * search( int data, Node * p ) {
    Node * pointer;

    if ( p == NULL ) {
        printf("Erro: Valor nao presente\n");
        return NULL;
    }

    if ( data < p->data ) 
        pointer = search( data, p->left );

    if ( data > p->data ) 
        pointer = search( data, p->right );
    else 
        pointer = p;

    return pointer;
}
*/