#include<stdio.h>
#include<stdlib.h>
struct AQueue
{
int size;
int f;
int r;
int* array;
};
struct AQueue* Queue(int size){
struct AQueue* q = malloc(sizeof(struct AQueue));
q->size =size;
q-> f=q->r= -1;
q->array= malloc(sizeof(int)*size);
}
int isEmpty( struct AQueue* Q){
return (Q->r==-1);
}
int isEmpty(struct AQueue *Q){
if(Q->r==Q->f){
return 1;
}
return 0;
}
int isFull(struct AQueue *q){
if(q->r==q->size-1){
return 1;
}
return 0;
}


void enqueue(struct AQueue *q, int val){
if(isFull(q)){
printf("This Queue is full\n");
}
else{
q->r++;
q->array[q->r] = val;
printf("Enqued element: %d\n", val);
}
}
int dequeue(struct AQueue *q){
int a = -1;
if(isEmpty(q)){
printf("This Queue is empty\n");
}
else{
q->f++;
a = q->array[q->f];
}
return a;
}
int main(){
struct AQueue q;
q.size = 4;
q.f = q.r = 0;
q.array = (int*) malloc(q.size*sizeof(int));
// Enqueue few elements
enqueue(&q, 12);
enqueue(&q, 15);
enqueue(&q, 1);
printf("Dequeuing element %d\n", dequeue(&q));
printf("Dequeuing element %d\n", dequeue(&q));
printf("Dequeuing element %d\n", dequeue(&q));


enqueue(&q, 45);
enqueue(&q, 45);
enqueue(&q, 45);
if(isEmpty(&q)){
printf("Queue is empty\n");
}
if(isFull(&q)){
printf("Queue is full\n");
}
return 0;
}