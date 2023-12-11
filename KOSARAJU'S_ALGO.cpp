#include<iostream>

//for strongly connected components
// aisa node jahase har node thak pahucha ja skta hai
#include <unordered_map>
#include <vector>
#include <list>
#include <stack>

using namespace std;

void Dfs(int node, unordered_map<int, bool>& vis, stack<int>& st, unordered_map<int, list<int>>& adj) {
    vis[node] = true;
    for (auto nbr : adj[node]) {
        if (!vis[nbr]) {
            Dfs(nbr, vis, st, adj);
        }
    }
    st.push(node);
}

void RevDfs(int node, unordered_map<int, bool>& vis, unordered_map<int, list<int>>& adj) {
    vis[node] = true;
    for (auto nbr : adj[node]) {
        if (!vis[nbr]) {
            RevDfs(nbr, vis, adj);
        }
    }
}

int stronglyConnectedComponents(int v, vector<vector<int>>& edges) {
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i][0];
        int w = edges[i][1];
        adj[u].push_back(w);
    }

    stack<int> st;
    unordered_map<int, bool> vis;

    for (int i = 0; i < v; i++) {
        if (!vis[i])
            Dfs(i, vis, st, adj);
    }

    unordered_map<int, list<int>> transpose;
    for (int i = 0; i < v; i++) {
        vis[i] = false;
        for (auto nbr : adj[i]) {
            transpose[nbr].push_back(i);
        }
    }

    int cnt = 0;
    while (!st.empty()) {
        int top = st.top();
        st.pop();
        if (!vis[top]) {
            cnt++;
            RevDfs(top, vis, transpose);
        }
    }
    return cnt;
}
