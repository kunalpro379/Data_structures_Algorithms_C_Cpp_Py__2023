#include<iostream>
using namespace std;

class heap {
public:
    int arr[100];
    int size;

    heap() {
        arr[0] = -1;
        size = 0;
    }

    void insert(int val) {
        size = size + 1;
        int index = size;
        arr[index] = val;
        while (index > 1) {
            int parent = index / 2;
            if (arr[parent] < arr[index]) {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else
                return;
        }
    }

    void print() {
        for (int i = 1; i <= size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    void DelFromHeap(){

if(size==0){
cout<<"Nothing to delete";
return ;
}
arr[1]=arr[size];
size--;
int i=1;
while(i<size){

    int LeftIndex=2*i;
    int RightIndex=2*i+1;
    if(LeftIndex<size&&arr[i]<arr[LeftIndex]){

        swap(arr[i],arr[LeftIndex]);
        i=LeftIndex;
    }
    else if(RightIndex<size&&arr[i]<arr[LeftIndex]){
swap(arr[i],arr[RightIndex]);
i=RightIndex;

    }
    else return;
}

    }
};

int main() {
    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.print();
h.DelFromHeap();
h.print();
    return 0;
}
