#include<iostream>
#include<stack>
using namespace std;

void insert_sorted(stack<int>&s,int insert){
if(s.empty()==true){
s.push(insert);
return;
}
if(s.top()<=insert){
s.push(insert);
return;
}
int topE=s.top();
s.pop();
insert_sorted(s,insert);
s.push(topE);
}
void sort_stack(stack<int>&s,int topE){
if(s.empty()==true){
return;
}
// if(s.top()<=insert){
// s.push(insert);
// return;
topE=s.top();
s.pop();
sort_stack(s,topE);
 insert_sorted(s,topE);

}


int main(){
    cout<<"hello"<<endl;    
    stack<int>s;
    int topE;
s.push(156);
s.push(2);
s.push(36);
s.push(664);
s.push(76);
s.push(22);
// s.push(1);
// s.push(2);
// s.push(3);
// s.push(5);
// s.push(6);
// s.push(22);

    
// insert_sorted(s,4);

while(s.empty()==false){
    cout<<s.top()<<endl;
    s.pop();
}
s.push(156);
s.push(2);
s.push(36);
s.push(664);
s.push(76);
s.push(22);
cout<<"after sorting"<<endl;
sort_stack(s,topE);
while(s.empty()==false){
    cout<<s.top()<<endl;
    s.pop();
}
}


