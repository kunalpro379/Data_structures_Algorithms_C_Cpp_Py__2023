#include <stdio.h>
#include <stdlib.h>
struct Stack {
int* array;
int size;
int top;
};
void push(struct Stack* s, int data) {
if ((s->top)-(s->size) <=1 ) {
s->top++;
s->array[s->top] = data;
} else {
printf("Stack is overflow\n");
}
}
void pop(struct Stack* s) {
if (s->top == -1) {
printf("Stack is underflow\n");
} else {
s->top--;
}
}
char gettingtop(struct Stack* s) {
if (s->top == -1) {
return -1;
} else {
return s->array[s->top];
}
}
int getsize(int top){
return top+1;
}
int isempty(struct Stack* s) {
return s->top == -1;
}
int isfull(struct Stack* s) {
return s->top == s->size - 1;
}


struct Stack* newstack(int size) {
struct Stack* s = (struct Stack*)malloc(sizeof(struct Stack));
s->size = size;
s->top = -1;
s->array = (int*)malloc(s->size * sizeof(int));
return s;
}
int printsf(struct Stack* s){while(!isempty(s)){
printf("%d\n",gettingtop(s));
pop(s);
}}
int main() {
struct Stack* s = newstack(100);
push(s,12);
push(s,112);
push(s,82);
push(s,72);
push(s,32);
push(s,12);
printf("hwhat operation u have to perform on stack\n");
printf("1) push operation\n");
printf("2) pop operation\n");
printf("3) getting size of stack\n");
printf("4) getting top element \n");
int last,i,n,element ,p;
scanf("%d",&p);
// Free allocated memory
if(p==1){
printf("enter number of elements u have to insert into the stack");
scanf("%d",&n);
for(int i=0;i<n;i++){
printf("enter elements");
scanf("%d",&element);
push(s,element);
}
printf("u have stored following elements in stack\n\n");
printsf(s);
}
else if (p == 2) {
printf("How many times u have to pop()? ");
scanf("%d", &last);
printf("After pop stack is:\n");
for (int i = 0; i < last && !isempty(s); i++) {
pop(s);
}



printsf(s);
}

else if(p==3){
int top=gettingtop(s);
getsize(top);
}
else if(p==4){
gettingtop(s);
}
free(s->array);
free(s);
return 0;
}