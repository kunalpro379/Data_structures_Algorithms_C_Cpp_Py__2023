#include<iostream>
using namespace std;
class Node{
    public:
    int data;

//Node* temp;
Node* prev;
Node* next;
//Node* 
Node(){
    //constructor  this pointer not necessery  its good practise
  this->  next=NULL;
   this->  prev=NULL;
   this->  data=0;
}
//node creation
Node(int data){
    this->data=data;
    this->next=NULL;
    this->prev=NULL;
}
};
void insertathead(Node* &head, Node* &tail, int data){
//EMPTY LL
Node* newNode=new Node(data);
//newnode creation which has to be inserted 
if(head==NULL && tail==NULL){

head=newNode;
tail=newNode;
//return newNode;
}
else{

newNode->next=head;
head->prev=newNode;
head=newNode;


}}

int len(Node* &head){
Node* temp=head;
int len=0;
while(temp!=NULL){
    temp=temp->next;
len++;
}
return len;
}
void print(Node* &head){
Node* temp=head;

while(temp!=NULL){
  
   cout<<temp->data<<" ";
    temp= temp->next;
}

}
void insertattail(Node* & head, Node* &tail, int data){
//empty LL
int p;
if(head==NULL){Node* newNode1=new Node(data);
    head=newNode1;
    tail=newNode1;
}
else{Node* newNode1=new Node(data);
    tail->next=newNode1;
    newNode1->prev=tail;
    tail=newNode1;
}
}
void insertatpos(Node* &head, Node* &tail, int data, int posn) {
    if (head == NULL) {
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }

    if (posn == 1) {
        insertathead(head, tail, data);
        return;
    }

    int p = len(head);
    if (p < posn) {
        insertattail(head, tail, data);
        return;
    }

    Node* newNode = new Node(data);
    Node* currnod = head;
    int i = 1;
    while (i < posn) {
        currnod = currnod->next;
        i++;
    }
    Node* prevnode = currnod->prev;
    prevnode->next = newNode;
    newNode->prev = prevnode;
    newNode->next = currnod;
    currnod->prev = newNode;
}
void deletefromposn(Node* &head, Node* &tail,int posn){
    if(head==NULL){
        //LL is empty
        cout<<"Error_404 xd";
        return;
    }
  if(head->next==NULL){
Node* temp=head;
head=NULL;
tail=NULL;
delete temp;
return;
  }
  if(posn==1){
Node* temp=head;
head=head->next;
temp->next=NULL;
delete temp;
return;
}
int p=len(head);
if(p<posn){
cout<<"Error_404";
}
if(p==posn){
Node* temp=tail;
tail=tail->prev;
tail->next=NULL;
temp->prev=NULL;
delete temp;
return;
}
if(1<posn && posn <p){
     Node* currnod = head;
    int i = 1;
    while (i < posn) {
        currnod = currnod->next;
        i++;
    }
Node* prevnod=currnod->prev;
Node* nextnod=currnod->next;
prevnod->next=prevnod->next->next;
nextnod->prev=nextnod->prev->prev;
currnod->next=NULL;
currnod->prev=NULL;
return;
}
}




int main() {
    Node* head = NULL;
    Node* tail = NULL;

    Node* node1 = new Node(10);
    Node* node2 = new Node(20);
    Node* node3 = new Node(20);
    Node* node4 = new Node(20);

    node1->next = node2;
    node2->prev = node1;
    node2->next = node3;
    node3->prev = node2;
    node3->next = node4;
    node4->prev = node3;
    node4->next = NULL;
    node1->prev = NULL;
//tail=node4;
    print(node1);
    cout << endl;
    cout << endl;
    int p = len(node1);
    cout << p << endl;

    insertathead(node1, tail, 9);
     insertathead(node1, tail, 845);
      insertathead(node1, tail, 9586);
       insertathead(node1, tail, 94895);
    print(node1);
    cout << endl;
  
  insertattail(node1, node4, 499);
    insertattail(node1, node4, 9453);
    insertattail(node1, node4, 929);

    print(node1);
  
    cout << p << endl;

    insertatpos(node1,node4, 454, 64);
    print(node1);
   
    cout << p <<endl;
    deletefromposn(node1,node4,3);
    deletefromposn(node1,node4,3);
    deletefromposn(node1,node4,3);
    deletefromposn(node1,node4,3);
    deletefromposn(node1,node4,3);
    deletefromposn(node1,node4,3);
    deletefromposn(node1,node4,3);
    deletefromposn(node1,node4,3);
    deletefromposn(node1,node4,3);
    deletefromposn(node1,node4,3);
    deletefromposn(node1,node4,1);
    deletefromposn(node1,node4,3);
    deletefromposn(node1,node4,2);
    deletefromposn(node1,node4,1);
    deletefromposn(node1,node4,2);
    cout<<endl;
print(node1);
   cout<<endl;
    cout << p <<endl;
}