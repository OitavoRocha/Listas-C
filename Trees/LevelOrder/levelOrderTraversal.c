// https://leetcode.com/problems/binary-tree-level-order-traversal/
#include <stdio.h>
#include <stdlib.h>

struct _node {
    int val;
    struct _node *left;
    struct _node *right;
};
typedef struct _node TreeNode;

TreeNode * create( int value );
int** levelOrder( TreeNode* root, int* returnSize, int** returnColumnSizes);

int main() {
    

    return 0;
}

int **levelOrder( TreeNode *root, int *returnSize, int **returnColumnSizes) {
    
}