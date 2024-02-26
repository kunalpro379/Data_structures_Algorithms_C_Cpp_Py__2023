#include <iostream>

using namespace std;

class stack {
public:
    char* array;
    int size;
    int top;

    stack() {
        array = NULL;
        size = 0;
        top = -1;
    }

    stack(int size) {
        array = new char[size];
        this->size = size;
        this->top = -1;
    }

    void push(char data) {
        if ((top + 1) < size) {
            top++;
            array[top] = data;
        }
        else
            cout << "stack over-flow" << endl;
    }

    void pop() {
        if (top == -1) {
            cout << "stack is empty";
        }
        else
            top--;
    }

    int length() {
        return top + 1;
    }

    char gettop() {
        if (top == -1) {
            cout << "stack is empty" << endl;
            return '\0';
        }
        else
            return array[top];
    }
};

bool solutn(stack s) {
    char ch;
    for (int temp = 0; temp < s.length(); temp++) {
        ch = s.array[temp];
        if (ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);
        }
        else if (ch == '+' || ch == '-' || ch == '/' || ch == '*') {
            s.push(ch);
        }
        else {
            if (s.top == -1) {
                return false;
            }
            char topE = s.gettop();
            if ((topE == '+' || topE == '-' || topE == '/' || topE == '*')) {
                s.pop();
            }
            else {
                if (topE == '(' && ch == ')') {
                    s.pop();
                }
                else if (topE == '{' && ch == '}') {
                    s.pop();
                }
                else if (topE == '[' && ch == ']') {
                    s.pop();
                }
                else {
                    return false;
                }
            }
        }
    }
    return (s.top == -1);
}

int main() {
    char* array = new char[10];
    stack s(10);

    cout << "Enter expression (max 10 characters)" << endl;
    for (int i = 0; i < 10; i++) {
        cin >> array[i];
    }

    if (solutn(s) == true) {
        cout << "Expression is balanced." << endl;
    }
    else if(!solutn(s)){
        cout << "Expression is not balanced." << endl;
    }

    delete[] array;
}

