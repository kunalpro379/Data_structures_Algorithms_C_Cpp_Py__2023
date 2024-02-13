#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int spanningTree(int V, vector<vector<int>> adj[]) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> vis(V, 0);
        int sum = 0; // Initialize sum
        pq.push({0, 0}); // {wt, node}

        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int node = it.second;
            int wt = it.first;

            if (vis[node] == 1) continue;

            vis[node] = 1;
            sum += wt;

            for (auto it : adj[node]) {
                int adjNode = it[0];
                int adjWt = it[1];
                if (!vis[adjNode]) {
                    pq.push({adjWt, adjNode});
                }
            }
        }
        return sum;
    }
};

int main() {
    int V = 5; 

    vector<vector<int>> adj[V];

    adj[0].push_back({1, 2}); // Edge from node 0 to node 1 with weight 2
    adj[0].push_back({3, 6}); // Edge from node 0 to node 3 with weight 6
    adj[1].push_back({2, 3}); // Edge from node 1 to node 2 with weight 3
    adj[1].push_back({3, 8}); // Edge from node 1 to node 3 with weight 8
    adj[1].push_back({4, 5}); // Edge from node 1 to node 4 with weight 5
    adj[2].push_back({4, 7}); // Edge from node 2 to node 4 with weight 7

    Solution sol;
    int sum = sol.spanningTree(V, adj);

    cout << "Sum of weights of the minimum spanning tree: " << sum << endl;

    return 0;
}
