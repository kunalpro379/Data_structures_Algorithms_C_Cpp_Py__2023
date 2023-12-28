#include <iostream>
using namespace std;

class stacks {
public:
    int* array;
    int* top;
    int size, data, N, n;

    stacks(int size) {
        this->size = size;
        data = 0;
        array = new int[100];
        top = NULL;
    }

    void topij() {
        top = new int[n];
        for (int i = 0; i < n; i++) {
            top[i] = (i * (N / n)) - 1;
        }
    }

    void pushIJ(int i, int data) {
        if (top[i] >= top[i * 2 + 1] || top[i] >= top[i * 2 + 2]) {
            cout << i << " th stack overflow hogaya bhai " << endl;
            return;
        }
        else {
            top[i]++;
            array[top[i]] = data;
        }
    }

    void pushJ(int j, int data) {
        if (top[j] > top[j * 2 + 1] || top[j] > top[j * 2 + 2]) {
            cout << j << " th stack overflow hogaya bhai " << endl;
            return;
        }
        else {
            top[j]++;
            array[top[j]] = data;
        }
    }

    void popi(int i) {
        if (top[i] == (i * (N / n)) - 1) {
            cout << "stack khali hai bhai" << endl;
        }
        else {
            int x = array[top[i]];
            top[i]--;
        }
    }

    void popj(int j) {
        if (top[j] == ((j + 1) * (N / n)) + 1) {
            cout << "stack khali hai bhai" << endl;
        }
        else {
            int x = array[top[j]];
            top[j]--;
        }
    }

    void printsI(int i) {
        if (top[i] == i * (N / n) - 1) {
            cout << "stack is empty";
            return;
        }
        else {
            int start = i * (N / n);
            int end = (i + 1) * (N / n);
            for (int m = top[i]; m >= start; m--) {
                cout << array[m] << " ";
            }
            cout << endl;
        }
    }

    void printsJ(int j) {
        if (top[j] == (j + 1) * (N / n) + 1) {
            cout << "stack is empty";
            return;
        }
        else {
            int start = (j + 1) * (N / n);
            int end = j * (N / n);
            for (int m = top[j]; m >= start; m--) {
                cout << array[m] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int N, n;
    cout << "enter the size of an array";
    cin >> N;
    cout << "enter number of stacks";
    cin >> n;
    cout << "it is possible to make " << n << "stacks using array each having " << N / n << "elements" << endl;

    stacks st(N);
    st.N = N;
    st.n = n;
    st.topij();

    st.pushIJ(1, 234);
    st.pushIJ(1, 24);
    st.pushIJ(2, 26734);
    st.pushIJ(2, 5234);
    st.pushIJ(3, 4);
    st.pushIJ(3, 23);
    st.pushIJ(4, 4);
    

    for (int c = 0; c < n; c++) {
        if (c * 2 + 1 < n) {
            cout << "stack no " << c * 2 + 1 << endl;
            st.printsI(c * 2 + 1);
        }
        if (c * 2 + 2 < n) {
            cout << "stack no " << c * 2 + 2 << endl;
            st.printsI(c * 2 + 2);
        }
    }
    return 0;
}