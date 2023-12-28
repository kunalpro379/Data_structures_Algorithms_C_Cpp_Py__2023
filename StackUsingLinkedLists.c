#include <stdio.h>
#include <stdlib.h>

struct LL {
    int data;
    struct LL* next;
};

struct LL* NewLL(int data) {
    struct LL* newNode = (struct LL*)malloc(sizeof(struct LL));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct stack {
    struct LL* Top;
};

struct stack* newStack() {
    struct stack* STACK = (struct stack*)malloc(sizeof(struct stack));
    STACK->Top = NULL;
    return STACK;
}

int isEmpty(struct stack* STACK) {
    return (STACK->Top == NULL);
}

struct stack* pushdata(struct stack* STACK, int data) {
    struct LL* newNode = NewLL(data);
    
    newNode->data = data;
    newNode->next = STACK->Top;
    STACK->Top = newNode;
    
    return STACK;
}

void PopData(struct stack* STACK) {
    if (isEmpty(STACK)) {
        printf("stack using linked lists is underflown\n");
        return;
    }
    
    struct LL* temp = STACK->Top;
    STACK->Top = STACK->Top->next;
    
    temp->next = NULL;
    free(temp);
}

void DisplayStack(struct stack* STACK) {
    struct LL* temp = STACK->Top;
    printf("Stack Contents:\n");
    
    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

int main() {
    struct stack* STACK = newStack();
    int ch;
    
    printf("What data structures do you want to create using linked lists?\n1) Stack\n2) Queue\n");
    scanf("%d", &ch);
    
    switch (ch) {
        case 1:
            printf("Enter the number of elements you want to insert in the STACK: ");
            int n, data;
            scanf("%d", &n);

            for (int i = 1; i <= n; i++) {
                printf("Enter data for element %d: ", i);
                scanf("%d", &data);
                pushdata(STACK, data);
            }

            DisplayStack(STACK);

            // Free allocated memory
            while (!isEmpty(STACK)) {
                PopData(STACK);
            }
            free(STACK);
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }

    return 0;
}
