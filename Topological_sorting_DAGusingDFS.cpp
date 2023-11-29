#include <bits/stdc++.h>
#include <algorithm>
#include <stack>
#include <list>
#include <vector>
#include <unordered_map>

using namespace std;

void TopoSort(int node, vector<bool>& visited, stack<int>& Stk, unordered_map<int, list<int>>& adj) {
    visited[node] = true;
    for (auto neighbour : adj[node]) {
        if (!visited[neighbour]) {
            TopoSort(neighbour, visited, Stk, adj);
        }
    }
    Stk.push(node);
}
 
vector<int> topologicalSort(vector<vector<int>>& edges, int v, int e) {
    // Write your code here
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < e; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
    }

    // Call DFS topological sort for all components
    vector<bool> visited(v);
    stack<int> Stk;
    for (int i = 0; i < v; i++) {
        if (!visited[i]) {
            TopoSort(i, visited, Stk, adj);
        }
    }

    vector<int> ans;
    while (!Stk.empty()) {
        ans.push_back(Stk.top());
        Stk.pop();
    }
    return ans;
}
