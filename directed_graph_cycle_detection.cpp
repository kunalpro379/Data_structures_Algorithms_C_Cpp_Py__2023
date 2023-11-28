#include <list>
#include <vector>
#include <unordered_map>

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
