//https://leetcode.com/problems/symmetric-tree/
#include <stdio.h>
#include <stdlib.h>

struct _node {
    int data;
    struct _node * pLeft;
    struct _node * pRight;
};

typedef struct _node Node;
typedef struct _node * Tree;

Tree create( int value );
Tree insertLeft( Tree newNode );
Tree insertRight( Tree newNode );
int equals( Tree root );
void preOrder( Tree root ) {
    if ( root == NULL )
        return;

    printf("%d ", root->data);
    preOrder( root->pLeft );
    preOrder( root->pRight );
}

int main() {
    int flag;
    Tree root = create(1);

    //
    root->pLeft = insertLeft( create(2));
    root->pLeft->pLeft = insertLeft( create(3));
    root->pLeft->pRight = insertRight( create(4));
    //
    root->pRight = insertRight( create(2));
    root->pRight->pLeft = insertLeft( create(4));
    root->pRight->pRight = insertRight( create(3));

    preOrder( root );

    flag = equals( root );
    if( flag == 0 )
        printf("\nArvore simetrica\n");

    return 0;
}

Tree create( int value ) {
    Tree newNode = (Tree)malloc( sizeof(Node) );

    newNode->data = value;
    newNode->pLeft = NULL;
    newNode->pRight = NULL;

    return newNode;
}

Tree insertLeft( Tree newNode ) {
    return newNode;
}

Tree insertRight( Tree newNode ) {
    return newNode;
}

int equals( Tree root ) {
    int flag = 0;

    if ( root->pLeft->data != root->pRight->data )
        return 1;
    
    flag += equals( root->pLeft );
    flag += equals( root->pRight );
    return flag;
}
