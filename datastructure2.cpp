//
// Created by HtetZarni
//


#include "stdio.h"
#include "stdlib.h"

struct Node{
    int data;
    struct Node* next;
};



void push(struct Node** head_node,int da_ta) {

    struct Node* new_node = (struct Node*) malloc(sizeof (struct Node));

    new_node->data = da_ta;
    new_node->next = (*head_node);
    (*head_node) = new_node;

}

void printData(struct Node* myNode) {

    while (myNode != NULL) {
        printf("data: %d\n", myNode->data);
        myNode = myNode->next;

    }

}

void insertAfter(struct Node *input_node,int da_ta) {

    if(input_node->next == NULL) {
        printf("The input node is NULL!\n");

    } else{

        struct Node* new_node = (struct Node*) malloc(sizeof (struct Node));

        new_node->data = da_ta;

        new_node->next = input_node->next;

        input_node->next = new_node;
    }

}

int searchData(int da_ta,struct Node* input_node) {

    if (input_node == NULL) {
        printf("The input node is NULL!\n");
        return -1;
    }

    while (input_node != NULL) {
        if(da_ta == input_node->data) {
            printf("The data is found.\n");
            return 1;
        } else {
            input_node = input_node->next;
        }
    }

}

int main() {


    struct Node* one = (struct Node*)malloc(sizeof (struct Node));
    struct Node* two = (struct Node*)malloc(sizeof (struct Node));
    struct Node* three = (struct Node*)malloc(sizeof (struct Node));

    one->data = 11;
    one->next = two;
    two->data = 22;
    two->next = three;
    three->data = 33;
    three->next = NULL;

    push(&one,44);
    printData(one);
    printf("\n::::::After inserting new node::::::\n\n ");
    insertAfter(two,99);
    int result = searchData(22,one);

    printData(one);



    return 0;
}