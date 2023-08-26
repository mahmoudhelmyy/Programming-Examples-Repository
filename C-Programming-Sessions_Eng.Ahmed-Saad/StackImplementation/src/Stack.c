/*
 ============================================================================
 Name        : Stack.c
 Author      : Mahmoud Sayed Helmy
 Description : Basic implementation of a stack in C
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

/* MISRA Rule 8.2: Functions should have complete prototypes */
struct stack* create_stack(int size);
void push(int data, struct stack *helmystack);
int pop(struct stack *helmystack);
void print(struct stack *helmystack);

/* MISRA Rule 8.1: All declaration should be at the top of the function */
struct stack {
    int *arr;   // Array to hold stack elements
    int size;   // Maximum size of the stack
    int top;    // Index of the top element in the stack
};

int main(void) {
    // Create a stack of size 5
    struct stack *mystack = create_stack(5);

    // Push and pop elements
    push(1, mystack);
    push(2, mystack);
    push(3, mystack);
    printf("%d\n", pop(mystack));
    pop(mystack);
    push(4, mystack);
    push(5, mystack);
    push(6, mystack); // Won't be pushed due to stack size limit
    push(7, mystack); // Won't be pushed due to stack size limit

    // Print the remaining elements in the stack after popping
    print(mystack);

    // Pop the last element
    printf("%d\n", pop(mystack));

    // MISRA Rule 21.1: All dynamically allocated memory should be released
    free(mystack->arr); // Free allocated memory for stack's array
    free(mystack); // Free allocated memory for stack structure

    return 0; // Return 0 to indicate successful execution
}

/* MISRA Rule 8.2: Function definitions should have complete prototypes */
struct stack* create_stack(int size) {
    struct stack *helmystack;
    helmystack = (struct stack *) malloc(sizeof(struct stack));
    if (helmystack == NULL) {
        printf("Memory allocation failed for stack structure!\n");
        exit(EXIT_FAILURE);
    }
    helmystack->arr = (int *) malloc(sizeof(int) * size);
    if (helmystack->arr == NULL) {
        printf("Memory allocation failed for stack array!\n");
        free(helmystack); // MISRA Rule 21.1: Free previously allocated memory
        exit(EXIT_FAILURE);
    }
    helmystack->size = size;
    helmystack->top = -1;
    return helmystack;
}

void push(int data, struct stack *helmystack) {
    if (helmystack->top == helmystack->size - 1) {
        printf("Stack FULL!!\n");
    } else {
        helmystack->top++;
        helmystack->arr[helmystack->top] = data;
    }
}

int pop(struct stack *helmystack) {
    if (helmystack->top == -1) {
        printf("Stack EMPTY!!\n");
        return 0;
    } else {
        int result = helmystack->arr[helmystack->top];
        helmystack->top--;
        return result;
    }
}

void print(struct stack *helmystack) {
    int popped;

    while (helmystack->top != -1) {
        popped = pop(helmystack);
        printf("pop: %d\n", popped);
    }
}
