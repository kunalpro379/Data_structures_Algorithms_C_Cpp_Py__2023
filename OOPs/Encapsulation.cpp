// Encapsulation = Data Protection + Controlled Access
// Encapsulation means:
// Hide internal data + expose only safe operations through methods.
// So user cannot directly mess with object internals.
#include<iostream>
using namespace std;
class BankAccount{
    private: int balance;
    public: void deposite(int amount){
        if(amount>0)balance+=amount;
    }
    public: int getBalance(){
        return balance;
    }
};
// Access Control = Compiler-Level Protection
/*
| Specifier | Accessible where?      |
| --------- | ---------------------- |
| public    | Everywhere             |
| private   | Only inside class      |
| protected | Inside class + derived |
*/
// obj.balance :- compile error

//Encapsulation is NOT 100% Safe
/*
Pointers can bypass encapsulation.
Pointer Hack
Pointer Hack = Breaking Private Data Using Memory Access
Private is only enforced by compiler.
But in memory:
Private data still exists physically.
So pointer can access it.
*/
class Secret {
private:
    int password = 9999;
};

// Secret s;
// addr -> password = 9999
// int main(){
// Secret s;
// int* ptr = (int*)&s;
// cout << *ptr;
// *ptr = 1234;   
// cout << *ptr;

// }

/*
Object is contiguous memory block

Pointer gives raw access

Compiler privacy doesn’t exist at runtime


s object:

| password |
(int*)&s → points to first integer inside object


*/

class User {
private:
    bool isAdmin = false;
public:
    void showStatus(){
        cout<<"isAdmin="<<isAdmin<<endl;
    }
};
int main(){
    User u;
    cout<<"before hack";
    u.showStatus();
    //take object address
    char* raw=(char *)&u;
//convert first byte into bool pointer
    bool* hack=(bool*) (raw+0);//convert first byte into bool pointer
//overwrite private member    
    *hack =true; 
    cout << "After Hack: ";
    u.showStatus();
    return 0;
}

// User u;

// const keyword
/*
Pointers are powerful because they allow:
Direct memory access
Changing values through address
Passing memory efficiently
Low-level control

But that same power allows dangerous hacks, like:
Modifying data that should not change
Accidentally overwriting memory
Breaking encapsulation
Writing into read-only memory


Pointer to const data
int x = 10;
const int* ptr = &x;
You cannot change x through ptr
But ptr can point somewhere else

*ptr = 20;   Not allowed
ptr = &y;    Allowed

*/