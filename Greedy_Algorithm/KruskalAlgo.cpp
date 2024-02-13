#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class DisjointSet{
    vector<int> rank, parent, size;
public:
    DisjointSet(int n){
        rank.resize(n+1, 0);
        parent.resize(n+1);
        size.resize(n+1, 1); // Initialize size vector with 1
        for(int i = 0; i <= n; i++){
            parent[i] = i;
        }
    }
    
    int findUltimateParent(int node){
        if(node == parent[node]){
            return node;
        } else {
            return parent[node] = findUltimateParent(parent[node]);
        }
    }
    
    void UnionByRank(int u, int v){
        int ultimateParentOfU = findUltimateParent(u);
        int ultimateParentOfV = findUltimateParent(v);
        
        if(ultimateParentOfU == ultimateParentOfV) return;
        
        if(rank[ultimateParentOfU] < rank[ultimateParentOfV]){
            parent[ultimateParentOfU] = ultimateParentOfV;
        } else if(rank[ultimateParentOfV] < rank[ultimateParentOfU]){
            parent[ultimateParentOfV] = ultimateParentOfU;
        } else {
            parent[ultimateParentOfV] = ultimateParentOfU;
            rank[ultimateParentOfU]++;
        }
    }

    void UnionBySize(int u, int v){
        int ultimateParentOfU = findUltimateParent(u);
        int ultimateParentOfV = findUltimateParent(v);
        if(ultimateParentOfU == ultimateParentOfV) return;

        if(size[ultimateParentOfU] < size[ultimateParentOfV]){
            parent[ultimateParentOfU] = ultimateParentOfV;
            size[ultimateParentOfV] += size[ultimateParentOfU];
        } else {
            parent[ultimateParentOfV] = ultimateParentOfU;
            size[ultimateParentOfU] += size[ultimateParentOfV];
        }
    }
};

class Solution{
    
    public:
    int spanningTrees(int V, vector<vector<int>>adj[]){
        vector<pair<int,pair<int, int>>>edges;
        for(int i=0;i<V;i++){
        //every node
        for(auto i: adj[i])
        {
            int adjNode=i[0];
            int wt=i[1];
            int node=i;

            edges.push_back({wt,{node,adjNode}});
        }

        }
        DisjointSet ds(V);
        sort(edges.begin(),edges.end());    //sorting the edges
        int mstWt=0;
        for(auto i:edges){
            int wt=i.first;
            int u=i.second.first;
            int v=i.second.second;

            if(ds.findUltimateParent(u)!=ds.findUltimateParent(v)){
                mstWt+=wt;
                ds.UnionByRank(u,v);
            }
        }
        return mstWt;
    }
};