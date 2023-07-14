#include<iostream>
using namespace std;
class Node {
private:
    int data;

public:
    Node* next;
    Node* prev;
    Node* temp;
    Node() {
        this->data = 0;
        this->next = NULL;
        this->prev = NULL;
    }

    Node(int data) {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }

    void setNode(int data) {
        this->data = data;
    }

    int getNode() const {
        return data;
    }

};
void print(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->getNode() << " ";
        temp = temp->next;
    }
    cout << endl;
}

void insertAtHead(Node*& head, Node*& tail, int data) {
    if (head == NULL) {
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }
    else {
        Node* newNode = new Node(data);
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
void LLl(){
    Node* temp;
  while(temp!=NULL){
    int l=1;
    temp=head;
    temp=head->next;
    l=l+1;
  }  
}
void insertatpos(Node* head, Node*tail, int data,int pos);{
if(head==NULL){
    Node* newnode=new Node(data);
    head=newnode;
    tail=newnode;
}
else{
    if(int pos=0){

    }
    else {
 Node* newnode=new Node(data);

    }
    
    

    }
}}
int main() {
    int New = 1;
    Node* a = new Node(New);
    a->setNode(20);
    New = a->getNode();
    New++;

    Node* b = new Node(New);
    b->setNode(30);
    New = b->getNode();
    New++;

    Node* c = new Node(New);
    c->setNode(40);

    a->next = b;
    b->prev = a;
    b->next = c;
    c->prev = b;
    c->next = NULL;
LLl();
    print(a); // Print the linked list

    insertAtHead(a, c, 12);
   print(a); // Print the updated linked list

   
}
