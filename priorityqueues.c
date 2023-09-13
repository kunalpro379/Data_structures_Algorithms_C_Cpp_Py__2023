#include <stdio.h>
#include <stdlib.h>
#include <limits.h> // For INT_MIN

#define MAX 100

struct PriorQ {
    int data;
    int priority;
    int order;
};

int pos = -1;
struct PriorQ arrdata[MAX];

void Enq(int data, int priority, int order) {
    if (pos < MAX - 1) {
        pos++;
        arrdata[pos].data = data;
        arrdata[pos].priority = priority;
        arrdata[pos].order = order;
    } else {
        printf("Queue is full. Cannot enqueue.\n");
    }
}

int pee() {
    int highprior = INT_MIN;
    int poop = -1;

    for (int i = 0; i <= pos; i++) {
        if ((highprior == arrdata[poop].priority) && (arrdata[poop].data < arrdata[i].data)) {
            highprior = arrdata[i].priority;
            poop = i;
        } else if (highprior < arrdata[i].priority) {
            highprior = arrdata[i].priority;
            poop = i;
        }
    }

    return poop;
}

void Dq() {
    if (pos == -1) {
        printf("Queue is empty. Cannot dequeue.\n");
        return;
    }

    int poop = pee();

    for (int j = poop; j < pos; j++) {
        arrdata[j] = arrdata[j + 1];
    }

    pos--;
}

int main() {
    Enq(12, 4, 3);
    Enq(12, 3, 2);
    Enq(12, 1, 1);
    Enq(12, 2, 4);

    Dq();

    for (int i = 0; i <= pos; i++) {
        printf("Data: %d Priority: %d Order: %d\n", arrdata[i].data, arrdata[i].priority, arrdata[i].order);
    }

return 0;
}