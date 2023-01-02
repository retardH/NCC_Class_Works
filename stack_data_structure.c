//
// Created by HtetZarni on 31/12/2022.
//

#include "stdio.h"
#include "stdlib.h"

#define MAXOFSTACK 10

struct stack{

    int data_arr[MAXOFSTACK];

    int top;

};

typedef struct stack st;

void create_emptyStack(st *stack) {

    stack->top = -1;

}

int is_stack_empty(st *stack) {

    if(stack->top == -1) {
        return 1;
    } else {
        return 0;
    }

}

int is_stack_full(st *stack) {

    if(stack->top == MAXOFSTACK-1) {
        return 1;
    } else {
        return 0;
    }

}

void push(st *stack, int value) {

    if(is_stack_full(stack)){
        printf("The stack is already full!\n");
    } else {
        stack->top++;
        stack->data_arr[stack->top] = value;
    }

}

void pop(st *stack) {

    if(is_stack_empty(stack)) {
        printf("The stack is empty!\n");
    } else {
        printf("The removed value from the stack is %d\n",stack->data_arr[stack->top]);
        stack->top--;
    }

}

void print_data_from_stack(st *stack) {

    if(is_stack_empty(stack)) {
        printf("This stack doesn't have any items.\n");
    } else {
        for(int n=stack->top; n>=0; n--) {

            printf("\t Items in the stack are %d\n", stack->data_arr[n]);

        }
    }

}

int main() {

    st *firstStack = (st *)malloc(sizeof (st));

    create_emptyStack(firstStack);

    push(firstStack,11);
    push(firstStack,22);
    push(firstStack,33);
    print_data_from_stack(firstStack);
    push(firstStack,99);
    push(firstStack,111);
    print_data_from_stack(firstStack);
    pop(firstStack);
    pop(firstStack);
    pop(firstStack);
    pop(firstStack);
    pop(firstStack);
    print_data_from_stack(firstStack);
    return 0;
}