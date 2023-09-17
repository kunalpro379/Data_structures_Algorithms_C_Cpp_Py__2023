#include <stdio.h>
#include <stdlib.h>

struct LL {
    int data;
    struct LL* next;
};

struct Queue {
    struct LL* Front;
    struct LL* Rear;
};

struct Queue* newQueue() {
    struct Queue* newQue = (struct Queue*)malloc(sizeof(struct Queue));
    newQue->Front = newQue->Rear = NULL;
    return newQue;
}

int isEmptyQ(struct Queue* newQue) {
    return (newQue->Front == NULL);
}

struct Queue* EnQueue(struct Queue* que, int data) {
    struct LL* newNode = (struct LL*)malloc(sizeof(struct LL));
    newNode->data = data;
    newNode->next = NULL;

    if (isEmptyQ(que)) {
        que->Front = que->Rear = newNode;
    } else {
        que->Rear->next = newNode;
        que->Rear = newNode;
    }

    return que;
}

void DeQueue(struct Queue* que) {
    if (isEmptyQ(que)) {
        printf("Queue is empty.\n");
        return;
    }

    struct LL* temp = que->Front;
    que->Front = que->Front->next;

    free(temp);
}

void DisplayQueue(struct Queue* que) {
    struct LL* temp = que->Front;

    printf("Queue Contents:\n");
    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

int main() {
    struct Queue* que = newQueue();

    que = EnQueue(que, 2322);
    que = EnQueue(que, 878);
    que = EnQueue(que, 90);
    que = EnQueue(que, 34);

    DisplayQueue(que);

    DeQueue(que);
    DeQueue(que);

    DisplayQueue(que);

    // Free allocated memory
    while (!isEmptyQ(que)) {
        DeQueue(que);
    }
    free(que);

    return 0;
}
