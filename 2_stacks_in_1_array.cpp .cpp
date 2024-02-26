#include<iostream>
using namespace std;
class stacksin1array{
 public:
 int size;
    int top1;
    int top2;
    int* arrptr;
// stacksin1array(){
//     //default constructor 
    
//   arrptr=NULL;
//   top1=-1;
//   top2=size;

    
// }
stacksin1array(int size){
    arrptr=new int[size];
    this->size=size;
   
    top1=-1;
    top2=size;

}

void ppush1(int data){
if((top2-top1)<=1){
cout<<"stack overflow";}
else{

top1++;
arrptr[top1]=data;
// top1++;
}
}
void ppush2(int data){
    if((top2-top1)<=1){
        cout<<"stack overflown";
    }
    else{        top2--;
        arrptr[top2]=data;
        //  top2--;
    }
}
void pop1(){
if(top1==-1){
cout<<"stack is underflow";
}
else{top1--;}
}
void pop2(){
    if(top2==size){
        cout<<"stack is underflow";
}
else{
    top2++;
}

}
  bool isemptys1() {
        return (top1 == -1 );
    }

    bool isemptys2() {
        return (top2 == size);
    }


     int gettop2() {
        if (top2 == size) {
            cout << endl << "Stack is empty" << endl;
            return -1;  // or throw an exception
        }
        else {
            return arrptr[top2];
        }
    }
     int gettop1() {
        if (top1 == -1) {
            cout << endl << "Stack is empty" << endl;
            return -1;  // or throw an exception
        }
        else {
            return arrptr[top1];
        }
    }


};
int main(){
    cout<<"learning stacks";
    stacksin1array s(10);
s.ppush1(23);
s.ppush1(13);
s.ppush1(13);
s.ppush1(111);
while(!s.isemptys1()){
   cout << s.gettop1() << endl;
        s.pop1();
}
s.ppush2(2342);
s.ppush2(1423);
s.ppush2(143);
s.ppush2(1411);
while(!s.isemptys2()){
   cout << s.gettop2() << endl;
        s.pop2();
}
}