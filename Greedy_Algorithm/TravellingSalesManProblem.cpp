#include <iostream>
#include <vector>
#include <climits>
using namespace std;

const int n = 10;
vector<vector<int>> dist = {
    {0, 10, 2, 3, 4, 5, 6, 7, 8, 9},
    {1, 0, 11, 12, 13, 14, 15, 16, 17, 18},
    {2, 11, 0, 21, 22, 23, 24, 25, 26, 27},
    {3, 12, 21, 0, 31, 32, 33, 34, 35, 36},
    {4, 13, 22, 31, 0, 41, 42, 43, 44, 45},
    {5, 14, 23, 32, 41, 0, 51, 52, 53, 54},
    {6, 15, 24, 33, 42, 51, 0, 61, 62, 63},
    {7, 16, 25, 34, 43, 52, 61, 0, 71, 72},
    {8, 17, 26, 35, 44, 53, 62, 71, 0, 81},
    {9, 18, 27, 36, 45, 54, 63, 72, 81, 0}
};

const int MAX = INT_MAX;
vector<int> visited(n, 0);
int m, cost = 0;

void minCostTravel(int C) {
    const int INF = 9999;
    int min = INF;
    int adj_vert = 9999;

    visited[C] = 1;

    // Shortest path
    cout << C + 1 << "->";

    for (int k = 0; k < m; k++) {
        if (dist[C][k] != 0 && visited[k] == 0) {
            if (dist[C][k] < min) {
                min = dist[C][k];
                adj_vert = k;
            }
        }
    }

    if (min != INF) {
        cost = cost + min;
    }

    if (adj_vert == 9999) {
        adj_vert = 0;
        cout << adj_vert + 1 << "->";
        cost = cost + dist[C][adj_vert];
        return;
    }

    minCostTravel(adj_vert);
}

int main() {
    m = n;  

    cout << "Shortest Path: ";
    minCostTravel(0);

    cout << "\nMinimum Cost: " << cost << endl;

    return 0;
}
