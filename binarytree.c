#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

typedef struct BinaryTree{
    TreeNode *root;
} BinaryTree;

void init_binary_tree(BinaryTree *tree){
    tree->root=NULL;
}

TreeNode *init_node(int data){
    TreeNode *node = malloc(sizeof(TreeNode));
    node->data=data;
    node->left=NULL;
    node->right=NULL;

    return node;
}

char* traverse_preorder(TreeNode *root, char *traversal){
    if (root){
        traversal += sprintf(traversal, "%d", root->data);
        traversal = traverse_preorder(root->left, traversal);
        traversal = traverse_preorder(root->right, traversal);
    }
    return traversal;
}

int get_height(TreeNode *root){
    if (!root){
        return 0;
    }
    int max = 0;
    int left = get_height(root->left);
    int right = get_height(root->right);
    if(left>max){
        max=left;
    }
    if(right>max){
        max=right;
    }

    return 1+max;
}

int main(){

    BinaryTree *tree = malloc(sizeof(BinaryTree));
    init_binary_tree(tree);
    tree->root=init_node(1);
    tree->root->left=init_node(2);
    tree->root->right=init_node(3);
    tree->root->left->left=init_node(4);
    tree->root->left->left->left=init_node(4);
    char traversal[100] = "";
    traverse_preorder(tree->root, traversal);
    printf("%s\n", traversal);

    printf("%d", get_height(tree->root));
    return 0;
}