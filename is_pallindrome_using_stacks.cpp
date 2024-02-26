#include <iostream>

using namespace std;

class Stacks {
public:
    char* arrptr;
    int size;
    int top;
int temp;
int mid;
    public:
    // Default constructor initializer
    Stacks() {
        arrptr = NULL;
        size = 0;
        top = -1;
                 
 
        
    }

    Stacks(int size) {
        this->size = size;
        arrptr = new char[size];  // Pointer ki memory allocated
        top = -1;  // Empty
       /// temp=arrptr[size];
    }

    // Behavior
    void push(char data) {
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
            // or throw an exception
        }
        else {
            return arrptr[top];
        }
    }

    bool isempty() {
        if(top == -1) {
            return true;
        }
        else {
            return false;
        }
    }
  
        
    
    
    int ispallindrome(){
        
        Stacks s2(mid);  // Create a second stack

        // Push the first half of the elements from the original stack to the second stack
        for (int i = 0; i < mid; i++) {
            s2.push(arrptr[i]);
        }

        // Compare the remaining elements in the original stack with the popped elements from the second stack
        for (int i = mid; i < size; i++) {
            if (arrptr[i] != s2.gettop()) {
                return 0;  // If elements don't match, it's not a palindrome
            }
            s2.pop();  // Pop the top element from the second stack
        }

        return 1;
        }
        
      
    
};

int main() {
    int size;
    cout << "Enter the number of elements: ";
    cin >> size;
int mid=size/2;
    Stacks s(size);
    cout << "Enter stack elements:" << endl;
    for (int i = 0; i < size; i++) {
        char element;
       // cout << "Element " << i + 1 << ": ";
        cin >> element;
        s.push(element);
    }

    cout << endl << "Stack string :" << endl;
   
    // char p=s.gettop();
    //cout<<p;
    // while (!s.isempty()) {
    //     char p = s.gettop();
    //     cout << p << endl;
    //     s.pop();
    // }
    // if((size%2)==0{
        int c=s.ispallindrome();
    // }
    //  if ((size%2==0)){
         c=s.ispallindrome();
    //  }
    //  else{
    //      mid=mid+1;
    //      c=s.ispallindrome();
    //  }
//int c=ispallindrome();
if (c==0){
    cout<<"string isnt pallindrome";
}
if(c==1){
    cout<<"string is a pallindrome";
}

    // int p = s.getsize();
    // cout << "Stack size: " << p << endl;
}