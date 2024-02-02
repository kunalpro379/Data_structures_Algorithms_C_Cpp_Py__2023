#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Graph {
public:
    int V; 
    vector<pair<int, pair<int, int>>> edges; // (weight, (vertex1, vertex2))

    Graph(int vertices)  {V=vertices;}

    void addEdge(int u, int v, int w) {
        edges.push_back({w, {u, v}});
    }
    int findParents(vector<int>&parent,int i){
if(parent[i]==i)
return i;

return findParents(parent,parent[i]);
    }

void UnionSet(vector<int>&parent,vector<int>&rank,int x,int y){
int rootX=findParents(parent,x);//findig root of the set containting vertex x
int rootY=findParents(parent,y);//finding the root of the set containting vertx y
if(rank[rootX]<rank[rootY])//if ranks odf the set are different then merge the smaller rank set intto the larger rank set
parent[rootX]=rootY;
//setting up rootY as the parent of rootX
else if(rank[rootX]>rank[rootY])
parent[rootY]=rootX;
//setting up rootX as the parent of rootY
else{//if ranks are same then merge any of the set into the other and increase the rank of the set
parent[rootX]=rootY;//setting up rootY as the parent of rootX
rank[rootY]++;//increasing the rank of the set
}
}   
vector<pair<int , pair<int , int>>> kruskalMST(){
vector<pair<int , pair<int , int>>> result;//here we will store the edges of the minimum spanning tree
sort(edges.begin(),edges.end());//sorting the edges in increasing order of their weights
vector<int>parent(V);//parent array for the disjoint set
vector<int >rank(V,0);//rank array for the disjoint set
for(int i=0;i<V;i++){
    parent[i]=i;//iniitialize each vertex as its own parent ,i.e, each vertex is in its own set
}
    int i=0;
while(result.size()<V-1){//continue untill V-1 edges are added int the reuslt
int u=edges[i].second.first;//first vertex of the current edge
int v=edges[i].second.second;//second vertex of the current edge
int w=edges[i].first;//weight of the current edge
i++;//next edge
int rootU=findParents(parent,u);//finding the root of the set containing vertex u
int rootV=findParents(parent,v);//finding the root of the set containing vertex v
//now cheak if adding of current edge creates a cycle or not i.e vertex u and v arent in same set
if(rootU!=rootV){
    result.push_back({w,{u,v}});//if they are not in same set then add the current edge in the result
    UnionSet(parent,rank,rootU,rootV);//merge the two sets
}
}
return result;
}

};
int main() {
    Graph g(4);
    g.addEdge(0, 1, 10);
    g.addEdge(0, 2, 6);
    g.addEdge(0, 3, 5);
    g.addEdge(1, 3, 15);
    g.addEdge(2, 3, 4);

    vector<pair<int, pair<int, int>>> minimumSpanningTree = g.kruskalMST();

    cout << "Minimum Spanning Tree:" << endl;
    for (const auto& edge : minimumSpanningTree) {
        cout << edge.second.first << " -- " << edge.second.second << " with weight " << edge.first << endl;
    }

    return 0;
}