#include <stdio.h>
#include <stdlib.h>
struct CirLL {
int data;
struct CirLL* next;
};
struct CirLL* NewCirLL(int data) {
struct CirLL* newNode = (struct CirLL*)malloc(sizeof(struct CirLL));
newNode->data = data;
newNode->next = NULL;
return newNode;
}
struct CirLL* InsertAtStart(struct CirLL* tail, int data) {
struct CirLL* newNode = NewCirLL(data);
if (tail == NULL) {
newNode->next = newNode; // pointing to itself
tail = newNode;
} else {
newNode->next = tail->next;
tail->next = newNode;
}
return tail;
}
struct CirLL* InsertAtEnd(struct CirLL* tail, int data) {
struct CirLL* newNode = NewCirLL(data);
if (tail == NULL) {
newNode->next = newNode;
tail = newNode;
} else {
newNode->next = tail->next;
tail->next = newNode;
tail = newNode;
}
return tail;
}
struct CirLL* InsertAfterPos(struct CirLL* tail, int data, int insdata) {
if (tail == NULL) {
printf("Circular Linked List is empty\n");
return NULL;
}
struct CirLL* temp = tail->next;
do {



if (temp->data == insdata) {
struct CirLL* newNode = NewCirLL(data);
newNode->next = temp->next;
temp->next = newNode;
if (temp == tail) {
tail = newNode;
}
return tail;
}
temp = temp->next;
} while (temp != tail);
printf("Value %d not found in the list.\n", insdata);
return tail;
}
struct CirLL* InsertBeforePos(struct CirLL* tail, int data, int pos) {
if (tail == NULL) {
printf("Circular Linked List is empty!\n");
return NULL;
}
struct CirLL* head = tail->next;
struct CirLL* current = head;
struct CirLL* prev = NULL;
int count = 0;
while (count < pos && current != tail) {
prev = current;
current = current->next;
count++;
}
if (count < pos) {
printf("Position %d is out of bounds.\n", pos);
return tail;
}
struct CirLL* newNode = NewCirLL(data);
newNode->next = current;
if (prev == NULL) {
tail->next = newNode;
} else {
prev->next = newNode;
}
return tail;
}


int countingNodes(struct CirLL* tail) {
if (tail == NULL) {
return 0;
}
int count = 1;
struct CirLL* current = tail->next;
while (current != tail) {
count++;
current = current->next;
}
return count;
}
struct CirLL* DeleteCompleteNode(struct CirLL* tail, int data) {
if (tail == NULL) {
printf("Circular Linked List is empty!\n");
return NULL;
}
struct CirLL* head = tail->next;
struct CirLL* current = head;
struct CirLL* prev = tail;
while (current != tail) {
if (current->data == data) {
prev->next = current->next;
free(current);
current = prev->next;
} else {
prev = current;
current = current->next;
}
}
if (tail->data == data) {
prev->next = head;
free(tail);
return head;
}
return tail;
}
int SearchingforVal(struct CirLL* tail, int target) {
if (tail == NULL) {
printf("Circular Linked List is empty!\n");
return -1;
}

struct CirLL* head = tail->next;
struct CirLL* current = head;
int position = 0;
do {
if (current->data == target) {
printf("Value %d found at position %d.\n", target, position);
return position;
}
current = current->next;
position++;
} while (current != head);
printf("Value %d not found in the list.\n", target);
return -1;
}
struct CirLL* DeleteParticular_Ith_Node(struct CirLL* tail, int data, int pos) {
if (tail == NULL) {
printf("Circular Linked List is empty!\n");
return NULL;
}
struct CirLL* head = tail->next;
struct CirLL* current = head;
struct CirLL* prev = tail;
int count = 0;
while (count < pos && current != tail) {
prev = current;
current = current->next;
count++;
}
if (count < pos) {
printf("Position %d is out of bounds.\n", pos);
}
if (current->data == data) {
prev->next = current->next;
if (current == tail) {
tail = prev;
}
free(current);
} else {
printf("Node at position %d doesn't contain data %d.\n", pos, data);
}

return tail;
}
void DisplayList(struct CirLL* tail) {
if (tail == NULL) {
printf("Circular Linked List is empty!\n");
return;
}
struct CirLL* head = tail->next;
struct CirLL* current = head;
printf("Circular Linked List: ");
do {
printf("%d ", current->data);
current = current->next;
} while (current != head);
printf("\n");
}
int main() {
struct CirLL* head = NULL;
// Menu for operations
int choice;
int data, insertData, insdata, pos;
while (1) {
printf("\nChoose an operation:\n");
printf("1) Insert at the start\n");
printf("2) Insert at the end\n");
printf("3) Insert after a specific value\n");
printf("4) Insert before a specific position\n");
printf("5) Delete a specific value\n");
printf("6) Delete a specific node at a position\n");
printf("7) Delete the whole linked list\n");
printf("8) Search for a value and return its position\n");
printf("0) Exit\n");
scanf("%d", &choice);
switch (choice) {
case 1:
printf("Enter data to insert at the start: ");
scanf("%d", &data);
head = InsertAtStart(head, data);
break;
case 2:


printf("Enter data to insert at the end: ");
scanf("%d", &data);
head = InsertAtEnd(head, data);
break;
case 3:
printf("Enter data to insert: ");
scanf("%d", &data);
printf("Enter value after which to insert: ");
scanf("%d", &insdata);
head = InsertAfterPos(head, data, insdata);
break;
case 4:
printf("Enter data to insert: ");
scanf("%d", &data);
printf("Enter position before which to insert: ");
scanf("%d", &pos);
head = InsertBeforePos(head, data, pos);
break;
case 5:
printf("Enter value to delete: ");
scanf("%d", &data);
head = DeleteCompleteNode(head, data);
break;
case 6:
printf("Enter position of node to delete: ");
scanf("%d", &pos);
head = DeleteParticular_Ith_Node(head, data, pos);
break;
case 7:
while (head != NULL) {
head = DeleteCompleteNode(head, head->data);
}
break;
case 8:
printf("Enter value to search for: ");
scanf("%d", &data);
SearchingforVal(head, data);
break;
case 9:
printf("printing a lists.\n");
DisplayList(head);
break;
default:
printf("Invalid choice! Please enter a valid option.\n");
}
}
return 0;
}