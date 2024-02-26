#include<iostream>
using namespace std;
class Animal{
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
int main(){\
cout<<"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
Dog a;
a.speak();

}