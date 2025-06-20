#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/tree.h"

bool isEmpty(TreeNode *root) {
    return root == NULL;
}

TreeNode* newNode(char data) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    if (node == NULL) {
        printf("Alokasi memori gagal!");
        return NULL;
    }
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void preOrder(TreeNode *root) {
    if (isEmpty(root)) return;
    
    printf("%c ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(TreeNode *root) {
    if (isEmpty(root)) return;

    inOrder(root->left);
    printf("%c ", root->data);
    inOrder(root->right);
}

void postOrder(TreeNode *root) {
    if (isEmpty(root)) return;
    
    postOrder(root->left);
    postOrder(root->right);
    printf("%c ", root->data);
}

void insertNode(TreeNode **root, char data, TreeNode *parent) {
    if (isEmpty(*root) && isEmpty(parent)) {
        // Create root if empty
        *root = (TreeNode*)malloc(sizeof(TreeNode));
        (*root)->data = data;
        (*root)->left = (*root)->right = NULL;
        return;
    }
    
    if (isEmpty(parent)) return; // Invalid parent
    
    // Create new node
    TreeNode *newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    
    // Insert as left or right child based on availability
    if (parent->left == NULL) {
        parent->left = newNode;
    } else if (parent->right == NULL) {
        parent->right = newNode;
    } else {
        printf("Parent already has two children. Cannot insert node.\n");
        free(newNode);
    }
}

TreeNode* getNodeByChar(TreeNode *root, char key) {
    if (isEmpty(root)) return NULL;
    
    if (root->data == key) return root;
    
    TreeNode* left = getNodeByChar(root->left, key);
    if (left != NULL) return left;
    
    return getNodeByChar(root->right, key);
}