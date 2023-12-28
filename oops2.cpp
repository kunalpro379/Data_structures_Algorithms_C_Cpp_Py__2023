#include<iostream>
using namespace std;
class Animal{                   //vertual keyword-> object ka fn call hoga
public:
     void speak(){
    cout<<"speaking"<<endl;}
};
class Dog:public Animal{
public:
void speak(){
    cout<<"barking"<<endl;
}
};
int main(){
//cout<<"@@@@@@@@@@@@@@@@@@@@@@";
Dog a;
a.speak();
Animal* b=new Animal();
//b.speak();
b->speak();
Animal* c=new Dog();  //upcasting
c->speak();
//Dog* d=new Animal();   //dowmncasting // error --> vertual keyword
cout<<endl;
Dog* d=(Dog*)new Animal();  // jabardasti typecasting
d->speak();
cout<<endl;
Dog* e=(Dog*)new Dog();
d->speak();
cout<<endl;
Dog* f=new Dog();
d->speak();


}
