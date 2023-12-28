#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Stack {
char* string;
int size;
int top;
};
void push(struct Stack* s, char data) {
if (s->top < s->size - 1) {
s->top++;
s->string[s->top] = data;
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
return -1; // It's better to use a different sentinel value, as -1 could be a valid

} else {
return s->string[s->top];
}
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
s->string = (char*)malloc(s->size * sizeof(char));
return s;
}
char op[10] = {'*', '^', '(', ')', '+', '-'};
int precedence(char op) {
switch (op) {
case '(': case ')':
return 4;
case '*': case '/': case '%':
return 3;
case '+': case '-':
return 2;
default:
return 0;
}
}
void InfToPostf(char* exp, struct Stack* s, char* st) {
int j = 0;
for (int i = 0; i < strlen(exp); i++) {
int oppresent = 0;
for (int k = 0; k < strlen(op); k++) {
if (exp[i] == op[k]) {
oppresent = 1;
break;
}
}
if (oppresent) {
while (!isempty(s) && precedence(gettingtop(s)) >= precedence(exp[i])) {
st[j++] = gettingtop(s);
pop(s);
}
push(s, exp[i]);
} else if (exp[i] == '(') {
push(s, exp[i]);
} else if (exp[i] == ')') {
while (!isempty(s) && gettingtop(s) != '(') {
st[j++] = gettingtop(s);
pop(s);
}
pop(s); // Pop the '(' from the stack.
} else {


st[j++] = exp[i];
}
}
while (!isempty(s)) {
st[j++] = gettingtop(s);
pop(s);
}
st[j] = '\0';
}
void PostfixEvaluation(char* exp, struct Stack* s, char* st1) {
for (int i =0; i<strlen(exp); i++) {
if (exp[i] == ' ') {
continue; // Skip spaces
}
int isop = 0;
for (int k = 0; k < strlen(op); k++) {
if (exp[i] == op[k]) {
isop = 1;
break;
}
}
if (isop == 1) {
char operand1 = gettingtop(s);
pop(s);
char operand2 = gettingtop(s);
pop(s);
char result;
switch (exp[i]) {
case '*':
result = operand1 * operand2;
break;
case '/':
result = operand1 / operand2;
break;
case '-':
result = operand1 - operand2;
break;
case '+':
result = operand1 + operand2;
break;
}
push(s, result);
} else {
push(s, exp[i] - '0'); // Convert character to integer
}
}
}
void PrefixEvaluation(char* exp, struct Stack* s, char* st1) {


for (int i = strlen(exp) - 1; i >= 0; i--) {
if (exp[i] == ' ') {
continue; // Skip spaces
}
int isop = 0;
for (int k = 0; k < strlen(op); k++) {
if (exp[i] == op[k]) {
isop = 1;
break;
}
}
if (isop == 1) {
char operand1 = gettingtop(s);
pop(s);
char operand2 = gettingtop(s);
pop(s);
char result;
switch (exp[i]) {
case '*':
result = operand1 * operand2;
break;
case '/':
result = operand1 / operand2;
break;
case '-':
result = operand1 - operand2;
break;
case '+':
result = operand1 + operand2;
break;
}
push(s, result);
} else {
push(s, exp[i] - '0'); // Convert character to integer
}
}
}
void InfToPrefixf(char* exp, struct Stack* s, char* st1) {
int j = 0; // Index for st1 array
for (int i = strlen(exp) - 1; i >= 0; i--) {
int isop = 0;
for (int k = 0; k < strlen(op); k++) {
if (exp[i] == op[k]) {
isop = 1;
break;
}
}


if (isop == 1) {
while (!isempty(s) && precedence(exp[i]) >= precedence(gettingtop(s))) {
st1[j++] = gettingtop(s);
pop(s);
}
push(s, exp[i]);
} else if (exp[i] == ')') {
push(s, exp[i]);
} else if (exp[i] == '(') {
while (!isempty(s) && gettingtop(s) != ')') {
st1[j++] = gettingtop(s);
pop(s);
}
pop(s); // Pop the '(' from the stack.
} else {
st1[j++] = exp[i];
}
}
while (!isempty(s)) {
st1[j++] = gettingtop(s);
pop(s);
}
// Reverse the st1 array to get the correct prefix expression
for (int i = 0; i < j / 2; i++) {
char temp = st1[i];
st1[i] = st1[j - i - 1];
st1[j - i - 1] = temp;
}
st1[j] = '\0'; // Add null terminator to the end of the expression
}

int main() {
struct Stack* s = newstack(100);
char* exp = (char*)malloc(100 * sizeof(char));
char* st1 = (char*)malloc(100 * sizeof(char));
printf("Choose what you want:\n");
printf("1: Infix to postfix conversion\n");
printf("2: Infix to prefix\n");
printf("3: Prefix evaluation\n");
printf("4: Postfix evaluation\n");


int t;
scanf("%d", &t);
printf("Enter the expression: ");
scanf("%s", exp);
switch (t) {
case 1:
InfToPostf(exp, s, st1);
printf("Postfix expression: %s\n", st1);
break;
case 2:
InfToPrefixf(exp, s, st1);
printf("Prefix expression: %s\n", st1);
break;
case 3:
PrefixEvaluation(exp, s, st1);
printf("Prefix evaluation: %s\n", st1);
break;
case 4:
PostfixEvaluation(exp, s, st1);
printf("Postfix evaluation: %s\n", st1);
break;
default:
printf("Invalid choice\n");
break;
}
free(s->string);
free(s);
free(exp);
free(st1);
return 0;
}