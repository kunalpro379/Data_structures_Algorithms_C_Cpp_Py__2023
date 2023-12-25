//algo--:
//swap a[1]--->a[last]
//root node-> correct position
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void HEAPYFY(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;  // zero-based indexing
    int right = 2 * i + 2; //  zero-based indexing

    if (left < n && arr[largest] < arr[left]) {
        largest = left;
    }
    if (right < n && arr[largest] < arr[right]) {
        largest = right;
    }
    if (largest != i) {
        swap(arr[largest], arr[i]);
        HEAPYFY(arr, n, largest);
    }
}

void HEAPSORT(int arr[], int n) {
    int size = n;
    while (size > 1) {
        swap(arr[size - 1], arr[0]); // zero-based indexing
        size--;
        HEAPYFY(arr, size, 0); //  zero-based indexing
    }
}

int main() {
    int arr[9] = {23, 45, 1, 23, 67, 34, 90, 34, 23};
    int n = 9;

    // Heap creation
    for (int i = n / 2 - 1; i >= 0; i--) { //  zero-based indexing
        HEAPYFY(arr, n, i);
    }

    // Heap sort
    HEAPSORT(arr, n);

    cout << "Printing sorted" << endl;
    for (int i = 0; i < n; i++) { // zero-based indexing
        cout << arr[i] << endl;
    }

    cout << endl;
}
