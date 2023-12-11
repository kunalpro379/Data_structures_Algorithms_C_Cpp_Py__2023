#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
using namespace std;

int min(int a, int b) {
    if (a > b)
        return b;
    return a;
}

void Dfs(int node, int parent, vector<int>& disc, vector<int>& low, unordered_map<int, bool>& vis, unordered_map<int, list<int>>& adj, vector<int>& ap, int& timer) {
    vis[node] = true;
    disc[node] = low[node] = timer++;
    int child = 0;

    for (auto nbr : adj[node]) {
        if (nbr == parent)
            continue;

        if (!vis[nbr]) {
            Dfs(nbr, node, disc, low, vis, adj, ap, timer);
            low[node] = min(low[node], low[nbr]);

            // Check for articulation point
            if (low[nbr] >= disc[node] &&parent !=-1) {
                ap[node] = 1;
            }
            child++;
        } else {
            low[node] = min(low[node], disc[nbr]);
        }
    }

    if (parent == -1 && child > 1) {
        ap[node] = 1;
    }
}

int main() {
    int n = 6;
    int e = 7;

    vector<pair<int, int>> edges;
    edges.push_back(make_pair(1, 4));
    edges.push_back(make_pair(1, 2));
    edges.push_back(make_pair(4, 3));
    edges.push_back(make_pair(2, 3));
    edges.push_back(make_pair(3, 5));
    edges.push_back(make_pair(3, 6));
    edges.push_back(make_pair(5, 6));

    // Adjacency list
    unordered_map<int, list<int>> adj;

    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i].first;
        int v = edges[i].second;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int timer = 0;
    vector<int> disc(n);
    vector<int> low(n);
    unordered_map<int, bool> vis;
    vector<int> ap(n, 0);

    for (int i = 0; i < n; i++) {
        disc[i] = -1;
        low[i] = -1;
    }

    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            Dfs(i, -1, disc, low, vis, adj, ap, timer);
        }
    }

    cout << "Articulation Points are: " << endl;
    for (int i = 0; i < n; i++) {
        if (ap[i] != 0) {
            cout << i << endl;
        }
    }

    return 0;
}
