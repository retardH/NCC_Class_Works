//
// Created by HtetZarni on 27/04/2023.
//

#include "stdio.h"
#include "stdlib.h"

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};


struct Node* create_balanced_bst(int start, int end) {
    if(start > end) {
        return NULL;
    }
    // find the middle value
    int middleValue = (start + end) / 2;
    struct Node* root = (struct Node*)malloc(sizeof (struct Node));
    root->data = middleValue;
    // struct the left node with lesser values
    root->left = create_balanced_bst(start, middleValue - 1);
    // struct the right node with the greater values
    root->right = create_balanced_bst(middleValue + 1, end);

    return root;
}

struct Node* create_bst() {

    struct Node* root = (struct Node*)malloc(sizeof (struct Node));
    root->data = 50;
    struct Node* leftSubTree = create_balanced_bst(1,49);
    root->left = leftSubTree;
    struct Node* rightSubTree = create_balanced_bst(51,100);
    root->right = rightSubTree;

    return root;
}

void print_in_order(struct Node* root) {
    if(root == NULL) {
        return;
    }
    print_in_order(root->left);
    printf("%d\n",root->data);
    print_in_order(root->right);
}

int main () {

    struct Node* root = create_bst();

    printf("Inorder traversal of the BST\n");

//    print_in_order(root);
    print_in_order(root->left);
    printf("\n\n");
    print_in_order(root->right);
    return 0;
};
