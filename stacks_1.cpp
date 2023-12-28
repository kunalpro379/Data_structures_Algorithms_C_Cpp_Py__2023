#include<iostream>
#include<stack>
using namespace std;

class Stacks {
public:
    int* arrptr;
    int size;
    int top;

    // Default constructor initializer
    Stacks() {
        arrptr = NULL;
        size = 0;
        top = -1;
    }

    Stacks(int size) {
        this->size = size;
        arrptr = new int[size];  // Pointer ki memory allocated
        top = -1;  // Empty
    }

    // Behavior
    void push(int data) {
        if (top + 1 < size) {
            top++;
            arrptr[top] = data;
        }
        else {
            cout << endl << "Stack overflow" << endl;
        }
    }

    void pop() {
        if (top == -1) {
            cout << endl << "Stack is empty" << endl;
        }
        else {
            top--;
        }
    }

    int getsize() {
        return (top + 1);
    }

    int gettop() {
        if (top == -1) {
            cout << endl << "Stack is empty" << endl;
            return -1;  // or throw an exception
        }
        else {
            return arrptr[top];
        }
    }

    bool isempty() {
        if(top == -1){return true;}
        else{return false;}
    }
};

int main() {
    Stacks s(10);
cout<<s.getsize();
    s.push(20);
    s.push(30);
    s.push(40);
cout<<s.getsize();
    cout << endl;
    while (!s.isempty()) {
        cout << s.gettop() << endl;
        s.pop();
    }

    return 0;
}
