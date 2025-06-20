#ifndef TREE_H
#define TREE_H

#include "stdbool.h"

typedef struct TreeNode {
    char data;
    struct TreeNode *left;   // dot (.)
    struct TreeNode *right;  // strip (-)
} TreeNode;

TreeNode* newNode(char data);

bool isEmpty(TreeNode *root);

void preOrder(TreeNode *root);

void inOrder(TreeNode *root);

void postOrder(TreeNode *root);

void insertNode(TreeNode **root, char info, TreeNode parent);

TreeNode* getNodeByChar(TreeNode *root, char key);

#endif
