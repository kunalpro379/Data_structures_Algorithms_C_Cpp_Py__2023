#include <iostream>
#include <unordered_map>
#include <list>
#include <algorithm>
#include <vector>
#include <stack>
#include <climits> // for INT_MAX

using namespace std;

class Graph {
public:
    stack<int> Topo;
    unordered_map<int, list<pair<int, int>>> Adj;

    void addEdge(int u, int v, int weight) {
        pair<int, int> P = make_pair(v, weight);
        Adj[u].push_back(P);
    }

    void printAdj() {
        for (auto i : Adj) {
            cout << i.first << " : ";
            for (auto j : i.second) {
                cout << " [" << j.first << ", " << j.second << "]";
            }
            cout << endl;
        }
    }

    void dfs(int node, unordered_map<int, bool>& Vis, stack<int>& Topo) {
        Vis[node] = true;

        for (auto neighbour : Adj[node]) {
            if (!Vis[neighbour.first]) {
                dfs(neighbour.first, Vis, Topo);
            }
        }

        Topo.push(node);
    }

    void getShortestPath(int src, vector<int>& Dist, stack<int>& Topo) {
        Dist[src] = 0;

        while (!Topo.empty()) {
            int top = Topo.top();
            Topo.pop();

            if (Dist[top] != INT_MAX) {
                for (auto i : Adj[top]) {
                    if (Dist[top] + i.second < Dist[i.first]) {
                        Dist[i.first] = Dist[top] + i.second;
                    }
                }
            }
        }
    }
};

int main() {
    Graph g;
    g.addEdge(1, 3, 6);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 4, 4);
    g.addEdge(2, 5, 2);
    g.addEdge(3, 4, -1);
    g.addEdge(4, 5, -1);

    g.printAdj();

    int n = 6;
    unordered_map<int, bool> visited;
    stack<int> Stk;

    // Topological sort
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            g.dfs(i, visited, Stk);
        }
    }

    int src = 1;
    vector<int> Dist(n);
    for (int i=0;i<n;i++){Dist[i]=INT_MAX;}

    g.getShortestPath(src, Dist, Stk);

    cout << "Shortest distances from node " << src << " to all other nodes: " << endl;
    for (int i = 0; i < n; i++) {
        cout<< Dist[i] << endl;
    }

    return 0;




} // 
//