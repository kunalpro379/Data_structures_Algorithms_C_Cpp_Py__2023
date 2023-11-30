
#include <list>
#include <stack>
#include <iostream>
#include <unordered_map>
#include <set>
using namespace std;

User
#include <bits/stdc++.h> 
#include <list>
#include<stack>
#include<iostream>
#include<unordered_map>
#include <set>
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    // Write your code here.
    //create adjacency list

    unordered_map<int, list<int>>Adj;
    for (int i=0;i<edges;i++) {
        int u=vec[i][0];
        int v=vec[i][1];
        int w=vec[i][2];

        Adj[u].push_back(v);
        Adj[v].push_back(w);
    }
    vector<int>Dist(vertices);
    for (int i=0;i<vertices;i++) 
        Dist[i]=INT_MAX;
        
        
        set<pair<int,int>>St;

        Dist[source]=0;
        St.insert(make_pair(0,source));
        while (!St.empty()) {
        auto top=*(St.begin());
        int nodeDistance=top.first;
        int topNode=top.second;
        //remove top record
        St.erase(St.begin());

        //traverse onm neighbours

        for (auto neighbours: Adj[topNode]) {
          if (nodeDistance+neighbours.second<Dist[neighbours.first]) {
              auto record=St.find(make_pair(Dist[neighbours.first], neighbours.first));
              //if record found delete itt
              if (record!=St.end()) {
                  St.erase(record);
              }
                 //update distanve

        Dist[neighbours.first]=nodeDistance+neighbours.second;

        //record push in set
        St.insert(make_pair(Dist[neighbours.first],neighbours.first));
         }
        }

        }
        return Dist;
}

int main() {
 
    int vertices = 5;
    int edges = 8;
    vector<vector<int>> vec = {{0, 1, 4}, {0, 2, 1}, {1, 3, 1}, {1, 4, 7}, {2, 1, 2}, {2, 3, 5}, {2, 4, 6}, {3, 4, 8}};
    int source = 0;

    vector<int> result = dijkstra(vec, vertices, edges, source);

    cout << "Shortest distances from node " << source << " to all other nodes: " << endl;
    for (int i = 0; i < vertices; i++) {
        cout << i << ": " << result[i] << endl;
    }

    return 0;
}
