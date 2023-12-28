#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main() {
    FILE* Fptr;

    // Opening file in reading mode 
    Fptr = fopen("notes.jpg", "r");

    if (Fptr == NULL) {
        cout << "File is not opened\n";
        exit(0);
    }

    return 0;
}
