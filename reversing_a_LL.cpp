#include<iostream>
using namespace std;
class Node{
    public:

int data;
Node* next;
Node* head;
Node* tail;
Node* prev;

Node(){
    // initializing node
    Node* head=NULL;
    Node* tail=NULL;
    int data=0;
    Node* next=NULL;
}
Node(int data){
  this->data=data;
  this->head=NULL;
  
 
}
};


void insertathead(Node* &head,  int data){
//EMPTY LL
Node* newNode=new Node(data);
//newnode creation which has to be inserted 
if(head==NULL ){

head=newNode;
//tail=newNode;
//return newNode;
}
else{

newNode->next=head;

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

//my mistake
// void print(Node* &head){
// Node* temp=head;

// while(temp!=NULL){
  
//    cout<<temp->data<<" ";
//     temp= temp->next;
//     break;
// }//my mistake
void print(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
/*
//REVERSING A LINKED LISTS
Node* revLL(Node* &head){
//base case
Node* prevnode=NULL;
Node* currnode=head;
Node* prevnode=NULL;
if(currnode==NULL){ // //node khatam, hogayi be 
return prevnode;
}
else{
Node* next=currnode->next;
Node*prevnode=NULL;
//Node* head;
//head->next=prevnode;
currnode->next=prevnode;
currnode=currnode->next;

return revLL(head);

}
*/

Node* revLL( Node* &prevnode,Node* &currnode)
 {
    //Node* currnode=head;
 //Node* prevnode = NULL;
    if (currnode == NULL) {
        return prevnode;
    }

    Node* nextnode = currnode->next;
    currnode->next = prevnode;
    return revLL( prevnode, currnode);
}


void insertattail( Node*&head,Node* &tail, int data){
//empty LL
Node* newNode=new Node(data);
if(head==NULL &&tail==NULL){
    head=newNode;
    tail=newNode;
}
else{
    tail->next=newNode;
    //newNode1->prev=tail;
    tail=newNode;
    return;
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
        insertathead(head,  data);
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
  //  Node* prevnode = currnod->prev;
    
    //newNode->prev = prevnode;
    newNode->next = currnod->next;
    currnod->next = newNode;
   // currnod->prev = newNode;
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
   // Node* prevn =NULL;
Node* temp=tail;
tail=tail->prev;
tail->next=NULL;
temp->next=NULL;
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
//Node* prevnod=currnod->prev;
Node* nextnod=currnod->next;
//prevnod->next=prevnod->next->next;
currnod->prev=currnod->next;
currnod->next=NULL;
//currnod->prev=NULL;
return;
}
}



Node* reversingloop(Node* head){
Node* prev=NULL;
Node* currnode=head;

while(currnode!=NULL){
    Node* nexnode=currnode->next;
  currnode->next=prev;
prev=currnode;
currnode=nexnode;
 //nexnode=nexnode->next;
    //nxtnode=currnode->next;
//currnode->nxtnode=prev;
}
return prev;
}

int main(){
    Node* head=NULL;
    Node* tail=NULL;
Node* n1=new Node(120);
Node* n2=new Node(12);
Node* n3=new Node(12);
Node* n4=new Node(12);
Node* n5=new Node(12);
n1->next=n2;
n2->next=n3;
n3->next=n4;
n4->next=n5;
n5->next=NULL;
print(n1);
Node* prevnode=NULL;
Node*currnode=head;
 int p=len(n1);
 cout<<p;
 deletefromposn(n1,n5,3);
  print(n1);
 Node* reversingloop(head);
 print(n1);
revLL(prevnode,currnode);
 print(n1);
cout<<endl;
insertathead(n1,46);
print(n1);
insertattail(n1,n5,4);
print(n1);
insertatpos(n1,n5,36738,3);
print(n1);
return 0;

}