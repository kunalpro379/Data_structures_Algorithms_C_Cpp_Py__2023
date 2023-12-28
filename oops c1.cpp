#include<iostream>
using namespace std;
class Animal{
private:
int Weight;  
   
//empty class ki memory is 1
int age1; //4
//ek integer ke case me memory 4
public:
char ch;   
//1

//4
//aab 12 memory how??? 9 chahhiye naa
//  HW --->  PADDING AND GREEDY ALIGNMENT 
//state orm properties

int Age;
string name;
int vergin;
//behavior 
void eat(){
cout<<"kunal likes sweat food";
}
void sleep(){

}
//how to access private memebers    using getter and setter functiomns
int getWeight(){
    return Weight;

}
int setWeight(int Weight){
//Weight =Weight;
this->Weight=Weight;

}
int setAge(int Age){
this->Age=Age;
}
int getAge(){
    return Age;
}
//default constructor 
//object creation 
//no return type
//name same as class //initialize karna object ko
Animal(){
    cout<<"constructor called";
    this->Weight=0;     //use of this is good practice 
    this->Age=0;     //values ki initialization   // by default
    this-> name =" no name ";
}
//parameterized constructor
Animal(int x){
    cout<<"parameterized constructor called";
    this->Weight=10;     //use of this is good practice 
    this->Age=056;     //values ki initialization   // by default
    this-> name =" hey ";
}
//copy constructor 
Animal (Animal &abc){
 this ->Age=abc.Age;
this->Weight=abc.Age;
cout<<"copy constructor called";
}

//destructor 
//~tilda
~Animal (){
    cout <<"memory is deallocated destructor is called ";

}
void print(){
   
cout<<endl<<this->Age<<endl<<Weight<<endl;

}
};

int main()
{
    Animal m,n;
    m.setWeight(100);
    n.setWeight(200);
    m.setAge(10);
    n.setAge(20);
    
m.print();
n.print();
// cout<<endl;
// cout<<"size of animal"<<endl<<sizeof(Animal)<<endl;

//  //objext creation 

// //static
// Animal kunal;
// //animal type ka object jiska naam hai kunal
// //object ki roperties ka access
// //kunal ki age ka access    dot property

// //access modifiers 
// //1) private inside class access not outside (bydefault state)
// //2) public  inside or outside access 
// //3)protected 
// cout<<"age of kunal"<<endl<<kunal.age;
// cout<<endl;
// //cin>>kunal.name;
// //cout<<endl<<"name of kaunal"<<endl<<kunal.name;

// kunal.setWeight(74);
// cout<<endl<<"weight of kunal"<<kunal.getWeight();
// //dynamic memory allocatiotn
// cout<<endl;
// Animal* xyz=new Animal;
//  cout<<endl;
//  xyz->vergin=1;
//  cout<<endl;
// cout<<xyz->vergin;
// cout<<endl;

// Animal someone(100);
// cout<<endl;
// Animal* kutra = new Animal(19829);
// //cout<<Animal(19829)->Weight;
// Animal c(*kutra);
// cout<<endl;
// Animal d= someone;
// cout<<endl;
// Animal f(*xyz);

// cout<<endl;
// cout<<endl;
// cout<<"farzi object creation";
// Animal farzi;
// farzi.age=19;
// cout<<endl;
// cout<<"fantu object creation";
// cout<<endl;
// Animal * fantu=new Animal;
// fantu->age=1292;
// //destructor not called 
// //so for manually calling destrutor
// delete(fantu);
//Animal n;
m=n;
m.print();
n.print();

}