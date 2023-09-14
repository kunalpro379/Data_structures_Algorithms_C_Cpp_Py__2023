#include <stdio.h>
#include <stdlib.h> // Don't forget to include this for malloc
struct LinkNode {
int data;
struct LinkNode *next;
};
struct LinkNode *head = NULL;
struct LinkNode *tail = NULL;
struct LinkNode *LL(int data) {
struct LinkNode *node = (struct LinkNode *)malloc(sizeof(struct LinkNode));
node->data = data;
node->next = NULL;
return node;
}
struct LinkNode *newNode(int data) {
struct LinkNode *node = LL(data);
if (head == NULL) {
head = node;
tail = node;
} else {
tail->next = node;
tail = node;
}
return node;
}
struct LinkNode *displayLL(struct LinkNode *temp) {
while (temp != NULL) {
printf("%d ", temp->data);
temp = temp->next;
}
}
struct LinkNode *InsertAfterPos(int data, int position) {
struct LinkNode *newNode = LL(data);
struct LinkNode *temp = head;
for (int i = 1; i < position && temp != NULL; i++) {
temp = temp->next;
}
if (temp == NULL) {


return NULL;
}
newNode->next = temp->next;
temp->next = newNode;
}
struct LinkNode *DeleteAfterPos(int position) {
struct LinkNode *temp = head;
for (int i = 1; i < position && temp != NULL; i++) {
temp = temp->next;
}
if (temp == NULL || temp->next == NULL) {
// Position is out of bounds or there's no node after the position
return NULL;
}
struct LinkNode *nodeToDelete = temp->next;
temp->next = nodeToDelete->next;
free(nodeToDelete);
}
void DeleteLinkedList() {
struct LinkNode *current = head;
while (current != NULL) {
struct LinkNode *temp = current;
current = current->next;
free(temp);
}
head = NULL;
tail = NULL;
}
struct LinkNode *Search(int target) {
struct LinkNode *current = head;
while (current != NULL) {
if (current->data == target) {
return current;
}
current = current->next;
}
return NULL;
}
// Sorting the linked list (Example: Bubble Sort)
void SortLinkedList() {
int swapped;


struct LinkNode *ptr1;
struct LinkNode *lptr = NULL;
if (head == NULL)
return;
do {
swapped = 0;
ptr1 = head;
while (ptr1->next != lptr) {
if (ptr1->data > ptr1->next->data) {
// Swap data of adjacent nodes
int temp = ptr1->data;
ptr1->data = ptr1->next->data;
ptr1->next->data = temp;
swapped = 1;
}
ptr1 = ptr1->next;
}
lptr = ptr1;
} while (swapped);
}
int main() {
// Example usage
newNode(5);
newNode(10);
newNode(15);
printf("Original linked list: ");
displayLL(head);
InsertAfterPos(12, 2);
printf("\nLinked list after insertion: ");
displayLL(head);
DeleteAfterPos(3);
printf("\nLinked list after deletion: ");
displayLL(head);
printf("\nSearching for element 10: ");
struct LinkNode *result = Search(10);
if (result)
printf("Found\n");
else


printf("Not Found\n");
printf("\nSorting the linked list: ");
SortLinkedList();
displayLL(head);
DeleteLinkedList();
printf("\nLinked list after deletion: ");
displayLL(head);
return 0;
}