#include <iostream>
#include <vector>

using namespace std;

int maxInd(int* dist, int n) {
    int mInd = 0;
    for (int i = 1; i < n; i++) {
        if (dist[i] > dist[mInd])
            mInd = i;
    }
    return mInd;
}


void SelectKCities(int n, int weights[4][4], int k) {
    vector<int> centers;
    int* dist = new int[n];

    // Initialize distances to 0
    for (int i = 0; i < n; i++) {
        dist[i] = 0;
    }

int MInd = 0;
for (int i = 0; i < k; i++) {
    centers.push_back(MInd);

    for (int j = 0; j < n; j++) {
        dist[j] = min(dist[j], weights[MInd][j]);
    }

    MInd = maxInd(dist, n);
}


    cout << "The selected cities are: ";
    for (int i = 0; i < k; i++) {
        cout << centers[i] << " ";
    }

    cout << endl << "The maximum distance is: " << dist[MInd] << endl;

    // Cleanup dynamic memory
    delete[] dist;
}

int main() {
    int n = 4;
    int weights[4][4] = { { 4430, 4, 8, 5 },
                          { 4, 60, 10, 67 },
                          { 86, 610, 906, 9 },
                          { 5, 7, 9, 60 } };
    int k = 2;

    // Function Call
    SelectKCities(n, weights, k);

    return 0;
}
