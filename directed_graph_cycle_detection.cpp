///using kahns algorithem   
#include <list>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <queue>

using namespace std;

bool CheakCycleDFS(int node, unordered_map<int, bool>& visited, unordered_map<int, bool>& dfsvisited, unordered_map<int, list<int>>& adjancy) {
    visited[node] = true;
    dfsvisited[node] = true;
    for (auto neighbour : adjancy[node]) {
        if (!visited[neighbour]) {
            bool CycleDetected = CheakCycleDFS(neighbour, visited, dfsvisited, adjancy);
            if (CycleDetected) {
                return true;
            }
        } else if (dfsvisited[neighbour]) {
            return true;
        }
    }
    dfsvisited[node] = false;
    return false;
}

int detectCycleInDirectedGraph(int n, vector<pair<int, int>>& edges) {
    // Creating adjacency list
    unordered_map<int, list<int>> adjancy;
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i].first;
        int v = edges[i].second;
        adjancy[u].push_back(v);
    }

    // Call DFS for all components
    unordered_map<int, bool> visited;
    unordered_map<int, bool> dfsvisited;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            bool CycleFound = CheakCycleDFS(i, visited, dfsvisited, adjancy);
            if (CycleFound) {
                return true;
            }
        }
    }
    return false;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///
///                   USING K A H N S  ALGORITHEMS
///
////////////////////////////////////////////////////////////////////////////////////////
int detectCycleInDirectedGraph(int n, vector<pair<int, int>>& edges) {
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i].first - 1;
        int v = edges[i].second - 1;
        adj[u].push_back(v);
    }

    // Find all in-degrees
    vector<int> Indegree(n);
    for (auto i : adj) {
        for (auto j : i.second) {
            Indegree[j]++;
        }
    }

    // 0 in-degree nodes push into the queue
    queue<int> Q;
    for (int i = 0; i < n; i++) {
        if (Indegree[i] == 0) {
            Q.push(i);
        }
    }

    // Perform BFS
    int cnt = 0;
    while (!Q.empty()) {
        int front = Q.front();
        Q.pop();
        // ans store
        cnt++;

        // neighbor's in-degree check and update
        for (auto neighbour : adj[front]) {
            Indegree[neighbour]--;
            if (Indegree[neighbour] == 0) {
                Q.push(neighbour);
            }
        }
    }

    // If the count of processed nodes is equal to the number of nodes, there is no cycle
    if (cnt == n) {
        return false;
    } else {
        return true;
    }
}

