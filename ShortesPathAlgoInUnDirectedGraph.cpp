
#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <list>
#include <algorithm>

using namespace std;

vector<int> shortestPath(vector<pair<int, int>> edges, int n, int m, int s, int t) {
    // Create an adjacency list
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }


    unordered_map<int, bool> visited;
    unordered_map<int, int> parent;
    queue<int> Q;
    Q.push(s);
    visited[s] = true;

    while (!Q.empty()) {
        int front = Q.front();
        Q.pop();

        for (int neighbor : adj[front]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                parent[neighbor] = front;
                Q.push(neighbor);
            }
        }
    }

    // Shortest path
    vector<int> ans;
    int currNode = t;
    ans.push_back(t);

    while (currNode != s) {
        currNode = parent[currNode];
        ans.push_back(currNode);
    }

    reverse(ans.begin(), ans.end());
    return ans;
}





int main() {
    // Example usage
    vector<pair<int, int>> edges = {{1, 2}, {1, 3}, {2, 4}, {2, 5}, {3, 6}, {3, 7}};
    int n = 7; // Number of nodes
    int m = edges.size(); // Number of edges
    int source = 1;
    int target = 6;

    vector<int> result = shortestPath(edges, n, m, source, target);

    cout << "Shortest path from " << source << " to " << target << ": ";
    for (int node : result) {
        cout << node << " ";
    }
    cout << endl;
    //     // visualize `myGraphJson`!
    // string myGraphJson = "{\"kind\":{\"graph\":true},"
    //     "\"nodes\":[{\"id\":\"1\"},{\"id\":\"2\"}],"
    //     "\"edges\":[{\"from\":\"1\",\"to\":\"2\"}]}";
    // cout << myGraphJson;

    return 0;
}
