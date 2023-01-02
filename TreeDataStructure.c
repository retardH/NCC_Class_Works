//
// Created by HtetZarni on 20/12/2022.
//

#include "stdio.h"
#include "stdlib.h"

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int key) {

    struct Node* root_node = malloc(sizeof (struct Node));
    root_node->data = key;
    root_node->left = NULL;
    root_node->right = NULL;

    return root_node;
}

void insertAtLeft(struct Node* root_node, int key) {

    root_node->left = createNode(key);

}

void insertAtRight(struct Node* root_node, int key) {

    root_node->right = createNode(key);

}

int main() {

    struct Node* root = createNode(11);
    struct Node* root2 = createNode(22);
    insertAtLeft(root, 99);
    insertAtRight(root,88);
    printf("\t%d\n",root->left->data);
    printf("\t%d\n",root->right->data);

    return 0;
}